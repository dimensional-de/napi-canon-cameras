#include "camera-property.h"
#include "labels.h"
#include "flag.h"
#include "option.h"
#include "aperture.h"
#include "shutter-speed.h"
#include "api-error.h"
#include "utility.h"
#include "exposure-compensation.h"
#include "image-quality.h"

namespace CameraApi {

    std::vector<EdsPropertyID> LookupProperties = {
        kEdsPropID_AEModeSelect,
        kEdsPropID_MeteringMode,
        kEdsPropID_ISOSpeed,
        kEdsPropID_Av,
        kEdsPropID_Tv,
        kEdsPropID_ExposureCompensation,
        kEdsPropID_ImageQuality,
        kEdsPropID_WhiteBalance,
        kEdsPropID_ColorTemperature,
        kEdsPropID_PictureStyle,
        kEdsPropID_DriveMode,
        kEdsPropID_Evf_WhiteBalance,
        kEdsPropID_Evf_ColorTemperature,
        kEdsPropID_Evf_AFMode,
        kEdsPropID_DC_Strobe,
        kEdsPropID_DC_Zoom,
        kEdsPropID_MovieParam,
        kEdsPropID_TimeZone
    };

    CameraProperty::CameraProperty(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<CameraProperty>(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsObject()) {
            CameraWrap *wrap = Napi::ObjectWrap<CameraWrap>::Unwrap(info[0].As<Napi::Object>());
            CameraReference camera = wrap->GetCameraReference();
            edsCamera_ = camera->getEdsReference();
            EdsRetain(edsCamera_);
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a Camera instance."
            );
        }
        if (info.Length() > 1 && info[1].IsNumber()) {
            propertyIdentifier_ = info[1].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 1 must be a property identifier."
            );
        }
        if (info.Length() > 2 && info[2].IsNumber()) {
            propertySpecifier_ = info[2].As<Napi::Number>().Int32Value();
        }
    }

    CameraProperty::~CameraProperty() {
        EdsRelease(edsCamera_);
    }

    Napi::Value CameraProperty::GetLabel(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), CameraProperty::GetLabelFor(propertyIdentifier_));
    }

    Napi::Value CameraProperty::GetIdentifier(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), propertyIdentifier_);
    }

    Napi::Value CameraProperty::GetSpecifier(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), propertySpecifier_);
    }

    Napi::Value CameraProperty::IsAvailable(const Napi::CallbackInfo &info) {
        EdsDataType dataType;
        EdsUInt32 dataSize;
        return Napi::Boolean::New(
            info.Env(),
            EDS_ERR_OK == EdsGetPropertySize(edsCamera_, propertyIdentifier_, propertySpecifier_, &dataType, &dataSize)
        );
    }

    Napi::Value CameraProperty::GetValue(const Napi::CallbackInfo &info) {
        EdsError error = EDS_ERR_OK;
        Napi::Env env = info.Env();
        Napi::Value value = env.Null();
        EdsDataType dataType;
        EdsUInt32 dataSize;

        ApiError::ThrowIfFailed(
            env, EdsGetPropertySize(
                edsCamera_, propertyIdentifier_, propertySpecifier_, &dataType, &dataSize
            ));
        switch (dataType) {
            case kEdsDataType_Int32:
                EdsInt32 int32_value;
                ApiError::ThrowIfFailed(
                    env,
                    EdsGetPropertyData(
                        edsCamera_, propertyIdentifier_, propertySpecifier_, dataSize, &int32_value
                    )
                );
                value = Napi::Number::New(env, int32_value);
                break;
            case kEdsDataType_UInt32:
                EdsInt32 uint32_value;
                ApiError::ThrowIfFailed(
                    env,
                    EdsGetPropertyData(
                        edsCamera_, propertyIdentifier_, propertySpecifier_, dataSize, &uint32_value
                    )
                );
                value = Napi::Number::New(env, uint32_value);
                break;
            case kEdsDataType_String:
                EdsChar char_value[EDS_MAX_NAME];
                ApiError::ThrowIfFailed(
                    env,
                    EdsGetPropertyData(
                        edsCamera_, propertyIdentifier_, propertySpecifier_, EDS_MAX_NAME, &char_value
                    )
                );
                value = Napi::String::New(env, char_value);
                break;
            case kEdsDataType_Time:
                value = ReadTimeValue(info, dataSize);
                break;
            case kEdsDataType_Int32_Array:
                value = ReadInt32ArrayValue(info, dataSize, sizeof(EdsInt32));
                break;
            case kEdsDataType_PictureStyleDesc:
                value = ReadPictureStyleDescription(info, dataSize);
                break;
            default:
                throw Napi::Error::New(env, "Failed to get property (data type not implemented)");
                break;
        }
        switch (propertyIdentifier_) {
            case kEdsPropID_Av:
                return Aperture::NewInstance(
                    env, value.As<Napi::Number>().Int32Value()
                );
            case kEdsPropID_Tv:
                return ShutterSpeed::NewInstance(
                    env, value.As<Napi::Number>().Int32Value()
                );
            case kEdsPropID_ExposureCompensation:
                return ExposureCompensation::NewInstance(
                    env, value.As<Napi::Number>().Int32Value()
                );
            case kEdsPropID_ImageQuality:
                return ImageQuality::NewInstance(
                    env, value.As<Napi::Number>().Int32Value()
                );
            default:
                if (Flag::IsFlagProperty(propertyIdentifier_)) {
                    return Flag::NewInstance(
                        env, value.As<Napi::Number>().Int32Value()
                    );
                } else if (Option::IsOptionsProperty(propertyIdentifier_)) {
                    return Option::NewInstance(
                        env, propertyIdentifier_, value.As<Napi::Number>().Int32Value()
                    );
                }
        }
        return value;
    }

    Napi::Object CameraProperty::ReadTimeValue(const Napi::CallbackInfo &info, EdsUInt32 dataSize) {
        Napi::Env env = info.Env();
        EdsTime time_value;
        ApiError::ThrowIfFailed(
            env,
            EdsGetPropertyData(
                edsCamera_, propertyIdentifier_, propertySpecifier_, dataSize, &time_value
            )
        );
        Napi::Object value = Napi::Object::New(env);
        value.Set("year", Napi::Number::New(env, time_value.year));
        value.Set("month", Napi::Number::New(env, time_value.month));
        value.Set("day", Napi::Number::New(env, time_value.day));
        value.Set("hour", Napi::Number::New(env, time_value.hour));
        value.Set("minute", Napi::Number::New(env, time_value.minute));
        value.Set("second", Napi::Number::New(env, time_value.second));
        value.Set("milliseconds", Napi::Number::New(env, time_value.milliseconds));
        return value;
    }

    Napi::Object
    CameraProperty::ReadInt32ArrayValue(const Napi::CallbackInfo &info, EdsUInt32 dataSize, EdsUInt32 itemSize) {
        Napi::Env env = info.Env();
        EdsUInt32 numElements = dataSize / itemSize;
        auto *items = new EdsInt32[numElements];
        Napi::Array value = Napi::Array::New(env, numElements);
        ApiError::ThrowIfFailed(
            env,
            EdsGetPropertyData(
                edsCamera_, propertyIdentifier_, propertySpecifier_, dataSize, items
            )
        );
        for (EdsUInt32 i = 0; i < numElements; i++) {
            value.Set(i, Napi::Number::New(env, items[i]));
        }
        delete[] items;

        return value;
    }

    Napi::Object CameraProperty::ReadPictureStyleDescription(const Napi::CallbackInfo &info, EdsUInt32 dataSize) {
        Napi::Env env = info.Env();
        EdsPictureStyleDesc style_value;
        ApiError::ThrowIfFailed(
            env,
            EdsGetPropertyData(
                edsCamera_, propertyIdentifier_, propertySpecifier_, dataSize, &style_value
            )
        );
        Napi::Object value = Napi::Object::New(env);
        value.Set("contrast", Napi::Number::New(env, style_value.contrast));
        value.Set("sharpness", Napi::Number::New(env, style_value.sharpness));
        value.Set("saturation", Napi::Number::New(env, style_value.saturation));
        value.Set("colorTone", Napi::Number::New(env, style_value.colorTone));
        value.Set("filterEffect", Napi::Number::New(env, style_value.filterEffect));
        value.Set("toningEffect", Napi::Number::New(env, style_value.toningEffect));
        value.Set("sharpFineness", Napi::Number::New(env, style_value.sharpFineness));
        value.Set("sharpThreshold", Napi::Number::New(env, style_value.sharpThreshold));
        return value;
    }


    Napi::Value CameraProperty::GetAllowedValues(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Array values = Napi::Array::New(env);
        EdsPropertyDesc propertyDescription;

        ApiError::ThrowIfFailed(env, EdsGetPropertyDesc(edsCamera_, propertyIdentifier_, &propertyDescription));
        for (int i = 0; i < propertyDescription.numElements; ++i) {
            switch (propertyIdentifier_) {
                case kEdsPropID_Av:
                    values.Set(i, Aperture::NewInstance(env, propertyDescription.propDesc[i]));
                    break;
                case kEdsPropID_Tv:
                    values.Set(i, ShutterSpeed::NewInstance(env, propertyDescription.propDesc[i]));
                    break;
                case kEdsPropID_ExposureCompensation:
                    values.Set(i, ExposureCompensation::NewInstance(env, propertyDescription.propDesc[i]));
                    break;
                case kEdsPropID_ImageQuality:
                    values.Set(i, ImageQuality::NewInstance(env, propertyDescription.propDesc[i]));
                    break;
                default:
                    if (Option::IsOptionsProperty(propertyIdentifier_)) {
                        values.Set(
                            i,
                            Option::NewInstance(
                                env, propertyIdentifier_, propertyDescription.propDesc[i]
                            )
                        );
                    } else {
                        values.Set(i, Napi::Number::New(env, propertyDescription.propDesc[i]));
                    }
            }
        }
        return values;
    }

    void CameraProperty::SetValue(const Napi::CallbackInfo &info, const Napi::Value &propertyValue) {
        Napi::Env env = info.Env();
        Napi::Value value = propertyValue;
        EdsError error = EDS_ERR_OK;
        EdsDataType dataType;
        EdsUInt32 dataSize;

        if (Option::IsClassOf(propertyValue)) {
            value = propertyValue.As<Napi::Object>().Get("value");
        }

        error = EdsGetPropertySize(edsCamera_, propertyIdentifier_, propertySpecifier_, &dataType, &dataSize);

        if (isLookUpProperty()) {
            if (!isAllowedPropertyValue(value.As<Napi::Number>().Int32Value())) {
                ApiError::ThrowIfFailed(info.Env(), EDS_ERR_INVALID_DEVICEPROP_VALUE);
            }
        }

        switch (dataType) {
            case kEdsDataType_Int32:
                if (value.IsNumber()) {
                    EdsInt32 int32_value = value.As<Napi::Number>().Int32Value();
                    error = EdsSetPropertyData(
                        edsCamera_, propertyIdentifier_, propertySpecifier_, dataSize, &int32_value
                    );
                }
                break;
            case kEdsDataType_UInt32:
                if (value.IsNumber()) {
                    EdsInt32 uint32_value = value.As<Napi::Number>().Uint32Value();
                    error = EdsSetPropertyData(
                        edsCamera_, propertyIdentifier_, propertySpecifier_, dataSize, &uint32_value
                    );
                }
                break;
            default:
                throw Napi::Error::New(env, "Failed to set property (data type not implemented)");
                break;
        }
        if (error == EDS_ERR_OK) {
            switch (propertyIdentifier_) {
                case kEdsPropID_SaveTo:
                    if (value.As<Napi::Number>().Uint32Value() == kEdsSaveTo_Host) {
                        EdsCapacity capacity = {0x7FFFFFFF, 0x1000, 1};
                        error = EdsSetCapacity(edsCamera_, capacity);
                        if (error != EDS_ERR_OK) {
                            throw Napi::Error::New(env, "Failed to set capacity of host");
                        }
                    }
                    break;
            }
        } else {
            ApiError::ThrowIfFailed(env, EDS_ERR_OK);
        }
    }

    Napi::Value CameraProperty::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), CameraProperty::JSClassName);
    }

    Napi::Value CameraProperty::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto isNamedIdentifier = (Labels::PropertyID.find(propertyIdentifier_) == Labels::PropertyID.end());
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, CameraProperty::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {GetLabel(info), Napi::String::New(env, isNamedIdentifier ? "symbol" : "number")}
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    }

    bool CameraProperty::isLookUpProperty() const {
        int propertyID = propertyIdentifier_;
        return (
            std::any_of(
                LookupProperties.begin(),
                LookupProperties.end(),
                [propertyID](int p) { return p == propertyID; }
            )
        );
    }

    bool CameraProperty::isAllowedPropertyValue(int propertyValue) {
        EdsPropertyDesc propertyDescription;
        EdsError error = EdsGetPropertyDesc(edsCamera_, propertyIdentifier_, &propertyDescription);
        if (error == EDS_ERR_OK) {
            for (int i = 0; i < propertyDescription.numElements; ++i) {
                if (propertyDescription.propDesc[i] == propertyValue) {
                    return true;
                }
            }
        }
        return false;
    }

    Napi::Value CameraProperty::ToJSON(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        Napi::Object Json = Napi::Object::New(env);
        Json.Set("label", GetLabel(info));
        Json.Set("identifier", GetIdentifier(info));
        if (propertySpecifier_ > 0) {
            Json.Set("specifier", GetSpecifier(info));
        }
        Json.Set("value", GetValue(info));
        return Json;
    }

    std::string CameraProperty::GetLabelFor(const EdsPropertyID propertyID) {
        if (Labels::PropertyID.find(propertyID) == Labels::PropertyID.end()) {
            return CodeToHexLabel(propertyID);
        }
        return Labels::PropertyID[propertyID];
    }

    Napi::Object CameraProperty::NewInstance(
        Napi::Env env, CameraReference camera, EdsPropertyID identifier, EdsInt32 specifier
    ) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                CameraWrap::NewInstance(env, std::move(camera)),
                Napi::Number::New(env, identifier),
                Napi::Number::New(env, specifier),
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void CameraProperty::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object IDs = Napi::Object::New(env);
        for (const auto &it : Labels::PropertyID) {
            IDs.DefineProperty(
                Napi::PropertyDescriptor::Value(
                    it.second.c_str(), Napi::Number::New(env, it.first), napi_enumerable
                )
            );
        }

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&CameraProperty::GetLabel>("label"),
            InstanceAccessor<&CameraProperty::GetIdentifier>("identifier"),
            InstanceAccessor<&CameraProperty::GetSpecifier>("specifier"),
            InstanceAccessor<&CameraProperty::IsAvailable>("available"),
            InstanceAccessor<&CameraProperty::GetValue, &CameraProperty::SetValue>("value"),
            InstanceAccessor<&CameraProperty::GetAllowedValues>("allowedValues"),
            InstanceMethod("toJSON", &CameraProperty::ToJSON),

            InstanceAccessor<&CameraProperty::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &CameraProperty::Inspect),

            StaticValue("ID", IDs, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, CameraProperty::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(CameraProperty::JSClassName, func);
    }
}
