import * as CameraApi from "../../stubs/public_api";

const CommonISOSensitivityTests = (api: typeof CameraApi) => {
    describe(
        'ISOSensitivity',
        () => {
            test(
                'ISOSensitivity.value for "Auto"',
                () => {
                    const sensitivity = new api.ISOSensitivity(api.ISOSensitivity.ID.Auto);
                    expect(sensitivity.value).toStrictEqual(api.ISOSensitivity.ID.Auto);
                }
            );
            test(
                'ISOSensitivity.label for "Auto"',
                () => {
                    const sensitivity = new api.ISOSensitivity(api.ISOSensitivity.ID.Auto);
                    expect(sensitivity.label).toStrictEqual("Auto");
                }
            );
            test(
                'ISOSensitivity.label for "Auto"',
                () => {
                    const sensitivity = new api.ISOSensitivity(api.ISOSensitivity.ID.Auto);
                    expect(sensitivity.sensitivity).toStrictEqual(0);
                }
            );
            test(
                'ISOSensitivity.label for "400"',
                () => {
                    const sensitivity = new api.ISOSensitivity(0x00000058);
                    expect(sensitivity.label).toStrictEqual("400");
                }
            );
            test(
                'ISOSensitivity.sensitivity for "400"',
                () => {
                    const sensitivity = new api.ISOSensitivity(0x00000058);
                    expect(sensitivity.label).toStrictEqual('400');
                    expect(sensitivity.sensitivity).toStrictEqual(400);
                }
            );
            test(
                'ISOSensitivity.forLabel("400")',
                () => {
                    const sensitivity = api.ISOSensitivity.forLabel('400');
                    expect(sensitivity.label).toStrictEqual('400');
                    expect(sensitivity.value).toStrictEqual(0x00000058);
                    expect(sensitivity.sensitivity).toStrictEqual(400);
                }
            );
            test(
                'ISOSensitivity.forLabel("invalid") expecting null',
                () => {
                    const sensitivity = api.ISOSensitivity.forLabel("invalid");
                    expect(sensitivity).toBeNull();
                }
            );
            test(
                'ISOSensitivity.findNearest() for 400',
                () => {
                    const sensitivity = api.ISOSensitivity.findNearest(0x00000058);
                    expect(sensitivity.sensitivity).toStrictEqual(400);
                }
            );
            test(
                'ISOSensitivity.findNearest() for 8000',
                () => {
                    const sensitivity = api.ISOSensitivity.findNearest(0x0000007b);
                    expect(sensitivity.sensitivity).toStrictEqual(8000);
                }
            );
            test(
                'ISOSensitivity.findNearest() filtering all expecting null',
                () => {
                    const sensitivity = api.ISOSensitivity.findNearest(0x0000007b, () => false);
                    expect(sensitivity).toBeNull();
                }
            );
            test(
                'ISOSensitivity.findNearest() filtering below 4000',
                () => {
                    const sensitivity = api.ISOSensitivity.findNearest(
                        0x0000007b,
                        (a) => a.sensitivity < 4000
                    );
                    expect(sensitivity.sensitivity).toStrictEqual(3200);
                }
            );
            test(
                'ISOSensitivity.findNearest() for label',
                () => {
                    const sensitivity = api.ISOSensitivity.findNearest(
                        "8000",
                        (a) => a.sensitivity < 4000
                    );
                    expect(sensitivity.sensitivity).toStrictEqual(3200);
                }
            );
        }
    );
}
export default CommonISOSensitivityTests;
