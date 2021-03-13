import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryOptionTests = (api: typeof CameraApi) => {
    describe(
        'Option',
        () => {
            test(
                'Option[Symbol.for("nodejs.util.inspect.custom")] with known value',
                () => {
                    const value = new api.Option(
                        api.CameraProperty.ID.SaveTo,
                        api.Option.SaveTo.Host
                    );
                    expect(
                        util.inspect(value)
                    ).toBe('Option <SaveTo.Host>');
                }
            );
            test(
                'Option[Symbol.for("nodejs.util.inspect.custom")] with unknown value',
                () => {
                    const value = new api.Option(
                        api.CameraProperty.ID.SaveTo,
                        0x21
                    );
                    expect(
                        util.inspect(value)
                    ).toBe('Option <0x00000021>');
                }
            );
            test(
                'Option[Symbol.for("nodejs.util.inspect.custom")] with unknown property',
                () => {
                    const value = new api.Option(
                        0x1234,
                        api.Option.SaveTo.Host
                    );
                    expect(
                        util.inspect(value)
                    ).toBe('Option <0x00000002>');
                }
            );
        }
    );
}
export default LibraryOptionTests;
