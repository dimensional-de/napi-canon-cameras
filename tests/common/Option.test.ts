import * as CameraApi from '../../stubs/public_api';

const CommonOptionTests = (api: typeof CameraApi) => {
    describe(
        'Option',
        () => {
            test(
                'Option for "Option.SaveTo.Host"',
                () => {
                    const option = new api.Option(
                        api.CameraProperty.ID.SaveTo,
                        api.Option.SaveTo.Host,
                    );
                    expect(option.propertyID).toStrictEqual(api.CameraProperty.ID.SaveTo);
                    expect(option.value).toStrictEqual(api.Option.SaveTo.Host);
                    expect(option.label).toStrictEqual('SaveTo.Host');
                },
            );
            test(
                'Option.forLabel("SaveTo.Host")',
                () => {
                    const option = api.Option.forLabel('SaveTo.Host');
                    expect(option).toBeTruthy();
                    if (option) {
                        expect(option.propertyID).toStrictEqual(api.CameraProperty.ID.SaveTo);
                        expect(option.value).toStrictEqual(api.Option.SaveTo.Host);
                    }
                },
            );
            test(
                'Option.forLabel("invalid") expecting null',
                () => {
                    const option = api.Option.forLabel('invalid');
                    expect(option).toBeNull();
                },
            );
        },
    );
};
export default CommonOptionTests;
