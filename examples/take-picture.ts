import {
    Camera,
    cameraBrowser, CameraProperty,
    DownloadRequestEvent, Option,
    watchCameras
} from '../';

process.on('exit', () => cameraBrowser.terminate());
process.on('SIGINT', () => process.exit());

try {
    // get first camera
    const camera = new Camera();
    // catch download request events
    camera.setEventHandler(
        (eventName, event) => {
            if (eventName === Camera.EventName.DownloadRequest) {
                const file = (event as DownloadRequestEvent).file;
                console.log(file);
                file.downloadToPath(__dirname + '/images');
                console.log(`Downloaded ${file.name}.`);

                process.exit();
            }
        }
    );
    console.log(camera);
    camera.connect();
    // configure
    camera.getProperty(CameraProperty.ID.SaveTo).value = Option.SaveTo.Host;
    camera.getProperty(CameraProperty.ID.ImageQuality).value = Option.ImageQuality.LargeJPEGFine;
    camera.getProperty(CameraProperty.ID.WhiteBalance).value = Option.WhiteBalance.Fluorescent;

    // trigger picture
    camera.takePicture();
} catch (e) {
    console.log('No camera found.');
}

// watch for camera events
watchCameras();


