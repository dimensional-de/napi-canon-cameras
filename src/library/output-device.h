#ifndef NAPI_CANON_CAMERAS_OUTPUT_DEVICE_H
#define NAPI_CANON_CAMERAS_OUTPUT_DEVICE_H

#include "types.h"

namespace CameraApi {

    class OutputDevice : public Napi::ObjectWrap<OutputDevice> {
        public:
            explicit OutputDevice(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

        private:
            static constexpr const char JSClassName[] = "OutputDevice";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsInt32 value_ = 0;

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value GetDevices(const Napi::CallbackInfo &info);

            bool IsEnabled(EdsInt32 deviceID) const;

            Napi::Value IsEnabled(const Napi::CallbackInfo &info);

            static Napi::Value ForLabel(const Napi::CallbackInfo &info);

            static EdsInt32 GetValueForDeviceName(const std::string& deviceName);
    };
}

#endif //NAPI_CANON_CAMERAS_OUTPUT_DEVICE_H
