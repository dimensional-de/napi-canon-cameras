#include "flag.h"
#include "utility.h"
#include <unordered_map>
#include <cctype>

namespace CameraApi {

    std::vector<EdsPropertyID> FlagProperty = {
        kEdsPropID_Evf_DepthOfFieldPreview,
        kEdsPropID_Evf_Mode,
        kEdsPropID_FixedMovie,
        kEdsPropID_MirrorUpSetting,
        kEdsPropID_SummerTimeSetting
    };

    Flag::Flag(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<Flag>(info) {

        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsBoolean()) {
            value_ = info[0].As<Napi::Boolean>().Value() ? 0x01 : 0x00;
        } else if (info.Length() > 0 && info[0].IsNumber()) {
            value_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a boolean or number."
            );
        }
    }

    std::string Flag::GetLabelForValue(EdsInt32 value) {
        return value == 0x01 ? "true" : "false";
    }

    Napi::Value Flag::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), GetLabelForValue(value_));
    }

    Napi::Value Flag::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value Flag::GetFlag(const Napi::CallbackInfo &info) {
        return Napi::Boolean::New(info.Env(), value_ != 0x00);
    }

    Napi::Value Flag::GetPrimitive(const Napi::CallbackInfo &info) {
        if (info.Length() > 0 && info[0].IsString()) {
            std::string hint = info[0].As<Napi::String>().Utf8Value();
            if (hint == "number") {
                return GetValue(info);
            }
            if (hint == "boolean") {
                return GetFlag(info);
            }
            if (hint == "string") {
                return GetLabel(info);
            }
        }
        return info.Env().Null();
    }

    Napi::Value Flag::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        Json.Set("flag", GetFlag(info));
        return Json;
    }

    bool Flag::IsFlagProperty(EdsPropertyID propertyID) {
        return (
            std::find(
                FlagProperty.begin(), FlagProperty.end(), propertyID
            ) != FlagProperty.end()
        );
    }

    Napi::Value Flag::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), Flag::JSClassName);
    }

    Napi::Value Flag::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, Flag::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {
                    Napi::String::New(env, value_ == 0x01 ? "true" : "false"),
                    Napi::String::New(env, "boolean")
                }
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    }

    Napi::Value Flag::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) {
            return Flag::NewInstance(info.Env(), 0x00);
        }
        std::string label = info[0].As<Napi::String>().Utf8Value();
        try {
            std::transform(
                label.begin(),
                label.end(),
                label.begin(),
                [](unsigned char c) { return std::tolower(c); }
            );
            bool isTruthy;
            isTruthy = (
                (label == "true") ||
                (label == "1") ||
                (label == "yes") ||
                (label == "on")
            );
            return Flag::NewInstance(info.Env(), isTruthy ? 0x01 : 0x00);
        } catch (...) {
            return Flag::NewInstance(info.Env(), 0x00);
        }
    }

    Napi::Object Flag::NewInstance(Napi::Env env, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void Flag::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&Flag::GetLabel>("label"),
            InstanceAccessor<&Flag::GetValue>("value"),
            InstanceAccessor<&Flag::GetFlag>("flag"),
            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &Flag::GetPrimitive),
            InstanceMethod("toJSON", &Flag::ToJSON),

            InstanceAccessor<&Flag::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &Flag::Inspect),

            StaticMethod<&Flag::ForLabel>("forLabel"),

            StaticValue("True", Napi::Number::New(env, 0x01), napi_enumerable),
            StaticValue("False", Napi::Number::New(env, 0x00), napi_enumerable)
        };

        Napi::Function func = DefineClass(env, Flag::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(Flag::JSClassName, func);
    }
}
