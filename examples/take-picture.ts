import {
    Camera, CameraProperty,
    DownloadRequestEvent, Option,
    watchCameras
} from '../';

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
    camera.setProperties(
        {
            [CameraProperty.ID.SaveTo]: Option.SaveTo.Host,
            [CameraProperty.ID.ImageQuality]: Option.ImageQuality.LargeJPEGFine,
            [CameraProperty.ID.WhiteBalance]: Option.WhiteBalance.Fluorescent
        }
    );

    // trigger picture
    camera.takePicture();
} catch (e) {
    console.log('Failed.', e);
}

// watch for camera events
watchCameras();


