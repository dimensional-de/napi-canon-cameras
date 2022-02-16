#include "file-format.h"
#include "utility.h"

namespace CameraApi {


    LabelMap FileFormatLabels = {
        {kEdsObjectFormat_Unknown, "Unknown"},
        {kEdsObjectFormat_Jpeg, "JPEG"},
        {kEdsObjectFormat_CR2, "CR2"},
        {kEdsObjectFormat_CR3, "CR3"},
        {kEdsObjectFormat_MP4, "MP4"},
        {kEdsObjectFormat_HEIF_CODE, "HEIF_CODE"}
    };

    FileFormat::FileFormat(const Napi::CallbackInfo &info) : ObjectWrap(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsNumber()) {
            value_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property value."
            );
        }
    }

    Napi::Value FileFormat::GetLabel(const Napi::CallbackInfo &info) {
        std::string label;
        if (FileFormatLabels.find(value_) != FileFormatLabels.end()) {
            label.append(FileFormatLabels[value_]);
        } else {
            label.append(CodeToHexLabel(value_));
        }
        return Napi::String::New(info.Env(), label);
    }

    Napi::Value FileFormat::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value FileFormat::GetPrimitive(const Napi::CallbackInfo &info) {
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

    Napi::Value FileFormat::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        return Json;
    }

    Napi::Value FileFormat::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), FileFormat::JSClassName);
    }

    Napi::Value FileFormat::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, FileFormat::JSClassName), Napi::String::New(env, "special")}
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

    Napi::Object FileFormat::NewInstance(Napi::Env env, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void FileFormat::Init(Napi::Env env, Napi::Object exports) {

        Napi::HandleScope scope(env);

        Napi::Object FileTypes = Napi::Object::New(env);
        for (const auto &it : FileFormatLabels) {
            FileTypes.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&FileFormat::GetLabel>("label"),
            InstanceAccessor<&FileFormat::GetValue>("value"),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &FileFormat::GetPrimitive),
            InstanceMethod("toJSON", &FileFormat::ToJSON),

            InstanceAccessor<&FileFormat::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &FileFormat::Inspect),

            StaticValue("ID", FileTypes, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, FileFormat::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(FileFormat::JSClassName, func);

    }
}

