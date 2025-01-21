#include "aperture.h"
#include "utility.h"
#include <map>
#include <iostream>

namespace CameraApi {

    const LabelMap &NamedApertureLabels() {
        static const LabelMap map = {
            {0x00, "Auto"},
            {0xFFFFFFFF, "NotValid"}
        };
        return map;
    }

    const std::map<int, double> &OneHalfApertureValues() {
        static const std::map<int, double> map = {
            {0x08, 1},
            {0x0B, 1.1},
            {0x0C, 1.2},
            {0x10, 1.4},
            {0x13, 1.6},
            {0x14, 1.8},
            {0x18, 2},
            {0x1B, 2.2},
            {0x1C, 2.5},
            {0x20, 2.8},
            {0x23, 3.2},
            {0x85, 3.4},
            {0x24, 3.5},
            {0x28, 4},
            {0x2B, 4.5},
            {0x2C, 4.5},
            {0x2D, 5.0},
            {0x30, 5.6},
            {0x33, 6.3},
            {0x34, 6.7},
            {0x35, 7.1},
            {0x38, 8},
            {0x3B, 9},
            {0x3C, 9.5},
            {0x3D, 10},
            {0x40, 11},
            {0x44, 13},
            {0x45, 14},
            {0x48, 16},
            {0x4B, 18},
            {0x4C, 19},
            {0x4D, 20},
            {0x50, 22},
            {0x53, 25},
            {0x54, 27},
            {0x55, 29},
            {0x58, 32},
            {0x5B, 36},
            {0x5C, 38},
            {0x5D, 40},
            {0x60, 45},
            {0x63, 51},
            {0x64, 54},
            {0x65, 57},
            {0x68, 64},
            {0x6B, 72},
            {0x6C, 76},
            {0x6D, 80},
            {0x70, 91}
        };
        return map;
    }

    const std::map<int, double> &OneThirdApertureValues() {
        static const std::map<int, double> map = {
            {0x0D, 1.2}, // (1/3),
            {0x15, 1.8}, // (1/3),
            {0x1D, 2.5}, // (1/3),
            {0x25, 3.5}, // (1/3),
            {0x43, 13}, // (1/3),
        };
        return map;
    }

    const std::map<int, double> &AllApertureValues() {
        static const std::map<int, double> map = []{
            std::map<int, double> combined = {};
            combined.insert(OneHalfApertureValues().begin(), OneHalfApertureValues().end());
            combined.insert(OneThirdApertureValues().begin(), OneThirdApertureValues().end());
            return combined;
        }();
        return map;
    }

    Aperture::Aperture(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<Aperture>(info) {

        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsNumber()) {
            value_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property value."
            );
        }

