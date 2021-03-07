import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryPropertyOptionTests = (api: typeof CameraApi) => {
    describe(
        'PropertyOption',
        () => {
            test(
                'PropertyOption[Symbol.for("nodejs.util.inspect.custom")] with known value',
                () => {
                    const value = new api.PropertyOption(
                        api.CameraProperty.ID.SaveTo,
                        api.PropertyOption.SaveTo.Host
                    );
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyOption <SaveTo.Host>');
                }
            );
            test(
                'PropertyOption[Symbol.for("nodejs.util.inspect.custom")] with unknown value',
                () => {
                    const value = new api.PropertyOption(
                        api.CameraProperty.ID.SaveTo,
                        0x21
                    );
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyOption <0x00000021>');
                }
            );
            test(
                'PropertyOption[Symbol.for("nodejs.util.inspect.custom")] with unknown property',
                () => {
                    const value = new api.PropertyOption(
                        0x1234,
                        api.PropertyOption.SaveTo.Host
                    );
                    expect(
                        util.inspect(value)
                    ).toBe('PropertyOption <0x00000002>');
                }
            );
        }
    );
}
export default LibraryPropertyOptionTests;