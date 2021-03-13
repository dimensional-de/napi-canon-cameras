import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryExposureCompensationTests = (api: typeof CameraApi) => {
    describe(
        'ExposureCompensation',
        () => {
            test(
                'ExposureCompensation[Symbol.for("nodejs.util.inspect.custom")] with "0"',
                () => {
                    const value = new api.ExposureCompensation(0x00);
                    expect(
                        util.inspect(value)
                    ).toBe('ExposureCompensation <0>');
                }
            );
            test(
                'ExposureCompensation[Symbol.for("nodejs.util.inspect.custom")] with "2 1/2"',
                () => {
                    const value = new api.ExposureCompensation(0x14);
                    expect(
                        util.inspect(value)
                    ).toBe('ExposureCompensation <+2 1/2>');
                }
            );
        }
    );
}
export default LibraryExposureCompensationTests;
