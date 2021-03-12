import { PropertyValue } from "./CameraProperty";

export class PropertyExposureCompensation implements PropertyValue {

    [Symbol.toStringTag] = 'PropertyExposureCompensation';

    private readonly compensation_: number;
    private readonly label_: string;

    /**
     * Encapsulate Object for a exposure compensation value
     * @class PropertyExposureCompensation
     * @param {number} value_
     */
    constructor(
        private readonly value_: number
    ) {
        this.compensation_ = PropertyExposureCompensation.Values[value_] || 0;
        this.label_ = PropertyExposureCompensation.getLabelForCompensation(this.compensation_);
    }

    private static getLabelForCompensation(compensation: number): string {
        let label = '';
        if (compensation === 0) {
            return "0";
        }
        const full = compensation > 0 ? Math.floor(compensation) : Math.ceil(compensation);
        const fraction = Math.abs(compensation - full);
        label = full > 0 ? '+' + String(full) : String(full);
        if (fraction > 0.6) {
            label += " 2/3";
        } else if (fraction > 0.49) {
            label += " 1/2";
        } else if (fraction > 0.3) {
            label += " 1/3";
        }
        return label;
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
     * @type {number}
     */
    get compensation(): number {
        return this.compensation_;
    }

    /**
     * Allows type cast to number - returns the value.
     * @param {string} hint
     * @return {number|string|null}
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

    private static findNearest(compensation: number): number | null {
        const found = Object.keys(PropertyExposureCompensation.Values).reduce(
            (carry, key) => {
                if (carry.difference < 0.001) {
                    return carry;
                }
                const current = PropertyExposureCompensation.Values[key];
                const difference = Math.abs(current - compensation);
                if (difference < carry.difference) {
                    return {
                        value: +key,
                        difference
                    };
                }
                return carry;
            },
            {
                value: 0,
                difference: 100
            }
        );
        if (found) {
            return found.value;
        }
        return null;
    }


    /**
     * Create instance for label.
     *
     * @param {string} label
     * @return {PropertyExposureCompensation | null}
     */
    static forLabel(label: string): PropertyExposureCompensation | null {
        const match = label.match(/([+-]\d+)\s+(?:([12])\/([23]))?/);
        if (match) {
            let compensation = parseFloat(match[1]);
            if (match[2] && match[3]) {
                if (compensation < 0) {
                    compensation -= parseFloat(match[2]) / parseFloat(match[3]);
                } else {
                    compensation += parseFloat(match[2]) / parseFloat(match[3]);
                }
            }
            const value = PropertyExposureCompensation.findNearest(compensation);
            if (value) {
                return new PropertyExposureCompensation(value);
            }
        }
        return null;
    }

    // Generate: PropertyExposureCompensation

    /**
     * @readonly
     * @enum {number}
     */
     static readonly Values = {"0":0,"3":0.3333333333333333,"4":0.5,"5":0.6666666666666666,"8":1,"11":1.3333333333333333,"12":1.5,"13":1.6666666666666665,"16":2,"19":2.3333333333333335,"20":2.5,"21":2.6666666666666665,"24":3,"27":3.3333333333333335,"28":3.5,"29":3.6666666666666665,"32":4,"35":4.333333333333333,"36":4.5,"37":4.666666666666667,"40":5,"216":-5,"219":-4.666666666666667,"220":-4.5,"221":-4.333333333333333,"224":-4,"227":-3.6666666666666665,"228":-3.5,"229":-3.3333333333333335,"232":-3,"235":-2.6666666666666665,"236":-2.5,"237":-2.3333333333333335,"240":-2,"243":-1.6666666666666665,"244":-1.5,"245":-1.3333333333333333,"248":-1,"251":-0.6666666666666666,"252":-0.5,"253":-0.3333333333333333};

    // GenerateEnd
}
