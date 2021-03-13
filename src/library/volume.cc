#include "volume.h"
#include "utility.h"

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

        Napi::Function func = DefineClass(
            env,
            Volume::JSClassName,
            {
                InstanceAccessor<&Volume::GetLabel>("label"),

                InstanceAccessor<&Volume::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
                InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &Volume::Inspect),
            }
        );
        JSConstructor(&func);
    }
}
