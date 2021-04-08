#include "labels.h"

namespace CameraApi {

    LabelMap Labels::ObjectEventID = {
        {kEdsObjectEvent_All, "All"},
        {kEdsObjectEvent_VolumeInfoChanged, "VolumeInfoChanged"},
        {kEdsObjectEvent_VolumeUpdateItems, "VolumeUpdateItems"},
        {kEdsObjectEvent_FolderUpdateItems, "FolderUpdateItems"},
        {kEdsObjectEvent_DirItemCreated, "DirItemCreated"},
        {kEdsObjectEvent_DirItemRemoved, "DirItemRemoved"},
        {kEdsObjectEvent_DirItemInfoChanged, "DirItemInfoChanged"},
        {kEdsObjectEvent_DirItemContentChanged, "DirItemContentChanged"},
        {kEdsObjectEvent_DirItemRequestTransfer, "DirItemRequestTransfer"},
        {kEdsObjectEvent_DirItemRequestTransferDT, "DirItemRequestTransferDT"},
        {kEdsObjectEvent_DirItemCancelTransferDT, "DirItemCancelTransferDT"},

        {kEdsObjectEvent_VolumeAdded, "VolumeAdded"},
        {kEdsObjectEvent_VolumeRemoved, "VolumeRemoved"},
    };

    LabelMap Labels::StateEventID = {
        {kEdsStateEvent_All, "All"},
        {kEdsStateEvent_Shutdown, "Shutdown"},
        {kEdsStateEvent_JobStatusChanged, "JobStatusChanged"},
        {kEdsStateEvent_WillSoonShutDown, "WillSoonShutDown"},
        {kEdsStateEvent_ShutDownTimerUpdate, "ShutDownTimerUpdate"},
        {kEdsStateEvent_CaptureError, "CaptureError"},
        {kEdsStateEvent_InternalError, "InternalError"},
        {kEdsStateEvent_AfResult, "AfResult"},
        {kEdsStateEvent_BulbExposureTime, "BulbExposureTime"},
        {kEdsStateEvent_PowerZoomInfoChanged, "PowerZoomInfoChanged"},
    };

    LabelMap Labels::PropertyID = {
        // Camera Setting Properties
        {kEdsPropID_ProductName, "ProductName"},
        {kEdsPropID_OwnerName, "OwnerName"},
        {kEdsPropID_MakerName, "MakerName"},
        {kEdsPropID_DateTime, "DateTime"},
        {kEdsPropID_FirmwareVersion, "FirmwareVersion"},
        {kEdsPropID_BatteryLevel, "BatteryLevel"},
        {kEdsPropID_CFn, "CFn"},
        {kEdsPropID_SaveTo, "SaveTo"},
        {kEdsPropID_CurrentStorage, "CurrentStorage"},
        {kEdsPropID_CurrentFolder, "CurrentFolder"},
        {kEdsPropID_MyMenu, "MyMenu"},

        {kEdsPropID_BatteryQuality, "BatteryQuality"},

        {kEdsPropID_BodyIDEx, "BodyIDEx"},
        {kEdsPropID_HDDirectoryStructure, "HDDirectoryStructure"},

        {kEdsPropID_TempStatus, "TemperatureStatus"},

        // Image Properties
        {kEdsPropID_ImageQuality, "ImageQuality"},
        {kEdsPropID_JpegQuality, "JpegQuality"},
        {kEdsPropID_Orientation, "Orientation"},
        {kEdsPropID_ICCProfile, "ICCProfile"},
        {kEdsPropID_FocusInfo, "FocusInfo"},
        {kEdsPropID_WhiteBalance, "WhiteBalance"},
        {kEdsPropID_ColorTemperature, "ColorTemperature"},
        {kEdsPropID_WhiteBalanceShift, "WhiteBalanceShift"},
        {kEdsPropID_ColorSpace, "ColorSpace"},
        {kEdsPropID_PictureStyle, "PictureStyle"},
        {kEdsPropID_PictureStyleDesc, "PictureStyleDescription"},
        {kEdsPropID_PictureStyleCaption, "PictureStyleCaption"},

        //Image GPS Properties
        {kEdsPropID_GPSVersionID, "GPSVersionID"},
        {kEdsPropID_GPSLatitudeRef, "GPSLatitudeRef"},
        {kEdsPropID_GPSLatitude, "GPSLatitude"},
        {kEdsPropID_GPSLongitudeRef, "GPSLongitudeRef"},
        {kEdsPropID_GPSLongitude, "GPSLongitude"},
        {kEdsPropID_GPSAltitudeRef, "GPSAltitudeRef"},
        {kEdsPropID_GPSAltitude, "GPSAltitude"},
        {kEdsPropID_GPSTimeStamp, "GPSTimeStamp"},
        {kEdsPropID_GPSSatellites, "GPSSatellites"},
        {kEdsPropID_GPSStatus, "GPSStatus"},
        {kEdsPropID_GPSMapDatum, "GPSMapDatum"},
        {kEdsPropID_GPSDateStamp, "GPSDateStamp"},

        // Capture Properties
        {kEdsPropID_AEMode, "AEMode"},
        {kEdsPropID_DriveMode, "DriveMode"},
        {kEdsPropID_ISOSpeed, "ISOSpeed"},
        {kEdsPropID_MeteringMode, "MeteringMode"},
        {kEdsPropID_AFMode, "AFMode"},
        {kEdsPropID_Av, "Av"},
        {kEdsPropID_Tv, "Tv"},
        {kEdsPropID_ExposureCompensation, "ExposureCompensation"},
        {kEdsPropID_FocalLength, "FocalLength"},
        {kEdsPropID_AvailableShots, "AvailableShots"},
        {kEdsPropID_Bracket, "Bracket"},
        {kEdsPropID_WhiteBalanceBracket, "WhiteBalanceBracket"},
        {kEdsPropID_LensName, "LensName"},
        {kEdsPropID_AEBracket, "AEBracket"},
        {kEdsPropID_FEBracket, "FEBracket"},
        {kEdsPropID_ISOBracket, "ISOBracket"},
        {kEdsPropID_NoiseReduction, "NoiseReduction"},
        {kEdsPropID_FlashOn, "FlashOn"},
        {kEdsPropID_RedEye, "RedEye"},
        {kEdsPropID_FlashMode, "FlashMode"},
        {kEdsPropID_LensStatus, "LensStatus"},
        {kEdsPropID_Artist, "Artist"},
        {kEdsPropID_Copyright, "Copyright"},
        {kEdsPropID_AEModeSelect, "AEModeSelect"},
        {kEdsPropID_DepthOfField, "DepthOfField"},
        {kEdsPropID_EFCompensation, "EFCompensation"},
        {kEdsPropID_PowerZoom_Speed, "PowerZoom_Speed"},

        // EVF Properties
        {kEdsPropID_Evf_OutputDevice, "Evf_OutputDevice"},
        {kEdsPropID_Evf_Mode, "Evf_Mode"},
        {kEdsPropID_Evf_WhiteBalance, "Evf_WhiteBalance"},
        {kEdsPropID_Evf_ColorTemperature, "Evf_ColorTemperature"},
        {kEdsPropID_Evf_DepthOfFieldPreview, "Evf_DepthOfFieldPreview"},

        // EVF IMAGE DATA Properties
        {kEdsPropID_Evf_Zoom, "Evf_Zoom"},
        {kEdsPropID_Evf_ZoomPosition, "Evf_ZoomPosition"},
        {kEdsPropID_Evf_FocusAid, "Evf_FocusAid"},
        {kEdsPropID_Evf_Histogram, "Evf_Histogram"},
        {kEdsPropID_Evf_ImagePosition, "Evf_ImagePosition"},
        {kEdsPropID_Evf_HistogramStatus, "Evf_HistogramStatus"},
        {kEdsPropID_Evf_AFMode, "Evf_AFMode"},

        {kEdsPropID_Record, "Record"},

        {kEdsPropID_Evf_HistogramY, "Evf_HistogramY"},
        {kEdsPropID_Evf_HistogramR, "Evf_HistogramR"},
        {kEdsPropID_Evf_HistogramG, "Evf_HistogramG"},
        {kEdsPropID_Evf_HistogramB, "Evf_HistogramB"},

        {kEdsPropID_Evf_CoordinateSystem, "Evf_CoordinateSystem"},
        {kEdsPropID_Evf_ZoomRect, "Evf_ZoomRect"},
        {kEdsPropID_Evf_ImageClipRect, "Evf_ImageClipRect"},

        {kEdsPropID_Evf_PowerZoom_CurPosition, "Evf_PowerZoom_CurPosition"},
        {kEdsPropID_Evf_PowerZoom_MaxPosition, "Evf_PowerZoom_MaxPosition"},
        {kEdsPropID_Evf_PowerZoom_MinPosition, "Evf_PowerZoom_MinPosition"},

        // Limited Properties
        {kEdsPropID_EVF_RollingPitching, "EVF_RollingPitching"},
        {kEdsPropID_FixedMovie, "FixedMovie"},
        {kEdsPropID_MovieParam, "MovieParam"},
        {kEdsPropID_Evf_ClickWBCoeffs, "Evf_ClickWBCoeffs"},
        {kEdsPropID_ManualWhiteBalanceData, "ManualWhiteBalanceData"},
        {kEdsPropID_MirrorUpSetting, "MirrorUpSetting"},
        {kEdsPropID_MirrorLockUpState, "MirrorLockUpState"},
        {kEdsPropID_UTCTime, "UTCTime"},
        {kEdsPropID_TimeZone, "TimeZone"},
        {kEdsPropID_SummerTimeSetting, "SummerTimeSetting"},
        {kEdsPropID_AutoPowerOffSetting, "AutoPowerOffSetting"},

        // DC Properties
        {kEdsPropID_DC_Zoom, "DC_Zoom"},
        {kEdsPropID_DC_Strobe, "DC_Strobe"},
        {kEdsPropID_LensBarrelStatus, "LensBarrelStatus"},
    };

