#include "iso-sensitivity.h"
#include "utility.h"
#include <unordered_map>
#include <iostream>

namespace CameraApi {

    std::unordered_map<int, int> ISOSensitivityValues = {
        {0x00000028, 6},
        {0x00000030, 12},
        {0x00000038, 25},
        {0x00000040, 50},
        {0x00000048, 100},
        {0x0000004b, 125},
        {0x0000004d, 160},
        {0x00000050, 200},
        {0x00000053, 250},
        {0x00000055, 320},
        {0x00000058, 400},
        {0x0000005b, 500},
        {0x0000005d, 640},
        {0x00000060, 800},
        {0x00000063, 1000},
        {0x00000065, 1250},
        {0x00000068, 1600},
        {0x0000006b, 2000},
        {0x0000006d, 2500},
        {0x00000070, 3200},
        {0x00000073, 4000},
        {0x00000075, 5000},
        {0x00000078, 6400},
        {0x0000007b, 8000},
        {0x0000007d, 10000},
        {0x00000080, 12800},
        {0x00000083, 16000},
        {0x00000085, 20000},
        {0x00000088, 25600},
        {0x0000008b, 32000},
        {0x0000008d, 40000},
        {0x00000090, 51200},
        {0x00000093, 64000},
        {0x00000095, 80000},
        {0x00000098, 102400},
        {0x000000a0, 204800},
        {0x000000a8, 409600},
        {0x000000b0, 819200}
    };

    ISOSensitivity::ISOSensitivity(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<ISOSensitivity>(info) {

        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsNumber()) {
            value_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property value."
            );
        }

        if (ISOSensitivityValues.find(value_) != ISOSensitivityValues.end()) {
            sensitivity_ = ISOSensitivityValues[value_];
        } else {
            sensitivity_ = 0;
        }
    }

    std::string ISOSensitivity::GetLabelForValue(EdsInt32 value) {
        if (0 == value) {
            return "Auto";
        } else if (ISOSensitivityValues.find(value) != ISOSensitivityValues.end()) {
            return std::to_string(ISOSensitivityValues[value]);
        }
        return "";
    }

    Napi::Value ISOSensitivity::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), GetLabelForValue(value_));
    }

    Napi::Value ISOSensitivity::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value ISOSensitivity::GetISOSensitivity(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), sensitivity_);
    }

    Napi::Value ISOSensitivity::GetPrimitive(const Napi::CallbackInfo &info) {
        if (info.Length() > 0 && info[0].IsString()) {
            std::string hint = info[0].As<Napi::String>().Utf8Value();
            if (hint == "number") {
                return GetValue(info);
            }
            if (hint == "string") {
                return GetLabel(info);
            }
        }
        return info.Env().Null();
    }

    Napi::Value ISOSensitivity::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        Json.Set("sensitivity", GetISOSensitivity(info));
        return Json;
    }

    Napi::Value ISOSensitivity::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), ISOSensitivity::JSClassName);
    }

    Napi::Value ISOSensitivity::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, ISOSensitivity::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {
                    GetLabel(info),
                    (value_ == 0)
                    ? Napi::String::New(env, "string")
                    : Napi::String::New(env, "number")
                }
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    }

    EdsInt32 ISOSensitivity::ForLabel(const std::string& label) {
        try {
            int sensitivity = std::stoi(label);
            for (const auto &it : ISOSensitivityValues) {
                if (sensitivity == it.second) {
                    return it.first;
                }
            }
        } catch (...) {
        }
        throw std::logic_error("Label does not match any value");
    }

    Napi::Value ISOSensitivity::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) {
            return info.Env().Null();
        }
        std::string label = info[0].As<Napi::String>().Utf8Value();
        if (label == "Auto") {
            return ISOSensitivity::NewInstance(info.Env(), 0);
        }
        try {
            return ISOSensitivity::NewInstance(
                info.Env(), ISOSensitivity::ForLabel(label)
            );
        } catch (...) {
            return info.Env().Null();
        }
    }

    Napi::Value ISOSensitivity::FindNearest(const Napi::CallbackInfo &info) {
        const Napi::Env &env = info.Env();
        int sensitivity;
        bool validArgument = false;
        if (info.Length() > 0) {
            try {
                if (info[0].IsString()) {
                    auto value = ISOSensitivity::ForLabel(
                        info[0].As<Napi::String>().Utf8Value()
                    );
                    sensitivity = ISOSensitivityValues[value];
                    validArgument = true;
                } else if (info[0].IsNumber()) {
                    auto value = info[0].As<Napi::Number>().Int32Value();
                    if (ISOSensitivityValues.find(value) != ISOSensitivityValues.end()) {
                        sensitivity = ISOSensitivityValues[value];
                        validArgument = true;
                    }
                }
            } catch (...) {
            }
        }
        if (!validArgument) {
            throw Napi::TypeError::New(
                env, "Argument 0 must be a number or string."
            );
        }
        Napi::Function filter;
        bool ignoreFilter = true;
        if ((info.Length() > 1) && info[1].IsFunction()) {
            filter = info[1].As<Napi::Function>();
            ignoreFilter = false;
        }
        int matchDelta = INT_MAX;
        EdsInt32 matchValue = 0;
        for (const auto &it : ISOSensitivityValues) {
            auto delta = std::abs(sensitivity - it.second);
            if (delta < matchDelta) {
                auto allowed = (
                    ignoreFilter ||
                    filter.Call(
                        {ISOSensitivity::NewInstance(env, it.first)}
                    ).As<Napi::Boolean>().Value()
                );
                if (allowed) {
                    matchDelta = delta;
                    matchValue = it.first;
                }
            }
        }
        return matchValue > 0 ? ISOSensitivity::NewInstance(env, matchValue) : env.Null();
    }

    Napi::Object ISOSensitivity::NewInstance(Napi::Env env, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void ISOSensitivity::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object IDs = Napi::Object::New(env);
        IDs.Set("Auto", Napi::Number::New(env, 0));
        Napi::Object Values = Napi::Object::New(env);
        for (const auto &it : ISOSensitivityValues) {
            Values.Set(it.first, it.second);
        }

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&ISOSensitivity::GetLabel>("label"),
            InstanceAccessor<&ISOSensitivity::GetValue>("value"),
            InstanceAccessor<&ISOSensitivity::GetISOSensitivity>("sensitivity"),
            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &ISOSensitivity::GetPrimitive),
            InstanceMethod("toJSON", &ISOSensitivity::ToJSON),

            InstanceAccessor<&ISOSensitivity::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &ISOSensitivity::Inspect),

            StaticMethod<&ISOSensitivity::ForLabel>("forLabel"),
            StaticMethod<&ISOSensitivity::FindNearest>("findNearest"),

            StaticValue("ID", IDs, napi_enumerable),
            StaticValue("Values", Values, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, ISOSensitivity::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(ISOSensitivity::JSClassName, func);
    }
}
