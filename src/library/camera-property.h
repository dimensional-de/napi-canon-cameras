#ifndef NAPI_CANON_API_PROPERTY_H
#define NAPI_CANON_API_PROPERTY_H

#include "types.h"
#include "camera.h"

namespace CameraApi {

    class CameraProperty : public Napi::ObjectWrap<CameraProperty> {
        public:
            CameraProperty(const Napi::CallbackInfo &info);

            ~CameraProperty();

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(
                Napi::Env env, CameraReference camera, EdsPropertyID identifier, EdsInt32 specifier
            );

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetIdentifier(const Napi::CallbackInfo &info);

            Napi::Value GetSpecifier(const Napi::CallbackInfo &info);

            Napi::Value IsAvailable(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetAllowedValues(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            void SetValue(const Napi::CallbackInfo &info, const Napi::Value &propertyValue);

            void SetValue(const Napi::CallbackInfo &info);

            static std::string GetLabelFor(EdsPropertyID propertyID);

        private:
            static Napi::FunctionReference constructor;
            static constexpr const char JSClassName[] = "CameraProperty";

            EdsCameraRef edsCamera_ = 0;
            EdsPropertyID propertyIdentifier_ = 0;
            EdsPropertyID propertySpecifier_ = 0;

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            bool isLookUpProperty();

            bool isAllowedPropertyValue(int propertyValue);

            Napi::Object ReadTimeValue(const Napi::CallbackInfo &info, EdsUInt32 dataSize);

            Napi::Object ReadInt32ArrayValue(const Napi::CallbackInfo &info, EdsUInt32 dataSize, EdsUInt32 itemSize);

            Napi::Object ReadPictureStyleDescription(const Napi::CallbackInfo &info, EdsUInt32 dataSize);
    };
}

#endif //NAPI_CANON_API_PROPERTY_H
