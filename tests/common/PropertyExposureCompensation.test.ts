import * as CameraApi from "../../stubs/public_api";

const CommonPropertyExposureCompensationTests = (api: typeof CameraApi) => {
    describe(
        'PropertyExposureCompensation',
        () => {
            test(
                'PropertyExposureCompensation.value for "0"',
                () => {
                    const value = new api.PropertyExposureCompensation(0x00);
                    expect(value.value).toStrictEqual(0x00);
                }
            );
            test(
                'PropertyExposureCompensation.label for "0"',
                () => {
                    const value = new api.PropertyExposureCompensation(0x00);
                    expect(value.label).toStrictEqual("0");
                }
            );
            test(
                'PropertyExposureCompensation.label for "Auto"',
                () => {
                    const value = new api.PropertyExposureCompensation(0x00);
                    expect(value.compensation).toStrictEqual(0.0);
                }
            );
            test(
                'PropertyExposureCompensation.label for "+2 1/2"',
                () => {
                    const value = new api.PropertyExposureCompensation(0x14);
                    expect(value.label).toStrictEqual("+2 1/2");
                }
            );
            test(
                'PropertyExposureCompensation.compensation for "+2 1/2"',
                () => {
                    const value = new api.PropertyExposureCompensation(0x14);
                    expect(value.compensation).toStrictEqual(2.5);
                }
            );
            test(
                'PropertyExposureCompensation.forLabel("+1 1/3")',
                () => {
                    const value = api.PropertyExposureCompensation.forLabel('+1 1/3');
                    expect(value.compensation).toStrictEqual(1 + (1/3));
                    expect(value.label).toStrictEqual('+1 1/3');
                    expect(value.value).toStrictEqual(0x0B);
                }
            );
            test(
                'PropertyExposureCompensation.forLabel("+4 1/2")',
                () => {
                    const value = api.PropertyExposureCompensation.forLabel('+4 1/2');
                    expect(value.compensation).toStrictEqual(4 + (1/2));
                    expect(value.label).toStrictEqual('+4 1/2');
                    expect(value.value).toStrictEqual(0x24);
                }
            );
            test(
                'PropertyExposureCompensation.forLabel("-3 2/3")',
                () => {
                    const value = api.PropertyExposureCompensation.forLabel('-3 2/3');
                    expect(value.compensation).toStrictEqual(-3 - (2/3));
                    expect(value.label).toStrictEqual('-3 2/3');
                    expect(value.value).toStrictEqual(0xE3);
                }
            );
        }
    );
}
export default CommonPropertyExposureCompensationTests;
