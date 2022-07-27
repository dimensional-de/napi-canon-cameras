#ifndef NAPI_CANON_API_LABELS_H
#define NAPI_CANON_API_LABELS_H

#include "types.h"

namespace CameraApi {

    class Labels {
        public:
            static const LabelMap &Error();

            static const LabelMap &ObjectEventID();

            static const LabelMap &StateEventID();

            static const LabelMap &PropertyID();

            static const std::unordered_map<int, LabelMap> &Option();

            static const LabelMap &AEMode();

            static const LabelMap &AEModeSelect();

            static const LabelMap &AFMode();

            static const LabelMap &Bracket();

            static const LabelMap &BatteryQuality();

            static const LabelMap &ColorSpace();

            static const LabelMap &DCStrobe();

            static const LabelMap &DriveMode();

            static const LabelMap &EvfAFMode();

            static const LabelMap &EvfHistogramStatus();

            static const LabelMap &EvfOutputDevice();

            static const LabelMap &EvfZoom();

            static const LabelMap &ImageQuality();

            static const LabelMap &LensBarrelStatus();

            static const LabelMap &LensStatus();

            static const LabelMap &MeteringMode();

            static const LabelMap &MirrorUpStatus();

            static const LabelMap &MovieQuality();

            static const LabelMap &NoiseReduction();

            static const LabelMap &PictureStyle();

            static const LabelMap &Record();

            static const LabelMap &RedEye();

            static const LabelMap &SaveTo();

            static const LabelMap &WhiteBalance();

            static const LabelMap &StorageType();

            static const LabelMap &ImageFormat();

            static const LabelMap &ImageSize();

            static const LabelMap &ImageCompression();
    };
}

#endif //NAPI_CANON_API_LABELS_H
