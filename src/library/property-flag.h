#ifndef NAPI_CANON_API_PROPERTY_FLAG_VALUE_H
#define NAPI_CANON_API_PROPERTY_FLAG_VALUE_H

#include "types.h"

namespace CameraApi {

    class PropertyFlag : public Napi::ObjectWrap<PropertyFlag> {
        public:
            PropertyFlag(const Napi::CallbackInfo &info);

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetFlag(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

            static Napi::Value ForLabel(const Napi::CallbackInfo &info);

            static bool IsFlagProperty(EdsPropertyID propertyID);

        private:
            static Napi::FunctionReference constructor;

            EdsInt32 value_ = 0;

            static std::string GetLabelForValue(EdsInt32 value);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_API_PROPERTY_FLAG_VALUE_H
