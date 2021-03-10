#include "camera-file.h"
#include "api-error.h"
#include <filesystem>
#include "base64.h"
#include "utility.h"

namespace fs =  std::filesystem;

namespace CameraApi {
    Napi::FunctionReference CameraFileWrap::constructor;

    CameraFileWrap::CameraFileWrap(const Napi::CallbackInfo &info) : Napi::ObjectWrap<CameraFileWrap>(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);


        if (!(info.Length() > 0 && info[0].IsExternal())) {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a directory item."
            );
        }

        auto external = info[0].As < Napi::External < EdsDirectoryItemRef >> ();
        edsDirectoryItem_ = *external.Data();
        EdsRetain(edsDirectoryItem_);

        EdsError error = EdsGetDirectoryItemInfo(edsDirectoryItem_, &edsDirectoryItemInfo_);
        if (error != EDS_ERR_OK) {
            throw Napi::Error::New(
                info.Env(), "Failed to get directory item info."
            );
        }
    }

    CameraFileWrap::~CameraFileWrap() {
        if (!(isDownloaded_ || isCanceled_)) {
            EdsDownloadCancel(edsDirectoryItem_);
        }
        EdsRelease(edsDirectoryItem_);
        edsDirectoryItem_ = NULL;
    }

    Napi::Value CameraFileWrap::Cancel(const Napi::CallbackInfo &info) {
        if (!isCanceled_) {
            return ApiError::ThrowIfFailed(info.Env(), EdsDownloadCancel(edsDirectoryItem_));
            isCanceled_ = true;
        }
        return info.Env().Undefined();
    }

    Napi::Value CameraFileWrap::GetName(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), edsDirectoryItemInfo_.szFileName);
    }

    Napi::Value CameraFileWrap::GetGroupID(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), edsDirectoryItemInfo_.groupID);
    }

    Napi::Value CameraFileWrap::GetSize(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), edsDirectoryItemInfo_.size);
    }

    Napi::Value CameraFileWrap::GetLocalFile(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), localFile_);
    }

    Napi::Value CameraFileWrap::GetFormat(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), edsDirectoryItemInfo_.format);
    }

    Napi::Value CameraFileWrap::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), CameraFileWrap::JSClassName);
    }

    Napi::Value CameraFileWrap::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, CameraFileWrap::JSClassName), Napi::String::New(env, "special")}
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

    Napi::Value CameraFileWrap::DownloadToPath(const Napi::CallbackInfo &info) {
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

    Napi::Value CameraFileWrap::DownloadToFile(const Napi::CallbackInfo &info) {
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

    Napi::Value CameraFileWrap::DownloadToString(const Napi::CallbackInfo &info) {
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
        unsigned char* imageData;

        EdsGetLength( stream, &imageDataLength );
        if( imageDataLength <= 0 ) {
            throw Napi::Error::New(
                info.Env(), "No image data."
            );
        }

        EdsGetPointer( stream, (EdsVoid**)&imageData );

        char* imageString = base64(imageData, imageDataLength, &imageStringLength);
        Napi::String result = Napi::String::New(info.Env(), imageString, imageStringLength);
        free(imageString);
        if(stream != nullptr) {
            EdsRelease(stream);
            stream = nullptr;
        }
        return result;
    }

    Napi::Object CameraFileWrap::NewInstance(Napi::Env env, EdsDirectoryItemRef directoryItem) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = constructor.New({Napi::External<EdsDirectoryItemRef>::New(env, &directoryItem)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void CameraFileWrap::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Function func = DefineClass(
            env,
            CameraFileWrap::JSClassName,
            {
                InstanceAccessor<&CameraFileWrap::GetName>("name"),
                InstanceAccessor<&CameraFileWrap::GetSize>("size"),
                InstanceAccessor<&CameraFileWrap::GetLocalFile>("localFile"),
                InstanceAccessor<&CameraFileWrap::GetFormat>("format"),
                InstanceAccessor<&CameraFileWrap::GetGroupID>("groupID"),

                InstanceAccessor<&CameraFileWrap::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
                InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &CameraFileWrap::Inspect),

                InstanceMethod("cancel", &CameraFileWrap::Cancel),
                InstanceMethod("downloadToPath", &CameraFileWrap::DownloadToPath),
                InstanceMethod("downloadToFile", &CameraFileWrap::DownloadToFile),
                InstanceMethod("downloadToString", &CameraFileWrap::DownloadToString)
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
    }
}
