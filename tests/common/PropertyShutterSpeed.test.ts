import * as CameraApi from "../../stubs/public_api";

const CommonPropertyShutterSpeedTests = (api: typeof CameraApi) => {
    describe(
        'ShutterSpeed',
        () => {
            test(
                'ShutterSpeed.value for "Auto"',
                () => {
                    const value = new api.PropertyShutterSpeed(api.PropertyShutterSpeed.ID.Auto);
                    expect(value.value).toStrictEqual(api.PropertyShutterSpeed.ID.Auto);
                }
            );
            test(
                'ShutterSpeed.label for "Auto"',
                () => {
                    const value = new api.PropertyShutterSpeed(api.PropertyShutterSpeed.ID.Auto);
                    expect(value.label).toStrictEqual("Auto");
                }
            );
            test(
                'ShutterSpeed.label for "Auto"',
                () => {
                    const value = new api.PropertyShutterSpeed(api.PropertyShutterSpeed.ID.Auto);
                    expect(value.seconds).toStrictEqual(0.0);
                }
            );
            test(
                'ShutterSpeed.label for "3"',
                () => {
                    const value = new api.PropertyShutterSpeed(0x2C);
                    expect(value.label).toStrictEqual("3");
                }
            );
            test(
                'ShutterSpeed.seconds for "3"',
                () => {
                    const value = new api.PropertyShutterSpeed(0x2C);
                    expect(value.seconds).toStrictEqual(3.0);
                }
            );
            test(
                'ShutterSpeed.forLabel("3")',
                () => {
                    const value = api.PropertyShutterSpeed.forLabel('3');
                    expect(value.value).toStrictEqual(0x2C);
                    expect(value.label).toStrictEqual("3");
                    expect(value.seconds).toStrictEqual(3.0);
                }
            )
            test(
                'ShutterSpeed.forLabel(1/400)',
                () => {
                    const value = api.PropertyShutterSpeed.forLabel('1/400');
                    expect(value.value).toStrictEqual(0x7D);
                    expect(value.label).toStrictEqual('1/400');
                    expect(value.seconds).toStrictEqual(0.0025);
                }
            )
        }
    );
}
export default CommonPropertyShutterSpeedTests;