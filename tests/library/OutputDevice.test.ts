import * as util from "util";
import * as CameraApi from "../../stubs/public_api";

const LibraryOutputDeviceTests = (api: typeof CameraApi) => {
    describe(
        'OutputDevice',
        () => {
            test(
                'OutputDevice[Symbol.for("nodejs.util.inspect.custom")] with "None"',
                () => {
                    const value = new api.OutputDevice(api.OutputDevice.ID.None);
                    expect(
                        util.inspect(value)
                    ).toBe('OutputDevice <None>');
                }
            );
            test(
                'OutputDevice[Symbol.for("nodejs.util.inspect.custom")] with "PC"',
                () => {
                    const value = new api.OutputDevice(api.OutputDevice.ID.PC);
                    expect(
                        util.inspect(value)
                    ).toBe('OutputDevice <PC>');
                }
            );
            test(
                'OutputDevice[Symbol.for("nodejs.util.inspect.custom")] with "PC, Mobile"',
                () => {
                    const value = new api.OutputDevice(
                        api.OutputDevice.ID.PC | api.OutputDevice.ID.PCSmall
                    );
                    expect(
                        util.inspect(value)
                    ).toBe('OutputDevice <PC|PCSmall>');
                }
            );
        }
    );
}
export default LibraryOutputDeviceTests;
