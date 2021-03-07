const AddOn = require('node-gyp-build')(__dirname);

AddOn.watchCameras = (timeout) => {
    let running = true;
    const stop = () => {
        running = false;
    }
    const watch = async () => {
        while (running) {
            AddOn.cameraBrowser.triggerEvents();
            await new Promise(resolve => setTimeout(resolve, timeout));
        }
    };
    watch().finally();
    return stop;
}

/**
 * @type {CanonApi}
 */
module.exports = AddOn;