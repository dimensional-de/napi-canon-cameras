import {
    Camera, CameraProperty,
    DownloadRequestEvent, Option,
    watchCameras
} from '../';

process.on('SIGINT', () => process.exit());

try {
    const camera = new Camera();
    camera.connect();

    for (const volume of camera.getVolumes()) {
        console.log(volume);
    }
} catch (e) {
    console.log(e);
}

watchCameras();