    LabelMap Labels::BatteryQuality = {
        {0, "Low"},
        {1, "Half"},
        {2, "High"},
        {3, "Full"}
    };

    LabelMap Labels::AEMode = {
        {kEdsAEMode_Program, "ProgramAE"},
        {kEdsAEMode_Tv, "Tv"},
        {kEdsAEMode_Av, "Av"},
        {kEdsAEMode_Manual, "Manual"},
        {kEdsAEMode_Bulb, "Bulb"},
        {kEdsAEMode_A_DEP, "A_DEP"},
        {kEdsAEMode_DEP, "DEP"},
        {kEdsAEMode_Custom, "Custom"},
        {kEdsAEMode_Lock, "Lock"},
        {kEdsAEMode_Green, "Green"},
        {kEdsAEMode_NightPortrait, "NightPortrait"},
        {kEdsAEMode_Sports, "Sports"},
        {kEdsAEMode_Portrait, "Portrait"},
        {kEdsAEMode_Landscape, "Landscape"},
        {kEdsAEMode_Closeup, "Closeup"},
        {kEdsAEMode_FlashOff, "FlashOff"},
        {kEdsAEMode_CreativeAuto, "CreativeAuto"},
        {kEdsAEMode_Movie, "Movie"},
        {kEdsAEMode_PhotoInMovie, "PhotoInMovie"},
        {kEdsAEMode_SceneIntelligentAuto, "SceneIntelligentAuto"},
        {kEdsAEMode_SCN, "SCN"},
        {kEdsAEMode_NightScenes, "NightScenes"},
        {kEdsAEMode_BacklitScenes, "BacklitScenes"},
        {kEdsAEMode_Children, "Children"},
        {kEdsAEMode_Food, "Food"},
        {kEdsAEMode_CandlelightPortraits, "CandlelightPortraits"},
        {kEdsAEMode_CreativeFilter, "CreativeFilter"},
        {kEdsAEMode_RoughMonoChrome, "RoughMonoChrome"},
        {kEdsAEMode_SoftFocus, "SoftFocus"},
        {kEdsAEMode_ToyCamera, "ToyCamera"},
        {kEdsAEMode_Fisheye, "Fisheye"},
        {kEdsAEMode_WaterColor, "WaterColor"},
        {kEdsAEMode_Miniature, "Miniature"},
        {kEdsAEMode_Hdr_Standard, "Hdr_Standard"},
        {kEdsAEMode_Hdr_Vivid, "Hdr_Vivid"},
        {kEdsAEMode_Hdr_Bold, "Hdr_Bold"},
        {kEdsAEMode_Hdr_Embossed, "Hdr_Embossed"},
        {kEdsAEMode_Movie_Fantasy, "Movie_Fantasy"},
        {kEdsAEMode_Movie_Old, "Movie_Old"},
        {kEdsAEMode_Movie_Memory, "Movie_Memory"},
        {kEdsAEMode_Movie_DirectMono, "Movie_DirectMono"},
        {kEdsAEMode_Movie_Mini, "Movie_Mini"},
        {kEdsAEMode_PanningAssist, "PanningAssist"},
        {kEdsAEMode_GroupPhoto, "GroupPhoto"},
        {kEdsAEMode_Myself, "Myself"},
        {kEdsAEMode_PlusMovieAuto, "PlusMovieAuto"},
        {kEdsAEMode_SmoothSkin, "SmoothSkin"},
        {kEdsAEMode_Panorama, "Panorama"},
        {kEdsAEMode_Silent, "Silent"},
        {kEdsAEMode_Flexible, "Flexible"},
        {kEdsAEMode_OilPainting, "OilPainting"},
        {kEdsAEMode_Fireworks, "Fireworks"},
        {kEdsAEMode_StarPortrait, "StarPortrait"},
        {kEdsAEMode_StarNightscape, "StarNightScape"},
        {kEdsAEMode_StarTrails, "StarTrails"},
        {kEdsAEMode_StarTimelapseMovie, "StarTimelapseMovie"},
        {kEdsAEMode_BackgroundBlur, "BackgroundBlur"},
        {kEdsAEMode_Unknown, "Unknown"}
    };

    LabelMap Labels::AEModeSelect = {
        {kEdsAEMode_Program, "ProgramAE"},
        {kEdsAEMode_Tv, "Tv"},
        {kEdsAEMode_Av, "Av"},
        {kEdsAEMode_Manual, "Manual"},
        {kEdsAEMode_Bulb, "Bulb"},
        {kEdsAEMode_A_DEP, "A_DEP"},
        {kEdsAEMode_DEP, "DEP"},
        {kEdsAEMode_Custom, "Custom"},
        {kEdsAEMode_Lock, "Lock"},
        {kEdsAEMode_Green, "Green"},
        {kEdsAEMode_NightPortrait, "NightPortrait"},
        {kEdsAEMode_Sports, "Sports"},
        {kEdsAEMode_Portrait, "Portrait"},
        {kEdsAEMode_Landscape, "Landscape"},
        {kEdsAEMode_Closeup, "Closeup"},
        {kEdsAEMode_FlashOff, "FlashOff"},
        {kEdsAEMode_CreativeAuto, "CreativeAuto"},
        {kEdsAEMode_Movie, "Movie"},
        {kEdsAEMode_PhotoInMovie, "PhotoInMovie"},
        {kEdsAEMode_SceneIntelligentAuto, "SceneIntelligentAuto"},
        {kEdsAEMode_SCN, "SCN"},
        {kEdsAEMode_NightScenes, "NightScenes"},
        {kEdsAEMode_BacklitScenes, "BacklitScenes"},
        {kEdsAEMode_Children, "Children"},
        {kEdsAEMode_Food, "Food"},
        {kEdsAEMode_CandlelightPortraits, "CandlelightPortraits"},
        {kEdsAEMode_CreativeFilter, "CreativeFilter"},
        {kEdsAEMode_RoughMonoChrome, "RoughMonoChrome"},
        {kEdsAEMode_SoftFocus, "SoftFocus"},
        {kEdsAEMode_ToyCamera, "ToyCamera"},
        {kEdsAEMode_Fisheye, "Fisheye"},
        {kEdsAEMode_WaterColor, "WaterColor"},
        {kEdsAEMode_Miniature, "Miniature"},
        {kEdsAEMode_Hdr_Standard, "Hdr_Standard"},
        {kEdsAEMode_Hdr_Vivid, "Hdr_Vivid"},
        {kEdsAEMode_Hdr_Bold, "Hdr_Bold"},
        {kEdsAEMode_Hdr_Embossed, "Hdr_Embossed"},
        {kEdsAEMode_Movie_Fantasy, "Movie_Fantasy"},
        {kEdsAEMode_Movie_Old, "Movie_Old"},
        {kEdsAEMode_Movie_Memory, "Movie_Memory"},
        {kEdsAEMode_Movie_DirectMono, "Movie_DirectMono"},
        {kEdsAEMode_Movie_Mini, "Movie_Mini"},
        {kEdsAEMode_PanningAssist, "PanningAssist"},
        {kEdsAEMode_GroupPhoto, "GroupPhoto"},
        {kEdsAEMode_Myself, "Myself"},
        {kEdsAEMode_PlusMovieAuto, "PlusMovieAuto"},
        {kEdsAEMode_SmoothSkin, "SmoothSkin"},
        {kEdsAEMode_Panorama, "Panorama"},
        {kEdsAEMode_Silent, "Silent"},
        {kEdsAEMode_Flexible, "Flexible"},
        {kEdsAEMode_OilPainting, "OilPainting"},
        {kEdsAEMode_Fireworks, "Fireworks"},
        {kEdsAEMode_StarPortrait, "StarPortrait"},
        {kEdsAEMode_StarNightscape, "StarNightScape"},
        {kEdsAEMode_StarTrails, "StarTrails"},
        {kEdsAEMode_StarTimelapseMovie, "StarTimelapseMovie"},
        {kEdsAEMode_BackgroundBlur, "BackgroundBlur"},
        {kEdsAEMode_Unknown, "Unknown"},
        {7, "Custom1"},
        {16, "Custom2"},
        {17, "Custom3"},
        {25, "SCNSpecialScene"}
    };

