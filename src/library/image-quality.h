#ifndef NAPI_CANON_CAMERAS_IMAGE_QUALITY_H
#define NAPI_CANON_CAMERAS_IMAGE_QUALITY_H

#include "types.h"

namespace CameraApi {

    class ImageQuality : public Napi::ObjectWrap<ImageQuality> {
        public:
            explicit ImageQuality(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 value);

        private:
            static constexpr const char JSClassName[] = "ImageQuality";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsInt32 value_ = 0;
            std::string label_;

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value GetMain(const Napi::CallbackInfo &info);

            Napi::Value GetSecondary(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_CAMERAS_IMAGE_QUALITY_H