        auto oneHalfValues = OneHalfApertureValues();
        auto oneThirdValues = OneThirdApertureValues();
        if (oneHalfValues.find(value_) != oneHalfValues.end()) {
            f_ = oneHalfValues[value_];
        } else if  (oneThirdValues.find(value_) != oneThirdValues.end()) {
            f_ = oneThirdValues[value_];
            stopSize_ = ExposureStopSize::OneThird;
        } else {
            f_ = 0;
        }
    }

    std::string Aperture::GetLabelForValue(EdsInt32 value) {
        auto labels = NamedApertureLabels();
        auto oneThirdValues = OneThirdApertureValues();
        auto oneHalfValues = OneHalfApertureValues();
        if (labels.find(value) != labels.end()) {
            return labels[value];
        } else if (oneThirdValues.find(value) != oneThirdValues.end()) {
            return Aperture::GetLabelForAperture(
                oneThirdValues[value], ExposureStopSize::OneThird
            );
        } else if (oneHalfValues.find(value) != oneHalfValues.end()) {
            return Aperture::GetLabelForAperture(oneHalfValues[value]);
        }
        return "";
    }

    std::string Aperture::GetLabelForAperture(double f, ExposureStopSize stopSize) {
        std::string label;
        label = stringFormat("f%01.1f", f);
        auto labelLength = label.length();
        if (label.substr(labelLength - 2) == ".0") {
            label.erase(labelLength - 2);
        }
        if (stopSize == ExposureStopSize::OneThird) {
            label.append(" (1/3)");
        }
        return label;
    }

    Napi::Value Aperture::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), GetLabelForValue(value_));
    }

    Napi::Value Aperture::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value Aperture::GetAperture(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), f_);
    }

    Napi::Value Aperture::GetStop(const Napi::CallbackInfo &info) {
        return Napi::String::New(
            info.Env(),
            stopSize_ == ExposureStopSize::OneThird ? "1/3" : "1/2"
        );
    }

    Napi::Value Aperture::GetPrimitive(const Napi::CallbackInfo &info) {
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

    Napi::Value Aperture::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        Json.Set("aperture", GetAperture(info));
        Json.Set("stop", GetStop(info));
        return Json;
    }

    Napi::Value Aperture::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), Aperture::JSClassName);
    }

    Napi::Value Aperture::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, Aperture::JSClassName), Napi::String::New(env, "special")}
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

    EdsInt32 Aperture::ForLabel(const std::string& label) {
        try {
            double aperture;
            auto offset = label.find('f');
            auto suffixOffset = label.find(' ');
            bool isOneThird = false;
            if (offset != std::string::npos) {
                if (suffixOffset != std::string::npos) {
                    aperture = std::stod(label.substr(offset + 1, suffixOffset - offset - 1));
                    isOneThird = (
                        label.substr(suffixOffset).find("1/3") != std::string::npos
                    );
                } else {
                    aperture = std::stod(label.substr(offset + 1));
                }
            } else {
                aperture = std::stod(label);
            }
            auto values = isOneThird
                ? OneThirdApertureValues() : OneHalfApertureValues();
            for (const auto &it : values) {
                auto delta = std::abs(aperture - it.second);
                if (delta < 0.001) {
                    return it.first;
                }
            }
        } catch (...) {
        }
        throw std::runtime_error("Label does not match any value");
    }

    Napi::Value Aperture::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) {
            return info.Env().Null();
        }
        std::string label = info[0].As<Napi::String>().Utf8Value();
        for (const auto &it : NamedApertureLabels()) {
            if (it.second == label) {
                return Aperture::NewInstance(info.Env(), it.first);
            }
        }
        try {
            auto value = Aperture::ForLabel(label);
            return Aperture::NewInstance(info.Env(), value);
        } catch (...) {
            return info.Env().Null();
        }
    }

    Napi::Value Aperture::FindNearest(const Napi::CallbackInfo &info) {
        const Napi::Env &env = info.Env();
        double aperture;
        bool validArgument = false;
        auto values = AllApertureValues();
        if (info.Length() > 0) {
            try {
                if (info[0].IsString()) {
                    auto value = Aperture::ForLabel(
                        info[0].As<Napi::String>().Utf8Value()
                    );
                    aperture = values[value];
                    validArgument = true;
                } else if (info[0].IsNumber()) {
                    auto value = info[0].As<Napi::Number>().Int32Value();
                    if (values.find(value) != values.end()) {
                        aperture = values[value];
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
        double matchDelta = 9999.0;
        EdsInt32 matchValue = 0;
        for (const auto &it : AllApertureValues()) {
            auto delta = std::abs(aperture - it.second);
            if (delta < matchDelta) {
                auto allowed = (
                    ignoreFilter ||
                    filter.Call(
                        {Aperture::NewInstance(env, it.first)}
                    ).As<Napi::Boolean>().Value()
                );
                if (allowed) {
                    matchDelta = delta;
                    matchValue = it.first;
                }
            }
        }
        return matchValue > 0 ? Aperture::NewInstance(env, matchValue) : env.Null();
    }

    Napi::Object Aperture::NewInstance(Napi::Env env, EdsUInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void Aperture::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object IDs = Napi::Object::New(env);
        for (const auto &it : NamedApertureLabels()) {
            IDs.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }
        Napi::Object AllValues = Napi::Object::New(env);
        Napi::Object OneHalfValues = Napi::Object::New(env);
        for (const auto &it : OneHalfApertureValues()) {
            OneHalfValues.Set(it.first, it.second);
            AllValues.Set(it.first, it.second);
        }
        Napi::Object OneThirdValues = Napi::Object::New(env);
        for (const auto &it : OneThirdApertureValues()) {
            OneThirdValues.Set(it.first, it.second);
            AllValues.Set(it.first, it.second);
        }

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&Aperture::GetLabel>("label"),
            InstanceAccessor<&Aperture::GetValue>("value"),
            InstanceAccessor<&Aperture::GetAperture>("aperture"),
            InstanceAccessor<&Aperture::GetStop>("stop"),
            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &Aperture::GetPrimitive),
            InstanceMethod("toJSON", &Aperture::ToJSON),

            InstanceAccessor<&Aperture::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &Aperture::Inspect),

            StaticMethod<&Aperture::ForLabel>("forLabel"),
            StaticMethod<&Aperture::FindNearest>("findNearest"),

            StaticValue("ID", IDs, napi_enumerable),
            StaticValue("OneHalfValues", OneHalfValues, napi_enumerable),
            StaticValue("OneThirdValues", OneThirdValues, napi_enumerable),
            StaticValue("AllValues", AllValues, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, Aperture::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(Aperture::JSClassName, func);
    }
}
