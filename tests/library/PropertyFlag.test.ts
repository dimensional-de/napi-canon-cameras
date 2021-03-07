import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryPropertyFlagTests = (api: typeof CameraApi) => {
    describe(
        'PropertyFlag',
        () => {
            test(
                'PropertyFlag[Symbol.for("nodejs.util.inspect.custom")] with "true"',
                () => {
                    const value = new api.PropertyFlag(true);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyFlag <true>');
                }
            );
            test(
                'PropertyFlag[Symbol.for("nodejs.util.inspect.custom")] with "false"',
                () => {
                    const value = new api.PropertyFlag(false);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyFlag <false>');
                }
            );
            test(
                'PropertyFlag[Symbol.for("nodejs.util.inspect.custom")] with "PropertyFlag.ID.True"',
                () => {
                    const value = new api.PropertyFlag(api.PropertyFlag.True);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyFlag <true>');
                }
            );
            test(
                'PropertyFlag[Symbol.for("nodejs.util.inspect.custom")] with "PropertyFlag.ID.False"',
                () => {
                    const value = new api.PropertyFlag(api.PropertyFlag.False);
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyFlag <false>');
                }
            );
        }
    );
}
export default LibraryPropertyFlagTests;