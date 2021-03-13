#include "exposure-compensation.h"
#include "types.h"
#include "utility.h"

namespace CameraApi {


    std::unordered_map<int, double> ExposureCompensationValues = {
        {0x00, 0},
        {0x1B, (3.0 + (1.0 / 3.0))},
        {0x1C, (3.0 + (1.0 / 2))},
        {0x1D, (3.0 + (2.0 / 3.0))},
        {0x03, (1.0 / 3.0)},
        {0x04, (1.0 / 2.0)},
        {0x05, (2.0 / 3.0)},
        {0x08, (1.0)},
        {0x10, (2.0)},
        {0x13, (2.0 + (1.0 / 3.0))},
        {0x14, (2.0 + (1.0 / 2.0))},
        {0x15, (2.0 + (2.0 / 3.0))},
        {0x18, (3.0)},
        {0x20, (4.0)},
        {0x23, (4.0 + (1.0 / 3.0))},
        {0x24, (4.0 + (1.0 / 2.0))},
        {0x25, (4.0 + (2.0 / 3.0))},
        {0x28, (5.0)},
        {0x0B, (1.0 + (1.0 / 3.0))},
        {0x0C, (1.0 + (1.0 / 2.0))},
        {0x0D, (1.0 + (2.0 / 3.0))},
        {0xD8, (-5.0)},
        {0xDB, (-4.0 - (2.0 / 3.0))},
        {0xDC, (-4.0 - (1.0 / 2.0))},
        {0xDD, (-4.0 - (1.0 / 3.0))},
        {0xE0, (-4.0)},
        {0xE3, (-3.0 - (2.0 / 3.0))},
        {0xE4, (-3.0 - (1.0 / 2.0))},
        {0xE5, (-3.0 - (1.0 / 3.0))},
        {0xE8, (-3.0)},
        {0xEB, (-2.0 - (2.0 / 3.0))},
        {0xEC, (-2.0 - (1.0 / 2.0))},
        {0xED, (-2.0 - (1.0 / 3.0))},
        {0xF0, (-2.0)},
        {0xF3, (-1.0 - (2.0 / 3.0))},
        {0xF4, (-1.0 - (1.0 / 2.0))},
        {0xF5, (-1.0 - (1.0 / 3.0))},
        {0xF8, (-1.0)},
        {0xFB, -(2.0 / 3.0)},
        {0xFC, -(1.0 / 2.0)},
        {0xFD, -(1.0 / 3.0)}
    };

    ExposureCompensation::ExposureCompensation(
        const Napi::CallbackInfo &info
    ) : Napi::ObjectWrap<ExposureCompensation>(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsNumber()) {
            value_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property value."
            );
        }

        if (ExposureCompensationValues.find(value_) != ExposureCompensationValues.end()) {
            compensation_ = ExposureCompensationValues[value_];
        } else {
            compensation_ = 0;
        }
    }

    std::string ExposureCompensation::GetLabelForValue(EdsInt32 value) {
        if (value == 0) {
            return "0";
        } else if (value == 0xFFFFFF) {
            return "";
        }
        return ExposureCompensation::GetLabelForCompensation(
            ExposureCompensationValues[value]
        );
    }

    std::string ExposureCompensation::GetLabelForCompensation(double compensation) {
        std::string label;
        if (compensation == 0) {
            return "0";
        }
        int full = (int) compensation;
        double fraction = abs(compensation - full);
        label = (full == 0) ? "" :  stringFormat("%+d", full);
        if (fraction > 0.6) {
            label.append(" 2/3");
        } else if (fraction > 0.49) {
            label.append(" 1/2");
        } else if (fraction > 0.3) {
            label.append(" 1/3");
        }
        return label;
    }

    Napi::Value ExposureCompensation::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), GetLabelForValue(value_));
    }

    Napi::Value ExposureCompensation::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value ExposureCompensation::GetCompensation(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), compensation_);
    }

    Napi::Value ExposureCompensation::GetPrimitive(const Napi::CallbackInfo &info) {
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

    Napi::Value ExposureCompensation::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        Json.Set("compensation", GetCompensation(info));
        return Json;
    }

    Napi::Value ExposureCompensation::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), ExposureCompensation::JSClassName);
    }

    Napi::Value ExposureCompensation::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, ExposureCompensation::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {GetLabel(info), Napi::String::New(env, "string")}
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    }

    Napi::Value ExposureCompensation::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) {
            return info.Env().Null();
        }
        std::string label = info[0].As<Napi::String>().Utf8Value();
        try {
            double compensation;
            auto separatorAt = label.find(' ');
            if (separatorAt > 0) {
                compensation = std::stod(label.substr(0, separatorAt));
                label = label.substr(separatorAt + 1);
                separatorAt = label.find('/');
                if (separatorAt > 0) {
                    auto fraction = std::stod(label.substr(0, separatorAt)) /
                        std::stod(label.substr(separatorAt + 1));
                    if (compensation < 0) {
                        compensation -= fraction;
                    } else {
                        compensation += fraction;
                    }
                }
            } else {
                compensation = std::stod(label);
            }
            double matchDelta = 9999.0;
            EdsInt32 matchValue = 0;
            for (const auto &it : ExposureCompensationValues) {
                auto delta = std::abs(compensation - it.second);
                if (delta < matchDelta) {
                    matchDelta = delta;
                    matchValue = it.first;
                }
            }
            return ExposureCompensation::NewInstance(info.Env(), matchValue);
        } catch (...) {
            return info.Env().Null();
        }
    }

    Napi::Object ExposureCompensation::NewInstance(Napi::Env env, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void ExposureCompensation::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object Values = Napi::Object::New(env);
        for (const auto &it : ExposureCompensationValues) {
            Values.Set(it.first, it.second);
        }

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&ExposureCompensation::GetLabel>("label"),
            InstanceAccessor<&ExposureCompensation::GetValue>("value"),
            InstanceAccessor<&ExposureCompensation::GetCompensation>("compensation"),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &ExposureCompensation::GetPrimitive),
            InstanceMethod("toJSON", &ExposureCompensation::ToJSON),

            InstanceAccessor<&ExposureCompensation::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &ExposureCompensation::Inspect),

            StaticMethod<&ExposureCompensation::ForLabel>("forLabel"),

            StaticValue("Values", Values, napi_enumerable)
        };
        Napi::Function func = DefineClass(env, ExposureCompensation::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(ExposureCompensation::JSClassName, func);
    }
}