    LabelMap Labels::AFMode = {
        {0, "OneShot"},
        {1, "AIServo"},
        {2, "AIFocus"},
        {3, "ManualFocus"},
        {0xffffffff, "NotValid"}
    };

    LabelMap Labels::Bracket = {
        {kEdsBracket_AEB, "AEBracket"},
        {kEdsBracket_ISOB, "ISOBracket"},
        {kEdsBracket_WBB, "WBBracket"},
        {kEdsBracket_FEB, "FEBracket"},
        {kEdsBracket_Unknown, "BracketOff"}
    };

    LabelMap Labels::EvfAFMode = {
        {Evf_AFMode_Quick, "Quick"},
        {Evf_AFMode_Live, "OnePointAF"},
        {Evf_AFMode_LiveFace, "FaceTracking"},
        {Evf_AFMode_LiveMulti, "FlexiZoneMulti"},
        {Evf_AFMode_LiveZone, "ZoneAF"},
        {Evf_AFMode_LiveSingleExpandCross, "ExpandAFAreaCross"},
        {Evf_AFMode_LiveSingleExpandSurround, "ExpandAFAreaAround"},
        {Evf_AFMode_LiveZoneLargeH, "LargeZoneAFHorizontal"},
        {Evf_AFMode_LiveZoneLargeV, "LargeZoneAFVertical"},
        {Evf_AFMode_LiveCatchAF, "TrackingAF"},
        {Evf_AFMode_LiveSpotAF, "SpotAF"}
    };

    LabelMap Labels::EvfHistogramStatus = {
        {0, "Hide"},
        {1, "Normal"},
        {2, "Grayout"}
    };

    LabelMap Labels::EvfOutputDevice = {
        {0x00, "None"},
        {kEdsEvfOutputDevice_PC, "PC"},
        {kEdsEvfOutputDevice_TFT, "TFT"},
        {kEdsEvfOutputDevice_MOBILE, "Mobile"},
        {kEdsEvfOutputDevice_MOBILE2, "Mobile2"}
    };

    LabelMap Labels::EvfZoom = {
        {kEdsEvfZoom_Fit, "Fit"},
        {kEdsEvfZoom_x5, "x5"},
        {kEdsEvfZoom_x10, "x10"}
    };

