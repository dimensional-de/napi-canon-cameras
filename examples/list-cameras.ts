import { cameraBrowser, watchCameras} from '../';

cameraBrowser.setEventHandler(
    (eventName, ...args) => {
        console.log('Emitted:', eventName, ...args);
    }
);

process.on('SIGINT', () => process.exit());

try {
    console.log(cameraBrowser.getCameras());
    watchCameras();
} catch (e) {
    console.log(e);
}
