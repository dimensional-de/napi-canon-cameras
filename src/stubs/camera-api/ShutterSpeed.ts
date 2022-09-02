import { PropertyValue } from './CameraProperty';

export class ShutterSpeed implements PropertyValue {

    [Symbol.toStringTag] = 'ShutterSpeed';

    private readonly seconds_: number;

    private readonly label_: string;

    /**
     * Encapsulate Object for a Shutter Speed value
     * @class ShutterSpeed
     * @param {number} value_
     */
    constructor(
        private readonly value_: number,
    ) {
        const name = Object
            .keys(ShutterSpeed.ID)
            .find(key => ShutterSpeed.ID[key] === value_);
        if (name) {
            this.label_ = name;
            this.seconds_ = 0;
        } else if (`${value_}` in ShutterSpeed.OneThirdValues) {
            this.seconds_ = ShutterSpeed.OneThirdValues[value_] || 0;
            this.label_ = ShutterSpeed.getLabelForSeconds(this.seconds_) + ' (1/3)';
        } else {
            this.seconds_ = ShutterSpeed.OneHalfValues[value_] || 0;
            this.label_ = ShutterSpeed.getLabelForSeconds(this.seconds_);
        }
    }

    private static getLabelForSeconds(seconds: number): string {
        let label = '';
        if (seconds > 0.2999) {
            label = seconds.toFixed(1).replace(/\.0+$/, '');
        } else if (seconds > 0.0) {
            label = `1/${Math.round(1.0 / seconds)}`;
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
    get seconds(): number {
        return this.seconds_;
    }

    /**
     * @readonly
     * @type {number}
     */
    get stop(): string {
        return (`${this.value_}` in ShutterSpeed.OneThirdValues) ? '1/3' : '1/2';
    }

    /**
     * Allows type cast to number - returns the value.
     * @param {string} hint
     * @return {number|string|null}
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
     * @return {{label: string, value: number, seconds: number, stop: string}}
     */
    toJSON(): { label: string, value: number, seconds: number, stop: string } {
        return {
            label: this.label,
            value: this.value,
            seconds: this.seconds,
            stop: this.stop,
        };
    }

    static findNearest(
        valueOrLabel: number | string, filter?: (aperture: ShutterSpeed) => boolean,
    ): ShutterSpeed | null {
        let seconds = 0;
        if (typeof valueOrLabel === 'string') {
            const speed = ShutterSpeed.forLabel(valueOrLabel);
            if (!speed) {
                return null;
            }
            seconds = speed.seconds;
        } else {
            seconds = (new ShutterSpeed(valueOrLabel)).seconds;
        }
        const found = Object.keys(ShutterSpeed.AllValues).reduce(
            (carry: null | { value: number, difference: number }, key) => {
                const current = ShutterSpeed.AllValues[key];
                const difference = Math.abs(current - seconds);
                if (!carry || difference < carry.difference) {
                    if (filter && !filter(new ShutterSpeed(+key))) {
                        return carry;
                    }
                    return {
                        value: +key,
                        difference,
                    };
                }
                return carry;
            },
            null,
        );
        if (found) {
            return new ShutterSpeed(found.value);
        }
        return null;
    }

    /**
     * Create instance for label.
     *
     * @param {string} label
     * @return {ShutterSpeed | null}
     */
    static forLabel(label: string): ShutterSpeed | null {
        if (label in ShutterSpeed.ID) {
            return new ShutterSpeed(ShutterSpeed.ID[label]);
        }
        const match = label.match(
            /(\d+(?:\.\d+)?)(?:\s*\/\s*(\d+))?(?:\s+(.*))?/,
        );
        if (match) {
            const isOneThird = (match[3] || '').indexOf('1/3') >= 0;
            let seconds: number = parseFloat(match[1]) || 0.0;
            if (match[2]) {
                seconds /= parseFloat(match[2]);
            }
            const values = isOneThird ? ShutterSpeed.OneThirdValues : ShutterSpeed.OneHalfValues;
            const value = Object.keys(values).find(
                (straw) => Math.abs(values[straw] - seconds) < 0.0000001,
            );
            return new ShutterSpeed(+(value || -1));
        }
        return null;
    }

    // Generate: ShutterSpeed

    /**
     * @readonly
     * @enum {number}
     */
    static readonly ID: {[key: string]: number} = {
        'Auto': 0,
        'Bulb': 12,
        'NotValid': 4294967295,
    };

    /**
     * @readonly
     * @enum {number}
     */
    static readonly OneHalfValues: {[key: string]: number} = {
        '16': 30,
        '19': 25,
        '20': 20,
        '24': 15,
        '27': 13,
        '28': 10,
        '32': 8,
        '36': 6,
        '37': 5,
        '40': 4,
        '43': 3.2,
        '44': 3,
        '45': 2.5,
        '48': 2,
        '51': 1.6,
        '52': 1.5,
        '53': 1.3,
        '56': 1,
        '59': 0.8,
        '60': 0.7,
        '61': 0.6,
        '64': 0.5,
        '67': 0.4,
        '68': 0.3,
        '72': 0.25,
        '75': 0.2,
        '76': 0.16666666666666666,
        '80': 0.125,
        '84': 0.1,
        '85': 0.07692307692307693,
        '88': 0.06666666666666667,
        '92': 0.05,
        '93': 0.04,
        '96': 0.03333333333333333,
        '99': 0.025,
        '100': 0.022222222222222223,
        '101': 0.02,
        '104': 0.016666666666666666,
        '107': 0.0125,
        '108': 0.011111111111111112,
        '109': 0.01,
        '112': 0.008,
        '115': 0.00625,
        '116': 0.005555555555555556,
        '117': 0.005,
        '120': 0.004,
        '123': 0.003125,
        '124': 0.002857142857142857,
        '125': 0.0025,
        '128': 0.002,
        '131': 0.0015625,
        '132': 0.0013333333333333333,
        '133': 0.00125,
        '136': 0.001,
        '139': 0.0008,
        '140': 0.0006666666666666666,
        '141': 0.000625,
        '144': 0.0005,
        '147': 0.0004,
        '148': 0.0003333333333333333,
        '149': 0.0003125,
        '152': 0.00025,
        '155': 0.0002,
        '156': 0.00016666666666666666,
        '157': 0.00015625,
        '160': 0.000125,
    };

    /**
     * @readonly
     * @enum {number}
     */
    static readonly OneThirdValues: {[key: string]: number} = {
        '21': 20,
        '29': 10,
        '35': 6,
        '69': 0.3,
        '77': 0.16666666666666666,
        '83': 0.1,
        '91': 0.05,
    };

    // GenerateEnd

    static readonly AllValues = { ...ShutterSpeed.OneHalfValues, ...ShutterSpeed.OneThirdValues };
}
