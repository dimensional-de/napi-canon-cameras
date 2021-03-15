#ifndef NAPI_CANON_CAMERAS_DIRECTORY_H
#define NAPI_CANON_CAMERAS_DIRECTORY_H

#include "types.h"

namespace CameraApi {

    class Directory : public Napi::ObjectWrap<Directory> {
        public:
            explicit Directory(const Napi::CallbackInfo &info);

            ~Directory() override;

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsDirectoryItemRef directory);

        private:
            EdsDirectoryItemRef directoryRef_;
            EdsDirectoryItemInfo directoryInfo_;

            static constexpr const char JSClassName[] = "Directory";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value GetName(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_CAMERAS_DIRECTORY_H
