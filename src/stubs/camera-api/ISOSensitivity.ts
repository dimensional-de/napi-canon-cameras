import { PropertyValue } from "./CameraProperty";

export class ISOSensitivity implements PropertyValue {

    [Symbol.toStringTag] = 'ISOSensitivity';

    private readonly label_: string;
    private readonly sensitivity_: number;

    /**
     * ISO Sensitivity property value
     *
     * @class ISOSensitivity
     * @implements PropertyValue
     * @param {number} value_
     */
    constructor(
        private readonly value_: number
    ) {
        if (value_ === 0) {
            this.label_ = "Auto";
            this.sensitivity_ = 0;
        } else {
            this.sensitivity_ = ISOSensitivity.Values[value_] || 0;
            this.label_ = this.sensitivity_.toString();
        }
    }

    /**
     * @readonly
     * @type {string}
     */
    get label(): string {
        return this.label_
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
     * @type {number}
     */
    get sensitivity(): number {
        return this.sensitivity_;
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
     * @return {{label: string, value: number, sensitivity: number}}
     */
    toJSON(): { label: string, value: number, ISOSensitivity: number } {
        return {
            label: this.label,
            value: this.value,
            ISOSensitivity: this.sensitivity
        };
    }

    static findNearest(
        sensitivityOrLabel: number | string, filter: (sensitivity: ISOSensitivity) => boolean = null
    ): ISOSensitivity | null {
        let sensitivity: number;
        if (typeof sensitivityOrLabel === 'string') {
            const iso = ISOSensitivity.forLabel(sensitivityOrLabel);
            if (!iso) {
                return null;
            }
            sensitivity = iso.sensitivity;
        } else {
            sensitivity = +sensitivityOrLabel;
        }
        let found;
        found = Object.keys(ISOSensitivity.Values).reduce(
            (carry: null | { value: number, difference: number }, key) => {
                const current = ISOSensitivity.Values[key];
                const difference = Math.abs(current - sensitivity);
                if (!carry || difference < carry.difference) {
                    if (filter && !filter(new ISOSensitivity(+key))) {
                        return carry;
                    }
                    return {
                        value: +key,
                        difference
                    };
                }
                return carry;
            },
            null
        );
        if (found) {
            return new ISOSensitivity(found.value);
        }
        return null;
    }


    /**
     * Create instance for label.
     *
     * @param {string} label
     * @return {ISOSensitivity | null}
     */
    static forLabel(label: string): ISOSensitivity | null {
        if (label in ISOSensitivity.ID) {
            return new ISOSensitivity(ISOSensitivity.ID[label]);
        }
        const value = Object
            .keys(ISOSensitivity.Values)
            .find(key => ISOSensitivity.Values[key] === +label);
        if (value) {
            return new ISOSensitivity(+value);
        }
        return null;
    }

    // Generate: ISOSensitivity

    /**
     * @readonly
     * @enum {number}
     */
     static readonly ID = {"Auto":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Values = {"40":6,"48":12,"56":25,"64":50,"72":100,"75":125,"77":160,"80":200,"83":250,"85":320,"88":400,"91":500,"93":640,"96":800,"99":1000,"101":1250,"104":1600,"107":2000,"109":2500,"112":3200,"115":4000,"117":5000,"120":6400,"123":8000,"125":10000,"128":12800,"131":16000,"133":20000,"136":25600,"139":32000,"141":40000,"144":51200,"147":64000,"149":80000,"152":102400,"160":204800,"168":409600,"176":819200};

    // GenerateEnd
}
