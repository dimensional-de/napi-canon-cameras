import * as CameraApiStubs from "../src/stubs/index";
import CommonApiErrorTests from "./common/ApiError.test";
import CommonObjectEventTests from "./common/ObjectEvent.test";
import CommonPropertyApertureTests from "./common/PropertyAperture.test";
import CommonPropertyExposureCompensationTests from "./common/PropertyExposureCompensation.test";
import CommonPropertyFlagTests from "./common/PropertyFlag.test";
import CommonPropertyOptionTests from "./common/PropertyOption.test";
import CommonPropertyShutterSpeedTests from "./common/PropertyShutterSpeed.test";
import CommonStateEventTests from "./common/StateEvent.test";

describe('Stubs Tests', () => {
    const stubs = CameraApiStubs as any;
    CommonApiErrorTests(stubs);
    CommonObjectEventTests(stubs);
    CommonPropertyApertureTests(stubs);
    CommonPropertyExposureCompensationTests(stubs);
    CommonPropertyFlagTests(stubs);
    CommonPropertyOptionTests(stubs);
    CommonPropertyShutterSpeedTests(stubs);
    CommonStateEventTests(stubs);
});
