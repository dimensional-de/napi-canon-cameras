#include "camera-browser.h"
#include "api-error.h"
#include "utility.h"

namespace CameraApi {

    struct DeviceEventData {
        CameraReference camera;
    };

    CameraBrowserReference CameraBrowser::singleInstance_ = nullptr;

    CameraBrowserReference CameraBrowser::instance() {
        if (!singleInstance_) {
            singleInstance_ = CameraBrowserReference(new CameraBrowser())->shared_from_this();
        }
        return singleInstance_;
    }

    CameraBrowser::CameraBrowser() {
        isInitialized_ = false;
    }

    CameraBrowser::~CameraBrowser() {
        cameras_.clear();
        terminate();
    }

    void CameraBrowser::triggerEvents() {
        EdsGetEvent();
    }

    void CameraBrowser::attachEventEmit(const Napi::Function &emit) {
        tsEmit_ = Napi::ThreadSafeFunction::New(
            emit.Env(),
            emit,  // JavaScript function called asynchronously
            "EDSDK Event",         // Name
            0,                       // Unlimited queue
            1,                       // Only one thread will use this initially
            [](Napi::Env) {        // Finalizer used to clean threads up
                //nativeThread.join();
            }
        );
    }

    Napi::ThreadSafeFunction &CameraBrowser::getEventEmit() {
        return tsEmit_;
    }

    bool CameraBrowser::hasEventEmit() {
        return tsEmit_;
    }

    void CameraBrowser::handleApiError(EdsError errorCode) {
        if (errorCode != EDS_ERR_OK) {
            if (hasEventEmit()) {
                int *data = new int(errorCode);
                getEventEmit().BlockingCall(
                    data,
                    [](Napi::Env env, Napi::Function jsCallback, int *errorCode) {
                        jsCallback.Call(
                            {
                                Napi::String::New(env, EventName_Error),
                                ApiError::NewInstance(env, *errorCode)
                            }
                        );
                        delete errorCode;
                    }
                );
            }
        }
    }

    EdsError CameraBrowser::initialize() {
        EdsError error = EDS_ERR_OK;
        if (!isInitialized_) {
            error = EdsInitializeSDK();
            if (error == EDS_ERR_OK) {
                isInitialized_ = true;
                error = EdsSetCameraAddedHandler(CameraBrowser::handleCameraAdded, this);
            }
            enumerateCameraList();
        }
        return error;
    }

    EdsError CameraBrowser::terminate() {
        if (isInitialized_) {
            EdsSetCameraAddedHandler(nullptr, nullptr);
            if (tsEmit_) {
                tsEmit_.Release();
                tsEmit_ = nullptr;
            }
            isInitialized_ = false;
            for (const auto &camera : cameras_) {
                camera->disconnect();
            }
        }
        return EdsTerminateSDK();
    }

    CameraReference CameraBrowser::getCameraAtPort(const std::string &portName) {
        initialize();
        auto it = std::find_if(
            cameras_.begin(),
            cameras_.end(),
            [portName](const CameraReference &c) {
                return c->getPortName() == portName;
            }
        );
        if (it != cameras_.end()) {
            return cameras_[it - cameras_.begin()];
        }
        return nullptr;
    }

    CameraReference CameraBrowser::getCameraAtIndex(const uint32_t &index) {
        initialize();
        if ((index >= 0) && (cameras_.size() > index)) {
            return cameras_.at(index);
        }
        return nullptr;
    }

    CameraReference CameraBrowser::getCameraByEdsReference(EdsCameraRef edsCameraRef) {
        auto it = std::find_if(
            cameras_.begin(),
            cameras_.end(),
            [edsCameraRef](CameraReference c) {
                return c->getEdsReference() == edsCameraRef;
            }
        );
        if (it != cameras_.end()) {
            return cameras_[it - cameras_.begin()];
        }
        return nullptr;
    }

    std::vector<CameraReference> CameraBrowser::getCameraList() {
        initialize();
        return cameras_;
    }

