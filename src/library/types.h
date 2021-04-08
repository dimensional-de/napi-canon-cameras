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

    const char EventName_CameraAdd[] = "camera-add";
    const char EventName_CameraRemove[] = "camera-remove";
    const char EventName_StateChange[] = "camera-state";
    const char EventName_LiveViewStart[] = "camera-lv-start";
    const char EventName_LiveViewStop[] = "camera-lv-stop";
    const char EventName_PropertyChangeOptions[] = "property-change.allowed";
    const char EventName_PropertyChangeValue[] = "property-change.value";
    const char EventName_DownloadRequest[] = "download-request";
    const char EventName_ObjectChange[] = "object-change";
    const char EventName_Error[] = "error";



}

#endif
