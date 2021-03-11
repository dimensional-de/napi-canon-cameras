#include "property-option.h"
#include "camera-property.h"
#include <iostream>
#include "utility.h"
#include "labels.h"

namespace CameraApi {

    Napi::FunctionReference PropertyOption::constructor;

    PropertyOption::PropertyOption(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<PropertyOption>(info) {
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

        if (
            Labels::PropertyOption.find(propertyIdentifier_) != Labels::PropertyOption.end() &&
            Labels::PropertyOption[propertyIdentifier_].find(value_) !=
            Labels::PropertyOption[propertyIdentifier_].end()
            ) {
            isNamedValue_ = true;
            label_ = CameraProperty::GetLabelFor(propertyIdentifier_);
            label_.append(".");
            label_.append(Labels::PropertyOption[propertyIdentifier_][value_]);
        } else {
            isNamedValue_ = false;
            label_ = CodeToHexLabel(value_);
        }
    }

    Napi::Value PropertyOption::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), label_);
    }

    Napi::Value PropertyOption::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value PropertyOption::GetPropertyID(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), propertyIdentifier_);
    }

    Napi::Value PropertyOption::GetPrimitive(const Napi::CallbackInfo &info) {
        if (info.Length() > 0 && info[0].IsString()) {
            std::string hint = info[0].As<Napi::String>().Utf8Value();
            if (hint == "number") {
                return Napi::Number::New(info.Env(), value_);
            }
            if (hint == "string") {
                return Napi::String::New(info.Env(), CodeToHexLabel(value_));
            }
        }
        return info.Env().Null();
    }

    bool PropertyOption::IsOptionsProperty(EdsPropertyID propertyID) {
        return Labels::PropertyOption.find(propertyID) != Labels::PropertyOption.end();
    }

    bool PropertyOption::IsClassOf(Napi::Value value) {
        return (value.IsObject() && value.As<Napi::Object>().InstanceOf(constructor.Value()));
    }

    Napi::Value PropertyOption::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        return Json;
    }

    Napi::Value PropertyOption::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), PropertyOption::JSClassName);
    }

    Napi::Value PropertyOption::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, PropertyOption::JSClassName), Napi::String::New(env, "special")}
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

    Napi::Value PropertyOption::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) {
            return info.Env().Null();
        }
        std::string label = info[0].As<Napi::String>().Utf8Value();
        try {
            int separatorAt = label.find('.');
            std::string propertyLabel = label.substr(0, separatorAt);
            std::string optionLabel = label.substr(separatorAt + 1);
            auto propertyIt = std::find_if(
                std::begin(Labels::PropertyID),
                std::end(Labels::PropertyID),
                [propertyLabel](auto p) { return p.second.compare(propertyLabel) == 0; }
            );
            if (propertyIt == std::end(Labels::PropertyID)) {
                throw Napi::TypeError::New(
                    info.Env(), "PropertyOption::forLabel(): property not found."
                );
            }
            int propertyID = propertyIt->first;
            if (Labels::PropertyOption.find(propertyID) != Labels::PropertyOption.end()) {
                LabelMap optionLabels = Labels::PropertyOption[propertyID];
                auto optionIt = std::find_if(
                    std::begin(optionLabels),
                    std::end(optionLabels),
                    [optionLabel](auto o) { return o.second.compare(optionLabel) == 0; }
                );
                if (optionIt == std::end(Labels::PropertyID)) {
                    return info.Env().Null();
                }
                int optionID = optionIt->first;
                return PropertyOption::NewInstance(info.Env(), propertyID, optionID);
            }
            return info.Env().Null();
        } catch (...) {
            return info.Env().Null();
        }
    }

    Napi::Object PropertyOption::NewInstance(Napi::Env env, EdsInt32 identifier, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = constructor.New(
            {
                Napi::Number::New(env, identifier),
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    Napi::Object PropertyOption::CreateOptionGroup(Napi::Env env, const LabelMap &labels) {
        Napi::Object optionGroup = Napi::Object::New(env);
        for (const auto &it : labels) {
            optionGroup.DefineProperty(
                Napi::PropertyDescriptor::Value(
                    it.second.c_str(), Napi::Number::New(env, it.first), napi_enumerable
                )
            );
        }
        return optionGroup;
    }

    void PropertyOption::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&PropertyOption::GetLabel>("label"),
            InstanceAccessor<&PropertyOption::GetValue>("value"),
            InstanceAccessor<&PropertyOption::GetPropertyID>("propertyID"),
            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &PropertyOption::GetPrimitive),
            InstanceMethod("toJSON", &PropertyOption::ToJSON),

            InstanceAccessor<&PropertyOption::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &PropertyOption::Inspect),

            StaticMethod<&PropertyOption::ForLabel>("forLabel")
        };

        for (const auto &it : Labels::PropertyOption) {
            std::string name = CameraProperty::GetLabelFor(it.first);
            char *c_str = new char[name.length() + 1];
            std::strcpy(c_str, name.c_str());
            properties.push_back(
                StaticValue(
                    c_str,
                    CreateOptionGroup(env, it.second),
                    napi_enumerable
                )
            );
        }

        Napi::Function func = DefineClass(env, PropertyOption::JSClassName, properties);
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();

        exports.Set(PropertyOption::JSClassName, func);
    }
}
