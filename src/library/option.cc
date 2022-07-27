#include "option.h"
#include "camera-property.h"
#include <iostream>
#include "utility.h"
#include "labels.h"

namespace CameraApi {

    Option::Option(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<Option>(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsNumber()) {
            propertyIdentifier_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property identifier."
            );
        }
        if (info.Length() > 1 && info[1].IsNumber()) {
            value_ = info[1].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property option value."
            );
        }

        auto labels = Labels::Option();
        if (
            labels.find(propertyIdentifier_) != labels.end() &&
                labels[propertyIdentifier_].find(value_) !=
                    labels[propertyIdentifier_].end()
            ) {
            isNamedValue_ = true;
            label_ = CameraProperty::GetLabelFor(propertyIdentifier_);
            label_.append(".");
            label_.append(labels[propertyIdentifier_][value_]);
        } else {
            isNamedValue_ = false;
            label_ = CodeToHexLabel(value_);
        }
    }

    Napi::Value Option::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), label_);
    }

    Napi::Value Option::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value Option::GetPropertyID(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), propertyIdentifier_);
    }

    Napi::Value Option::GetPrimitive(const Napi::CallbackInfo &info) {
        if (info.Length() > 0 && info[0].IsString()) {
            std::string hint = info[0].As<Napi::String>().Utf8Value();
            if (hint == "number") {
                return Napi::Number::New(info.Env(), value_);
            }
            if (hint == "string") {
                return GetLabel(info);
            }
        }
        return info.Env().Null();
    }

    bool Option::IsOptionsProperty(EdsPropertyID propertyID) {
        auto labels = Labels::Option();
        return labels.find(propertyID) != labels.end();
    }

    bool Option::IsClassOf(Napi::Value value) {
        return (
            value.IsObject() &&
            value.As<Napi::Object>().InstanceOf(JSConstructor())
        );
    }

    Napi::Value Option::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        return Json;
    }

    Napi::Value Option::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), Option::JSClassName);
    }

    Napi::Value Option::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, Option::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {GetLabel(info), Napi::String::New(env, isNamedValue_ ? "symbol" : "string")}
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    }

    Napi::Value Option::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) {
            return info.Env().Null();
        }
        std::string label = info[0].As<Napi::String>().Utf8Value();
        try {
            auto separatorAt = label.find('.');
            auto propertyLabel = label.substr(0, separatorAt);
            auto optionLabel = label.substr(separatorAt + 1);
            auto propertyLabels = Labels::PropertyID();
            auto propertyIt = std::find_if(
                std::begin(propertyLabels),
                std::end(propertyLabels),
                [propertyLabel](auto p) { return p.second.compare(propertyLabel) == 0; }
            );
            if (propertyIt == std::end(propertyLabels)) {
                throw Napi::TypeError::New(
                    info.Env(), "Option::forLabel(): property not found."
                );
            }
            int propertyID = propertyIt->first;
            auto optionLabelGroups = Labels::Option();
            if (optionLabelGroups.find(propertyID) != optionLabelGroups.end()) {
                auto optionLabels = optionLabelGroups[propertyID];
                auto optionIt = std::find_if(
                    std::begin(optionLabels),
                    std::end(optionLabels),
                    [optionLabel](auto o) { return o.second.compare(optionLabel) == 0; }
                );
                if (optionIt == std::end(propertyLabels)) {
                    return info.Env().Null();
                }
                return Option::NewInstance(info.Env(), propertyID, optionIt->first);
            }
            return info.Env().Null();
        } catch (...) {
            return info.Env().Null();
        }
    }

    Napi::Object Option::NewInstance(Napi::Env env, EdsInt32 identifier, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, identifier),
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    Napi::Object Option::CreateOptionGroup(Napi::Env env, const LabelMap &labels) {
        Napi::Object optionGroup = Napi::Object::New(env);
        for (const auto &it : labels) {
            optionGroup.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }
        return optionGroup;
    }

    Napi::Object Option::CreateOptionGroup(Napi::Env env, EdsPropertyID propertyID) {
        auto optionLabelGroups = Labels::Option();
        return CreateOptionGroup(env, optionLabelGroups[propertyID]);
    }

    void Option::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&Option::GetLabel>("label"),
            InstanceAccessor<&Option::GetValue>("value"),
            InstanceAccessor<&Option::GetPropertyID>("propertyID"),
            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &Option::GetPrimitive),
            InstanceMethod("toJSON", &Option::ToJSON),

            InstanceAccessor<&Option::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &Option::Inspect),

            StaticMethod<&Option::ForLabel>("forLabel"),

            StaticValue("AEMode", CreateOptionGroup(env, kEdsPropID_AEMode), napi_enumerable),
            StaticValue("AEModeSelect", CreateOptionGroup(env, kEdsPropID_AEModeSelect), napi_enumerable),
            StaticValue("AFMode", CreateOptionGroup(env, kEdsPropID_AFMode), napi_enumerable),
            StaticValue("BatteryQuality", CreateOptionGroup(env, kEdsPropID_BatteryQuality), napi_enumerable),
            StaticValue("Bracket", CreateOptionGroup(env, kEdsPropID_Bracket), napi_enumerable),
            StaticValue("ColorSpace", CreateOptionGroup(env, kEdsPropID_ColorSpace), napi_enumerable),
            StaticValue("DCStrobe", CreateOptionGroup(env, kEdsPropID_DC_Strobe), napi_enumerable),
            StaticValue("DriveMode", CreateOptionGroup(env, kEdsPropID_DriveMode), napi_enumerable),
            StaticValue("EvfAFMode", CreateOptionGroup(env, kEdsPropID_Evf_AFMode), napi_enumerable),
            StaticValue("EvfHistogramStatus", CreateOptionGroup(env, kEdsPropID_Evf_HistogramStatus), napi_enumerable),
            StaticValue("EvfOutputDevice", CreateOptionGroup(env, kEdsPropID_Evf_OutputDevice), napi_enumerable),
            StaticValue("EvfZoom", CreateOptionGroup(env, kEdsPropID_Evf_Zoom), napi_enumerable),
            StaticValue("LensBarrelStatus", CreateOptionGroup(env, kEdsPropID_LensBarrelStatus), napi_enumerable),
            StaticValue("LensStatus", CreateOptionGroup(env, kEdsPropID_LensStatus), napi_enumerable),
            StaticValue("MeteringMode", CreateOptionGroup(env, kEdsPropID_MeteringMode), napi_enumerable),
            StaticValue("MirrorUpStatus", CreateOptionGroup(env, kEdsPropID_MirrorLockUpState), napi_enumerable),
            StaticValue("MovieQuality", CreateOptionGroup(env, kEdsPropID_MovieParam), napi_enumerable),
            StaticValue("NoiseReduction", CreateOptionGroup(env, kEdsPropID_NoiseReduction), napi_enumerable),
            StaticValue("RedEye", CreateOptionGroup(env, kEdsPropID_RedEye), napi_enumerable),
            StaticValue("Record", CreateOptionGroup(env, kEdsPropID_Record), napi_enumerable),
            StaticValue("SaveTo", CreateOptionGroup(env, kEdsPropID_SaveTo), napi_enumerable),
            StaticValue("WhiteBalance", CreateOptionGroup(env, kEdsPropID_WhiteBalance), napi_enumerable)
        };

        Napi::Function func = DefineClass(env, Option::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(Option::JSClassName, func);
    }
}
