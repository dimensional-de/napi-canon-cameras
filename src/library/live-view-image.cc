#include "live-view-image.h"
#include "base64.h"
#include "api-error.h"
#include "option.h"
#include "utility.h"

namespace CameraApi {

    LiveViewImage::LiveViewImage(const Napi::CallbackInfo &info) : Napi::ObjectWrap<LiveViewImage>(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);


        if (!(info.Length() > 0 && info[0].IsExternal())) {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a camera reference."
            );
        }

        auto external = info[0].As<Napi::External<EdsCameraRef >>();
        EdsCameraRef edsCameraRef = *external.Data();

        EdsError error = fetch(edsCameraRef);
        ApiError::ThrowIfFailed(env, error);

    }

    EdsError LiveViewImage::fetch(EdsCameraRef edsCameraRef) {
        EdsError error = EDS_ERR_OK;

        error = EdsCreateMemoryStream(0, &streamRef_);
        if (error == EDS_ERR_OK) {
            error = EdsCreateEvfImageRef(streamRef_, &imageRef_);
        }
        if (error == EDS_ERR_OK) {
            error = EdsDownloadEvfImage(edsCameraRef, imageRef_);
        }
        return error;
    }

    LiveViewImage::~LiveViewImage() {
        if (streamRef_ != nullptr) {
            EdsRelease(streamRef_);
            streamRef_ = nullptr;
        }
        if (imageRef_ != nullptr) {
            EdsRelease(imageRef_);
            imageRef_ = nullptr;
        }
    }

    Napi::Value LiveViewImage::GetDataURL(const Napi::CallbackInfo &info) {
        EdsUInt64 imageDataLength;
        int imageStringLength;
        unsigned char *imageData;
        std::string encodedData = "data:image/jpeg;base64,";

        EdsGetLength(streamRef_, &imageDataLength);
        if (imageDataLength > 0) {
            EdsGetPointer(streamRef_, (EdsVoid **) &imageData);

            char *imageString = base64(imageData, (int) imageDataLength, &imageStringLength);
            encodedData.append(imageString);
            free(imageString);
            return Napi::String::New(info.Env(), encodedData);
        }
        return info.Env().Undefined();
    }

    Napi::Value LiveViewImage::GetCoordinateSystem(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsSize coordinateSystem;
        EdsError error;
        error = EdsGetPropertyData(
            imageRef_,
            kEdsPropID_Evf_CoordinateSystem,
            0,
            sizeof (coordinateSystem),
            &coordinateSystem
        );
        ApiError::ThrowIfFailed(env, error);
        Napi::Object size = Napi::Object::New(env);
        size.Set("width", Napi::Number::New(env, coordinateSystem.width));
        size.Set("height", Napi::Number::New(env, coordinateSystem.height));
        return size;
    }

    Napi::Value LiveViewImage::GetHistogram(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsError error;
        Napi::Uint32Array y = Napi::TypedArrayOf<uint32_t>::New(env, 256);
        Napi::Uint32Array r = Napi::TypedArrayOf<uint32_t>::New(env, 256);
        Napi::Uint32Array g = Napi::TypedArrayOf<uint32_t>::New(env, 256);
        Napi::Uint32Array b = Napi::TypedArrayOf<uint32_t>::New(env, 256);
        auto propertySize = 256 * sizeof(EdsUInt32);

        error = EdsGetPropertyData(
            imageRef_, kEdsPropID_Evf_HistogramY, 0, propertySize,y.Data()
        );
        ApiError::ThrowIfFailed(env, error);
        error = EdsGetPropertyData(
            imageRef_, kEdsPropID_Evf_HistogramR, 0, propertySize,r.Data()
        );
        ApiError::ThrowIfFailed(env, error);
        error = EdsGetPropertyData(
            imageRef_, kEdsPropID_Evf_HistogramG, 0, propertySize,g.Data()
        );
        ApiError::ThrowIfFailed(env, error);
        error = EdsGetPropertyData(
            imageRef_, kEdsPropID_Evf_HistogramB, 0, propertySize,b.Data()
        );
        ApiError::ThrowIfFailed(env, error);
        Napi::Object histogram = Napi::Object::New(env);
        histogram.Set("y", y);
        histogram.Set("r", r);
        histogram.Set("g", g);
        histogram.Set("b", b);
        return histogram;
    }

    Napi::Value LiveViewImage::GetHistogramStatus(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsUInt32 status;
        EdsGetPropertyData(
            imageRef_,
            kEdsPropID_Evf_HistogramStatus,
            0,
            sizeof (status),
            &status
        );
        return Option::NewInstance(env, kEdsPropID_Evf_HistogramStatus, status);
    }

    Napi::Value LiveViewImage::GetPosition(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsPoint imagePosition;
        EdsError error;
        error = EdsGetPropertyData(
            imageRef_,
            kEdsPropID_Evf_ImagePosition,
            0,
            sizeof (imagePosition),
            &imagePosition
        );
        ApiError::ThrowIfFailed(env, error);
        Napi::Object position = Napi::Object::New(env);
        position.Set("left", Napi::Number::New(env, imagePosition.x));
        position.Set("top", Napi::Number::New(env, imagePosition.y));
        return position;
    }


    Napi::Value LiveViewImage::GetVisibleArea(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsRect visibleArea;
        EdsError error;
        error = EdsGetPropertyData(
            imageRef_,
            kEdsPropID_Evf_VisibleRect,
            0,
            sizeof (visibleArea),
            &visibleArea
        );
        ApiError::ThrowIfFailed(env, error);
        Napi::Object area = Napi::Object::New(env);
        area.Set("left", Napi::Number::New(env, visibleArea.point.x));
        area.Set("top", Napi::Number::New(env, visibleArea.point.y));
        area.Set("width", Napi::Number::New(env, visibleArea.size.width));
        area.Set("height", Napi::Number::New(env, visibleArea.size.height));
        return area;
    }

    Napi::Value LiveViewImage::GetZoom(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsUInt32 zoomFactor;
        EdsError error;
        error = EdsGetPropertyData(
            imageRef_,
            kEdsPropID_Evf_Zoom,
            0,
            sizeof (zoomFactor),
            &zoomFactor
        );
        ApiError::ThrowIfFailed(env, error);
        return Option::NewInstance(env, kEdsPropID_Evf_Zoom, zoomFactor);
    }

    Napi::Value LiveViewImage::GetZoomArea(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsRect zoomArea;
        EdsError error;
        error = EdsGetPropertyData(
            imageRef_,
            kEdsPropID_Evf_ZoomRect,
            0,
            sizeof (zoomArea),
            &zoomArea
        );
        ApiError::ThrowIfFailed(env, error);
        Napi::Object zoom = Napi::Object::New(env);
        zoom.Set("left", Napi::Number::New(env, zoomArea.point.x));
        zoom.Set("top", Napi::Number::New(env, zoomArea.point.y));
        zoom.Set("width", Napi::Number::New(env, zoomArea.size.width));
        zoom.Set("height", Napi::Number::New(env, zoomArea.size.height));
        return zoom;
    }

    Napi::Value LiveViewImage::GetZoomPosition(const Napi::CallbackInfo &info) {
        Napi::Env env = info.Env();
        EdsPoint zoomPosition;
        EdsError error;
        error = EdsGetPropertyData(
            imageRef_,
            kEdsPropID_Evf_ZoomPosition,
            0,
            sizeof (zoomPosition),
            &zoomPosition
        );
        ApiError::ThrowIfFailed(env, error);
        Napi::Object zoom = Napi::Object::New(env);
        zoom.Set("left", Napi::Number::New(env, zoomPosition.x));
        zoom.Set("top", Napi::Number::New(env, zoomPosition.y));
        return zoom;
    }

    Napi::Value LiveViewImage::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), LiveViewImage::JSClassName);
    }

    Napi::Value LiveViewImage::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, LiveViewImage::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        return Napi::String::New(env, output);
    }

    Napi::Object LiveViewImage::NewInstance(Napi::Env env, EdsCameraRef edsCameraRef) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New({Napi::External<EdsImageRef>::New(env, &edsCameraRef)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void LiveViewImage::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Function func = DefineClass(
            env,
            LiveViewImage::JSClassName,
            {
                InstanceAccessor<&LiveViewImage::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
                InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &LiveViewImage::Inspect),

                InstanceAccessor<&LiveViewImage::GetCoordinateSystem>("coordinateSystem"),
                InstanceAccessor<&LiveViewImage::GetHistogram>("histogram"),
                InstanceAccessor<&LiveViewImage::GetHistogramStatus>("histogramStatus"),
                InstanceAccessor<&LiveViewImage::GetPosition>("position"),
                InstanceAccessor<&LiveViewImage::GetVisibleArea>("visibleArea"),
                InstanceAccessor<&LiveViewImage::GetZoom>("zoom"),
                InstanceAccessor<&LiveViewImage::GetZoomArea>("zoomArea"),
                InstanceAccessor<&LiveViewImage::GetZoomPosition>("zoomPosition"),

                InstanceMethod("getDataURL", &LiveViewImage::GetDataURL),
            }
        );
        JSConstructor(&func);
    }
} // CameraApi
