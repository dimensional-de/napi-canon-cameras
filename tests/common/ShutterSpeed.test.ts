import * as CameraApi from "../../stubs/public_api";

const CommonShutterSpeedTests = (api: typeof CameraApi) => {
    describe(
        'ShutterSpeed',
        () => {
            test(
                'ShutterSpeed.value for "Auto"',
                () => {
                    const value = new api.ShutterSpeed(api.ShutterSpeed.ID.Auto);
                    expect(value.value).toStrictEqual(api.ShutterSpeed.ID.Auto);
                }
            );
            test(
                'ShutterSpeed.label for "Auto"',
                () => {
                    const value = new api.ShutterSpeed(api.ShutterSpeed.ID.Auto);
                    expect(value.label).toStrictEqual("Auto");
                }
            );
            test(
                'ShutterSpeed.label for "Auto"',
                () => {
                    const value = new api.ShutterSpeed(api.ShutterSpeed.ID.Auto);
                    expect(value.seconds).toStrictEqual(0.0);
                }
            );
            test(
                'ShutterSpeed.label for "3"',
                () => {
                    const value = new api.ShutterSpeed(0x2C);
                    expect(value.label).toStrictEqual("3");
                }
            );
            test(
                'ShutterSpeed.seconds for "3"',
                () => {
                    const value = new api.ShutterSpeed(0x2C);
                    expect(value.seconds).toStrictEqual(3.0);
                }
            );
            test(
                'ShutterSpeed.forLabel("3")',
                () => {
                    const value = api.ShutterSpeed.forLabel('3');
                    expect(value.value).toStrictEqual(0x2C);
                    expect(value.label).toStrictEqual("3");
                    expect(value.seconds).toStrictEqual(3.0);
                }
            );
            test(
                'ShutterSpeed.forLabel(1/400)',
                () => {
                    const value = api.ShutterSpeed.forLabel('1/400');
                    expect(value.value).toStrictEqual(0x7D);
                    expect(value.label).toStrictEqual('1/400');
                    expect(value.seconds).toStrictEqual(0.0025);
                }
            );
            test(
                'ShutterSpeed.forLabel("invalid") expecting null',
                () => {
                    const value = api.ShutterSpeed.forLabel("invalid");
                    expect(value).toBeNull();
                }
            );
        }
    );
}
export default CommonShutterSpeedTests;
