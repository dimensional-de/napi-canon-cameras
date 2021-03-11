#include "property-flag.h"
#include "types.h"
#include "utility.h"
#include <unordered_map>
#include <iostream>

namespace CameraApi {

    std::vector<EdsPropertyID> FlagProperty = {
        kEdsPropID_Evf_DepthOfFieldPreview,
        kEdsPropID_Evf_Mode,
        kEdsPropID_FixedMovie,
        kEdsPropID_MirrorUpSetting,
        kEdsPropID_SummerTimeSetting
    };

    PropertyFlag::PropertyFlag(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<PropertyFlag>(info) {

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

    std::string PropertyFlag::GetLabelForValue(EdsInt32 value) {
        return value == 0x01 ? "true" : "false";
    }

    Napi::Value PropertyFlag::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), GetLabelForValue(value_));
    }

    Napi::Value PropertyFlag::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value PropertyFlag::GetFlag(const Napi::CallbackInfo &info) {
        return Napi::Boolean::New(info.Env(), value_ != 0x00);
    }

    Napi::Value PropertyFlag::GetPrimitive(const Napi::CallbackInfo &info) {
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

    Napi::Value PropertyFlag::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        Json.Set("flag", GetFlag(info));
        return Json;
    }

    bool PropertyFlag::IsFlagProperty(EdsPropertyID propertyID) {
        return (
            std::find(
                FlagProperty.begin(), FlagProperty.end(), propertyID
            ) != FlagProperty.end()
        );
    }

    Napi::Value PropertyFlag::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), PropertyFlag::JSClassName);
    }

    Napi::Value PropertyFlag::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, PropertyFlag::JSClassName), Napi::String::New(env, "special")}
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

    Napi::Value PropertyFlag::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) {
            return PropertyFlag::NewInstance(info.Env(), 0x00);
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
            return PropertyFlag::NewInstance(info.Env(), isTruthy ? 0x01 : 0x00);
        } catch (...) {
            return PropertyFlag::NewInstance(info.Env(), 0x00);
        }
    }

    Napi::Object PropertyFlag::NewInstance(Napi::Env env, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void PropertyFlag::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&PropertyFlag::GetLabel>("label"),
            InstanceAccessor<&PropertyFlag::GetValue>("value"),
            InstanceAccessor<&PropertyFlag::GetFlag>("flag"),
            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &PropertyFlag::GetPrimitive),
            InstanceMethod("toJSON", &PropertyFlag::ToJSON),

            InstanceAccessor<&PropertyFlag::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &PropertyFlag::Inspect),

            StaticMethod<&PropertyFlag::ForLabel>("forLabel"),

            StaticValue("True", Napi::Number::New(env, 0x01), napi_enumerable),
            StaticValue("False", Napi::Number::New(env, 0x00), napi_enumerable)
        };

        Napi::Function func = DefineClass(env, PropertyFlag::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(PropertyFlag::JSClassName, func);
    }
}
