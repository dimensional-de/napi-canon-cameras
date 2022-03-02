import { PropertyValue } from "./CameraProperty";

export class Flag implements PropertyValue {

    [Symbol.toStringTag] = 'Flag';

    private readonly label_: string;
    private readonly value_: number;

    /**
     * Boolean property value
     * @class Flag
     * @param {number | boolean} value
     */
    constructor(
        value: number | boolean
    ) {
        if (typeof value === "boolean") {
            this.value_ = value ? Flag.True : Flag.False;
        } else if (value === Flag.True) {
            this.value_ = Flag.True;
        } else {
            this.value_ = Flag.False;
        }
        if (this.value_ === Flag.True) {
            this.label_ = 'true';
        } else {
            this.label_ = 'false';
        }
    }

    /**
     * @readonly
     * @type {string}
     */
    get label(): string {
        return this.label_;
    }

    /**
     * @readonly
     * @type {number}
     */
    get value(): number {
        return this.value_;
    }

    /**
     * @readonly
     * @type {boolean}
     */
    get flag(): boolean {
        return this.value_ !== 0;
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
     * @return {{label: string, value: number, flag: boolean}}
     */
    toJSON(): {label: string, value: number, flag: boolean} {
        return {
            label: this.label,
            value: this.value,
            flag: this.flag
        };
    }

    /**
     * Create instance for label.
     *
     * @param {string} label
     * @return {Flag}
     */
    static forLabel(label: string): Flag | null {
        if (['true', '1', 'yes', 'on'].indexOf(label.toLowerCase()) >= 0) {
            return new Flag(Flag.True);
        }
        return new Flag(Flag.False);
    }

    // Generate: Flag

    /**
     * @readonly
     * @type {number}
     */
     static readonly True = 1;
    /**
     * @readonly
     * @type {number}
     */
     static readonly False = 0;

    // GenerateEnd
}
