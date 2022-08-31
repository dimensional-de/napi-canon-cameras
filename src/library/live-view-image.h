#ifndef NAPI_CANON_CAMERAS_LIVE_VIEW_IMAGE_H
#define NAPI_CANON_CAMERAS_LIVE_VIEW_IMAGE_H

#include "types.h"

namespace CameraApi {

    class LiveViewImage : public Napi::ObjectWrap<LiveViewImage> {
        public:

            explicit LiveViewImage(const Napi::CallbackInfo &info);

            ~LiveViewImage() override;

            static Napi::Object NewInstance(Napi::Env env, EdsCameraRef edsCameraRef);

            static void Init(Napi::Env env, Napi::Object exports);

        private:
            static constexpr const char JSClassName[] = "LiveViewImage";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsEvfImageRef imageRef_ = nullptr;
            EdsStreamRef streamRef_ = nullptr;

            EdsError fetch(EdsCameraRef edsCameraRef);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value GetDataURL(const Napi::CallbackInfo &info);

            Napi::Value GetCoordinateSystem(const Napi::CallbackInfo &info);

            Napi::Value GetHistogram(const Napi::CallbackInfo &info);

            Napi::Value GetHistogramStatus(const Napi::CallbackInfo &info);

            Napi::Value GetPosition(const Napi::CallbackInfo &info);

            Napi::Value GetVisibleArea(const Napi::CallbackInfo &info);

            Napi::Value GetZoom(const Napi::CallbackInfo &info);

            Napi::Value GetZoomArea(const Napi::CallbackInfo &info);

            Napi::Value GetZoomPosition(const Napi::CallbackInfo &info);

    };

} // CameraApi

#endif //NAPI_CANON_CAMERAS_LIVE_VIEW_IMAGE_H
