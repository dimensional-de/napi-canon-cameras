#ifndef CANON_API_CAMERA_H
#define CANON_API_CAMERA_H

#include "types.h"

namespace CameraApi {

    typedef std::shared_ptr<class Camera> CameraReference;

    class Camera : public std::enable_shared_from_this<Camera> {
        public:
            Camera(const EdsCameraRef edsCamera);

            ~Camera();

            static CameraReference create(const EdsCameraRef &edsCamera);

            EdsError connect(bool shouldKeepAlive);

            EdsError disconnect();

            EdsError sendCommand(EdsCameraCommand command, EdsInt32 parameter);

            EdsError takePicture();

            EdsError startLiveView();

            EdsError stopLiveView();

            EdsError downloadLiveViewImage(std::string &image);

            inline std::string getDescription() const {
                return std::string(deviceInfo_.szDeviceDescription);
            }

            inline std::string getPortName() const {
                return std::string(deviceInfo_.szPortName);
            }

            inline EdsCameraRef getEdsReference() const {
                return edsCamera_;
            }

            inline Napi::Env Env() const {
                return env_;
            }

            void attachEventEmit(const Napi::Function &emit);

        private:
            Napi::Env env_ = nullptr;
            EdsCameraRef edsCamera_;
            EdsDeviceInfo deviceInfo_;
            bool isConnected_ = false;
            bool shouldKeepAlive_ = false;
            bool hasActiveLiveView_ = false;

            Napi::ThreadSafeFunction tsEmit_;

            bool updateLiveViewStatus();

            Napi::ThreadSafeFunction &getEventEmit();

            bool hasEventEmit();

            static EdsError __stdcall handleStateEvent(EdsStateEvent inEvent, EdsUInt32 inParam, EdsVoid *inContext);

            static EdsError __stdcall handlePropertyEvent(
                EdsPropertyEvent inEvent, EdsUInt32 inPropertyID, EdsUInt32 inParam, EdsVoid *inContext
            );

            static EdsError __stdcall handleObjectEvent(EdsObjectEvent inEvent, EdsBaseRef inRef, EdsVoid *inContext);
    };

    class CameraWrap : public Napi::ObjectWrap<CameraWrap> {
        public:
            static void Init(Napi::Env env, Napi::Object exports);

            explicit CameraWrap(const Napi::CallbackInfo &info);

            ~CameraWrap() override;

            static Napi::Object NewInstance(Napi::Env env, CameraReference camera);

            static Napi::Object NewInstance(Napi::Env env, EdsCameraRef edsCameraRef);

            CameraReference inline GetCameraReference() {
                return camera_;
            }

        private:
            static constexpr const char JSClassName[] = "Camera";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            CameraReference camera_;

            Napi::Value GetDescription(const Napi::CallbackInfo &info);

            Napi::Value GetPortName(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value Connect(const Napi::CallbackInfo &info);

            Napi::Value Disconnect(const Napi::CallbackInfo &info);

            Napi::Value SetEventHandler(const Napi::CallbackInfo &info);

            Napi::Value GetProperty(const Napi::CallbackInfo &info);

            Napi::Value SendCommand(const Napi::CallbackInfo &info);

            Napi::Value TakePicture(const Napi::CallbackInfo &info);

            Napi::Value StartLiveView(const Napi::CallbackInfo &info);

            Napi::Value StopLiveView(const Napi::CallbackInfo &info);

            Napi::Value DownloadLiveViewImage(const Napi::CallbackInfo &info);

            Napi::Value GetVolumes(const Napi::CallbackInfo &info);
    };
}

#endif
