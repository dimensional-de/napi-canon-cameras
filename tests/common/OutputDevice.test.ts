import * as CameraApi from "../../stubs/public_api";

const CommonOutputDeviceTests = (api: typeof CameraApi) => {
    describe(
        'OutputDevice',
        () => {
            test(
                'OutputDevice for no output device',
                () => {
                    const devices = new api.OutputDevice(api.OutputDevice.ID.None);
                    expect(devices.value).toStrictEqual(api.OutputDevice.ID.None);
                    expect(
                        {
                            "devices": {
                                "Mobile": false,
                                "Mobile2": false,
                                "PC": false,
                                "TFT": false,
                            },
                            "label": "None",
                            "value": api.OutputDevice.ID.None,
                        }
                    ).toEqual(devices.toJSON());
                }
            );
            test(
                'OutputDevice for single output device (PC)',
                () => {
                    const devices = new api.OutputDevice(api.OutputDevice.ID.PC);
                    expect(devices.value).toStrictEqual(api.OutputDevice.ID.PC);
                    expect(
                        {
                            "devices": {
                                "Mobile": false,
                                "Mobile2": false,
                                "PC": true,
                                "TFT": false,
                            },
                            "label": "PC",
                            "value": api.OutputDevice.ID.PC,
                        }
                    ).toEqual(devices.toJSON());
                }
            );
            test(
                'OutputDevice for multiple output device (PC, Mobile)',
                () => {
                    const devices = new api.OutputDevice(api.OutputDevice.ID.PC | api.OutputDevice.ID.Mobile);
                    expect(devices.value).toStrictEqual(api.OutputDevice.ID.PC | api.OutputDevice.ID.Mobile);
                    expect(
                        {
                            "devices": {
                                "Mobile": true,
                                "Mobile2": false,
                                "PC": true,
                                "TFT": false,
                            },
                            "label": "Mobile, PC",
                            "value": api.OutputDevice.ID.PC | api.OutputDevice.ID.Mobile,
                        }
                    ).toEqual(devices.toJSON());
                }
            );
            test(
                'OutputDevice.forLabel("PC, Mobile")',
                () => {
                    const devices = api.OutputDevice.forLabel("PC, Mobile");
                    expect(devices.value).toStrictEqual(
                        api.OutputDevice.ID.PC | api.OutputDevice.ID.Mobile
                    );
                }
            );
            test(
                'OutputDevice.isEnabled() expecting true',
                () => {
                    const devices = api.OutputDevice.forLabel("PC, Mobile");
                    expect(devices.isEnabled(api.OutputDevice.ID.PC)).toBeTruthy();
                }
            );
            test(
                'OutputDevice.isEnabled() expecting false',
                () => {
                    const devices = api.OutputDevice.forLabel("PC, Mobile");
                    expect(devices.isEnabled(api.OutputDevice.ID.Mobile2)).toBeFalsy();
                }
            );
        }
    );
}
export default CommonOutputDeviceTests;
