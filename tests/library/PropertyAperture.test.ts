import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryPropertyApertureTests = (api: typeof CameraApi) => {
    describe(
        'PropertyAperture',
        () => {
            test(
                'PropertyAperture[Symbol.for("nodejs.util.inspect.custom")] with known value code',
                () => {
                    const value = new api.PropertyAperture(api.PropertyAperture.ID.Auto);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyAperture <Auto>');
                }
            );
            test(
                'PropertyAperture[Symbol.for("nodejs.util.inspect.custom")] with value f40',
                () => {
                    const value = new api.PropertyAperture(0x5D);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyAperture <f40>');
                }
            );
        }
    );
}
export default LibraryPropertyApertureTests;