import * as CameraApi from "../../stubs/public_api";

const CommonPropertyFlagTests = (api: typeof CameraApi) => {
    describe(
        'PropertyFlag',
        () => {
            test(
                'PropertyFlag.value for "PropertyFlag.True"',
                () => {
                    const value = new api.PropertyFlag(api.PropertyFlag.True);
                    expect(value.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.value for boolean "True"',
                () => {
                    const value = new api.PropertyFlag(true);
                    expect(value.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.value for "PropertyFlag.False"',
                () => {
                    const value = new api.PropertyFlag(api.PropertyFlag.False);
                    expect(value.value).toStrictEqual(api.PropertyFlag.False);
                }
            );
            test(
                'PropertyFlag.value for boolean "False"',
                () => {
                    const value = new api.PropertyFlag(false);
                    expect(value.value).toStrictEqual(api.PropertyFlag.False);
                }
            );
            test(
                'PropertyFlag.label for "True"',
                () => {
                    const value = new api.PropertyFlag(true);
                    expect(value.label).toStrictEqual("true");
                }
            );
            test(
                'PropertyFlag.label for "False"',
                () => {
                    const value = new api.PropertyFlag(false);
                    expect(value.label).toStrictEqual("false");
                }
            );
        }
    );
}
export default CommonPropertyFlagTests;