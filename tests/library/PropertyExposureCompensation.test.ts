import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryPropertyExposureCompensationTests = (api: typeof CameraApi) => {
    describe(
        'PropertyExposureCompensation',
        () => {
            test(
                'PropertyExposureCompensation[Symbol.for("nodejs.util.inspect.custom")] with "0"',
                () => {
                    const value = new api.PropertyExposureCompensation(0x00);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyExposureCompensation <0>');
                }
            );
            test(
                'PropertyExposureCompensation[Symbol.for("nodejs.util.inspect.custom")] with "2 1/2"',
                () => {
                    const value = new api.PropertyExposureCompensation(0x14);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyExposureCompensation <+2 1/2>');
                }
            );
        }
    );
}
export default LibraryPropertyExposureCompensationTests;
