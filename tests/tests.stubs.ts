import * as CameraApiStubs from "../src/stubs/index";
import CommonApiErrorTests from "./common/ApiError.test";
import CommonObjectEventTests from "./common/ObjectEvent.test";
import CommonApertureTests from "./common/Aperture.test";
import CommonExposureCompensationTests from "./common/ExposureCompensation.test";
import CommonFlagTests from "./common/Flag.test";
import CommonOptionTests from "./common/Option.test";
import CommonShutterSpeedTests from "./common/ShutterSpeed.test";
import CommonStateEventTests from "./common/StateEvent.test";

describe('Stubs Tests', () => {
    const stubs = CameraApiStubs as any;
    CommonApiErrorTests(stubs);
    CommonObjectEventTests(stubs);
    CommonApertureTests(stubs);
    CommonExposureCompensationTests(stubs);
    CommonFlagTests(stubs);
    CommonOptionTests(stubs);
    CommonShutterSpeedTests(stubs);
    CommonStateEventTests(stubs);
});
