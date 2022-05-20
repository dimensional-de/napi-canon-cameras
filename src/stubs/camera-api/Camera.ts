/**
 * Represents a camera device
 *
 */
import { EventCallback } from "./CameraBrowser";
import { CameraProperty, PropertyValue } from "./CameraProperty";
import { Volume } from "./Volume";

type PropertyIdentifier = string|number;
type PropertiesData = {[key in PropertyIdentifier]?: PropertyValue};

export class Camera {

    [Symbol.toStringTag] = 'Camera';

    /**
     * Camera device
     * @class Camera
     * @param {number|string} [indexOrPort=0]
     */
    constructor(indexOrPort: number | string = 0) {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Set event handler callback
     * @param {EventCallback} listener
     */
    setEventHandler(listener: EventCallback) {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @readonly
     */
    get description(): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @readonly
     */
    get portName(): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Connect to device
     */
    connect(shouldKeepAlive = false): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Disconnect from device
     */
    disconnect(): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Fetch a camera property by ID or label
     * @param {number|string} propertyID
     * @param {number} specifier
     * @return {CameraProperty}
     */
    getProperty(propertyID: PropertyIdentifier, specifier: number = 0): CameraProperty {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @param {PropertyIdentifier} propertyID
     * @param {PropertyValue} value
     */
    setProperty(propertyID: PropertyIdentifier, value: PropertyValue): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @param {PropertiesData} properties
     */
    setProperties(properties: PropertiesData): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @param {number} command
     * @param {number} parameter
     */
    sendCommand(command: number, parameter: number = 0): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Trigger picture shot, successful shot will trigger an object event
     */
    takePicture(): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Return true if the LiveView is currently active
     * @returns {boolean}
     */
    isLiveViewActive(): boolean {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Request LiveView start, triggers event on success
     */
    startLiveView(): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Request LiveView stop, triggers event on success
     */
    stopLiveView(): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @return {string}
     */
    downloadLiveViewImage(): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @return {Volume[]}
     */
    getVolumes(): Volume[] {
        throw new Error("Not implemented - stub only.");
    }

    // Generate: Camera

    /**
     * @readonly
     * @enum {string}
     */
     static readonly EventName: {[label: string]: string} = {"CameraConnect":"CameraConnect","CameraDisconnect":"CameraDisconnect","DirectoryCreate":"DirectoryCreate","DownloadRequest":"DownloadRequest","Error":"Error","FileCreate":"FileCreate","KeepAlive":"KeepAlive","LiveViewStart":"LiveViewStart","LiveViewStop":"LiveViewStop","ObjectChange":"ObjectChange","PropertyChangeOptions":"PropertyChangeOptions","PropertyChangeValue":"PropertyChangeValue","StateChange":"StateChange","VolumeChange":"VolumeChange"};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Command: {[label: string]: number} = {"BulbEnd":3,"BulbStart":2,"DoClickWBEvf":260,"DoEvfAf":258,"DriveLensEvf":259,"DrivePowerZoom":269,"ExtendShutDownTimer":1,"MovieSelectSwOFF":264,"MovieSelectSwON":263,"PressShutterButton":4,"RequestRollPitchLevel":265,"RequestSensorCleaning":274,"SetRemoteShootingMode":271,"TakePicture":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly PressShutterButton: {[label: string]: number} = {"Completely":3,"CompletelyNonAF":65539,"Halfway":1,"HalfwayNonAF":65537,"OFF":0};

    // GenerateEnd
}
