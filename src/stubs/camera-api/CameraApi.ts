import { ApiError } from "./ApiError";
import { Camera } from "./Camera";
import { CameraBrowser, EventCallback } from "./CameraBrowser";
import { CameraFile } from "./CameraFile";
import { CameraProperty } from "./CameraProperty";
import { ObjectEvent } from "./ObjectEvent";
import { Aperture } from "./Aperture";
import { ExposureCompensation } from "./ExposureCompensation";
import { Flag } from "./Flag";
import { Option } from "./Option";
import { ShutterSpeed } from "./ShutterSpeed";
import { StateEvent } from "./StateEvent";
import { Volume } from "./Volume";

export * from "./ObjectEvent";
export * from "./Option";
export * from "./Camera";
export * from "./ApiError";
export * from "./CameraBrowser";
export * from "./CameraFile";
export * from "./CameraProperty";
export * from "./Aperture";
export * from "./Flag";
export * from "./ShutterSpeed";
export * from "./ExposureCompensation";
export * from "./StateEvent";
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
    ExposureCompensation,
    Flag,
    ObjectEvent,
    Option,
    ShutterSpeed,
    StateEvent,
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
