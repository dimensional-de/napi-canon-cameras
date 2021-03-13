import * as CameraApi from "../../stubs/public_api";

const CommonApertureTests = (api: typeof CameraApi) => {
    describe(
        'Aperture',
        () => {
            test(
                'Aperture.value for "Auto"',
                () => {
                    const value = new api.Aperture(api.Aperture.ID.Auto);
                    expect(value.value).toStrictEqual(api.Aperture.ID.Auto);
                }
            );
            test(
                'Aperture.label for "Auto"',
                () => {
                    const value = new api.Aperture(api.Aperture.ID.Auto);
                    expect(value.label).toStrictEqual("Auto");
                }
            );
            test(
                'Aperture.label for "Auto"',
                () => {
                    const value = new api.Aperture(api.Aperture.ID.Auto);
                    expect(value.aperture).toStrictEqual(0.0);
                }
            );
            test(
                'Aperture.label for "5.6"',
                () => {
                    const value = new api.Aperture(0x30);
                    expect(value.label).toStrictEqual("f5.6");
                }
            );
            test(
                'Aperture.aperture for "5.6"',
                () => {
                    const value = new api.Aperture(0x30);
                    expect(value.label).toStrictEqual('f5.6');
                    expect(value.aperture).toStrictEqual(5.6);
                }
            );
            test(
                'Aperture.forLabel("f5.6")',
                () => {
                    const value = api.Aperture.forLabel('f5.6');
                    expect(value.label).toStrictEqual('f5.6');
                    expect(value.value).toStrictEqual(0x30);
                    expect(value.aperture).toStrictEqual(5.6);
                }
            );
            test(
                'Aperture.forLabel("invalid") expecting null',
                () => {
                    const flag = api.Aperture.forLabel("invalid");
                    expect(flag).toBeNull();
                }
            );
        }
    );
}
export default CommonApertureTests;
