import * as util from 'util';
import * as CameraApi from '../../stubs/public_api';

const LibraryApiErrorTests = (api: typeof CameraApi) => {
    describe(
        'ApiError',
        () => {
            test(
                'ApiError[Symbol.for("nodejs.util.inspect.custom")] with known error code',
                () => {
                    const error = new api.ApiError(api.ApiError.Code.COMM_PORT_IS_IN_USE);
                    expect(
                        util.inspect(error),
                    ).toBe('ApiError <COMM_PORT_IS_IN_USE>');
                },
            );
            test(
                'ApiError[Symbol.for("nodejs.util.inspect.custom")] with unknown error code',
                () => {
                    const error = new api.ApiError(0x12345678);
                    expect(
                        util.inspect(error),
                    ).toBe('ApiError <0x12345678>');
                },
            );
        },
    );
};
export default LibraryApiErrorTests;
