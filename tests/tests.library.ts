import * as CameraApiLibrary from "../camera-api";
import CommonApertureTests from "./common/Aperture.test";
import CommonApiErrorTests from "./common/ApiError.test";
import CommonExposureCompensationTests from "./common/ExposureCompensation.test";
import CommonFileFormatTests from "./common/FileFormat.test";
import CommonFlagTests from "./common/Flag.test";
import CommonISOSensitivityTests from "./common/ISOSensitivity.test";
import CommonObjectEventTests from "./common/ObjectEvent.test";
import CommonOptionTests from "./common/Option.test";
import CommonOutputDeviceTests from "./common/OutputDevice.test";
import CommonShutterSpeedTests from "./common/ShutterSpeed.test";
import CommonStateEventTests from "./common/StateEvent.test";
import CommonTimeZoneTests from "./common/TimeZone.test";
import LibraryApertureTests from "./library/Aperture.test";
import LibraryApiErrorTests from "./library/ApiError.test";
import LibraryCameraBrowserTests from "./library/CameraBrowser.test";
import LibraryCameraPropertyTests from "./library/CameraProperty.test";
import LibraryCameraTests from "./library/Camera.test";
import LibraryExposureCompensationTests from "./library/ExposureCompensation.test";
import LibraryFileFormatTests from "./library/FileFormat.test";
import LibraryFlagTests from "./library/Flag.test";
import LibraryOptionTests from "./library/Option.test";
import LibraryOutputDeviceTests from "./library/OutputDevice.test";
import LibraryShutterSpeedTests from "./library/ShutterSpeed.test";

describe(
    'Library Tests',
    () => {
        CommonApertureTests(CameraApiLibrary);
        CommonApiErrorTests(CameraApiLibrary);
        CommonExposureCompensationTests(CameraApiLibrary);
        CommonFlagTests(CameraApiLibrary);
        CommonFileFormatTests(CameraApiLibrary);
        CommonISOSensitivityTests(CameraApiLibrary);
        CommonObjectEventTests(CameraApiLibrary);
        CommonOptionTests(CameraApiLibrary);
        CommonOutputDeviceTests(CameraApiLibrary);
        CommonShutterSpeedTests(CameraApiLibrary);
        CommonStateEventTests(CameraApiLibrary);
        CommonTimeZoneTests(CameraApiLibrary);

        LibraryApertureTests(CameraApiLibrary);
        LibraryApiErrorTests(CameraApiLibrary);
        LibraryCameraBrowserTests(CameraApiLibrary);
        LibraryCameraPropertyTests(CameraApiLibrary);
        LibraryCameraTests(CameraApiLibrary);
        LibraryExposureCompensationTests(CameraApiLibrary);
        LibraryFileFormatTests(CameraApiLibrary);
        LibraryFlagTests(CameraApiLibrary);
        LibraryOptionTests(CameraApiLibrary);
        LibraryOutputDeviceTests(CameraApiLibrary);
        LibraryShutterSpeedTests(CameraApiLibrary);
    }
);
