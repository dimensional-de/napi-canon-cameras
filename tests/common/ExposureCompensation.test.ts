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
            test(
                'ExposureCompensation.label for "+2 1/2"',
                () => {
                    const value = new api.ExposureCompensation(0x14);
                    expect(value.label).toStrictEqual('+2 1/2');
                },
            );
            test(
                'ExposureCompensation.compensation for "+2 1/2"',
                () => {
                    const value = new api.ExposureCompensation(0x14);
                    expect(value.compensation).toStrictEqual(2.5);
                },
            );
            test(
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
            test(
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
            test(
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
        },
    );
};
export default CommonExposureCompensationTests;