    void CameraBrowser::removeCamera(const CameraReference &camera) {
        auto it = std::find_if(
            cameras_.begin(),
            cameras_.end(),
            [camera](const CameraReference &c) {
                return c->getEdsReference() == camera->getEdsReference();
            }
        );
        if (it == cameras_.end()) {
            return;
        }

        CameraReference c = cameras_[it - cameras_.begin()];

        if (hasEventEmit()) {
            DeviceEventData *eventDataPtr;
            eventDataPtr = new DeviceEventData;
            eventDataPtr->camera = camera;

            tsEmit_.BlockingCall(
                eventDataPtr,
                [](Napi::Env env, Napi::Function jsCallback, DeviceEventData *dataPtr) {
                    Napi::Object event = Napi::Object::New(env);
                    event.Set("camera", CameraWrap::NewInstance(env, dataPtr->camera));
                    jsCallback.Call(
                        {
                            Napi::String::New(env, EventName_CameraRemove),
                            event
                        }
                    );
                    delete dataPtr;
                }
            );
        }

        cameras_.erase(it);
    }

    void CameraBrowser::enumerateCameraList() {
        EdsCameraListRef edsCameraList = nullptr;

        EdsError error = EdsGetCameraList(&edsCameraList);
        if (error != EDS_ERR_OK) {
            EdsRelease(edsCameraList);
            return;
        }

        EdsUInt32 cameraCount = 0;
        error = EdsGetChildCount(edsCameraList, &cameraCount);
        if (error != EDS_ERR_OK) {
            EdsRelease(edsCameraList);
            return;
        }

        std::vector<EdsCameraRef> currentRefs = {};
        for (uint32_t idx = 0; idx < cameraCount; idx++) {
            EdsCameraRef edsCamera = nullptr;
            error = EdsGetChildAtIndex(edsCameraList, idx, &edsCamera);
            if (error != EDS_ERR_OK) {
                continue;
            }
            currentRefs.push_back(edsCamera);
        }

        for (auto it = cameras_.rbegin(); it != cameras_.rend(); ++it) {
            CameraReference camera = *it;
            if (std::none_of(
                currentRefs.begin(), currentRefs.end(),
                [camera](EdsCameraRef edsCamera) { return camera->getEdsReference() == edsCamera; }
            )) {
                removeCamera(camera);
            }
        }

        for (auto edsCamera : currentRefs) {
            if (std::none_of(
                cameras_.begin(), cameras_.end(),
                [edsCamera](const CameraReference& c) { return c->getEdsReference() == edsCamera; }
            )) {

                CameraReference camera = nullptr;
                try {
                    camera = Camera::create(edsCamera);
                } catch (...) {
                    EdsRelease(edsCamera);
                    continue;
                }
                EdsRelease(edsCamera);

                cameras_.push_back(camera);

                if (hasEventEmit()) {
                    DeviceEventData *eventDataPtr;
                    eventDataPtr = new DeviceEventData;
                    eventDataPtr->camera = camera;

                    tsEmit_.BlockingCall(
                        eventDataPtr,
                        [](Napi::Env env, Napi::Function jsCallback, DeviceEventData *dataPtr) {
                            Napi::Object event = Napi::Object::New(env);
                            event.Set("camera", CameraWrap::NewInstance(env, dataPtr->camera));
                            jsCallback.Call(
                                {
                                    Napi::String::New(env, EventName_CameraAdd),
                                    event
                                }
                            );
                            delete dataPtr;
                        }
                    );
                }
            }
        }
        EdsRelease(edsCameraList);
    }

    EdsError __stdcall CameraBrowser::handleCameraAdded(EdsVoid *inContext) {
        CameraBrowser *browser = ((CameraBrowser *) inContext);
        browser->enumerateCameraList();

        return EDS_ERR_OK;
    }

    /* JS Wrapper Class */

    Napi::FunctionReference CameraBrowserWrap::constructor;

    CameraBrowserWrap::CameraBrowserWrap(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<CameraBrowserWrap>(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsFunction()) {
            CameraBrowser::instance()->attachEventEmit(info[0].As<Napi::Function>());
        }
    }

