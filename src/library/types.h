#ifndef CANON_API_TYPES_H
#define CANON_API_TYPES_H

#include <uv.h>
#include <unordered_map>
#include <napi.h>
#include <EDSDK.h>

#define kEdsPropID_MyMenu          0x0000000e
#define kEdsPropID_JpegQuality     0x00000101
#define kEdsPropID_DepthOfField    0x0000041b
#define kEdsPropID_EFCompensation  0x0000041e
#define kEdsPropID_Evf_FocusAid    0x00000509

namespace CameraApi {

    typedef std::unordered_map<int, std::string> LabelMap;
}

#endif