    LabelMap Labels::ImageQuality = {
        {EdsImageQuality_LJ, "LargeJPEG"},/* Jpeg Large */
        {EdsImageQuality_M1J, "Middle1JPEG"},/* Jpeg Middle1 */
        {EdsImageQuality_M2J, "Middle2JPEG"},/* Jpeg Middle2 */
        {EdsImageQuality_SJ, "SmallJPEG"},/* Jpeg Small */
        {EdsImageQuality_LJF, "LargeJPEGFine"},/* Jpeg Large Fine */
        {EdsImageQuality_LJN, "LargeJPEGNormal"},/* Jpeg Large Normal */
        {EdsImageQuality_MJF, "MiddleJPEGFine"},/* Jpeg Middle Fine */
        {EdsImageQuality_MJN, "MiddleJPEGNormal"},/* Jpeg Middle Normal */
        {EdsImageQuality_SJF, "SmallJPEGFine"},/* Jpeg Small Fine */
        {EdsImageQuality_SJN, "SmallJPEGNormal"},/* Jpeg Small Normal */
        {EdsImageQuality_S1JF, "Small1JPEGFine"},/* Jpeg Small1 Fine */
        {EdsImageQuality_S1JN, "Small1JPEGNormal"},/* Jpeg Small1 Normal */
        {EdsImageQuality_S2JF, "Small2JPEGFine"},/* Jpeg Small2 */
        {EdsImageQuality_S3JF, "Small3JPEGFine"},/* Jpeg Small3 */

        /* RAW + Jpeg */
        {EdsImageQuality_LR, "RAW"},/* RAW */
        {EdsImageQuality_LRLJF, "RAWAndLargeJPEGFine"},/* RAW + Jpeg Large Fine */
        {EdsImageQuality_LRLJN, "RAWAndLargeJPEGNormal"},/* RAW + Jpeg Large Normal */
        {EdsImageQuality_LRMJF, "RAWAndMiddleJPEGFine"},/* RAW + Jpeg Middle Fine */
        {EdsImageQuality_LRMJN, "RAWAndMiddleJPEGNormal"},/* RAW + Jpeg Middle Normal */
        {EdsImageQuality_LRSJF, "RAWAndSmallJPEGFine"},/* RAW + Jpeg Small Fine */
        {EdsImageQuality_LRSJN, "RAWAndSmallJPEGNormal"},/* RAW + Jpeg Small Normal */
        {EdsImageQuality_LRS1JF, "RAWAndSmall1JPEGFine"},/* RAW + Jpeg Small1 Fine */
        {EdsImageQuality_LRS1JN, "RAWAndSmall1JPEGNormal"},/* RAW + Jpeg Small1 Normal */
        {EdsImageQuality_LRS2JF, "RAWAndSmall2JPEGFine"},/* RAW + Jpeg Small2 */
        {EdsImageQuality_LRS3JF, "RAWAndSmall3JPEGFine"},/* RAW + Jpeg Small3 */

        {EdsImageQuality_LRLJ, "RAWAndLargeJPEG"},/* RAW + Jpeg Large */
        {EdsImageQuality_LRM1J, "RAWAndMiddle1JPEG"},/* RAW + Jpeg Middle1 */
        {EdsImageQuality_LRM2J, "RAWAndMiddle2JPEG"},/* RAW + Jpeg Middle2 */
        {EdsImageQuality_LRSJ, "RAWAndSmallJPEG"},/* RAW + Jpeg Small */

        /* MRAW(SRAW1) + Jpeg */
        {EdsImageQuality_MR, "MR"},/* MRAW(SRAW1) */
        {EdsImageQuality_MRLJF, "MRLJF"},/* MRAW(SRAW1) + Jpeg Large Fine */
        {EdsImageQuality_MRLJN, "MRLJN"},/* MRAW(SRAW1) + Jpeg Large Normal */
        {EdsImageQuality_MRMJF, "MRMJF"},/* MRAW(SRAW1) + Jpeg Middle Fine */
        {EdsImageQuality_MRMJN, "MRMJN"},/* MRAW(SRAW1) + Jpeg Middle Normal */
        {EdsImageQuality_MRSJF, "MRSJF"},/* MRAW(SRAW1) + Jpeg Small Fine */
        {EdsImageQuality_MRSJN, "MRSJN"},/* MRAW(SRAW1) + Jpeg Small Normal */
        {EdsImageQuality_MRS1JF, "MRS1JF"},/* MRAW(SRAW1) + Jpeg Small1 Fine */
        {EdsImageQuality_MRS1JN, "MRS1JN"},/* MRAW(SRAW1) + Jpeg Small1 Normal */
        {EdsImageQuality_MRS2JF, "MRS2JF"},/* MRAW(SRAW1) + Jpeg Small2 */
        {EdsImageQuality_MRS3JF, "MRS3JF"},/* MRAW(SRAW1) + Jpeg Small3 */

        {EdsImageQuality_MRLJ, "MRLJ"},/* MRAW(SRAW1) + Jpeg Large */
        {EdsImageQuality_MRM1J, "MRM1J"},/* MRAW(SRAW1) + Jpeg Middle1 */
        {EdsImageQuality_MRM2J, "MRM2J"},/* MRAW(SRAW1) + Jpeg Middle2 */
        {EdsImageQuality_MRSJ, "MRSJ"},/* MRAW(SRAW1) + Jpeg Small */

        /* SRAW(SRAW2) + Jpeg */
        {EdsImageQuality_SR, "SR"},/* SRAW(SRAW2) */
        {EdsImageQuality_SRLJF, "SRLJF"},/* SRAW(SRAW2) + Jpeg Large Fine */
        {EdsImageQuality_SRLJN, "SRLJN"},/* SRAW(SRAW2) + Jpeg Large Normal */
        {EdsImageQuality_SRMJF, "SRMJF"},/* SRAW(SRAW2) + Jpeg Middle Fine */
        {EdsImageQuality_SRMJN, "SRMJN"},/* SRAW(SRAW2) + Jpeg Middle Normal */
        {EdsImageQuality_SRSJF, "SRSJF"},/* SRAW(SRAW2) + Jpeg Small Fine */
        {EdsImageQuality_SRSJN, "SRSJN"},/* SRAW(SRAW2) + Jpeg Small Normal */
        {EdsImageQuality_SRS1JF, "SRS1JF"},/* SRAW(SRAW2) + Jpeg Small1 Fine */
        {EdsImageQuality_SRS1JN, "SRS1JN"},/* SRAW(SRAW2) + Jpeg Small1 Normal */
        {EdsImageQuality_SRS2JF, "SRS2JF"},/* SRAW(SRAW2) + Jpeg Small2 */
        {EdsImageQuality_SRS3JF, "SRS3JF"},/* SRAW(SRAW2) + Jpeg Small3 */

        {EdsImageQuality_SRLJ, "SRLJ"},/* SRAW(SRAW2) + Jpeg Large */
        {EdsImageQuality_SRM1J, "SRM1J"},/* SRAW(SRAW2) + Jpeg Middle1 */
        {EdsImageQuality_SRM2J, "SRM2J"},/* SRAW(SRAW2) + Jpeg Middle2 */
        {EdsImageQuality_SRSJ, "SRSJ"},/* SRAW(SRAW2) + Jpeg Small */

        /* CRAW + Jpeg */
        {EdsImageQuality_CR, "CR"},/* CRAW */
        {EdsImageQuality_CRLJF, "CRLJF"},/* CRAW + Jpeg Large Fine */
        {EdsImageQuality_CRMJF, "CRMJF"},/* CRAW + Jpeg Middle Fine  */
        {EdsImageQuality_CRM1JF, "CRM1JF"},/* CRAW + Jpeg Middle1 Fine  */
        {EdsImageQuality_CRM2JF, "CRM2JF"},/* CRAW + Jpeg Middle2 Fine  */
        {EdsImageQuality_CRSJF, "CRSJF"},/* CRAW + Jpeg Small Fine  */
        {EdsImageQuality_CRS1JF, "CRS1JF"},/* CRAW + Jpeg Small1 Fine  */
        {EdsImageQuality_CRS2JF, "CRS2JF"},/* CRAW + Jpeg Small2 Fine  */
        {EdsImageQuality_CRS3JF, "CRS3JF"},/* CRAW + Jpeg Small3 Fine  */
        {EdsImageQuality_CRLJN, "CRLJN"},/* CRAW + Jpeg Large Normal */
        {EdsImageQuality_CRMJN, "CRMJN"},/* CRAW + Jpeg Middle Normal */
        {EdsImageQuality_CRM1JN, "CRM1JN"},/* CRAW + Jpeg Middle1 Normal */
        {EdsImageQuality_CRM2JN, "CRM2JN"},/* CRAW + Jpeg Middle2 Normal */
        {EdsImageQuality_CRSJN, "CRSJN"},/* CRAW + Jpeg Small Normal */
        {EdsImageQuality_CRS1JN, "CRS1JN"},/* CRAW + Jpeg Small1 Normal */

        {EdsImageQuality_CRLJ, "CRLJ"},/* CRAW + Jpeg Large */
        {EdsImageQuality_CRM1J, "CRM1J"},/* CRAW + Jpeg Middle1 */
        {EdsImageQuality_CRM2J, "CRM2J"},/* CRAW + Jpeg Middle2 */
        {EdsImageQuality_CRSJ, "CRSJ"},/* CRAW + Jpeg Small */

        /* HEIF */
        {EdsImageQuality_HEIFL, "HEIFL"},/* HEIF Large */
        {EdsImageQuality_RHEIFL, "RHEIFL"},/* RAW  + HEIF Large */
        {EdsImageQuality_CRHEIFL, "CRHEIFL"},/* CRAW + HEIF Large */

        {EdsImageQuality_HEIFLF, "HEIFLF"},/* HEIF Large Fine */
        {EdsImageQuality_HEIFLN, "HEIFLN"},/* HEIF Large Normal */
        {EdsImageQuality_HEIFMF, "HEIFMF"},/* HEIF Middle Fine */
        {EdsImageQuality_HEIFMN, "HEIFMN"},/* HEIF Middle Normal */
        {EdsImageQuality_HEIFS1F, "HEIFS1F"},/* HEIF Small1 Fine */
        {EdsImageQuality_HEIFS1N, "HEIFS1N"},/* HEIF Small1 Normal */
        {EdsImageQuality_HEIFS2F, "HEIFS2F"},/* HEIF Small2 Fine */
        {EdsImageQuality_RHEIFLF, "RHEIFLF"},/* RAW + HEIF Large Fine */
        {EdsImageQuality_RHEIFLN, "RHEIFLN"},/* RAW + HEIF Large Normal */
        {EdsImageQuality_RHEIFMF, "RHEIFMF"},/* RAW + HEIF Middle Fine */
        {EdsImageQuality_RHEIFMN, "RHEIFMN"},/* RAW + HEIF Middle Normal */
        {EdsImageQuality_RHEIFS1F, "RHEIFS1F"},/* RAW + HEIF Small1 Fine */
        {EdsImageQuality_RHEIFS1N, "RHEIFS1N"},/* RAW + HEIF Small1 Normal */
        {EdsImageQuality_RHEIFS2F, "RHEIFS2F"},/* RAW + HEIF Small2 Fine */
        {EdsImageQuality_CRHEIFLF, "CRHEIFLF"},/* CRAW + HEIF Large Fine */
        {EdsImageQuality_CRHEIFLN, "CRHEIFLN"},/* CRAW + HEIF Large Normal */
        {EdsImageQuality_CRHEIFMF, "CRHEIFMF"},/* CRAW + HEIF Middle Fine */
        {EdsImageQuality_CRHEIFMN, "CRHEIFMN"},/* CRAW + HEIF Middle Normal */
        {EdsImageQuality_CRHEIFS1F, "CRHEIFS1F"},/* CRAW + HEIF Small1 Fine */
        {EdsImageQuality_CRHEIFS1N, "CRHEIFS1N"},/* CRAW + HEIF Small1 Normal */
        {EdsImageQuality_CRHEIFS2F, "CRHEIFS2F"},/* CRAW + HEIF Small2 Fine */

        {EdsImageQuality_Unknown, "Unknown"}
    };

    LabelMap Labels::ColorSpace = {
        {kEdsColorSpace_sRGB, "sRGB"},
        {kEdsColorSpace_AdobeRGB, "AdobeRGB"},
        {kEdsColorSpace_Unknown, "Unknown"}
    };

