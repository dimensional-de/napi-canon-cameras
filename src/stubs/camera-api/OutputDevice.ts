import { PropertyValue } from "./CameraProperty";

type OutputDeviceStatusList = {[deviceName: string]: boolean};

export class OutputDevice implements PropertyValue {

    [Symbol.toStringTag] = 'OutputDevice';

    private readonly label_: string = '';
    private readonly value_: number;

    /**
     * Boolean property value
     * @class Flag
     * @param {number | boolean} value
     */
    constructor(
        value: number
    ) {
        this.value_ = value;
        const deviceNames = [];
        for (const deviceName of Object.keys(OutputDevice.ID)) {
            if (
                OutputDevice.ID[deviceName] > 0 &&
                this.isEnabled(OutputDevice.ID[deviceName])
            ) {
                deviceNames.push(deviceName)
            }
        }
        this.label_ = deviceNames.join(', ');
    }

    /**
     * @readonly
     * @type {string}
     */
    get label(): string {
        return (this.label_) ? this.label_ : 'None';
    }

    /**
     * @readonly
     * @type {number}
     */
    get value(): number {
        return this.value_;
    }

    /**
     * Allows type cast to number - returns the value.
     * @param {string} hint
     * @return { number | string | null}
     */
    [Symbol.toPrimitive](hint: string): string | number | null {
        switch (hint) {
            case 'number':
                return this.value_;
            case 'string':
                return this.label_;
            default:
                return null;
        }
    }

    /**
     * @param {number} deviceID
     * @return {boolean}
     */
    isEnabled(deviceID: number): boolean {
        return (deviceID > 0 && (this.value_ & deviceID) === deviceID);
    }

    /**
     * @returns {OutputDeviceStatusList}
     */
    getDevices(): OutputDeviceStatusList {
        const devices: {[name: string]: boolean} = {};
        for (const deviceName of Object.keys(OutputDevice.ID)) {
            if (OutputDevice.ID[deviceName] > 0) {
                devices[deviceName] = this.isEnabled(OutputDevice.ID[deviceName])
            }
        }
        return devices;
    }

    /**
     * @return {{label: string, value: number, devices: OutputDeviceStatusList}}
     */
    toJSON(): {label: string, value: number, devices: OutputDeviceStatusList} {
        return {
            label: this.label,
            value: this.value,
            devices: this.getDevices()
        };
    }

    /**
     * Create instance for label.
     *
     * @param {string} label
     * @return {OutputDevice}
     */
    static forLabel(label: string): OutputDevice | null {
        const deviceNames = label.match(/[\w\d]+/g) || [];
        let value = OutputDevice.ID.None;
        for (const deviceName of deviceNames) {
            if (deviceName in OutputDevice.ID) {
                value |= OutputDevice.ID[deviceName]
            }
        }
        return new OutputDevice(value);
    }

    // Generate: OutputDevice

    /**
     * @readonly
     * @enum {number}
     */
     static readonly ID: {[label: string]: number} = {"None":0,"PC":2,"PCSmall":8,"TFT":1};

    // GenerateEnd
}
