import {
    Camera, watchCameras
} from '../';

process.on('SIGINT', () => process.exit());

try {
    const camera = new Camera();
    camera.connect();

    for (const volume of camera.getVolumes()) {
        console.log(volume);
        console.log(JSON.parse(JSON.stringify(volume)));
    }
} catch (e) {
    console.log(e);
}

process.exit();
