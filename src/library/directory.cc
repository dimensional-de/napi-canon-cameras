#include "directory.h"
#include "utility.h"
#include "api-error.h"
#include "camera-file.h"

namespace CameraApi {

    Directory::Directory(const Napi::CallbackInfo &info) : ObjectWrap(info) {

        if (!(info.Length() > 0 && info[0].IsExternal())) {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a directory reference."
            );
        }

        auto external = info[0].As<Napi::External<EdsDirectoryItemRef >>();
        directoryRef_ = *external.Data();
        EdsRetain(directoryRef_);

        EdsError error = EdsGetDirectoryItemInfo(directoryRef_, &directoryInfo_);
        if (error != EDS_ERR_OK) {
            throw Napi::Error::New(
                info.Env(), "Failed to get directory item info."
            );
        }
        if (!directoryInfo_.isFolder) {
            throw Napi::Error::New(
                info.Env(), "Reference is not a directory."
            );
        }
    }

    Directory::~Directory() {
        EdsRelease(directoryRef_);
    }

    Napi::Value Directory::GetName(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), directoryInfo_.szFileName);
    }

    Napi::Value Directory::GetLength(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        EdsError error;
        EdsUInt32 count = 0;
        error = EdsGetChildCount(directoryRef_, &count);
        ApiError::ThrowIfFailed(env, error);
        return Napi::Number::New(env, count);
    }

    Napi::Value Directory::GetEntries(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto entries = Napi::Array::New(env);
        EdsError error;
        EdsUInt32 count = 0;
        error = EdsGetChildCount(directoryRef_, &count);
        ApiError::ThrowIfFailed(env, error);
        for (EdsUInt32 idx = 0; idx < count; idx++) {
            EdsDirectoryItemRef entryRef;
            error = EdsGetChildAtIndex(directoryRef_, idx, &entryRef);
            ApiError::ThrowIfFailed(env, error);

            EdsDirectoryItemInfo entryInfo;
            error = EdsGetDirectoryItemInfo(entryRef, &entryInfo);
            if (error != EDS_ERR_OK) {
                EdsRelease(entryRef);
                ApiError::Throw(env, error);
            }
            entries.Set(
                idx,
                entryInfo.isFolder
                ? Directory::NewInstance(env, entryRef)
                : CameraFile::NewInstance(env, entryRef)
            );
            EdsRelease(entryRef);
        }
        return entries;
    }

    Napi::Value Directory::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), Directory::JSClassName);
    }

    Napi::Value Directory::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, Directory::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {GetName(info), Napi::String::New(env, "string")}
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    };

    Napi::Object Directory::NewInstance(Napi::Env env, EdsDirectoryItemRef directory) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {Napi::External<EdsDirectoryItemRef>::New(env, &directory)}
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void Directory::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Function func = DefineClass(
            env,
            Directory::JSClassName,
            {
                InstanceAccessor<&Directory::GetName>("name"),
                InstanceAccessor<&Directory::GetLength>("length"),

                InstanceMethod(Napi::Symbol::WellKnown(env, "iterator"), &Directory::GetEntries),
                InstanceMethod("getEntries", &Directory::GetEntries),

                //InstanceMethod("toJSON", &Directory::ToJSON),

                InstanceAccessor<&Directory::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
                InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &Directory::Inspect)
            }
        );
        JSConstructor(&func);

        exports.Set(Directory::JSClassName, func);
    }
}
