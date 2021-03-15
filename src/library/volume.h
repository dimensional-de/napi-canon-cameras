#ifndef NAPI_CANON_CAMERAS_VOLUME_H
#define NAPI_CANON_CAMERAS_VOLUME_H

#include "types.h"

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

            Napi::Value GetStorageType(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value IsReadable(const Napi::CallbackInfo &info);

            Napi::Value IsWritable(const Napi::CallbackInfo &info);

            Napi::Value GetMaximumCapacity(const Napi::CallbackInfo &info);

            Napi::Value GetFreeCapacity(const Napi::CallbackInfo &info);

            Napi::Value GetLength(const Napi::CallbackInfo &info);

            Napi::Value GetEntries(const Napi::CallbackInfo &info);
    };

}

#endif //NAPI_CANON_CAMERAS_VOLUME_H
