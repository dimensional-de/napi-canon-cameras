import * as CameraApi from "../../stubs/public_api";

const CommonPropertyShutterSpeedTests = (api: typeof CameraApi) => {
    describe(
        'PropertyShutterSpeed',
        () => {
            test(
                'PropertyShutterSpeed.value for "Auto"',
                () => {
                    const value = new api.PropertyShutterSpeed(api.PropertyShutterSpeed.ID.Auto);
                    expect(value.value).toStrictEqual(api.PropertyShutterSpeed.ID.Auto);
                }
            );
            test(
                'PropertyShutterSpeed.label for "Auto"',
                () => {
                    const value = new api.PropertyShutterSpeed(api.PropertyShutterSpeed.ID.Auto);
                    expect(value.label).toStrictEqual("Auto");
                }
            );
            test(
                'PropertyShutterSpeed.label for "Auto"',
                () => {
                    const value = new api.PropertyShutterSpeed(api.PropertyShutterSpeed.ID.Auto);
                    expect(value.seconds).toStrictEqual(0.0);
                }
            );
            test(
                'PropertyShutterSpeed.label for "3"',
                () => {
                    const value = new api.PropertyShutterSpeed(0x2C);
                    expect(value.label).toStrictEqual("3");
                }
            );
            test(
                'PropertyShutterSpeed.seconds for "3"',
                () => {
                    const value = new api.PropertyShutterSpeed(0x2C);
                    expect(value.seconds).toStrictEqual(3.0);
                }
            );
            test(
                'PropertyShutterSpeed.forLabel("3")',
                () => {
                    const value = api.PropertyShutterSpeed.forLabel('3');
                    expect(value.value).toStrictEqual(0x2C);
                    expect(value.label).toStrictEqual("3");
                    expect(value.seconds).toStrictEqual(3.0);
                }
            );
            test(
                'PropertyShutterSpeed.forLabel(1/400)',
                () => {
                    const value = api.PropertyShutterSpeed.forLabel('1/400');
                    expect(value.value).toStrictEqual(0x7D);
                    expect(value.label).toStrictEqual('1/400');
                    expect(value.seconds).toStrictEqual(0.0025);
                }
            );
            test(
                'PropertyShutterSpeed.forLabel("invalid") expecting null',
                () => {
                    const value = api.PropertyShutterSpeed.forLabel("invalid");
                    expect(value).toBeNull();
                }
            );
        }
    );
}
export default CommonPropertyShutterSpeedTests;