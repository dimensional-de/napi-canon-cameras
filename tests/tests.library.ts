import * as CameraApiLibrary from "../camera-api";
import CommonApiErrorTests from "./common/ApiError.test";
import CommonObjectEventTests from "./common/ObjectEvent.test";
import CommonApertureTests from "./common/Aperture.test";
import CommonExposureCompensationTests from "./common/ExposureCompensation.test";
import CommonFlagTests from "./common/Flag.test";
import CommonOptionTests from "./common/Option.test";
import CommonShutterSpeedTests from "./common/ShutterSpeed.test";
import CommonStateEventTests from "./common/StateEvent.test";
import LibraryApiErrorTests from "./library/ApiError.test";
import LibraryCameraTests from "./library/Camera.test";
import LibraryCameraBrowserTests from "./library/CameraBrowser.test";
import LibraryCameraPropertyTests from "./library/CameraProperty.test";
import LibraryApertureTests from "./library/Aperture.test";
import LibraryExposureCompensationTests from "./library/ExposureCompensation.test";
import LibraryFlagTests from "./library/Flag.test";
import LibraryOptionTests from "./library/Option.test";
import LibraryShutterSpeedTests from "./library/ShutterSpeed.test";

describe(
    'Library Tests',
    () => {
        CommonApiErrorTests(CameraApiLibrary);
        CommonObjectEventTests(CameraApiLibrary);
        CommonApertureTests(CameraApiLibrary);
        CommonExposureCompensationTests(CameraApiLibrary);
        CommonFlagTests(CameraApiLibrary);
        CommonOptionTests(CameraApiLibrary);
        CommonShutterSpeedTests(CameraApiLibrary);
        CommonStateEventTests(CameraApiLibrary);

        LibraryApiErrorTests(CameraApiLibrary);
        LibraryCameraTests(CameraApiLibrary);
        LibraryCameraBrowserTests(CameraApiLibrary);
        LibraryCameraPropertyTests(CameraApiLibrary);
        LibraryApertureTests(CameraApiLibrary);
        LibraryExposureCompensationTests(CameraApiLibrary);
        LibraryFlagTests(CameraApiLibrary);
        LibraryOptionTests(CameraApiLibrary);
        LibraryShutterSpeedTests(CameraApiLibrary);
    }
);