    LabelMap Labels::DCStrobe = {
        {kEdsDcStrobeAuto, "Auto"},
        {kEdsDcStrobeOn, "On"},
        {kEdsDcStrobeSlowsynchro, "SlowSynchro"},
        {kEdsDcStrobeOff, "Off"},
    };

    LabelMap Labels::DriveMode = {
        {0x00000000, "SingleShooting"},
        {0x00000001, "ContinuousShooting"},
        {0x00000002, "Video"},
        {0x00000004, "HighSpeedContinuous"},
        {0x00000005, "LowSpeedContinuous"},
        {0x00000006, "SingleSilentShooting"},
        {0x00000007, "SelfTimerContinuous"},
        {0x00000010, "SelfTimer10sec"},
        {0x00000011, "SelfTimer2sec"},
        {0x00000012, "SuperHighSpeed14fps"},
        {0x00000013, "SilentSingleShooting"},
        {0x00000014, "SilentContinuousShooting"},
        {0x00000015, "SilentHSContinuous"},
        {0x00000016, "SilentLSContinuous"}
    };

    LabelMap Labels::MeteringMode = {
        {1, "Spot"},
        {3, "Evaluative"},
        {4, "Partial"},
        {5, "CenterWeightedAverage"},
        {0xFFFFFFFF, "NotValid"}
    };

    LabelMap Labels::MirrorUpStatus = {
        {kEdsMirrorLockupStateDisable, "Disable"},
        {kEdsMirrorLockupStateEnable, "Enable"},
        {kEdsMirrorLockupStateDuringShooting, "DuringShooting"}
    };

    LabelMap Labels::MovieQuality = {
        /*
        {0x00000200,"1920x1080 23.98fps"},
        {0x00000210,"1920x1080 23.98fps For editing(ALL-I)"},
        {0x00000230,"1920x1080 23.98fps Standard(IPB)"},
        {0x00000310,"1920x1080 24.00fps For editing(ALL-I)"},
        {0x00000330,"1920x1080 24.00fps Standard(IPB)"},
        {0x00000400,"1920x1080 25.00fps"},
        {0x00000410,"1920x1080 25.00fps For editing(ALL-I)"},
        {0x00000430,"1920x1080 25.00fps Standard(IPB)"},
        {0x00000500,"1920x1080 29.97fps"},
        {0x00000510,"1920x1080 29.97fps For editing(ALL-I)"},
        {0x00000530,"1920x1080 29.97fps Standard(IPB)"},
        {0x00000610,"1920x1080 50.00fps For editing(ALL-I)"},
        {0x00000630,"1920x1080 50.00fps Standard(IPB)"},
        {0x00000710,"1920x1080 59.94fps For editing(ALL-I)"},
        {0x00000730,"1920x1080 59.94fps Standard(IPB)"},
        {0x00001210,"1920x1080 23.98fps For editing(ALL-I)"},
        {0x00001230,"1920x1080 23.98fps Standard(IPB)"},
        {0x00001310,"1920x1080 24.00fps For editing(ALL-I)"},
        {0x00001330,"1920x1080 24.00fps Standard(IPB)"},
        {0x00001410,"1920x1080 25.00fps For editing(ALL-I)"},
        {0x00001430,"1920x1080 25.00fps Standard(IPB)"},
        {0x00001431,"1920x1080 25.00fps Light(IPB)"},
        {0x00001510,"1920x1080 29.97fps For editing(ALL-I)"},
        {0x00001530,"1920x1080 29.97fps Standard(IPB)"},
        {0x00001531,"1920x1080 29.97fps Light(IPB)"},
        {0x00001610,"1920x1080 50.00fps For editing(ALL-I)"},
        {0x00001630,"1920x1080 50.00fps Standard(IPB)"},
        {0x00001710,"1920x1080 59.94fps For editing(ALL-I)"},
        {0x00001730,"1920x1080 59.94fps Standard(IPB)"},
        {0x00001810,"1920x1080 100.0fps For editing(ALL-I)"},
        {0x00001910,"1920x1080 119.9fps For editing(ALL-I)"},
        {0x00010600,"1280x720 50.00fps"},
        {0x00010700,"1280x720 59.94fps"},
        {0x00010810,"1280x720 100.0fps For editing(ALL-I)"},
        {0x00010910,"1280x720 119.9fps For editing(ALL-I)"},
        {0x00011430,"1280x720 25.00fps Standard(IPB)"},
        {0x00011431,"1280x720 50.00fps Standard(IPB)"},
        {0x00011530,"1280x720 29.97fps Standard(IPB)"},
        {0x00011531,"1280x720 29.97fps Light(IPB)"},
        {0x00011610,"1280x720 50.00fps For editing(ALL-I)"},
        {0x00011630,"1280x720 50.00fps Standard(IPB)"},
        {0x00011710,"1280x720 59.94fps For editing(ALL-I)"},
        {0x00011730,"1280x720 59.94fps Standard(IPB)"},
        {0x00011810,"1280x720 100.0fps For editing(ALL-I)"},
        {0x00011830,"1280x720 100.0fps Standard(IPB)"},
        {0x00011910,"1280x720 119.9fps For editing(ALL-I)"},
        {0x00011930,"1280x720 119.9fps Standard(IPB)"},
        {0x00020400,"640x480 25.00fps"},
        {0x00020500,"640x480 29.97ffps"},
        {0x00030240,"4096x2160 23.98fps Motion JPEG"},
        {0x00030340,"4096x2160 24.00fps Motion JPEG"},
        {0x00030440,"4096x2160 25.00fps Motion JPEG"},
        {0x00030540,"4096x2160 29.97fps Motion JPEG"},
        {0x00031210,"4096x2160 23.98fps For editing(ALL-I)"},
        {0x00031230,"4096x2160 23.98fps Standard(IPB)"},
        {0x00031310,"4096x2160 24.00fps For editing(ALL-I)"},
        {0x00031330,"4096x2160 24.00fps Standard(IPB)"},
        {0x00031410,"4096x2160 25.00fps For editing(ALL-I)"},
        {0x00031430,"4096x2160 25.00fps Standard(IPB)"},
        {0x00031510,"4096x2160 29.97fps For editing(ALL-I)"},
        {0x00031530,"4096x2160 29.970fps Standard(IPB)"},
        {0x00031610,"4096x2160 50.00fps For editing(ALL-I)"},
        {0x00031630,"4096x2160 50.00fps Standard(IPB)"},
        {0x00031710,"4096x2160 59.94fps For editing(ALL-I)"},
        {0x00031730,"4096x2160 59.94fps Standard(IPB)"},
        {0x00031810,"4096x2160 100.0fps For editing(ALL-I)"},
        {0x00031910,"4096x2160 119.9fps For editing(ALL-I)"},
        {0x00051210,"3840x2160 23.98fps For editing(ALL-I)"},
        {0x00051230,"3840x2160 23.98fps Standard(IPB)"},
        {0x00051310,"3840x2160 24.00fps For editing(ALL-I)"},
        {0x00051330,"3840x2160 24.00fps Standard(IPB)"},
        {0x00051410,"3840x2160 25.00fps For editing(ALL-I)"},
        {0x00051430,"3840x2160 25.00fps Standard(IPB)"},
        {0x00051510,"3840x2160 29.97fps For editing(ALL-I)"},
        {0x00051530,"3840x2160 29.97fps Standard(IPB)"},
        {0x00051610,"3840x2160 50.00fps For editing(ALL-I)"},
        {0x00051630,"3840x2160 50.00fps Standard(IPB)"},
        {0x00051710,"3840x2160 59.94fps For editing(ALL-I)"},
        {0x00051730,"3840x2160 59.94fps Standard(IPB)"},
        {0x00051810,"3840x2160 100.0fps For editing(ALL-I)"},
        {0x00051910,"3840x2160 119.9fps For editing(ALL-I)"},
        {0x00081210,"8192x4320 23.98fps For editing(ALL-I)"},
        {0x00081230,"8192x4320 23.98fps Standard(IPB)"},
        {0x00081310,"8192x4320 24.00fps For editing(ALL-I)"},
        {0x00081330,"8192x4320 24.00fps Standard(IPB)"},
        {0x00081410,"8192x4320 25.00fps For editing(ALL-I)"},
        {0x00081430,"8192x4320 25.00fps Standard(IPB)"},
        {0x00081510,"8192x4320 29.97fps For editing(ALL-I)"},
        {0x00081530,"8192x4320 29.97fps Standard(IPB)"},
        {0x00091210,"7680x4320 23.98fps For editing(ALL-I)"},
        {0x00091230,"7680x4320 23.98fps Standard(IPB)"},
        {0x00091410,"7680x4320 25.00fps For editing(ALL-I)"},
        {0x00091430,"7680x4320 25.00fps Standard(IPB)"},
        {0x00091510,"7680x4320 29.97fps For editing(ALL-I)"},
        {0x00091530,"7680x4320 29.97fps Standard(IPB)"},
        {0x000a3270,"23.98fps (RAW)"},
        {0x000a3370,"24.00fps (RAW)"},
        {0x000a3470,"25.00fps (RAW)"},
        {0x000a3570,"29.97fps (RAW)"},
        {0x000a3670,"50.00fps (RAW)"},
        {0x000a3770,"59.94fps (RAW)"},
        {0x08001210,"1920x1080 23.98fps For editing(ALL-I)Crop"},
        {0x08001230,"1920x1080 23.98fps Standard(IPB)Crop"},
        {0x08001410,"1920x1080 24.00fps For editing(ALL-I)Crop"},
        {0x08001430,"1920x1080 24.00fps Standard(IPB)Crop"},
        {0x08001431,"1920x1080 25.00fps For editing(ALL-I)Crop"},
        {0x08001510,"1920x1080 25.00fps Standard(IPB)Crop"},
        {0x08001530,"1920x1080 29.97fps For editing(ALL-I)Crop"},
        {0x08001531,"1920x1080 29.94fps Standard(IPB)Crop"},
        {0x08001610,"1920x1080 50.00fps For editing(ALL-I)Crop"},
        {0x08001630,"1920x1080 50.00fps Standard(IPB)Crop"},
        {0x08001710,"1920x1080 59.94fps For editing(ALL-I)Crop"},
        {0x08001730,"1920x1080 59.94fps Standard(IPB)Crop"},
        {0x08031210,"4096x2160 23.98fps For editing(ALL-I) Crop"},
        {0x08031230,"4096x2160 23.98fps Standard(IPB)Crop"},
        {0x08031310,"4096x2160 24.00fps For editing(ALL-I)Crop"},
        {0x08031330,"4096x2160 24.00fps Standard(IPB)Crop"},
        {0x08031410,"4096x2160 25.00fps For editing(ALL-I)Crop"},
        {0x08031430,"4096x2160 25.00fps Standard(IPB)Crop"},
        {0x08031510,"4096x2160 29.97fps For editing(ALL-I)Crop"},
        {0x08031530,"4096x2160 29.94fps Standard(IPB)Crop"},
        {0x08031610,"4096x2160 50.00fps For editing(ALL-I)Crop"},
        {0x08031630,"4096x2160 50.00fps Standard(IPB)Crop"},
        {0x08031710,"4096x2160 59.94fps For editing(ALL-I)Crop"},
        {0x08031730,"4096x2160 59.94fps Standard(IPB)Crop"},
        {0x08051210,"3840x2160 23.98fps For editing(ALL-I)"},
        {0x08051230,"3840x2160 23.98fps Standard(IPB)"},
        {0x08051410,"3840x2160 25.00fps For editing(ALL-I)"},
        {0x08051430,"3840x2160 25.00fps Standard(IPB)"},
        {0x08051510,"3840x2160 29.97fps For editing(ALL-I)"},
        {0x08051530,"3840x2160 29.97fps Standard(IPB)"},
        {0x08051610,"3840x2160 50.00fps For editing(ALL-I)"},
        {0x08051630,"3840x2160 50.00fps Standard(IPB)"},
        {0x08051710,"3840x2160 59.94fps For editing(ALL-I)"},
        {0x08051730,"3840x2160 59.94fps Standard(IPB)"}
         */
    };

