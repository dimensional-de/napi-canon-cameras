import { cameraBrowser, CameraBrowser, CameraProperty, watchCameras } from '../';
import { EventEmitter } from 'events';

const events = new EventEmitter();
events.on(
    CameraBrowser.EventName.PropertyChangeValue,
    (event) => {
        if (event.property.identifier === CameraProperty.ID.Evf_OutputDevice) {
            console.log(event.property.label, event.property.value);
        }
    }
);
events.on(
    CameraBrowser.EventName.LiveViewStart,
    (event) => {
        console.log('LV Started', event);
    }
);
events.on(
    CameraBrowser.EventName.LiveViewStop,
    (event) => {
        console.log('LV Stopped', event);
    }
);

cameraBrowser.setEventHandler(
    (eventName, ...args) => {
        //console.log('Emitted:', ...args);
        events.emit(eventName, ...args);
    }
);

process.on('SIGINT', () => process.exit());

try {
    const camera = cameraBrowser.getCamera();
    if (camera) {
        console.log(camera);
        camera.connect();
        console.log();
    }
    let liveMode = false;

    if (camera.getProperty(CameraProperty.ID.Evf_Mode).available) {
        camera.startLiveView();
        setInterval(
            () => {
                if (liveMode) {
                    camera.startLiveView();
                } else {
                    camera.stopLiveView();
                }
                liveMode = !liveMode;
            },
            5000
        );
        setInterval(
            () => {
                try {
                    console.log({image: camera.downloadLiveViewImage().substring(0, 20)});
                } catch (e) {
                    console.log(e);
                }
            },
            200
        );
    }

    watchCameras();
} catch (e) {
    console.log(e);
}


