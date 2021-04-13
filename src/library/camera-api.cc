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
#include "directory.h"
#include "image-quality.h"
#include "iso-sensitivity.h"
#include "time-zone.h"
#include "output-device.h"
#include "file-format.h"

namespace CameraApi {
    Napi::Object RegisterModule(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);
        Aperture::Init(env, exports);
        ApiError::Init(env, exports);
        CameraBrowserWrap::Init(env, exports);
        CameraFile::Init(env, exports);
        CameraProperty::Init(env, exports);
        CameraWrap::Init(env, exports);
        Directory::Init(env, exports);
        ExposureCompensation::Init(env, exports);
        FileFormat::Init(env, exports);
        Flag::Init(env, exports);
        ImageQuality::Init(env, exports);
        ISOSensitivity::Init(env, exports);
        ObjectEvent::Init(env, exports);
        Option::Init(env, exports);
        OutputDevice::Init(env, exports);
        ShutterSpeed::Init(env, exports);
        StateEvent::Init(env, exports);
        TimeZone::Init(env, exports);
        Volume::Init(env, exports);
        return exports;
    }

    NODE_API_MODULE(
        NODE_GYP_MODULE_NAME, RegisterModule
    )
}
