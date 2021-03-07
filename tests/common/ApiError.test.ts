import * as CameraApi from "../../stubs/public_api";

const CommonApiErrorTests = (api: typeof CameraApi) => {
    describe(
        'ApiError',
        () => {
            test(
                'ApiError.identifier',
                () => {
                    const error = new api.ApiError(api.ApiError.Code.UNKNOWN_COMMAND);
                    expect(error.identifier).toStrictEqual(api.ApiError.Code.UNKNOWN_COMMAND);
                }
            );
            test(
                'ApiError.label',
                () => {
                    const error = new api.ApiError(api.ApiError.Code.UNKNOWN_COMMAND);
                    expect(error.label).toStrictEqual('UNKNOWN_COMMAND');
                }
            );
            test(
                'ApiError.toJSON()',
                () => {
                    const error = new api.ApiError(api.ApiError.Code.UNKNOWN_COMMAND);
                    const json = JSON.parse(JSON.stringify(error));
                    expect(json).toStrictEqual(
                        {
                            "identifier": api.ApiError.Code.UNKNOWN_COMMAND,
                            "label": "UNKNOWN_COMMAND"
                        }
                    );
                }
            );
            test(
                'ApiError.equalTo()',
                () => {
                    const error = new api.ApiError(api.ApiError.Code.COMM_PORT_IS_IN_USE);
                    expect(error.equalTo(api.ApiError.Code.COMM_PORT_IS_IN_USE)).toStrictEqual(true);
                    expect(error.equalTo(api.ApiError.Code.UNKNOWN_COMMAND)).toStrictEqual(false);
                }
            );
            test(
                'ApiError[@@toPrimitive]',
                () => {
                    const error = new api.ApiError(api.ApiError.Code.COMM_PORT_IS_IN_USE);
                    expect(String(error)).toStrictEqual('0x000000c0');
                    expect(+(error)).toStrictEqual(api.ApiError.Code.COMM_PORT_IS_IN_USE);
                }
            );
            test(
                'ApiError[@@toStringTag]',
                () => {
                    const error = new api.ApiError(api.ApiError.Code.COMM_PORT_IS_IN_USE);
                    expect(Object.prototype.toString.call(error)).toStrictEqual('[object ApiError]');
                }
            );
        }
    );
}
export default CommonApiErrorTests;