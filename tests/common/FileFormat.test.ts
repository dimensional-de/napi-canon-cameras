import * as CameraApi from "../../stubs/public_api";

const CommonFileFormatTests = (api: typeof CameraApi) => {
    describe(
        'FileFormat',
        () => {
            test(
                'FileFormat for "FileFormat.ID.CR2"',
                () => {
                    const FileFormat = new api.FileFormat(api.FileFormat.ID.CR2);
                    expect(FileFormat.value).toStrictEqual(api.FileFormat.ID.CR2);
                    expect(FileFormat.label).toStrictEqual("CR2");
                }
            );
            test(
                'FileFormat for "FileFormat.ID.CR3"',
                () => {
                    const FileFormat = new api.FileFormat(api.FileFormat.ID.CR3);
                    expect(FileFormat.value).toStrictEqual(api.FileFormat.ID.CR3);
                    expect(FileFormat.label).toStrictEqual("CR3");
                }
            );
            test(
                'FileFormat for unknown format',
                () => {
                    const FileFormat = new api.FileFormat(0x42);
                    expect(FileFormat.label).toStrictEqual("0x00000042");
                }
            );
        }
    );
}
export default CommonFileFormatTests;
