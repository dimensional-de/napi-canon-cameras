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
        }
    );
}
export default CommonPropertyShutterSpeedTests;