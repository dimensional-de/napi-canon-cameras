import {
    Camera, Directory, watchCameras
} from '../';

process.on('SIGINT', () => process.exit());

try {
    const camera = new Camera();
    camera.connect();

    for (const volume of camera.getVolumes()) {
        console.log(volume);
        for (const entry of volume.getEntries()) {
            console.log(entry);
        }
    }
} catch (e) {
    console.log(e);
}

process.exit();