    LabelMap Labels::NoiseReduction = {
        {0, "Off"},
        {1, "On1"},
        {2, "On2"},
        {3, "On3"},
        {4, "Auto"}
    };

    LabelMap Labels::LensBarrelStatus{
        {kDcLensBarrelStateInner, "Inner"},
        {kDcLensBarrelStateOuter, "Outer"}
    };

    LabelMap Labels::LensStatus = {
        {0, "NotAttached"},
        {1, "Attached"}
    };

    LabelMap Labels::PictureStyle = {
        {kEdsPictureStyle_Standard, "Standard"},
        {kEdsPictureStyle_Portrait, "Portrait"},
        {kEdsPictureStyle_Landscape, "Landscape"},
        {kEdsPictureStyle_Neutral, "Neutral"},
        {kEdsPictureStyle_Faithful, "Faithful"},
        {kEdsPictureStyle_Monochrome, "Monochrome"},
        {kEdsPictureStyle_Auto, "Auto"},
        {kEdsPictureStyle_FineDetail, "FineDetail"},
        {kEdsPictureStyle_User1, "User1"},
        {kEdsPictureStyle_User2, "User2"},
        {kEdsPictureStyle_User3, "User3"},
        {kEdsPictureStyle_PC1, "PC1"},
        {kEdsPictureStyle_PC2, "PC2"},
        {kEdsPictureStyle_PC3, "PC3"},
    };

    LabelMap Labels::Record = {
        {0, "End"},
        {4, "Begin"}
    };

    LabelMap Labels::RedEye = {
        {0, "Off"},
        {1, "On"},
        {0xFFFFFFFF, "Invalid"}
    };

    LabelMap Labels::SaveTo = {
        {kEdsSaveTo_Host, "Host"},
        {kEdsSaveTo_Camera, "Camera"},
        {kEdsSaveTo_Both, "Both"}
    };

    LabelMap Labels::WhiteBalance = {
        {kEdsWhiteBalance_Auto, "AutoAmbiencePriority"},
        {kEdsWhiteBalance_Daylight, "Daylight"},
        {kEdsWhiteBalance_Cloudy, "Cloudy"},
        {kEdsWhiteBalance_Tangsten, "Tungsten"},
        {kEdsWhiteBalance_Fluorescent, "Fluorescent"},
        {kEdsWhiteBalance_Strobe, "Flash"},
        {kEdsWhiteBalance_WhitePaper, "WhitePaper"},
        {kEdsWhiteBalance_Shade, "Shade"},
        {kEdsWhiteBalance_ColorTemp, "ColorTemperature"},
        {kEdsWhiteBalance_PCSet1, "CustomPC1"},
        {kEdsWhiteBalance_PCSet2, "CustomPC2"},
        {kEdsWhiteBalance_PCSet3, "CustomPC3"},
        {kEdsWhiteBalance_WhitePaper2, "WhitePaper2"},
        {kEdsWhiteBalance_WhitePaper3, "WhitePaper3"},
        {kEdsWhiteBalance_WhitePaper4, "WhitePaper4"},
        {kEdsWhiteBalance_WhitePaper5, "WhitePaper5"},
        {kEdsWhiteBalance_PCSet4, "CustomPC4"},
        {kEdsWhiteBalance_PCSet5, "CustomPC5"},
        {kEdsWhiteBalance_AwbWhite, "AutoWhitePriority"},
        {kEdsWhiteBalance_Click, "Click"},
        {kEdsWhiteBalance_Pasted, "Pasted"}
    };

