import * as CameraApi from "../../stubs/public_api";

const CommonPropertyApertureTests = (api: typeof CameraApi) => {
    describe(
        'PropertyAperture',
        () => {
            test(
                'PropertyAperture.value for "Auto"',
                () => {
                    const value = new api.PropertyAperture(api.PropertyAperture.ID.Auto);
                    expect(value.value).toStrictEqual(api.PropertyAperture.ID.Auto);
                }
            );
            test(
                'PropertyAperture.label for "Auto"',
                () => {
                    const value = new api.PropertyAperture(api.PropertyAperture.ID.Auto);
                    expect(value.label).toStrictEqual("Auto");
                }
            );
            test(
                'PropertyAperture.label for "Auto"',
                () => {
                    const value = new api.PropertyAperture(api.PropertyAperture.ID.Auto);
                    expect(value.aperture).toStrictEqual(0.0);
                }
            );
            test(
                'PropertyAperture.label for "5.6"',
                () => {
                    const value = new api.PropertyAperture(0x30);
                    expect(value.label).toStrictEqual("f5.6");
                }
            );
            test(
                'PropertyAperture.aperture for "5.6"',
                () => {
                    const value = new api.PropertyAperture(0x30);
                    expect(value.label).toStrictEqual('f5.6');
                    expect(value.aperture).toStrictEqual(5.6);
                }
            );
            test(
                'PropertyAperture.forLabel("f5.6")',
                () => {
                    const value = api.PropertyAperture.forLabel('f5.6');
                    expect(value.label).toStrictEqual('f5.6');
                    expect(value.value).toStrictEqual(0x30);
                    expect(value.aperture).toStrictEqual(5.6);
                }
            );
            test(
                'PropertyAperture.forLabel("invalid") expecting null',
                () => {
                    const flag = api.PropertyAperture.forLabel("invalid");
                    expect(flag).toBeNull();
                }
            );
        }
    );
}
export default CommonPropertyApertureTests;