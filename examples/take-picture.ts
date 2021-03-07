import {
    cameraBrowser, CameraBrowser, CameraProperty, DownloadRequestEvent, PropertyOption, watchCameras
} from '../';

process.on('exit', () => cameraBrowser.terminate());
process.on('SIGINT', () => process.exit());

// catch download request events
cameraBrowser.setEventHandler(
    (eventName, event) => {
        if (eventName === CameraBrowser.Events.DownloadRequest) {
            const file = (event as DownloadRequestEvent).file;
            console.log(file);
            const localFile = file.downloadToPath(__dirname + '/images');
            console.log(`Downloaded ${file.name}.`);

            process.exit();
        }
    }
);

// get first camera
const camera = cameraBrowser.getCamera();
if (camera) {
    console.log(camera);
    camera.connect();
    // configure
    camera.getProperty(CameraProperty.ID.SaveTo).value = PropertyOption.SaveTo.Host;
    camera.getProperty(CameraProperty.ID.ImageQuality).value = PropertyOption.ImageQuality.LargeJPEGFine;
    camera.getProperty(CameraProperty.ID.WhiteBalance).value = PropertyOption.WhiteBalance.Fluorescent;

    // trigger picture
    camera.takePicture();
} else {
    console.log('No camera found.');
}

// watch for camera events
watchCameras();


