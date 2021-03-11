#ifndef CANON_API_CAMERA_BROWSER_H
#define CANON_API_CAMERA_BROWSER_H

#include "types.h"
#include "camera.h"

namespace CameraApi {

    typedef std::shared_ptr<class CameraBrowser> CameraBrowserReference;

    class CameraBrowser : public std::enable_shared_from_this<CameraBrowser> {
        public:
            static CameraBrowserReference instance();

            ~CameraBrowser();

            EdsError initialize();

            EdsError terminate();

            CameraReference getCameraAtPort(const std::string &portName);

            CameraReference getCameraAtIndex(const uint32_t &index);

            CameraReference getCameraByEdsReference(EdsCameraRef edsCameraRef);

            std::vector<CameraReference> getCameraList();

            void enumerateCameraList();

            void removeCamera(const CameraReference &camera);

            void attachEventEmit(const Napi::Function &emit);

            bool hasEventEmit();

            Napi::ThreadSafeFunction &getEventEmit();

            void handleApiError(EdsError errorCode);

            void triggerEvents();

        private:
            CameraBrowser();

            static CameraBrowserReference singleInstance_;

            bool isInitialized_ = false;

            Napi::ThreadSafeFunction tsEmit_;

            std::vector<CameraReference> cameras_;

            static EdsError __stdcall handleCameraAdded(EdsVoid *inContext);
    };

    class CameraBrowserWrap : public Napi::ObjectWrap<CameraBrowserWrap> {
        public:
            explicit CameraBrowserWrap(const Napi::CallbackInfo &info);

            static Napi::Object NewInstance(Napi::Env env);

            static Napi::Object Init(Napi::Env env, Napi::Object exports);

        private:
            static constexpr const char JSClassName[] = "CameraBrowser";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value Initialize(const Napi::CallbackInfo &info);

            Napi::Value Terminate(const Napi::CallbackInfo &info);

            Napi::Value SetEventHandler(const Napi::CallbackInfo &info);

            Napi::Value TriggerEvents(const Napi::CallbackInfo &info);

            Napi::Value GetCamera(const Napi::CallbackInfo &info);

            Napi::Value GetCameras(const Napi::CallbackInfo &info);

            Napi::Value Update(const Napi::CallbackInfo &info);
    };
}

#endif
