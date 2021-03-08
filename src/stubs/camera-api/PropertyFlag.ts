export class PropertyFlag {

    [Symbol.toStringTag] = 'PropertyFlag';

    private readonly label_: string;
    private readonly value_: number;

    /**
     * Boolean property value
     * @class PropertyFlag
     * @param {number | boolean} value
     */
    constructor(
        value: number | boolean
    ) {
        if (typeof value === "boolean") {
            this.value_ = value ? PropertyFlag.True : PropertyFlag.False;
        } else if (value === PropertyFlag.True) {
            this.value_ = PropertyFlag.True;
        } else {
            this.value_ = PropertyFlag.False;
        }
        if (this.value_ === PropertyFlag.True) {
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
    [Symbol.toPrimitive](hint): string | number | null {
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
     * @return {PropertyFlag}
     */
    static forLabel(label: string): PropertyFlag | null {
        if (['true', '1', 'yes', 'on'].indexOf(label.toLowerCase()) >= 0) {
            return new PropertyFlag(PropertyFlag.True);
        }
        return new PropertyFlag(PropertyFlag.False);
    }

    // Generate: PropertyFlag

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