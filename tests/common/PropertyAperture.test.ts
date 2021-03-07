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
                'PropertyAperture.label for "4.5"',
                () => {
                    const value = new api.PropertyAperture(0x2C);
                    expect(value.label).toStrictEqual("f4.5");
                }
            );
            test(
                'PropertyAperture.seconds for "4.5"',
                () => {
                    const value = new api.PropertyAperture(0x2C);
                    expect(value.aperture).toStrictEqual(4.5);
                }
            );
        }
    );
}
export default CommonPropertyApertureTests;