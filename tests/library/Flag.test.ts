import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryFlagTests = (api: typeof CameraApi) => {
    describe(
        'Flag',
        () => {
            test(
                'Flag[Symbol.for("nodejs.util.inspect.custom")] with "true"',
                () => {
                    const value = new api.Flag(true);
                    expect(
                        util.inspect(value)
                    ).toBe('Flag <true>');
                }
            );
            test(
                'Flag[Symbol.for("nodejs.util.inspect.custom")] with "false"',
                () => {
                    const value = new api.Flag(false);
                    expect(
                        util.inspect(value)
                    ).toBe('Flag <false>');
                }
            );
            test(
                'Flag[Symbol.for("nodejs.util.inspect.custom")] with "Flag.ID.True"',
                () => {
                    const value = new api.Flag(api.Flag.True);
                    expect(
                        util.inspect(value)
                    ).toBe('Flag <true>');
                }
            );
            test(
                'Flag[Symbol.for("nodejs.util.inspect.custom")] with "Flag.ID.False"',
                () => {
                    const value = new api.Flag(api.Flag.False);
                    expect(
                        util.inspect(value)
                    ).toBe('Flag <false>');
                }
            );
        }
    );
}
export default LibraryFlagTests;
