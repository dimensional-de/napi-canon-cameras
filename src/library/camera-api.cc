#include <napi.h>
#include "aperture.h"
#include "api-error.h"
#include "camera-browser.h"
#include "camera-file.h"
#include "camera-property.h"
#include "exposure-compensation.h"
#include "flag.h"
#include "object-event.h"
#include "option.h"
#include "shutter-speed.h"
#include "state-event.h"
#include "volume.h"

namespace CameraApi {
    Napi::Object RegisterModule(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);
        ApiError::Init(env, exports);
        CameraBrowserWrap::Init(env, exports);
        CameraFileWrap::Init(env, exports);
        CameraWrap::Init(env, exports);
        ObjectEvent::Init(env, exports);
        Option::Init(env, exports);
        Aperture::Init(env, exports);
        ExposureCompensation::Init(env, exports);
        Flag::Init(env, exports);
        ShutterSpeed::Init(env, exports);
        CameraProperty::Init(env, exports);
        StateEvent::Init(env, exports);
        Volume::Init(env, exports);
        return exports;
    }

    NODE_API_MODULE(
        NODE_GYP_MODULE_NAME, RegisterModule
    )
}
