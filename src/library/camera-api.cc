#include <napi.h>
#include "api-error.h"
#include "camera-browser.h"
#include "camera-file.h"
#include "camera-property.h"
#include "object-event.h"
#include "property-aperture.h"
#include "property-exposure-compensation.h"
#include "property-flag.h"
#include "property-option.h"
#include "property-shutter-speed.h"
#include "state-event.h"

namespace CameraApi {
    Napi::Object RegisterModule(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);
        ApiError::Init(env, exports);
        CameraBrowserWrap::Init(env, exports);
        CameraFileWrap::Init(env, exports);
        CameraWrap::Init(env, exports);
        ObjectEvent::Init(env, exports);
        PropertyOption::Init(env, exports);
        PropertyAperture::Init(env, exports);
        PropertyExposureCompensation::Init(env, exports);
        PropertyFlag::Init(env, exports);
        PropertyShutterSpeed::Init(env, exports);
        CameraProperty::Init(env, exports);
        StateEvent::Init(env, exports);
        return exports;
    }

    NODE_API_MODULE(
        NODE_GYP_MODULE_NAME, RegisterModule
    )
}