    Napi::Value CameraBrowserWrap::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), CameraBrowserWrap::JSClassName);
    }

    Napi::Value CameraBrowserWrap::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, CameraBrowserWrap::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        return Napi::String::New(env, output);
    }

    Napi::Value CameraBrowserWrap::Initialize(const Napi::CallbackInfo &info) {
        return ApiError::ThrowIfFailed(info.Env(), CameraBrowser::instance()->initialize());
    }

    Napi::Value CameraBrowserWrap::Terminate(const Napi::CallbackInfo &info) {
        return ApiError::ThrowIfFailed(info.Env(), CameraBrowser::instance()->terminate());
    }

    Napi::Value CameraBrowserWrap::TriggerEvents(const Napi::CallbackInfo &info) {
        CameraBrowser::instance()->triggerEvents();
        return info.Env().Undefined();
    }

    Napi::Value CameraBrowserWrap::SetEventHandler(const Napi::CallbackInfo &info) {
        if (info.Length() > 0 && info[0].IsFunction()) {
            CameraBrowser::instance()->attachEventEmit(info[0].As<Napi::Function>());
        }
        return info.Env().Undefined();
    }

    Napi::Value CameraBrowserWrap::GetCamera(const Napi::CallbackInfo &info) {
        CameraReference camera;
        if (info.Length() > 0) {
            if (info[0].IsNumber()) {
                camera = CameraBrowser::instance()->getCameraAtIndex(info[0].As<Napi::Number>());
            } else if (info[0].IsString()) {
                camera = CameraBrowser::instance()->getCameraAtPort(info[0].As<Napi::String>());
            } else {
                throw Napi::TypeError::New(info.Env(), "Argument must be a port name or index.");
            }
        } else {
            camera = CameraBrowser::instance()->getCameraAtIndex(0);
        }
        if (camera) {
            return CameraWrap::NewInstance(info.Env(), camera);
        }
        return info.Env().Null();
    }

    Napi::Value CameraBrowserWrap::GetCameras(const Napi::CallbackInfo &info) {
        std::vector<CameraReference> cameras = CameraBrowser::instance()->getCameraList();
        int cameraIndex = 0;
        Napi::Array list = Napi::Array::New(info.Env());
        for (CameraReference &camera : CameraBrowser::instance()->getCameraList()) {
            list.Set(
                cameraIndex,
                CameraWrap::NewInstance(info.Env(), camera)
            );
            cameraIndex++;
        }
        return list;
    }

    Napi::Value CameraBrowserWrap::Update(const Napi::CallbackInfo &info) {
        CameraBrowser::instance()->enumerateCameraList();
        return info.Env().Undefined();
    }

    Napi::Object CameraBrowserWrap::NewInstance(Napi::Env env) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = constructor.New({});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    Napi::Object CameraBrowserWrap::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object eventNames = Napi::Object::New(env);
        eventNames.Set("CameraAdd", EventName_CameraAdd);
        eventNames.Set("CameraRemove", EventName_CameraRemove);
        eventNames.Set("LiveViewStart", EventName_LiveViewStart);
        eventNames.Set("LiveViewStop", EventName_LiveViewStop);
        eventNames.Set("StateChange", EventName_StateChange);
        eventNames.Set("PropertyChangeOptions", EventName_PropertyChangeOptions);
        eventNames.Set("PropertyChangeValue", EventName_PropertyChangeValue);
        eventNames.Set("DownloadRequest", EventName_DownloadRequest);
        eventNames.Set("ObjectChange", EventName_ObjectChange);
        eventNames.Set("Error", EventName_Error);

        Napi::Function func = DefineClass(
            env,
            CameraBrowserWrap::JSClassName,
            {
                InstanceMethod("initialize", &CameraBrowserWrap::Initialize),
                InstanceMethod("terminate", &CameraBrowserWrap::Terminate),
                InstanceMethod("triggerEvents", &CameraBrowserWrap::TriggerEvents),
                InstanceMethod("getCamera", &CameraBrowserWrap::GetCamera),
                InstanceMethod("getCameras", &CameraBrowserWrap::GetCameras),
                InstanceMethod("update", &CameraBrowserWrap::Update),
                InstanceMethod("setEventHandler", &CameraBrowserWrap::SetEventHandler),

                InstanceAccessor<&CameraBrowserWrap::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
                InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &CameraBrowserWrap::Inspect),

                StaticValue("Events", eventNames, napi_enumerable)
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();

        exports.Set(CameraBrowserWrap::JSClassName, func);
        exports.Set("cameraBrowser", CameraBrowserWrap::NewInstance(env));
        return exports;
    }

}
