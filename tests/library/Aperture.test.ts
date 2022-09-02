import * as util from 'util';
import * as CameraApi from '../../stubs/public_api';

const LibraryApertureTests = (api: typeof CameraApi) => {
    describe(
        'Aperture',
        () => {
            test(
                'Aperture[Symbol.for("nodejs.util.inspect.custom")] with known value code',
                () => {
                    const value = new api.Aperture(api.Aperture.ID.Auto);
                    expect(
                        util.inspect(value),
                    ).toBe('Aperture <Auto>');
                },
            );
            test(
                'Aperture[Symbol.for("nodejs.util.inspect.custom")] with value f40',
                () => {
                    const value = new api.Aperture(0x5D);
                    expect(
                        util.inspect(value),
                    ).toBe('Aperture <f40>');
                },
            );
        },
    );
};
export default LibraryApertureTests;
