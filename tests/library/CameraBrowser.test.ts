import * as util from 'util';
import * as CameraApi from '../../stubs/public_api';

const LibraryCameraBrowserTests = (api: typeof CameraApi) => {
    describe(
        'CameraBrowser',
        () => {
            beforeEach(
                () => api.cameraBrowser.initialize(),
            );
            afterEach(
                () => api.cameraBrowser.terminate(),
            );
            test(
                'cameraBrowser[Symbol.for("nodejs.util.inspect.custom")]',
                () => {
                    expect(
                        util.inspect(api.cameraBrowser),
                    ).toBe('CameraBrowser');
                },
            );
            test(
                'cameraBrowser.getCameras() returns array',
                () => {
                    const cameraList = api.cameraBrowser.getCameras();
                    expect(
                        Array.isArray(cameraList),
                    ).toBe(true);
                },
            );
            test(
                'Create CameraBrowser Instance',
                () => {
                    const cameras = new api.CameraBrowser();
                    const cameraList = api.cameraBrowser.getCameras();
                    expect(
                        Array.isArray(cameraList),
                    ).toBe(true);
                },
            );
            test(
                'cameraBrowser.setEventHandler() accepts callback',
                () => {
                    api.cameraBrowser.setEventHandler(
                        () => {
                            // dummy event
                        },
                    );
                },
            );
            test(
                'cameraBrowser.getCamera() at invalid index expecting null',
                () => {
                    expect(
                        api.cameraBrowser.getCamera(999, true),
                    ).toBeNull();
                },
            );
            test(
                'cameraBrowser.getCamera() at invalid port expecting null',
                () => {
                    expect(
                        api.cameraBrowser.getCamera('invalid-port-name', true),
                    ).toBeNull();
                },
            );
        },
    );
};
export default LibraryCameraBrowserTests;
