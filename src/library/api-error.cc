#include "api-error.h"
#include "api-identifier.h"
#include "utility.h"
#include "labels.h"

namespace CameraApi {

    Napi::FunctionReference ApiErrorWrap::constructor;

    ApiErrorWrap::ApiErrorWrap(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<ApiErrorWrap>(info), ApiIdentifier(info, ApiErrorWrap::JSClassName, Labels::Error)  {
    }

    Napi::Object ApiErrorWrap::NewInstance(Napi::Env env, EdsError errorCode) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = constructor.New({Napi::Number::New(env, errorCode)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    Napi::Value ApiErrorWrap::Throw(Napi::Env env, EdsError errorCode) {
        std::string label = "EDSDK - ";
        if (Labels::Error.find(errorCode) == Labels::Error.end()) {
            label.append(CodeToHexLabel(errorCode));
        } else {
            label.append(Labels::Error[errorCode]);
        }
        Napi::Error error = Napi::Error::New(env, label);
        error.Value()["EDS_ERROR"] = ApiErrorWrap::NewInstance(env, errorCode);
        throw error;
    }

    Napi::Value ApiErrorWrap::ThrowIfFailed(Napi::Env env, EdsError errorCode, Napi::Value defaultValue) {
        if (errorCode != EDS_ERR_OK) {
            ApiErrorWrap::Throw(env, errorCode);
        }
        return defaultValue;
    }

    Napi::Value ApiErrorWrap::ThrowIfFailed(Napi::Env env, EdsError errorCode) {
        return ApiErrorWrap::ThrowIfFailed(env, errorCode, env.Undefined());
    }

    void ApiErrorWrap::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object Codes = Napi::Object::New(env);
        for (const auto &it : Labels::Error) {
            Codes.DefineProperty(
                Napi::PropertyDescriptor::Value(
                    it.second.c_str(), Napi::Number::New(env, it.first), napi_enumerable
                )
            );
        }

        std::vector <PropertyDescriptor> properties = {
            InstanceAccessor("label", &ApiErrorWrap::GetLabel, nullptr),
            InstanceAccessor("identifier", &ApiErrorWrap::GetIdentifier, nullptr),
            InstanceMethod("toJSON", &ApiErrorWrap::ToJSON),
            InstanceMethod("equalTo", &ApiErrorWrap::EqualTo),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &ApiErrorWrap::GetPrimitive),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &ApiErrorWrap::Inspect),
            InstanceAccessor(Napi::Symbol::WellKnown(env, "toStringTag"), &ApiErrorWrap::ToStringTag, nullptr),

            StaticValue("Code", Codes, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, ApiErrorWrap::JSClassName, properties);
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();

        exports.Set(ApiErrorWrap::JSClassName, func);
    }
}
