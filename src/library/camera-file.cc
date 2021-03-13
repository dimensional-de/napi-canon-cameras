#include "camera-file.h"
#include "api-error.h"
#include <filesystem>
#include "base64.h"
#include "utility.h"

namespace fs = std::filesystem;

namespace CameraApi {

    CameraFile::CameraFile(const Napi::CallbackInfo &info) : Napi::ObjectWrap<CameraFile>(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);


        if (!(info.Length() > 0 && info[0].IsExternal())) {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a directory item."
            );
        }

        auto external = info[0].As<Napi::External<EdsDirectoryItemRef >>();
        edsDirectoryItem_ = *external.Data();
        EdsRetain(edsDirectoryItem_);

        EdsError error = EdsGetDirectoryItemInfo(edsDirectoryItem_, &edsDirectoryItemInfo_);
        if (error != EDS_ERR_OK) {
            throw Napi::Error::New(
                info.Env(), "Failed to get directory item info."
            );
        }
    }

    CameraFile::~CameraFile() {
        if (!(isDownloaded_ || isCanceled_)) {
            EdsDownloadCancel(edsDirectoryItem_);
        }
        EdsRelease(edsDirectoryItem_);
        edsDirectoryItem_ = NULL;
    }

    Napi::Value CameraFile::Cancel(const Napi::CallbackInfo &info) {
        if (!isCanceled_) {
            return ApiError::ThrowIfFailed(info.Env(), EdsDownloadCancel(edsDirectoryItem_));
            isCanceled_ = true;
        }
        return info.Env().Undefined();
    }

    Napi::Value CameraFile::GetName(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), edsDirectoryItemInfo_.szFileName);
    }

    Napi::Value CameraFile::GetGroupID(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), edsDirectoryItemInfo_.groupID);
    }

    Napi::Value CameraFile::GetSize(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), (int)edsDirectoryItemInfo_.size);
    }

    Napi::Value CameraFile::GetLocalFile(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), localFile_);
    }

    Napi::Value CameraFile::GetFormat(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), edsDirectoryItemInfo_.format);
    }

    Napi::Value CameraFile::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), CameraFile::JSClassName);
    }

    Napi::Value CameraFile::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, CameraFile::JSClassName), Napi::String::New(env, "special")}
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

    Napi::Value CameraFile::DownloadToPath(const Napi::CallbackInfo &info) {
        if (isDownloaded_) {
            return Napi::String::New(info.Env(), localFile_);
        }
        if (info.Length() > 0 && info[0].IsString()) {
            fs::path destinationPath(info[0].As<Napi::String>().Utf8Value());
            if (destinationPath.compare("") == 0) {
                throw Napi::TypeError::New(
                    info.Env(), "Empty file path."
                );
            }
            if (!fs::exists(destinationPath)) {
                bool status = fs::create_directories(destinationPath);
                if (!status) {
                    throw Napi::TypeError::New(
                        info.Env(), "Can not create file path."
                    );
                }
            }
            fs::path targetFile(destinationPath / edsDirectoryItemInfo_.szFileName);
            EdsStreamRef stream = nullptr;
            EdsError error = EdsCreateFileStream(
                targetFile.generic_string().c_str(),
                kEdsFileCreateDisposition_CreateAlways,
                kEdsAccess_ReadWrite,
                &stream
            );
            if (error != EDS_ERR_OK) {
                throw Napi::TypeError::New(
                    info.Env(), "Can not create file stream."
                );
            }
            error = EdsDownload(edsDirectoryItem_, edsDirectoryItemInfo_.size, stream);
            if (error != EDS_ERR_OK) {
                throw Napi::TypeError::New(
                    info.Env(), "Download failed."
                );
            }
            error = EdsDownloadComplete(edsDirectoryItem_);
            if (error != EDS_ERR_OK) {
                throw Napi::TypeError::New(
                    info.Env(), "Download could not be completed."
                );
            }
            isDownloaded_ = true;
            localFile_ = targetFile.generic_string();
            if (stream) {
                EdsRelease(stream);
            }
            return Napi::String::New(info.Env(), localFile_);
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Missing file path."
            );
        }
    }

    Napi::Value CameraFile::DownloadToFile(const Napi::CallbackInfo &info) {
        if (isDownloaded_) {
            return Napi::String::New(info.Env(), localFile_);
        }
        if (info.Length() > 0 && info[0].IsString()) {
            fs::path targetFile(info[0].As<Napi::String>().Utf8Value());
            if (targetFile.compare("") == 0) {
                throw Napi::TypeError::New(
                    info.Env(), "Empty file name."
                );
            }
            fs::path targetPath = targetFile.parent_path();
            if (!fs::exists(targetPath)) {
                bool status = fs::create_directories(targetPath);
                if (!status) {
                    throw Napi::Error::New(
                        info.Env(), "Can not create file path."
                    );
                }
            }
            EdsStreamRef stream = nullptr;
            EdsError error = EdsCreateFileStream(
                targetFile.generic_string().c_str(),
                kEdsFileCreateDisposition_CreateAlways,
                kEdsAccess_ReadWrite,
                &stream
            );
            if (error != EDS_ERR_OK) {
                throw Napi::Error::New(
                    info.Env(), "Can not create file stream."
                );
            }
            error = EdsDownload(edsDirectoryItem_, edsDirectoryItemInfo_.size, stream);
            if (error != EDS_ERR_OK) {
                throw Napi::Error::New(
                    info.Env(), "Download failed."
                );
            }
            error = EdsDownloadComplete(edsDirectoryItem_);
            if (error != EDS_ERR_OK) {
                throw Napi::Error::New(
                    info.Env(), "Download could not be completed."
                );
            }
            isDownloaded_ = true;
            localFile_ = targetFile.generic_string();
            if (stream) {
                EdsRelease(stream);
            }
            return Napi::String::New(info.Env(), localFile_);
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Missing file name."
            );
        }
    }

    Napi::Value CameraFile::DownloadToString(const Napi::CallbackInfo &info) {
        if (isDownloaded_) {
            return Napi::String::New(info.Env(), localFile_);
        }
        EdsError error = EDS_ERR_OK;
        EdsStreamRef stream = nullptr;

        error = EdsCreateMemoryStream(0, &stream);
        if (error != EDS_ERR_OK) {
            throw Napi::Error::New(
                info.Env(), "Can not create memory stream."
            );
        }
        error = EdsDownload(edsDirectoryItem_, edsDirectoryItemInfo_.size, stream);
        if (error != EDS_ERR_OK) {
            throw Napi::Error::New(
                info.Env(), "Download failed."
            );
        }
        error = EdsDownloadComplete(edsDirectoryItem_);
        if (error != EDS_ERR_OK) {
            throw Napi::Error::New(
                info.Env(), "Download could not be completed."
            );
        }
        isDownloaded_ = true;

        EdsUInt64 imageDataLength;
        int imageStringLength;
        unsigned char *imageData;

        EdsGetLength(stream, &imageDataLength);
        if (imageDataLength <= 0) {
            throw Napi::Error::New(
                info.Env(), "No image data."
            );
        }

        EdsGetPointer(stream, (EdsVoid **) &imageData);

        char *imageString = base64(imageData, (int)imageDataLength, &imageStringLength);
        Napi::String result = Napi::String::New(info.Env(), imageString, imageStringLength);
        free(imageString);
        if (stream != nullptr) {
            EdsRelease(stream);
            stream = nullptr;
        }
        return result;
    }

    Napi::Object CameraFile::NewInstance(Napi::Env env, EdsDirectoryItemRef directoryItem) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New({Napi::External<EdsDirectoryItemRef>::New(env, &directoryItem)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void CameraFile::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Function func = DefineClass(
            env,
            CameraFile::JSClassName,
            {
                InstanceAccessor<&CameraFile::GetName>("name"),
                InstanceAccessor<&CameraFile::GetSize>("size"),
                InstanceAccessor<&CameraFile::GetLocalFile>("localFile"),
                InstanceAccessor<&CameraFile::GetFormat>("format"),
                InstanceAccessor<&CameraFile::GetGroupID>("groupID"),

                InstanceAccessor<&CameraFile::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
                InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &CameraFile::Inspect),

                InstanceMethod("cancel", &CameraFile::Cancel),
                InstanceMethod("downloadToPath", &CameraFile::DownloadToPath),
                InstanceMethod("downloadToFile", &CameraFile::DownloadToFile),
                InstanceMethod("downloadToString", &CameraFile::DownloadToString)
            }
        );
        JSConstructor(&func);
    }
}
