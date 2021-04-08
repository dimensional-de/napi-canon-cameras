import * as CameraApiLibrary from "../camera-api";
import CommonApertureTests from "./common/Aperture.test";
import CommonApiErrorTests from "./common/ApiError.test";
import CommonExposureCompensationTests from "./common/ExposureCompensation.test";
import CommonFlagTests from "./common/Flag.test";
import CommonISOSensitivityTests from "./common/ISOSensitivity.test";
import CommonObjectEventTests from "./common/ObjectEvent.test";
import CommonOptionTests from "./common/Option.test";
import CommonShutterSpeedTests from "./common/ShutterSpeed.test";
import CommonStateEventTests from "./common/StateEvent.test";
import CommonTimeZoneTests from "./common/TimeZone.test";
import LibraryApertureTests from "./library/Aperture.test";
import LibraryApiErrorTests from "./library/ApiError.test";
import LibraryCameraBrowserTests from "./library/CameraBrowser.test";
import LibraryCameraPropertyTests from "./library/CameraProperty.test";
import LibraryCameraTests from "./library/Camera.test";
import LibraryExposureCompensationTests from "./library/ExposureCompensation.test";
import LibraryFlagTests from "./library/Flag.test";
import LibraryOptionTests from "./library/Option.test";
import LibraryShutterSpeedTests from "./library/ShutterSpeed.test";

describe(
    'Library Tests',
    () => {
        CommonApertureTests(CameraApiLibrary);
        CommonApiErrorTests(CameraApiLibrary);
        CommonExposureCompensationTests(CameraApiLibrary);
        CommonFlagTests(CameraApiLibrary);
        CommonISOSensitivityTests(CameraApiLibrary);
        CommonObjectEventTests(CameraApiLibrary);
        CommonOptionTests(CameraApiLibrary);
        CommonShutterSpeedTests(CameraApiLibrary);
        CommonStateEventTests(CameraApiLibrary);
        CommonTimeZoneTests(CameraApiLibrary);

        LibraryApertureTests(CameraApiLibrary);
        LibraryApiErrorTests(CameraApiLibrary);
        LibraryCameraBrowserTests(CameraApiLibrary);
        LibraryCameraPropertyTests(CameraApiLibrary);
        LibraryCameraTests(CameraApiLibrary);
        LibraryExposureCompensationTests(CameraApiLibrary);
        LibraryFlagTests(CameraApiLibrary);
        LibraryOptionTests(CameraApiLibrary);
        LibraryShutterSpeedTests(CameraApiLibrary);
    }
);
