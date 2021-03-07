import { ApiError } from "./ApiError";
import { Camera } from "./Camera";
import { CameraBrowser, EventCallback } from "./CameraBrowser";
import { CameraFile } from "./CameraFile";
import { CameraProperty } from "./CameraProperty";
import { ObjectEvent } from "./ObjectEvent";
import { PropertyAperture } from "./PropertyAperture";
import { PropertyFlag } from "./PropertyFlag";
import { PropertyOption } from "./PropertyOption";
import { PropertyShutterSpeed } from "./PropertyShutterSpeed";
import { StateEvent } from "./StateEvent";

export * from "./ObjectEvent";
export * from "./PropertyOption";
export * from "./Camera";
export * from "./ApiError";
export * from "./CameraBrowser";
export * from "./CameraFile";
export * from "./CameraProperty";
export * from "./PropertyAperture";
export * from "./PropertyFlag";
export * from "./PropertyShutterSpeed";
export * from "./StateEvent";

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
    ApiError,
    Camera,
    CameraBrowser,
    CameraFile,
    CameraProperty,
    ObjectEvent,
    PropertyOption,
    PropertyShutterSpeed,
    PropertyAperture,
    PropertyFlag,
    StateEvent,
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