import * as CameraApi from '../../stubs/public_api';

const CommonExposureCompensationTests = (api: typeof CameraApi) => {
    describe(
        'ExposureCompensation',
        () => {
            test(
                'ExposureCompensation.value for "0"',
                () => {
                    const value = new api.ExposureCompensation(0x00);
                    expect(value.value).toStrictEqual(0x00);
                },
            );
            test(
                'ExposureCompensation.label for "0"',
                () => {
                    const value = new api.ExposureCompensation(0x00);
                    expect(value.label).toStrictEqual('0');
                },
            );
            test(
                'ExposureCompensation.label for "Auto"',
                () => {
                    const value = new api.ExposureCompensation(0x00);
                    expect(value.compensation).toStrictEqual(0.0);
                },
            );
            test.onWindows(
                'ExposureCompensation.label for "+2 1/2"',
                () => {
                    const value = new api.ExposureCompensation(0x14);
                    expect(value.label).toBe('+2 1/2');
                },
            );
            test.onLinux(
                'ExposureCompensation.label for "+2 1/2" => "+2" (Linux Lib Bug)',
                () => {
                    const isStubs = expect.getState().testPath?.includes('stubs');
                    const value = new api.ExposureCompensation(0x14);
                    expect(value.label).toBe(isStubs ? '+2 1/2' : '+2');
                },
            );
            test(
                'ExposureCompensation.compensation for "+2 1/2"',
                () => {
                    const value = new api.ExposureCompensation(0x14);
                    expect(value.compensation).toStrictEqual(2.5);
                },
            );
            test.onWindows(
                'ExposureCompensation.forLabel("+1 1/3")',
                () => {
                    const value = api.ExposureCompensation.forLabel('+1 1/3');
                    expect(value).toBeTruthy();
                    if (value) {
                        expect(value.compensation).toStrictEqual(1 + (1 / 3));
                        expect(value.label).toStrictEqual('+1 1/3');
                        expect(value.value).toStrictEqual(0x0B);
                    }
                },
            );
            test.onLinux(
                'ExposureCompensation.forLabel("+1 1/3") => "+1" (Linux Lib Bug)',
                () => {
                    const isStubs = expect.getState().testPath?.includes('stubs');
                    const value = api.ExposureCompensation.forLabel('+1 1/3');
                    expect(value).toBeTruthy();
                    if (value) {
                        expect(value.compensation).toStrictEqual(1 + (1 / 3));
                        expect(value.label).toStrictEqual(isStubs ? '+1 1/3' : '+1');
                        expect(value.value).toStrictEqual(0x0B);
                    }
                },
            );
            test.onWindows(
                'ExposureCompensation.forLabel("+4 1/2")',
                () => {
                    const value = api.ExposureCompensation.forLabel('+4 1/2');
                    expect(value).toBeTruthy();
                    if (value) {
                        expect(value.compensation).toStrictEqual(4 + (1 / 2));
                        expect(value.label).toStrictEqual('+4 1/2');
                        expect(value.value).toStrictEqual(0x24);
                    }
                },
            );
            test.onLinux(
                'ExposureCompensation.forLabel("+4 1/2") => "+4" (Linux Lib Bug)',
                () => {
                    const isStubs = expect.getState().testPath?.includes('stubs');
                    const value = api.ExposureCompensation.forLabel('+4 1/2');
                    expect(value).toBeTruthy();
                    if (value) {
                        expect(value.compensation).toStrictEqual(4 + (1 / 2));
                        expect(value.label).toStrictEqual(isStubs ? '+4 1/2' : '+4');
                        expect(value.value).toStrictEqual(0x24);
                    }
                },
            );
            test.onWindows(
                'ExposureCompensation.forLabel("-3 2/3")',
                () => {
                    const value = api.ExposureCompensation.forLabel('-3 2/3');
                    expect(value).toBeTruthy();
                    if (value) {
                        expect(value.compensation).toStrictEqual(-3 - (2 / 3));
                        expect(value.label).toStrictEqual('-3 2/3');
                        expect(value.value).toStrictEqual(0xE3);
                    }
                },
            );
            test.onLinux(
                'ExposureCompensation.forLabel("-3 2/3") => "-3" (Linux Lib Bug)',
                () => {
                    const isStubs = expect.getState().testPath?.includes('stubs');
                    const value = api.ExposureCompensation.forLabel('-3 2/3');
                    expect(value).toBeTruthy();
                    if (value) {
                        expect(value.compensation).toStrictEqual(-3 - (2 / 3));
                        expect(value.label).toStrictEqual(isStubs ? '-3 2/3' : '-3');
                        expect(value.value).toStrictEqual(0xE3);
                    }
                },
            );
        },
    );
};
export default CommonExposureCompensationTests;
