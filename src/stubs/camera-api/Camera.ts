/**
 * Represents a camera device
 *
 */
import { EventCallback } from "./CameraBrowser";
import {CameraProperty} from "./CameraProperty";
import { Volume } from "./Volume";

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
    connect(): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Disconnect from device
     */
    disconnect(): void {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Fetch a camera property by ID
     */
    getProperty(propertyID: number, specifier: number = 0): CameraProperty {
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
     static readonly EventName = {"DownloadRequest":"download-request","Error":"error","LiveViewStart":"camera-lv-start","LiveViewStop":"camera-lv-stop","ObjectChange":"object-change","PropertyChangeOptions":"property-change.allowed","PropertyChangeValue":"property-change.value","StateChange":"camera-state"};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Command = {"BulbEnd":3,"BulbStart":2,"DoClickWBEvf":260,"DoEvfAf":258,"DriveLensEvf":259,"DrivePowerZoom":269,"ExtendShutDownTimer":1,"MovieSelectSwOFF":264,"MovieSelectSwON":263,"PressShutterButton":4,"RequestRollPitchLevel":265,"SetRemoteShootingMode":271,"TakePicture":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly PressShutterButton = {"Completely":3,"CompletelyNonAF":65539,"Halfway":1,"HalfwayNonAF":65537,"OFF":0};

    // GenerateEnd
}
