#ifndef NAPI_CANON_CAMERAS_PROPERTY_EXPOSURE_COMPENSATION_H
#define NAPI_CANON_CAMERAS_PROPERTY_EXPOSURE_COMPENSATION_H

#include "types.h"

namespace CameraApi {
    class PropertyExposureCompensation : public Napi::ObjectWrap<PropertyExposureCompensation> {
        public:
            explicit PropertyExposureCompensation(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

        private:
            static constexpr const char JSClassName[] = "PropertyExposureCompensation";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsInt32 value_ = 0;
            double compensation_ = 0.0;

            Napi::Value GetCompensation(const Napi::CallbackInfo &info);

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            static std::string GetLabelForCompensation(double compensation);

            static std::string GetLabelForValue(EdsInt32 value);

            static Napi::Value ForLabel(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_CAMERAS_PROPERTY_EXPOSURE_COMPENSATION_H
