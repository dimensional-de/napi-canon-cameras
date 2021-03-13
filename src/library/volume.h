#ifndef NAPI_CANON_CAMERAS_VOLUME_H
#define NAPI_CANON_CAMERAS_VOLUME_H

#include <napi.h>
#include <EDSDK.h>

namespace CameraApi {

    class Volume : public Napi::ObjectWrap<Volume> {
        public:
            explicit Volume(const Napi::CallbackInfo &info);

            ~Volume() override;

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsVolumeRef volume);

        private:
            EdsVolumeRef volumeRef_;
            EdsVolumeInfo volumeInfo_;

            static constexpr const char JSClassName[] = "Volume";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);
    };

}

#endif //NAPI_CANON_CAMERAS_VOLUME_H
