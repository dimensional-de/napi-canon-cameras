import { Aperture } from "./Aperture";
import { ApiError } from "./ApiError";
import { Camera } from "./Camera";
import { CameraBrowser, EventCallback } from "./CameraBrowser";
import { CameraFile } from "./CameraFile";
import { CameraProperty } from "./CameraProperty";
import { Directory } from "./Directory";
import { ExposureCompensation } from "./ExposureCompensation";
import { Flag } from "./Flag";
import { ImageQuality } from "./ImageQuality";
import { ISOSensitivity } from "./ISOSensitivity";
import { ObjectEvent } from "./ObjectEvent";
import { Option } from "./Option";
import { OutputDevice } from "./OutputDevice";
import { ShutterSpeed } from "./ShutterSpeed";
import { StateEvent } from "./StateEvent";
import { TimeZone } from "./TimeZone";
import { Volume } from "./Volume";

export * from "./Aperture";
export * from "./ApiError";
export * from "./Camera";
export * from "./CameraBrowser";
export * from "./CameraFile";
export * from "./CameraProperty";
export * from "./Directory";
export * from "./ExposureCompensation";
export * from "./Flag";
export * from "./ImageQuality";
export * from "./ISOSensitivity";
export * from "./ObjectEvent";
export * from "./Option";
export * from "./OutputDevice";
export * from "./ShutterSpeed";
export * from "./StateEvent";
export * from "./TimeZone";
export * from "./Volume";

let STUB = 1;
/**
 * @external toPrimitive
 * @type {Symbol}
 */
STUB = 1;

/**
 * Watch for camera events
 * @param {int} [timeout=1000]
 * @return {Function} stop
 */
export const watchCameras = (timeout = 1000): (() => void) => {
    throw new Error("Not implemented - stub only.");
};
/**
 * Global CameraBrowser instance
 * @type {CameraBrowser}
 */
export const cameraBrowser = new CameraBrowser();

/**
 * @module CameraApi
 */
const CameraApi = {
    Aperture,
    ApiError,
    Camera,
    CameraBrowser,
    CameraFile,
    CameraProperty,
    Directory,
    ExposureCompensation,
    Flag,
    ImageQuality,
    ISOSensitivity,
    ObjectEvent,
    Option,
    OutputDevice,
    ShutterSpeed,
    StateEvent,
    TimeZone,
    Volume,
    /**
     * Global CameraBrowser instance
     * @type {CameraBrowser}
     */
    cameraBrowser,
    /**
     * Watch for camera events
     * @param {int} [timeout=1000]
     * @return {Function} stop
     */
    watchCameras
}
export default CameraApi;
