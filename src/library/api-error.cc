#include "api-error.h"
#include "utility.h"
#include "labels.h"

namespace CameraApi {

    ApiError::ApiError(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<ApiError>(info), ApiIdentifier(info, ApiError::JSClassName, Labels::Error)  {
    }

    Napi::Object ApiError::NewInstance(Napi::Env env, EdsError errorCode) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New({Napi::Number::New(env, errorCode)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    Napi::Value ApiError::Throw(Napi::Env env, EdsError errorCode) {
        std::string label = "EDSDK - ";
        if (Labels::Error.find(errorCode) == Labels::Error.end()) {
            label.append(CodeToHexLabel(errorCode));
        } else {
            label.append(Labels::Error[errorCode]);
        }
        Napi::Error error = Napi::Error::New(env, label);
        error.Value()["EDS_ERROR"] = ApiError::NewInstance(env, errorCode);
        throw error;
    }

    Napi::Value ApiError::ThrowIfFailed(Napi::Env env, EdsError errorCode, Napi::Value defaultValue) {
        if (errorCode != EDS_ERR_OK) {
            ApiError::Throw(env, errorCode);
        }
        return defaultValue;
    }

    Napi::Value ApiError::ThrowIfFailed(Napi::Env env, EdsError errorCode) {
        return ApiError::ThrowIfFailed(env, errorCode, env.Undefined());
    }

    void ApiError::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object Codes = Napi::Object::New(env);
        for (const auto &it : Labels::Error) {
            Codes.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }

        std::vector <PropertyDescriptor> properties = {
            InstanceAccessor("label", &ApiError::GetLabel, nullptr),
            InstanceAccessor("identifier", &ApiError::GetIdentifier, nullptr),
            InstanceMethod("toJSON", &ApiError::ToJSON),
            InstanceMethod("equalTo", &ApiError::EqualTo),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &ApiError::GetPrimitive),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &ApiError::Inspect),
            InstanceAccessor(Napi::Symbol::WellKnown(env, "toStringTag"), &ApiError::ToStringTag, nullptr),

            StaticValue("Code", Codes, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, ApiError::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(ApiError::JSClassName, func);
    }
}
