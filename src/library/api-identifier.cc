#include "api-identifier.h"
#include "utility.h"
#include <iostream>

namespace CameraApi {

    ApiIdentifier::ApiIdentifier(const Napi::CallbackInfo &info, const std::string &name, const LabelMap &labels) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);


        if (info.Length() > 0 && info[0].IsNumber()) {
            identifier_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be an identifier."
            );
        }
        name_ = name;
        labels_ = labels;
    }

    Napi::Value ApiIdentifier::EqualTo(const Napi::CallbackInfo &info) {
        bool isEqual;
        if ((info.Length() > 0)) {
            if (info[0].IsNumber()) {
                isEqual = (identifier_ == info[0].As<Napi::Number>().Int32Value());
                return Napi::Boolean::New(info.Env(), isEqual);
            } else {
                Napi::Symbol toPrimitive = Napi::Symbol::WellKnown(info.Env(), "toPrimitive");
                if (info[0].IsObject() && info[0].As<Napi::Object>().Has(toPrimitive)) {
                    auto o = info[0].As<Napi::Object>();
                    isEqual = identifier_ == o.Get(toPrimitive).As<Napi::Function>().Call(
                        o, {Napi::String::New(info.Env(), "number")}
                    ).As<Napi::Number>().Int32Value();
                    return Napi::Boolean::New(info.Env(), isEqual);
                }
            }
        }
        throw Napi::TypeError::New(
            info.Env(), "Argument 0 must be an identifier."
        );
    }

    Napi::Value ApiIdentifier::GetIdentifier(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), identifier_);
    }

    Napi::Value ApiIdentifier::GetLabel(const Napi::CallbackInfo &info) {
        if (labels_.find(identifier_) == labels_.end()) {
            return Napi::String::New(info.Env(), CodeToHexLabel(identifier_));
        }
        return Napi::String::New(info.Env(), labels_[identifier_]);
    }

    Napi::Value ApiIdentifier::GetPrimitive(const Napi::CallbackInfo &info) {
        if (info.Length() > 0 && info[0].IsString()) {
            std::string hint = info[0].As<Napi::String>().Utf8Value();
            if (hint == "number") {
                return Napi::Number::New(info.Env(), identifier_);
            }
            if (hint == "string") {
                return Napi::String::New(info.Env(), CodeToHexLabel(identifier_));
            }
        }
        return info.Env().Null();
    }

    Napi::Value ApiIdentifier::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("identifier", GetIdentifier(info));
        Json.Set("label", GetLabel(info));
        return Json;
    }

    Napi::Value ApiIdentifier::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto isNamedIdentifier = (labels_.find(identifier_) != labels_.end());
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, name_), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {GetLabel(info), Napi::String::New(env, isNamedIdentifier ? "symbol" : "number")}
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    }

    Napi::Value ApiIdentifier::ToStringTag(const Napi::CallbackInfo &info) {
        std::string stringTag = name_;
        return Napi::String::New(info.Env(), stringTag);
    }
}
