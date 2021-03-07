#ifndef NAPI_CANON_API_PROPERTY_APERTURE_H
#define NAPI_CANON_API_PROPERTY_APERTURE_H

#include "types.h"

namespace CameraApi {

    class PropertyAperture : public Napi::ObjectWrap<PropertyAperture> {
        public:
            PropertyAperture(const Napi::CallbackInfo &info);

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetAperture(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

        private:
            static Napi::FunctionReference constructor;

            EdsInt32 value_ = 0;
            double f_ = 0;

            static std::string GetLabelForValue(EdsInt32 value);

            static std::string GetLabelForAperture(double seconds);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_API_PROPERTY_APERTURE_H
