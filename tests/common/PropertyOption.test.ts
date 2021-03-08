import * as CameraApi from "../../stubs/public_api";

const CommonPropertyOptionTests = (api: typeof CameraApi) => {
    describe(
        'PropertyOption',
        () => {
            test(
                'PropertyOption for "PropertyOption.SaveTo.Host"',
                () => {
                    const option = new api.PropertyOption(
                        api.CameraProperty.ID.SaveTo,
                        api.PropertyOption.SaveTo.Host
                    );
                    expect(option.propertyID).toStrictEqual(api.CameraProperty.ID.SaveTo);
                    expect(option.value).toStrictEqual(api.PropertyOption.SaveTo.Host);
                    expect(option.label).toStrictEqual("SaveTo.Host");
                }
            );
            test(
                'PropertyOption.forLabel("SaveTo.Host")',
                () => {
                    const option = api.PropertyOption.forLabel('SaveTo.Host');
                    expect(option.propertyID).toStrictEqual(api.CameraProperty.ID.SaveTo);
                    expect(option.value).toStrictEqual(api.PropertyOption.SaveTo.Host);
                }
            );
            test(
                'PropertyOption.forLabel("invalid") expecting null',
                () => {
                    const option = api.PropertyOption.forLabel("invalid");
                    expect(option).toBeNull();
                }
            );
        }
    );
}
export default CommonPropertyOptionTests;