import * as CameraApi from "../../stubs/public_api";

const CommonApertureTests = (api: typeof CameraApi) => {
    describe(
        'Aperture',
        () => {
            test(
                'Aperture.value for "Auto"',
                () => {
                    const aperture = new api.Aperture(api.Aperture.ID.Auto);
                    expect(aperture.value).toStrictEqual(api.Aperture.ID.Auto);
                }
            );
            test(
                'Aperture.label for "Auto"',
                () => {
                    const aperture = new api.Aperture(api.Aperture.ID.Auto);
                    expect(aperture.label).toStrictEqual("Auto");
                }
            );
            test(
                'Aperture.label for "Auto"',
                () => {
                    const aperture = new api.Aperture(api.Aperture.ID.Auto);
                    expect(aperture.aperture).toStrictEqual(0.0);
                }
            );
            test(
                'Aperture.label for "5.6"',
                () => {
                    const aperture = new api.Aperture(0x30);
                    expect(aperture.label).toStrictEqual("f5.6");
                }
            );
            test(
                'Aperture.aperture for "5.6"',
                () => {
                    const aperture = new api.Aperture(0x30);
                    expect(aperture.label).toStrictEqual('f5.6');
                    expect(aperture.aperture).toStrictEqual(5.6);
                }
            );
            test(
                'Aperture.forLabel("f5.6")',
                () => {
                    const aperture = api.Aperture.forLabel('f5.6');
                    expect(aperture.label).toStrictEqual('f5.6');
                    expect(aperture.value).toStrictEqual(0x30);
                    expect(aperture.aperture).toStrictEqual(5.6);
                }
            );
            test(
                'Aperture.forLabel("invalid") expecting null',
                () => {
                    const aperture = api.Aperture.forLabel("invalid");
                    expect(aperture).toBeNull();
                }
            );
            test(
                'Aperture.findNearest() for 3.4',
                () => {
                    const aperture = api.Aperture.findNearest(3.4);
                    expect(aperture.aperture).toStrictEqual(3.4);
                }
            );
            test(
                'Aperture.findNearest() for 5.6',
                () => {
                    const aperture = api.Aperture.findNearest(5.6);
                    expect(aperture.aperture).toStrictEqual(5.6);
                }
            );
            test(
                'Aperture.findNearest() filtering all expecting null',
                () => {
                    const aperture = api.Aperture.findNearest(5.6, () => false);
                    expect(aperture).toBeNull();
                }
            );
            test(
                'Aperture.findNearest() filtering below 3.4',
                () => {
                    const aperture = api.Aperture.findNearest(
                        5.6,
                        (a) => a.aperture < 3.4
                    );
                    expect(aperture.aperture).toStrictEqual(3.2);
                }
            );
            test(
                'Aperture.findNearest() fromm label',
                () => {
                    const aperture = api.Aperture.findNearest(
                        'f5.6',
                        (a) => a.aperture < 3.4
                    );
                    expect(aperture.aperture).toStrictEqual(3.2);
                }
            );
        }
    );
}
export default CommonApertureTests;
