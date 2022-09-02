import * as CameraApi from '../../stubs/public_api';

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
                            'devices': {
                                'PCSmall': false,
                                'PC': false,
                                'TFT': false,
                            },
                            'label': 'None',
                            'value': api.OutputDevice.ID.None,
                        },
                    ).toEqual(devices.toJSON());
                },
            );
            test(
                'OutputDevice for single output device (PC)',
                () => {
                    const devices = new api.OutputDevice(api.OutputDevice.ID.PC);
                    expect(devices.value).toStrictEqual(api.OutputDevice.ID.PC);
                    expect(
                        {
                            'devices': {
                                'PCSmall': false,
                                'PC': true,
                                'TFT': false,
                            },
                            'label': 'PC',
                            'value': api.OutputDevice.ID.PC,
                        },
                    ).toEqual(devices.toJSON());
                },
            );
            test(
                'OutputDevice for multiple output device (PC, Mobile)',
                () => {
                    const devices = new api.OutputDevice(api.OutputDevice.ID.PC | api.OutputDevice.ID.PCSmall);
                    expect(devices.value).toStrictEqual(api.OutputDevice.ID.PC | api.OutputDevice.ID.PCSmall);
                    expect(
                        {
                            'devices': {
                                'PCSmall': true,
                                'PC': true,
                                'TFT': false,
                            },
                            'label': 'PC, PCSmall',
                            'value': api.OutputDevice.ID.PC | api.OutputDevice.ID.PCSmall,
                        },
                    ).toEqual(devices.toJSON());
                },
            );
            test(
                'OutputDevice.forLabel("PC, PCSmall")',
                () => {
                    const devices = api.OutputDevice.forLabel('PC, PCSmall');
                    expect(devices).toBeTruthy();
                    if (devices) {
                        expect(devices.value).toStrictEqual(
                            api.OutputDevice.ID.PC | api.OutputDevice.ID.PCSmall,
                        );
                    }
                },
            );
            test(
                'OutputDevice.isEnabled() expecting true',
                () => {
                    const devices = api.OutputDevice.forLabel('PC, PCSmall');
                    expect(devices).toBeTruthy();
                    if (devices) {
                        expect(devices.isEnabled(api.OutputDevice.ID.PC)).toBeTruthy();
                    }
                },
            );
            test(
                'OutputDevice.isEnabled() expecting false',
                () => {
                    const devices = api.OutputDevice.forLabel('PC, PCSmall');
                    expect(devices).toBeTruthy();
                    if (devices) {
                        expect(devices.isEnabled(api.OutputDevice.ID.TFT)).toBeFalsy();
                    }
                },
            );
        },
    );
};
export default CommonOutputDeviceTests;
