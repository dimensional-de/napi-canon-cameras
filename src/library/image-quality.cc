#include "image-quality.h"
#include "labels.h"
#include "utility.h"

namespace CameraApi {

    ImageQuality::ImageQuality(const Napi::CallbackInfo &info) : ObjectWrap(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsNumber()) {
            value_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property value."
            );
        }

        if (Labels::ImageQuality.find(value_) != Labels::ImageQuality.end()) {
            label_ = Labels::ImageQuality[value_];
        } else {
            label_ = CodeToHexLabel(value_);
        }
    }

    Napi::Value ImageQuality::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), label_);
    }

    Napi::Value ImageQuality::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value ImageQuality::GetMain(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto quality = Napi::Object::New(env);
        quality.Set(
            "size",
            Napi::Number::New(env, ReadBitsValue(value_, 24, 8))
        );
        quality.Set(
            "format",
            Napi::Number::New(env, ReadBitsValue(value_, 20, 4))
        );
        quality.Set(
            "quality",
            Napi::Number::New(env, ReadBitsValue(value_, 16, 4))
        );
        return quality;
    }

    Napi::Value ImageQuality::GetSecondary(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto quality = Napi::Object::New(env);
        quality.Set(
            "size",
            Napi::Number::New(env, ReadBitsValue(value_, 8, 8))
        );
        quality.Set(
            "format",
            Napi::Number::New(env, ReadBitsValue(value_, 4, 4))
        );
        quality.Set(
            "quality",
            Napi::Number::New(env, ReadBitsValue(value_, 0, 4))
        );
        return quality;
    }

    Napi::Value ImageQuality::GetPrimitive(const Napi::CallbackInfo &info) {
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

    Napi::Value ImageQuality::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("value", GetValue(info));
        Json.Set("main", GetMain(info));
        Json.Set("secondary", GetSecondary(info));
        return Json;
    }

    Napi::Value ImageQuality::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), ImageQuality::JSClassName);
    }

    Napi::Value ImageQuality::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, ImageQuality::JSClassName), Napi::String::New(env, "special")}
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

    Napi::Object ImageQuality::NewInstance(Napi::Env env, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void ImageQuality::Init(Napi::Env env, Napi::Object exports) {

        Napi::HandleScope scope(env);

        Napi::Object IDs = Napi::Object::New(env);
        for (const auto &it : Labels::ImageQuality) {
            IDs.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }

        Napi::Object ImageFormats = Napi::Object::New(env);
        for (const auto &it : Labels::ImageFormat) {
            ImageFormats.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }
        Napi::Object ImageSizes = Napi::Object::New(env);
        for (const auto &it : Labels::ImageSize) {
            ImageSizes.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }
        Napi::Object ImageCompressions = Napi::Object::New(env);
        for (const auto &it : Labels::ImageCompression) {
            ImageCompressions.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }

        std::vector <PropertyDescriptor> properties = {
            InstanceAccessor<&ImageQuality::GetLabel>("label"),
            InstanceAccessor<&ImageQuality::GetValue>("value"),
            InstanceAccessor<&ImageQuality::GetMain>("main"),
            InstanceAccessor<&ImageQuality::GetSecondary>("secondary"),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &ImageQuality::GetPrimitive),
            InstanceMethod("toJSON", &ImageQuality::ToJSON),

            InstanceAccessor<&ImageQuality::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &ImageQuality::Inspect),

            StaticValue("ID", IDs, napi_enumerable),
            StaticValue("Format", ImageFormats, napi_enumerable),
            StaticValue("Size", ImageSizes, napi_enumerable),
            StaticValue("CompressionQuality", ImageCompressions, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, ImageQuality::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(ImageQuality::JSClassName, func);

    }
}
