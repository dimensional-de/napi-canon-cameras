import * as CameraApiLibrary from "../camera-api";
import CommonApiErrorTests from "./common/ApiError.test";
import CommonObjectEventTests from "./common/ObjectEvent.test";
import CommonPropertyApertureTests from "./common/PropertyAperture.test";
import CommonPropertyExposureCompensationTests from "./common/PropertyExposureCompensation.test";
import CommonPropertyFlagTests from "./common/PropertyFlag.test";
import CommonPropertyOptionTests from "./common/PropertyOption.test";
import CommonPropertyShutterSpeedTests from "./common/PropertyShutterSpeed.test";
import CommonStateEventTests from "./common/StateEvent.test";
import LibraryApiErrorTests from "./library/ApiError.test";
import LibraryCameraTests from "./library/Camera.test";
import LibraryCameraBrowserTests from "./library/CameraBrowser.test";
import LibraryCameraPropertyTests from "./library/CameraProperty.test";
import LibraryPropertyApertureTests from "./library/PropertyAperture.test";
import LibraryPropertyExposureCompensationTests from "./library/PropertyExposureCompensation.test";
import LibraryPropertyFlagTests from "./library/PropertyFlag.test";
import LibraryPropertyOptionTests from "./library/PropertyOption.test";
import LibraryPropertyShutterSpeedTests from "./library/PropertyShutterSpeed.test";

describe(
    'Library Tests',
    () => {
        CommonApiErrorTests(CameraApiLibrary);
        CommonObjectEventTests(CameraApiLibrary);
        CommonPropertyApertureTests(CameraApiLibrary);
        CommonPropertyExposureCompensationTests(CameraApiLibrary);
        CommonPropertyFlagTests(CameraApiLibrary);
        CommonPropertyOptionTests(CameraApiLibrary);
        CommonPropertyShutterSpeedTests(CameraApiLibrary);
        CommonStateEventTests(CameraApiLibrary);

        LibraryApiErrorTests(CameraApiLibrary);
        LibraryCameraTests(CameraApiLibrary);
        LibraryCameraBrowserTests(CameraApiLibrary);
        LibraryCameraPropertyTests(CameraApiLibrary);
        LibraryPropertyApertureTests(CameraApiLibrary);
        LibraryPropertyExposureCompensationTests(CameraApiLibrary);
        LibraryPropertyFlagTests(CameraApiLibrary);
        LibraryPropertyOptionTests(CameraApiLibrary);
        LibraryPropertyShutterSpeedTests(CameraApiLibrary);
    }
);
