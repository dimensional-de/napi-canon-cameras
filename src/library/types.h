#ifndef CANON_API_TYPES_H
#define CANON_API_TYPES_H

#include <uv.h>
#include <unordered_map>
#include <napi.h>
#include <EDSDK.h>

#define kEdsPropID_CFn               0x00000009
#define kEdsPropID_MyMenu            0x0000000e
#define kEdsPropID_JpegQuality       0x00000101
#define kEdsPropID_FlashCompensation 0x00000408
#define kEdsPropID_DepthOfField      0x0000041b
#define kEdsPropID_EFCompensation    0x0000041e
#define kEdsPropID_Evf_FocusAid      0x00000509


// bc
#ifndef kEdsCameraCommand_RequestSensorCleaning
#define kEdsCameraCommand_RequestSensorCleaning    0x00000112
#endif

#ifndef kEdsCameraCommand_SetModeDialDisable
#define kEdsCameraCommand_SetModeDialDisable    0x00000113
#endif

#ifndef kEdsWhiteBalance_Tungsten
#define kEdsWhiteBalance_Tungsten   3
#endif

namespace CameraApi {

    typedef std::unordered_map<EdsUInt32, std::string> LabelMap;

    enum class ExposureStopSize { OneHalf, OneThird };
}

#endif
