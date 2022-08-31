import * as CameraApi from '../../stubs/public_api';

const CommonShutterSpeedTests = (api: typeof CameraApi) => {
    describe(
        'ShutterSpeed',
        () => {
            test(
                'ShutterSpeed.value for "Auto"',
                () => {
                    const shutterSpeed = new api.ShutterSpeed(api.ShutterSpeed.ID.Auto);
                    expect(shutterSpeed.value).toStrictEqual(api.ShutterSpeed.ID.Auto);
                },
            );
            test(
                'ShutterSpeed.label for "Auto"',
                () => {
                    const shutterSpeed = new api.ShutterSpeed(api.ShutterSpeed.ID.Auto);
                    expect(shutterSpeed.label).toStrictEqual('Auto');
                },
            );
            test(
                'ShutterSpeed.label for "Auto"',
                () => {
                    const shutterSpeed = new api.ShutterSpeed(api.ShutterSpeed.ID.Auto);
                    expect(shutterSpeed.seconds).toStrictEqual(0.0);
                },
            );
            test(
                'ShutterSpeed.label for "3"',
                () => {
                    const shutterSpeed = new api.ShutterSpeed(0x2C);
                    expect(shutterSpeed.label).toStrictEqual('3');
                },
            );
            test(
                'ShutterSpeed.seconds for "3"',
                () => {
                    const shutterSpeed = new api.ShutterSpeed(0x2C);
                    expect(shutterSpeed.seconds).toStrictEqual(3.0);
                },
            );
            test(
                'ShutterSpeed.forLabel("3")',
                () => {
                    const shutterSpeed = api.ShutterSpeed.forLabel('3');
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.value).toStrictEqual(0x2C);
                        expect(shutterSpeed.label).toStrictEqual('3');
                        expect(shutterSpeed.seconds).toStrictEqual(3.0);
                    }
                },
            );
            test(
                'ShutterSpeed.forLabel(1/400)',
                () => {
                    const shutterSpeed = api.ShutterSpeed.forLabel('1/400');
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.value).toStrictEqual(0x7D);
                        expect(shutterSpeed.label).toStrictEqual('1/400');
                        expect(shutterSpeed.seconds).toStrictEqual(0.0025);
                    }
                },
            );
            test(
                'ShutterSpeed.forLabel("1/6 (1/3)"))',
                () => {
                    const shutterSpeed = api.ShutterSpeed.forLabel('1/6 (1/3)');
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.value).toStrictEqual(0x4D);
                        expect(shutterSpeed.label).toStrictEqual('1/6 (1/3)');
                        expect(shutterSpeed.seconds).toStrictEqual(1/6);
                    }
                },
            );
            test(
                'ShutterSpeed.forLabel("invalid") expecting null',
                () => {
                    const shutterSpeed = api.ShutterSpeed.forLabel('invalid');
                    expect(shutterSpeed).toBeNull();
                },
            );
            test(
                'ShutterSpeed.findNearest()',
                () => {
                    const shutterSpeed = api.ShutterSpeed.findNearest(0x40);
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.seconds).toStrictEqual(0.5);
                    }
                },
            );
            test(
                'ShutterSpeed.findNearest()',
                () => {
                    const shutterSpeed = api.ShutterSpeed.findNearest(0x1B);
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.seconds).toStrictEqual(13);
                    }
                },
            );
            test(
                'ShutterSpeed.findNearest()',
                () => {
                    const shutterSpeed = api.ShutterSpeed.findNearest('1/400');
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.seconds).toStrictEqual(1.0 / 400);
                    }
                },
            );
            test(
                'ShutterSpeed.findNearest() filtering all expecting null',
                () => {
                    const shutterSpeed = api.ShutterSpeed.findNearest(0x2C, () => false);
                    expect(shutterSpeed).toBeNull();
                },
            );
            test(
                'ShutterSpeed.findNearest() filtering larger or equal 6',
                () => {
                    const shutterSpeed = api.ShutterSpeed.findNearest(
                        0x2C,
                        (speed) => speed.seconds >= 6,
                    );
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.seconds).toStrictEqual(6);
                    }
                },
            );
            test(
                'ShutterSpeed.findNearest() for label',
                () => {
                    const shutterSpeed = api.ShutterSpeed.findNearest(
                        '3',
                        (speed) => speed.seconds >= 6,
                    );
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.seconds).toStrictEqual(6);
                    }
                },
            );
            test(
                'ShutterSpeed.toJSON for "1/6"',
                () => {
                    const shutterSpeed = new api.ShutterSpeed(0x4C);
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.toJSON()).toEqual(
                            {
                                'seconds': 1 / 6,
                                'label': '1/6',
                                'stop': '1/2',
                                'value': 76,
                            },
                        );
                    }
                },
            );
            test(
                'ShutterSpeed.toJSON for "1/6 (1/3)"',
                () => {
                    const shutterSpeed = new api.ShutterSpeed(0x4D);
                    expect(shutterSpeed).toBeTruthy();
                    if (shutterSpeed) {
                        expect(shutterSpeed.toJSON()).toEqual(
                            {
                                'seconds': 1 / 6,
                                'label': '1/6 (1/3)',
                                'stop': '1/3',
                                'value': 77,
                            },
                        );
                    }
                },
            );
        },
    );
};
export default CommonShutterSpeedTests;
