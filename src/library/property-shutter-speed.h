#ifndef NAPI_CANON_API_PROPERTY_SHUTTER_SPEED_H
#define NAPI_CANON_API_PROPERTY_SHUTTER_SPEED_H

#include "types.h"

namespace CameraApi {

    class PropertyShutterSpeed : public Napi::ObjectWrap<PropertyShutterSpeed> {
        public:
            PropertyShutterSpeed(const Napi::CallbackInfo &info);

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetSeconds(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

        private:
            static Napi::FunctionReference constructor;

            EdsInt32 value_ = 0;
            double seconds_ = 0;

            static std::string GetLabelForValue(EdsInt32 value);

            static std::string GetLabelForSeconds(double seconds);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_API_PROPERTY_SHUTTER_SPEED_H
