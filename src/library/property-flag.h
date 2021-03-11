#ifndef NAPI_CANON_API_PROPERTY_FLAG_VALUE_H
#define NAPI_CANON_API_PROPERTY_FLAG_VALUE_H

#include "types.h"

namespace CameraApi {

    class PropertyFlag : public Napi::ObjectWrap<PropertyFlag> {
        public:
            explicit PropertyFlag(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

            static bool IsFlagProperty(EdsPropertyID propertyID);

        private:
            static constexpr const char JSClassName[] = "PropertyFlag";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsInt32 value_ = 0;

            static std::string GetLabelForValue(EdsInt32 value);

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetFlag(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            static Napi::Value ForLabel(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_API_PROPERTY_FLAG_VALUE_H
