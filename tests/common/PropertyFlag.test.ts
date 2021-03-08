import * as CameraApi from "../../stubs/public_api";

const CommonPropertyFlagTests = (api: typeof CameraApi) => {
    describe(
        'PropertyFlag',
        () => {
            test(
                'PropertyFlag.value for "PropertyFlag.True"',
                () => {
                    const flag = new api.PropertyFlag(api.PropertyFlag.True);
                    expect(flag.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.value for boolean "True"',
                () => {
                    const flag = new api.PropertyFlag(true);
                    expect(flag.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.value for "PropertyFlag.False"',
                () => {
                    const flag = new api.PropertyFlag(api.PropertyFlag.False);
                    expect(flag.value).toStrictEqual(api.PropertyFlag.False);
                }
            );
            test(
                'PropertyFlag.value for boolean "False"',
                () => {
                    const flag = new api.PropertyFlag(false);
                    expect(flag.value).toStrictEqual(api.PropertyFlag.False);
                }
            );
            test(
                'PropertyFlag.label for "True"',
                () => {
                    const flag = new api.PropertyFlag(true);
                    expect(flag.label).toStrictEqual("true");
                }
            );
            test(
                'PropertyFlag.label for "False"',
                () => {
                    const flag = new api.PropertyFlag(false);
                    expect(flag.label).toStrictEqual("false");
                }
            );
            test(
                'PropertyFlag.forLabel("True")',
                () => {
                    const flag = api.PropertyFlag.forLabel('true')
                    expect(flag.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.forLabel("Yes")',
                () => {
                    const flag = api.PropertyFlag.forLabel('Yes');
                    expect(flag.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.forLabel("1")',
                () => {
                    const flag = api.PropertyFlag.forLabel('Yes');
                    expect(flag.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.forLabel("On")',
                () => {
                    const flag = api.PropertyFlag.forLabel('Yes');
                    expect(flag.value).toStrictEqual(api.PropertyFlag.True);
                }
            );
            test(
                'PropertyFlag.forLabel("False")',
                () => {
                    const flag = api.PropertyFlag.forLabel('false');
                    expect(flag.value).toStrictEqual(api.PropertyFlag.False);
                }
            );
        }
    );
}
export default CommonPropertyFlagTests;