import * as CameraApi from "../../stubs/public_api";

const LibraryCameraPropertyTests = (api: typeof CameraApi) => {
    describe(
        'Camera',
        () => {
            beforeEach(
                () => api.cameraBrowser.initialize()
            );
            afterEach(
                () => api.cameraBrowser.terminate()
            );
            test(
                "Create CameraProperty with invalid Camera expecting exception",
                () => {
                    expect(
                        () => {
                            new api.CameraProperty(null as any, api.CameraProperty.ID.SaveTo)
                        }
                    ).toThrow(
                        "Property: Argument 0 must be a Camera instance."
                    )
                }
            );
        }
    );
}
export default LibraryCameraPropertyTests;