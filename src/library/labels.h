#ifndef NAPI_CANON_API_LABELS_H
#define NAPI_CANON_API_LABELS_H

#include "types.h"

namespace CameraApi {

    class Labels {
        public:
            static LabelMap Error;

            static LabelMap ObjectEventID;
            static LabelMap StateEventID;
            static LabelMap PropertyID;

            static std::unordered_map<int, LabelMap> PropertyOption;

            static LabelMap AEMode;
            static LabelMap AEModeSelect;
            static LabelMap AFMode;
            static LabelMap Bracket;
            static LabelMap BatteryQuality;
            static LabelMap ColorSpace;
            static LabelMap DCStrobe;
            static LabelMap DriveMode;
            static LabelMap EvfAFMode;
            static LabelMap EvfHistogramStatus;
            static LabelMap EvfOutputDevice;
            static LabelMap EvfZoom;
            static LabelMap ImageQuality;
            static LabelMap ISOSpeed;
            static LabelMap LensBarrelStatus;
            static LabelMap LensStatus;
            static LabelMap MeteringMode;
            static LabelMap MirrorUpStatus;
            static LabelMap MovieQuality;
            static LabelMap NoiseReduction;
            static LabelMap PictureStyle;
            static LabelMap Record;
            static LabelMap RedEye;
            static LabelMap SaveTo;
            static LabelMap WhiteBalance;
    };
}

#endif //NAPI_CANON_API_LABELS_H
