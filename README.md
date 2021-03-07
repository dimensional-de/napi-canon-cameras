# @dimensional/napi-canon-cameras

EDSDK (Canon camera) wrapper module for Node.js

* [Features](#features)
* [Usage Example](#usage)
* [Build Package](#build-package)
  * [NPM Tasks](#npm-tasks)
* [FAQ](#faq)
* [API Documentation](API.md)

## Features

The EDSDK provides a lot of features and not all of them are
implemented in the module. Our use case was a photo booth 
application.

- [x] List Cameras
- [x] Camera Events
- [ ] Read Camera Properties
    - [x] Text
    - [x] Integer
    - [x] Integer Array
    - [x] Time
    - [x] Flags (true/false)
    - [x] Options (named list values)
    - [x] Aperture
    - [x] Shutter Speed
- [ ] Write Camera Properties
    - [ ] Text Properties
    - [x] Integer
    - [ ] Integer Array
    - [ ] Time
    - [x] Flags (true/false)
    - [x] Options (named list values)
    - [x] Aperture
    - [x] Shutter Speed
- [x] Take Picture
    - [x] Download To Directory
    - [x] Download To File
    - [x] Download To String (Base64)
- [x] Live View

## Usage

```typescript
import {
    cameraBrowser, CameraBrowser, CameraProperty, DownloadRequestEvent, PropertyOption, watchCameras
} from '../';

process.on('exit', () => cameraBrowser.terminate() );
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
```
 
## Build Package

The package does not include the Canon EDSDK files. To install the package you will have to build a TGZ.
 
 1. Unpack the Canon EDSDK as `EDSDK` subdirectory into `third_party`.
 2. Run `npm run package`
 3. Look for `../node_packages/@dimensional/napi-canon-cameras.tgz`
 4. `cd ../YourProject` (Switch tp your project directory)
 5. `npm -i ../node_packages/@dimensional/napi-canon-cameras.tgz`

### NPM Tasks

* `package` - Create TGZ package for AddOn
* `prebuild` - Build for 32 and 64bit Node.js
* `prebuild:x64` - Build for 64bit Node.js
* `prebuild:ia32` - Build for 32bit Node.js
* `build:docs` - Update API documentation in README.md
* `build:stubs` - Update and build stubs (needs prebuild AddOn)
* `clean` - Remove build artifacts

## FAQ

### Does the module work in Electron Applications?

Yes.

