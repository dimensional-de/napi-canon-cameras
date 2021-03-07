import * as CameraApi from "../../stubs/public_api";

const LibraryCameraTests = (api: typeof CameraApi) => {
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
                "Create Camera at invalid index expecting exception",
                () => {
                    expect(
                        () => {
                            new api.Camera(999)
                        }
                    ).toThrow(
                        "EDSDK - DEVICE_NOT_FOUND"
                    )
                }
            );
            test(
                "Create Camera at invalid port name expecting exception",
                () => {
                    expect(
                        () => {
                            new api.Camera("invalid-port-name")
                        }
                    ).toThrow(
                        "EDSDK - DEVICE_NOT_FOUND"
                    )
                }
            );
        }
    );
}
export default LibraryCameraTests;