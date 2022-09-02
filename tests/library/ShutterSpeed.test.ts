import * as util from 'util';
import * as CameraApi from '../../stubs/public_api';

const LibraryShutterSpeedTests = (api: typeof CameraApi) => {
    describe(
        'ShutterSpeed',
        () => {
            test(
                'ShutterSpeed[Symbol.for("nodejs.util.inspect.custom")] with known value code',
                () => {
                    const value = new api.ShutterSpeed(api.ShutterSpeed.ID.Auto);
                    expect(
                        util.inspect(value)
                    ).toBe('ShutterSpeed <Auto>');
                }
            );
            test(
                'ShutterSpeed[Symbol.for("nodejs.util.inspect.custom")] with value 1/25',
                () => {
                    const value = new api.ShutterSpeed(0x5D);
                    expect(
                        util.inspect(value)
                    ).toBe('ShutterSpeed <1/25>');
                }
            );
        }
    );
};
export default LibraryShutterSpeedTests;
