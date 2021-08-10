#ifndef NAPI_CANON_CAMERAS_EVENTS_H
#define NAPI_CANON_CAMERAS_EVENTS_H

namespace CameraApi {

    const char EventName_CameraAdd[] = "CameraAdd";
    const char EventName_CameraRemove[] = "CameraRemove";
    const char EventName_CameraConnect[] = "CameraConnect";
    const char EventName_CameraDisconnect[] = "CameraDisconnect";
    const char EventName_StateChange[] = "StateChange";
    const char EventName_KeepAlive[] = "KeepAlive";
    const char EventName_LiveViewStart[] = "LiveViewStart";
    const char EventName_LiveViewStop[] = "LiveViewStop";
    const char EventName_PropertyChangeOptions[] = "PropertyChangeOptions";
    const char EventName_PropertyChangeValue[] = "PropertyChangeValue";
    const char EventName_DownloadRequest[] = "DownloadRequest";
    const char EventName_FileCreate[] = "FileCreate";
    const char EventName_DirectoryCreate[] = "DirectoryCreate";
    const char EventName_VolumeChange[] = "VolumeChange";
    const char EventName_ObjectChange[] = "ObjectChange";
    const char EventName_Error[] = "Error";

    const std::vector CameraBrowserEvents = {
        EventName_CameraAdd,
        EventName_CameraRemove,
        EventName_CameraConnect,
        EventName_CameraDisconnect,
        EventName_StateChange,
        EventName_KeepAlive,
        EventName_LiveViewStart,
        EventName_LiveViewStop,
        EventName_PropertyChangeOptions,
        EventName_PropertyChangeValue,
        EventName_DownloadRequest,
        EventName_FileCreate,
        EventName_DirectoryCreate,
        EventName_VolumeChange,
        EventName_ObjectChange,
        EventName_Error
    };

    const std::vector CameraEvents = {
        EventName_CameraConnect,
        EventName_CameraDisconnect,
        EventName_StateChange,
        EventName_KeepAlive,
        EventName_LiveViewStart,
        EventName_LiveViewStop,
        EventName_PropertyChangeOptions,
        EventName_PropertyChangeValue,
        EventName_DownloadRequest,
        EventName_FileCreate,
        EventName_DirectoryCreate,
        EventName_VolumeChange,
        EventName_ObjectChange,
        EventName_Error
    };
}

#endif //NAPI_CANON_CAMERAS_EVENTS_H
