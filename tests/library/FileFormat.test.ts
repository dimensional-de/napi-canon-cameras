import * as util from 'util';
import * as CameraApi from '../../stubs/public_api';

const LibraryFileFormatTests = (api: typeof CameraApi) => {
    describe(
        'FileFormat',
        () => {
            test(
                'FileFormat[Symbol.for("nodejs.util.inspect.custom")] with "CR2"',
                () => {
                    const value = new api.FileFormat(api.FileFormat.ID.CR2);
                    expect(
                        util.inspect(value),
                    ).toBe('FileFormat <CR2>');
                },
            );
        },
    );
};
export default LibraryFileFormatTests;
