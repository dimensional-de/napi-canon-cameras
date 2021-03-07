#ifndef CANON_API_TYPES_H
#define CANON_API_TYPES_H

#include <uv.h>
#include <unordered_map>
#include <napi.h>
#include <EDSDK.h>


namespace CameraApi {

    typedef std::unordered_map<int, std::string> LabelMap;

    const std::string EventName_CameraAdd = "camera-add";
    const std::string EventName_CameraRemove = "camera-remove";
    const std::string EventName_StateChange = "camera-state";
    const std::string EventName_LiveViewStart = "camera-lv-start";
    const std::string EventName_LiveViewStop = "camera-lv-stop";
    const std::string EventName_PropertyChangeOptions = "property-change.allowed";
    const std::string EventName_PropertyChangeValue = "property-change.value";
    const std::string EventName_DownloadRequest = "download-request";
    const std::string EventName_ObjectChange = "object-change";
    const std::string EventName_Error = "error";

}

#endif
