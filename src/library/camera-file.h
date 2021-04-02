#ifndef NAPI_CANON_API_CAMERA_FILE_H
#define NAPI_CANON_API_CAMERA_FILE_H

#include "types.h"
#include <EDSDKTypes.h>

namespace CameraApi {


    class CameraFile : public Napi::ObjectWrap<CameraFile> {
        public:

            explicit CameraFile(const Napi::CallbackInfo &info);

            ~CameraFile() override;

            static Napi::Object NewInstance(Napi::Env env, EdsDirectoryItemRef directoryItem);

            static void Init(Napi::Env env, Napi::Object exports);

        private:
            static constexpr const char JSClassName[] = "CameraFile";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsDirectoryItemRef edsDirectoryItem_;
            EdsDirectoryItemInfo edsDirectoryItemInfo_;

            bool isDownloaded_ = false;
            bool isCanceled_ = false;
            std::string localFile_;

            Napi::Value GetGroupID(const Napi::CallbackInfo &info);

            Napi::Value GetName(const Napi::CallbackInfo &info);

            Napi::Value GetSize(const Napi::CallbackInfo &info);

            Napi::Value GetLocalFile(const Napi::CallbackInfo &info);

            Napi::Value GetFormat(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            Napi::Value Cancel(const Napi::CallbackInfo &info);

            Napi::Value DownloadToFile(const Napi::CallbackInfo &info);

            Napi::Value DownloadToPath(const Napi::CallbackInfo &info);

            Napi::Value DownloadToString(const Napi::CallbackInfo &info);

            Napi::Value DownloadThumbnailToString(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_API_CAMERA_FILE_H
