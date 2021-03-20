#ifndef NAPI_CANON_API_PROPERTY_ISO_SENSITIVITY_H
#define NAPI_CANON_API_PROPERTY_ISO_SENSITIVITY_H

#include "types.h"

namespace CameraApi {

    class ISOSensitivity : public Napi::ObjectWrap<ISOSensitivity> {
        public:
            explicit ISOSensitivity(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

        private:
            static constexpr const char JSClassName[] = "ISOSensitivity";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsInt32 value_ = 0;
            int sensitivity_ = 0;

            static std::string GetLabelForValue(EdsInt32 value);

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetISOSensitivity(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            static Napi::Value ForLabel(const Napi::CallbackInfo &info);

            static Napi::Value FindNearest(const Napi::CallbackInfo &info);

            EdsInt32 ForLabel(const std::string &label);
    };
}

#endif //NAPI_CANON_API_PROPERTY_ISO_SENSITIVITY_H
