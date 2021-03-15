#include "api-error.h"
#include "utility.h"
#include "volume.h"
#include "labels.h"
#include "directory.h"
#include "camera-file.h"

namespace CameraApi {

    Volume::Volume(const Napi::CallbackInfo &info) : ObjectWrap(info) {

        if (!(info.Length() > 0 && info[0].IsExternal())) {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a volume reference."
            );
        }

        auto external = info[0].As<Napi::External<EdsDirectoryItemRef >>();
        volumeRef_ = *external.Data();
        EdsRetain(volumeRef_);

        EdsError error = EdsGetVolumeInfo(volumeRef_, &volumeInfo_);
        if (error != EDS_ERR_OK) {
            throw Napi::Error::New(
                info.Env(), "Failed to get directory item info."
            );
        }
    }

    Volume::~Volume() {
        EdsRelease(volumeRef_);
    }

    Napi::Value Volume::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), volumeInfo_.szVolumeLabel);
    }

    Napi::Value Volume::GetStorageType(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), volumeInfo_.storageType);
    }

    Napi::Value Volume::IsReadable(const Napi::CallbackInfo &info) {
        return Napi::Boolean::New(
            info.Env(), (volumeInfo_.access == 0) || (volumeInfo_.access == 2)
        );
    }

    Napi::Value Volume::IsWritable(const Napi::CallbackInfo &info) {
        return Napi::Boolean::New(
            info.Env(), (volumeInfo_.access == 1) || (volumeInfo_.access == 2)
        );
    }

    Napi::Value Volume::GetMaximumCapacity(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), (int) volumeInfo_.maxCapacity);
    }

    Napi::Value Volume::GetFreeCapacity(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), (int) volumeInfo_.freeSpaceInBytes);
    }

    Napi::Value Volume::GetLength(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        EdsError error;
        EdsUInt32 count = 0;
        error = EdsGetChildCount(volumeRef_, &count);
        ApiError::ThrowIfFailed(env, error);
        return Napi::Number::New(env, count);
    }

    Napi::Value Volume::GetEntries(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto entries = Napi::Array::New(env);
        EdsError error;
        EdsUInt32 count = 0;
        error = EdsGetChildCount(volumeRef_, &count);
        ApiError::ThrowIfFailed(env, error);
        for (EdsUInt32 idx = 0; idx < count; idx++) {
            EdsDirectoryItemRef entryRef;
            error = EdsGetChildAtIndex(volumeRef_, idx, &entryRef);
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

    Napi::Value Volume::ToJSON(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto json = Napi::Object::New(env);
        json.Set("label", GetLabel(info));
        json.Set("length", GetLength(info));
        json.Set("storageType", GetStorageType(info));
        json.Set("isReadable", IsReadable(info));
        json.Set("isWritable", IsReadable(info));
        json.Set("maximumCapacity", GetMaximumCapacity(info));
        json.Set("freeCapacity", GetFreeCapacity(info));
        return json;
    }

    Napi::Value Volume::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), Volume::JSClassName);
    }

    Napi::Value Volume::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, Volume::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {GetLabel(info), Napi::String::New(env, "string")}
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    };

    Napi::Object Volume::NewInstance(Napi::Env env, EdsVolumeRef volume) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {Napi::External<EdsVolumeRef>::New(env, &volume)}
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void Volume::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object StorageTypes = Napi::Object::New(env);
        for (const auto &it : Labels::StorageType) {
            StorageTypes.DefineProperty(
                Napi::PropertyDescriptor::Value(
                    it.second.c_str(), Napi::Number::New(env, it.first), napi_enumerable
                )
            );
        }

        Napi::Function func = DefineClass(
            env,
            Volume::JSClassName,
            {
                InstanceAccessor<&Volume::GetLabel>("label"),
                InstanceAccessor<&Volume::GetLength>("length"),
                InstanceAccessor<&Volume::GetStorageType>("storageType"),
                InstanceAccessor<&Volume::IsReadable>("isReadable"),
                InstanceAccessor<&Volume::IsWritable>("isWritable"),
                InstanceAccessor<&Volume::GetMaximumCapacity>("maximumCapacity"),
                InstanceAccessor<&Volume::GetFreeCapacity>("freeCapacity"),

                InstanceMethod(Napi::Symbol::WellKnown(env, "iterator"), &Volume::GetEntries),
                InstanceMethod("getEntries", &Volume::GetEntries),

                InstanceMethod("toJSON", &Volume::ToJSON),

                InstanceAccessor<&Volume::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
                InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &Volume::Inspect),

                StaticValue("StorageType", StorageTypes, napi_enumerable)
            }
        );
        JSConstructor(&func);

        exports.Set(Volume::JSClassName, func);
    }
}
