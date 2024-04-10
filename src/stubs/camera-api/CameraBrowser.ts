import { ApiError } from './ApiError';
import { Camera } from './Camera';
import { CameraFile } from './CameraFile';
import { CameraProperty } from './CameraProperty';
import { Directory } from './Directory';
import { ObjectEvent } from './ObjectEvent';
import { StateEvent } from './StateEvent';
import { Volume } from './Volume';

export class CameraBrowser {

    [Symbol.toStringTag] = 'CameraBrowser';

    /**
     * Access to Canon Cameras
     *
     * @class CameraBrowser
     * @fires CameraBrowser#CameraAdd
     * @fires CameraBrowser#CameraRemove
     * @fires CameraBrowser#Error
     * @fires CameraBrowser#ObjectChange
     * @fires CameraBrowser#StateChange
     * @fires CameraBrowser#PropertyChangeValue
     * @fires CameraBrowser#PropertyChangeAllowed
     * @fires CameraBrowser#DownloadRequest
     * @fires CameraBrowser#LiveViewStart
     * @fires CameraBrowser#LiveViewStop
     *
     * @example
     * ```typescript
     * const {cameraBrowser, watchCameras} = require('@dimensional/napi-canon-cameras');
     * cameraBrowser.setEventHandler(
     *   (eventName, event) => { console.log(eventName, event); }
     * );
     *
     * process.on('SIGINT', () => process.exit());
     *
     * console.log(cameraBrowser.getCameras());
     *
     * watchCameras();
     * ```
     */
    constructor() {
    }

    /**
     * Set event handler callback
     * @param {EventCallback} listener
     */
    setEventHandler(listener: EventCallback) {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Initialize SDK
     */
    initialize() {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Terminate SDK and free all resources
     */
    terminate() {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Trigger SDK events
     */
    triggerEvents() {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Get camera at port or index. Returns the first camera in the internal list if
     * port or position is invalid. USe the exactOnly argument to disable the fallback.
     *
     * @param {string|number} [at] index or port name
     * @param {boolean} [exactOnly=false]
     */
    getCamera(at: string | number = 0, exactOnly = false): Camera {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Get currently connected cameras.
     *
     * @return {Camera[]}
     */
    getCameras(): Camera[] {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Update internal camera list
     */
    update() {
        throw new Error('Not implemented - stub only.');
    }

    // Generate: CameraBrowser

    /**
     * @readonly
     * @enum {string}
     */
    static readonly EventName: {[key: string]: string} = {
        'CameraAdd': 'CameraAdd',
        'CameraConnect': 'CameraConnect',
        'CameraDisconnect': 'CameraDisconnect',
        'CameraRemove': 'CameraRemove',
        'DirectoryCreate': 'DirectoryCreate',
        'DownloadRequest': 'DownloadRequest',
        'Error': 'Error',
        'FileCreate': 'FileCreate',
        'KeepAlive': 'KeepAlive',
        'LiveViewStart': 'LiveViewStart',
        'LiveViewStop': 'LiveViewStop',
        'ObjectChange': 'ObjectChange',
        'PropertyChangeOptions': 'PropertyChangeOptions',
        'PropertyChangeValue': 'PropertyChangeValue',
        'StateChange': 'StateChange',
        'VolumeChange': 'VolumeChange',
    };

    // GenerateEnd
}

let STUB = 1;

/**
 * New camera found
 * @event CameraBrowser#CameraAdd
 * @type {CameraDeviceEvent}
 * @property {Camera} camera
 */
STUB = 1;
/**
 * Camera removed or not found while enumerating current devices
 * @event CameraBrowser#CameraRemove
 * @type {CameraDeviceEvent}
 * @property {Camera} camera
 */
STUB = 1;
/**
 * Property value change
 * @event CameraBrowser#PropertyChangeValue
 * @type {PropertyChangeEvent}
 * @property {Camera} camera
 * @property {CameraProperty} property
 */
STUB = 1;
/**
 * Property value change
 * @event CameraBrowser#PropertyChangeOptions
 * @type {PropertyChangeEvent}
 * @property {Camera} camera
 * @property {CameraProperty} property
 */
STUB = 1;
/**
 * New image available for download
 * @event CameraBrowser#DownloadRequest
 * @type {DownloadRequestEvent}
 * @property {Camera} camera
 * @property {CameraFile} file
 */
STUB = 1;
/**
 * Generic object change event, for debugging
 * @event CameraBrowser#ObjectChange
 * @type {ObjectChangeEvent}
 * @property {Camera} camera
 * @property {ObjectEvent} objectEvent
 */
STUB = 1;
/**
 * Camera state changed
 * @event CameraBrowser#StateChange
 * @type {StateChangeEvent}
 * @property {Camera} camera
 * @property {StateChange} stateEvent
 */
/**
 * Camera live view started
 * @event CameraBrowser#LiveViewStart
 * @type {CameraDeviceEvent}
 * @property {Camera} camera
 */
/**
 * Camera live view stopped
 * @event CameraBrowser#LiveViewStop
 * @type {CameraDeviceEvent}
 * @property {Camera} camera
 */
STUB = 1;
/**
 * API Error
 * @event CameraBrowser#Error
 * @type {ApiError}
 */
STUB = 1;

/**
 * @interface CameraDeviceEvent
 * @property {Camera} camera
 */
STUB = 1;

/**
 * @interface PropertyChangeEvent
 * @extends CameraDeviceEvent
 * @property {Camera} camera
 * @property {CameraProperty} property
 */
STUB = 1;
/**
 * @interface FileChangeEvent
 * @extends CameraDeviceEvent
 * @property {Camera} camera
 * @property {CameraFile} file
 */
STUB = 1;
/**
 * @interface DirectoryChangeEvent
 * @extends CameraDeviceEvent
 * @property {Camera} camera
 * @property {CameraFile} file
 */
STUB = 1;
/**
 * @interface VolumeChangeEvent
 * @extends CameraDeviceEvent
 * @property {Camera} camera
 * @property {CameraFile} file
 */
STUB = 1;
/**
 * @interface ObjectChangeEvent
 * @extends CameraDeviceEvent
 * @property {Camera} camera
 * @property {ObjectEvent} objectEvent
 */
STUB = 1;
/**
 * @interface StateChangeEvent
 * @extends CameraDeviceEvent
 * @property {Camera} camera
 * @property {StateEvent} stateEvent
 */
STUB = 1;

export interface CameraDeviceEvent {
    camera: Camera;
}
export interface PropertyChangeEvent extends CameraDeviceEvent {
    camera: Camera;
    property: CameraProperty;
}
export interface FileChangeEvent extends CameraDeviceEvent {
    camera: Camera;
    file: CameraFile;
}
export interface DirectoryChangeEvent extends CameraDeviceEvent {
    camera: Camera;
    directory: Directory;
}
export interface VolumeChangeEvent extends CameraDeviceEvent {
    camera: Camera;
    volume: Volume;
}
export interface ObjectChangeEvent extends CameraDeviceEvent {
    camera: Camera;
    objectEvent: ObjectEvent;
}
export interface StateChangeEvent extends CameraDeviceEvent {
    camera: Camera;
    stateEvent: StateEvent;
}

export type EventCallback = (eventName: string, event: CameraDeviceEvent | ApiError) => void;

/**
 * @callback EventCallback
 * @param {string} eventName
 * @param {CameraDeviceEvent|ApiError} event
 */
STUB = 1;
