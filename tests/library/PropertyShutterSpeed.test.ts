import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryPropertyShutterSpeedTests = (api: typeof CameraApi) => {
    describe(
        'PropertyShutterSpeed',
        () => {
            test(
                'PropertyShutterSpeed[Symbol.for("nodejs.util.inspect.custom")] with known value code',
                () => {
                    const value = new api.PropertyShutterSpeed(api.PropertyShutterSpeed.ID.Auto);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyShutterSpeed <Auto>');
                }
            );
            test(
                'PropertyShutterSpeed[Symbol.for("nodejs.util.inspect.custom")] with value 1/25',
                () => {
                    const value = new api.PropertyShutterSpeed(0x5D);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyShutterSpeed <1/25>');
                }
            );
        }
    );
}
export default LibraryPropertyShutterSpeedTests;