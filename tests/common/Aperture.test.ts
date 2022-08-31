import * as CameraApi from '../../stubs/public_api';

const CommonApertureTests = (api: typeof CameraApi) => {
    describe(
        'Aperture',
        () => {
            test(
                'Aperture.value for "Auto"',
                () => {
                    const aperture = new api.Aperture(api.Aperture.ID.Auto);
                    expect(aperture.value).toStrictEqual(api.Aperture.ID.Auto);
                },
            );
            test(
                'Aperture.label for "Auto"',
                () => {
                    const aperture = new api.Aperture(api.Aperture.ID.Auto);
                    expect(aperture.label).toStrictEqual('Auto');
                },
            );
            test(
                'Aperture.label for "Auto"',
                () => {
                    const aperture = new api.Aperture(api.Aperture.ID.Auto);
                    expect(aperture.aperture).toStrictEqual(0.0);
                },
            );
            test(
                'Aperture.label for "5.6"',
                () => {
                    const aperture = new api.Aperture(0x30);
                    expect(aperture.label).toStrictEqual('f5.6');
                },
            );
            test(
                'Aperture.aperture for "5.6"',
                () => {
                    const aperture = new api.Aperture(0x30);
                    expect(aperture.label).toStrictEqual('f5.6');
                    expect(aperture.aperture).toStrictEqual(5.6);
                },
            );
            test(
                'Aperture.forLabel("f5.6")',
                () => {
                    const aperture = api.Aperture.forLabel('f5.6');
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.label).toStrictEqual('f5.6');
                        expect(aperture.value).toStrictEqual(0x30);
                        expect(aperture.aperture).toStrictEqual(5.6);
                    }
                },
            );
            test(
                'Aperture.forLabel("f3.5 (1/3)")',
                () => {
                    const aperture = api.Aperture.forLabel('f3.5 (1/3)');
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.label).toStrictEqual('f3.5 (1/3)');
                        expect(aperture.value).toStrictEqual(0x25);
                        expect(aperture.aperture).toStrictEqual(3.5);
                    }
                },
            );
            test(
                'Aperture.forLabel("invalid") expecting null',
                () => {
                    const aperture = api.Aperture.forLabel('invalid');
                    expect(aperture).toBeNull();
                },
            );
            test(
                'Aperture.findNearest() for 3.4',
                () => {
                    const aperture = api.Aperture.findNearest(0x85);
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.aperture).toStrictEqual(3.4);
                    }
                },
            );
            test(
                'Aperture.findNearest() for 5.6',
                () => {
                    const aperture = api.Aperture.findNearest(0x30);
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.aperture).toStrictEqual(5.6);
                    }
                },
            );
            test(
                'Aperture.findNearest() filtering all expecting null',
                () => {
                    const aperture = api.Aperture.findNearest(0x30, () => false);
                    expect(aperture).toBeNull();
                },
            );
            test(
                'Aperture.findNearest() filtering below 3.4',
                () => {
                    const aperture = api.Aperture.findNearest(
                        0x30,
                        (a) => a.aperture < 3.4,
                    );
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.aperture).toStrictEqual(3.2);
                    }
                },
            );
            test(
                'Aperture.findNearest() for label',
                () => {
                    const aperture = api.Aperture.findNearest(
                        'f5.6',
                        (a) => a.aperture < 3.4,
                    );
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.aperture).toStrictEqual(3.2);
                    }
                },
            );
            test(
                'Aperture.toJSON for "f3.5"',
                () => {
                    const aperture = new api.Aperture(0x24);
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.toJSON()).toEqual(
                            {
                                'aperture': 3.5,
                                'label': 'f3.5',
                                'stop': '1/2',
                                'value': 36,
                            },
                        );
                    }
                },
            );
            test(
                'Aperture.toJSON for "f3.5 (1/3)"',
                () => {
                    const aperture = new api.Aperture(0x25);
                    expect(aperture).toBeTruthy();
                    if (aperture) {
                        expect(aperture.toJSON()).toEqual(
                            {
                                'aperture': 3.5,
                                'label': 'f3.5 (1/3)',
                                'stop': '1/3',
                                'value': 37,
                            },
                        );
                    }
                },
            );
        },
    );
};
export default CommonApertureTests;