    std::unordered_map<int, LabelMap> Labels::Option = {
        {kEdsPropID_AEMode, AEMode},
        {kEdsPropID_AEModeSelect, AEModeSelect},
        {kEdsPropID_AFMode, AFMode},
        {kEdsPropID_BatteryQuality, BatteryQuality},
        {kEdsPropID_Bracket, Bracket},
        {kEdsPropID_ColorSpace, ColorSpace},
        {kEdsPropID_DC_Strobe, DCStrobe},
        {kEdsPropID_DriveMode, DriveMode},
        {kEdsPropID_Evf_AFMode, EvfAFMode},
        {kEdsPropID_Evf_HistogramStatus, EvfHistogramStatus},
        {kEdsPropID_Evf_OutputDevice, EvfOutputDevice},
        {kEdsPropID_Evf_WhiteBalance, WhiteBalance},
        {kEdsPropID_Evf_Zoom, EvfZoom},
        {kEdsPropID_ImageQuality, ImageQuality},
        {kEdsPropID_LensBarrelStatus, LensBarrelStatus},
        {kEdsPropID_LensStatus, LensStatus},
        {kEdsPropID_MeteringMode, MeteringMode},
        {kEdsPropID_MirrorLockUpState, MirrorUpStatus},
        {kEdsPropID_MovieParam, MovieQuality},
        {kEdsPropID_NoiseReduction, NoiseReduction},
        {kEdsPropID_RedEye, RedEye},
        {kEdsPropID_Record, Record},
        {kEdsPropID_SaveTo, SaveTo},
        {kEdsPropID_WhiteBalance, WhiteBalance}
    };

    LabelMap Labels::Error = {

        /* Miscellaneous errors */
        {EDS_ERR_UNIMPLEMENTED, "UNIMPLEMENTED"},
        {EDS_ERR_INTERNAL_ERROR, "INTERNAL_ERROR"},
        {EDS_ERR_MEM_ALLOC_FAILED, "MEM_ALLOC_FAILED"},
        {EDS_ERR_MEM_FREE_FAILED, "MEM_FREE_FAILED"},
        {EDS_ERR_OPERATION_CANCELLED, "OPERATION_CANCELLED"},
        {EDS_ERR_INCOMPATIBLE_VERSION, "INCOMPATIBLE_VERSION"},
        {EDS_ERR_NOT_SUPPORTED, "NOT_SUPPORTED"},
        {EDS_ERR_UNEXPECTED_EXCEPTION, "UNEXPECTED_EXCEPTION"},
        {EDS_ERR_PROTECTION_VIOLATION, "PROTECTION_VIOLATION"},
        {EDS_ERR_MISSING_SUBCOMPONENT, "MISSING_SUBCOMPONENT"},
        {EDS_ERR_SELECTION_UNAVAILABLE, "SELECTION_UNAVAILABLE"},

        /* File errors */
        {EDS_ERR_FILE_IO_ERROR, "FILE_IO_ERROR"},
        {EDS_ERR_FILE_TOO_MANY_OPEN, "FILE_TOO_MANY_OPEN"},
        {EDS_ERR_FILE_NOT_FOUND, "FILE_NOT_FOUND"},
        {EDS_ERR_FILE_OPEN_ERROR, "FILE_OPEN_ERROR"},
        {EDS_ERR_FILE_CLOSE_ERROR, "FILE_CLOSE_ERROR"},
        {EDS_ERR_FILE_SEEK_ERROR, "FILE_SEEK_ERROR"},
        {EDS_ERR_FILE_TELL_ERROR, "FILE_TELL_ERROR"},
        {EDS_ERR_FILE_READ_ERROR, "FILE_READ_ERROR"},
        {EDS_ERR_FILE_WRITE_ERROR, "FILE_WRITE_ERROR"},
        {EDS_ERR_FILE_PERMISSION_ERROR, "FILE_PERMISSION_ERROR"},
        {EDS_ERR_FILE_DISK_FULL_ERROR, "FILE_DISK_FULL_ERROR"},
        {EDS_ERR_FILE_ALREADY_EXISTS, "FILE_ALREADY_EXISTS"},
        {EDS_ERR_FILE_FORMAT_UNRECOGNIZED, "FILE_FORMAT_UNRECOGNIZED"},
        {EDS_ERR_FILE_DATA_CORRUPT, "FILE_DATA_CORRUPT"},
        {EDS_ERR_FILE_NAMING_NA, "FILE_NAMING_NA"},

        /* Directory errors */
        {EDS_ERR_DIR_NOT_FOUND, "DIR_NOT_FOUND"},
        {EDS_ERR_DIR_IO_ERROR, "DIR_IO_ERROR"},
        {EDS_ERR_DIR_ENTRY_NOT_FOUND, "DIR_ENTRY_NOT_FOUND"},
        {EDS_ERR_DIR_ENTRY_EXISTS, "DIR_ENTRY_EXISTS"},
        {EDS_ERR_DIR_NOT_EMPTY, "DIR_NOT_EMPTY"},

        /* Property errors */
        {EDS_ERR_PROPERTIES_UNAVAILABLE, "PROPERTIES_UNAVAILABLE"},
        {EDS_ERR_PROPERTIES_MISMATCH, "PROPERTIES_MISMATCH"},
        {EDS_ERR_PROPERTIES_NOT_LOADED, "PROPERTIES_NOT_LOADED"},

        /* Function Parameter errors */
        {EDS_ERR_INVALID_PARAMETER, "INVALID_PARAMETER"},
        {EDS_ERR_INVALID_HANDLE, "INVALID_HANDLE"},
        {EDS_ERR_INVALID_POINTER, "INVALID_POINTER"},
        {EDS_ERR_INVALID_INDEX, "INVALID_INDEX"},
        {EDS_ERR_INVALID_LENGTH, "INVALID_LENGTH"},
        {EDS_ERR_INVALID_FN_POINTER, "INVALID_FN_POINTER"},
        {EDS_ERR_INVALID_SORT_FN, "INVALID_SORT_FN"},

        /* Device errors */
        {EDS_ERR_DEVICE_NOT_FOUND, "DEVICE_NOT_FOUND"},
        {EDS_ERR_DEVICE_BUSY, "DEVICE_BUSY"},
        {EDS_ERR_DEVICE_INVALID, "DEVICE_INVALID"},
        {EDS_ERR_DEVICE_EMERGENCY, "DEVICE_EMERGENCY"},
        {EDS_ERR_DEVICE_MEMORY_FULL, "DEVICE_MEMORY_FULL"},
        {EDS_ERR_DEVICE_INTERNAL_ERROR, "DEVICE_INTERNAL_ERROR"},
        {EDS_ERR_DEVICE_INVALID_PARAMETER, "DEVICE_INVALID_PARAMETER"},
        {EDS_ERR_DEVICE_NO_DISK, "DEVICE_NO_DISK"},
        {EDS_ERR_DEVICE_DISK_ERROR, "DEVICE_DISK_ERROR"},
        {EDS_ERR_DEVICE_CF_GATE_CHANGED, "DEVICE_CF_GATE_CHANGED"},
        {EDS_ERR_DEVICE_DIAL_CHANGED, "DEVICE_DIAL_CHANGED"},
        {EDS_ERR_DEVICE_NOT_INSTALLED, "DEVICE_NOT_INSTALLED"},
        {EDS_ERR_DEVICE_STAY_AWAKE, "DEVICE_STAY_AWAKE"},
        {EDS_ERR_DEVICE_NOT_RELEASED, "DEVICE_NOT_RELEASED"},

        /* Stream errors */
        {EDS_ERR_STREAM_IO_ERROR, "STREAM_IO_ERROR"},
        {EDS_ERR_STREAM_NOT_OPEN, "STREAM_NOT_OPEN"},
        {EDS_ERR_STREAM_ALREADY_OPEN, "STREAM_ALREADY_OPEN"},
        {EDS_ERR_STREAM_OPEN_ERROR, "STREAM_OPEN_ERROR"},
        {EDS_ERR_STREAM_CLOSE_ERROR, "STREAM_CLOSE_ERROR"},
        {EDS_ERR_STREAM_SEEK_ERROR, "STREAM_SEEK_ERROR"},
        {EDS_ERR_STREAM_TELL_ERROR, "STREAM_TELL_ERROR"},
        {EDS_ERR_STREAM_READ_ERROR, "STREAM_READ_ERROR"},
        {EDS_ERR_STREAM_WRITE_ERROR, "STREAM_WRITE_ERROR"},
        {EDS_ERR_STREAM_PERMISSION_ERROR, "STREAM_PERMISSION_ERROR"},
        {EDS_ERR_STREAM_COULDNT_BEGIN_THREAD, "STREAM_COULDNT_BEGIN_THREAD"},
        {EDS_ERR_STREAM_BAD_OPTIONS, "STREAM_BAD_OPTIONS"},
        {EDS_ERR_STREAM_END_OF_STREAM, "STREAM_END_OF_STREAM"},

        /* Communications errors */
        {EDS_ERR_COMM_PORT_IS_IN_USE, "COMM_PORT_IS_IN_USE"},
        {EDS_ERR_COMM_DISCONNECTED, "COMM_DISCONNECTED"},
        {EDS_ERR_COMM_DEVICE_INCOMPATIBLE, "COMM_DEVICE_INCOMPATIBLE"},
        {EDS_ERR_COMM_BUFFER_FULL, "COMM_BUFFER_FULL"},
        {EDS_ERR_COMM_USB_BUS_ERR, "COMM_USB_BUS_ERR"},

        /* Lock/Unlock */
        {EDS_ERR_USB_DEVICE_LOCK_ERROR, "USB_DEVICE_LOCK_ERROR"},
        {EDS_ERR_USB_DEVICE_UNLOCK_ERROR, "USB_DEVICE_UNLOCK_ERROR"},

        /* STI/WIA */
        {EDS_ERR_STI_UNKNOWN_ERROR, "STI_UNKNOWN_ERROR"},
        {EDS_ERR_STI_INTERNAL_ERROR, "STI_INTERNAL_ERROR"},
        {EDS_ERR_STI_DEVICE_CREATE_ERROR, "STI_DEVICE_CREATE_ERROR"},
        {EDS_ERR_STI_DEVICE_RELEASE_ERROR, "STI_DEVICE_RELEASE_ERROR"},
        {EDS_ERR_DEVICE_NOT_LAUNCHED, "DEVICE_NOT_LAUNCHED"},

        {EDS_ERR_ENUM_NA, "ENUM_NA"},
        {EDS_ERR_INVALID_FN_CALL, "INVALID_FN_CALL"},
        {EDS_ERR_HANDLE_NOT_FOUND, "HANDLE_NOT_FOUND"},
        {EDS_ERR_INVALID_ID, "INVALID_ID"},
        {EDS_ERR_WAIT_TIMEOUT_ERROR, "WAIT_TIMEOUT_ERROR"},

        /* PTP */
        {EDS_ERR_SESSION_NOT_OPEN, "SESSION_NOT_OPEN"},
        {EDS_ERR_INVALID_TRANSACTIONID, "INVALID_TRANSACTIONID"},
        {EDS_ERR_INCOMPLETE_TRANSFER, "INCOMPLETE_TRANSFER"},
        {EDS_ERR_INVALID_STRAGEID, "INVALID_STRAGEID"},
        {EDS_ERR_DEVICEPROP_NOT_SUPPORTED, "DEVICEPROP_NOT_SUPPORTED"},
        {EDS_ERR_INVALID_OBJECTFORMATCODE, "INVALID_OBJECTFORMATCODE"},
        {EDS_ERR_SELF_TEST_FAILED, "SELF_TEST_FAILED"},
        {EDS_ERR_PARTIAL_DELETION, "PARTIAL_DELETION"},
        {EDS_ERR_SPECIFICATION_BY_FORMAT_UNSUPPORTED, "SPECIFICATION_BY_FORMAT_UNSUPPORTED"},
        {EDS_ERR_NO_VALID_OBJECTINFO, "NO_VALID_OBJECTINFO"},
        {EDS_ERR_INVALID_CODE_FORMAT, "INVALID_CODE_FORMAT"},
        {EDS_ERR_UNKNOWN_VENDOR_CODE, "UNKNOWN_VENDOR_CODE"},
        {EDS_ERR_CAPTURE_ALREADY_TERMINATED, "CAPTURE_ALREADY_TERMINATED"},
        {EDS_ERR_PTP_DEVICE_BUSY, "PTP_DEVICE_BUSY"},
        {EDS_ERR_INVALID_PARENTOBJECT, "INVALID_PARENTOBJECT"},
        {EDS_ERR_INVALID_DEVICEPROP_FORMAT, "INVALID_DEVICEPROP_FORMAT"},
        {EDS_ERR_INVALID_DEVICEPROP_VALUE, "INVALID_DEVICEPROP_VALUE"},
        {EDS_ERR_SESSION_ALREADY_OPEN, "SESSION_ALREADY_OPEN"},
        {EDS_ERR_TRANSACTION_CANCELLED, "TRANSACTION_CANCELLED"},
        {EDS_ERR_SPECIFICATION_OF_DESTINATION_UNSUPPORTED, "SPECIFICATION_OF_DESTINATION_UNSUPPORTED"},
        {EDS_ERR_NOT_CAMERA_SUPPORT_SDK_VERSION, "NOT_CAMERA_SUPPORT_SDK_VERSION"},

        /* PTP Vendor */
        {EDS_ERR_UNKNOWN_COMMAND, "UNKNOWN_COMMAND"},
        {EDS_ERR_OPERATION_REFUSED, "OPERATION_REFUSED"},
        {EDS_ERR_LENS_COVER_CLOSE, "LENS_COVER_CLOSE"},
        {EDS_ERR_LOW_BATTERY, "LOW_BATTERY"},
        {EDS_ERR_OBJECT_NOTREADY, "OBJECT_NOTREADY"},
        {EDS_ERR_CANNOT_MAKE_OBJECT, "CANNOT_MAKE_OBJECT"},
        {EDS_ERR_MEMORYSTATUS_NOTREADY, "MEMORYSTATUS_NOTREADY"},

        /* Take Picture errors */
        {EDS_ERR_TAKE_PICTURE_AF_NG, "TAKE_PICTURE_AF_NG"},
        {EDS_ERR_TAKE_PICTURE_RESERVED, "TAKE_PICTURE_RESERVED"},
        {EDS_ERR_TAKE_PICTURE_MIRROR_UP_NG, "TAKE_PICTURE_MIRROR_UP_NG"},
        {EDS_ERR_TAKE_PICTURE_SENSOR_CLEANING_NG, "TAKE_PICTURE_SENSOR_CLEANING_NG"},
        {EDS_ERR_TAKE_PICTURE_SILENCE_NG, "TAKE_PICTURE_SILENCE_NG"},
        {EDS_ERR_TAKE_PICTURE_NO_CARD_NG, "TAKE_PICTURE_NO_CARD_NG"},
        {EDS_ERR_TAKE_PICTURE_CARD_NG, "TAKE_PICTURE_CARD_NG"},
        {EDS_ERR_TAKE_PICTURE_CARD_PROTECT_NG, "TAKE_PICTURE_CARD_PROTECT_NG"},
        {EDS_ERR_TAKE_PICTURE_MOVIE_CROP_NG, "TAKE_PICTURE_MOVIE_CROP_NG"},
        {EDS_ERR_TAKE_PICTURE_STROBO_CHARGE_NG, "TAKE_PICTURE_STROBO_CHARGE_NG"},
        {EDS_ERR_TAKE_PICTURE_NO_LENS_NG, "TAKE_PICTURE_NO_LENS_NG"},
        {EDS_ERR_TAKE_PICTURE_SPECIAL_MOVIE_MODE_NG, "TAKE_PICTURE_SPECIAL_MOVIE_MODE_NG"},
        {EDS_ERR_TAKE_PICTURE_LV_REL_PROHIBIT_MODE_NG, "TAKE_PICTURE_LV_REL_PROHIBIT_MODE_NG"}
    };

    LabelMap Labels::StorageType = {
        {0, "NoMemoryCard"},
        {1, "SDCard"},
        {2, "CompactFlash"},
    };

    LabelMap Labels::ImageFormat = {
        {0x00000000, "Unknown"},
        {0x00000001, "Jpeg"},
        {0x00000002, "CRW"},
        {0x00000004, "RAW"},
        {0x00000006, "CR2"}
    };
    LabelMap Labels::ImageSize = {
        {0, "Large"},
        {1, "Middle"},
        {2, "Small"},
        {5, "Middle1"},
        {6, "Middle2"},
        {14, "Small1"},
        {15, "Small2"},
        {16, "Small3"},
        {0xffffffff, "Unknown"}
    };
    LabelMap Labels::ImageCompression = {
        {2, "Normal"},
        {3, "Fine"},
        {4, "Lossless"},
        {5, "SuperFine"},
        {0xffffffff, "Unknown"}
    };
}
