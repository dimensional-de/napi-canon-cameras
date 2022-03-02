import { PropertyValue } from "./CameraProperty";

export class Aperture implements PropertyValue {

    [Symbol.toStringTag] = 'Aperture';

    private readonly label_: string;
    private readonly aperture_: number;

    /**
     * Aperture property value
     *
     * @class Aperture
     * @implements PropertyValue
     * @param {number} value_
     */
    constructor(
        private readonly value_: number
    ) {
        const name = Object.keys(Aperture.ID).find(key => Aperture.ID[key] === value_);
        if (name) {
            this.label_ = name;
            this.aperture_ = 0;
        } else {
            this.aperture_ = Aperture.Values[`${value_}`] || 0;
            this.label_ = 'f' + this.aperture_.toFixed(1).replace(/\.0$/, '');
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
    get aperture(): number {
        return this.aperture_;
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
     * @return {{label: string, value: number, aperture: number}}
     */
    toJSON(): { label: string, value: number, aperture: number } {
        return {
            label: this.label,
            value: this.value,
            aperture: this.aperture
        };
    }

    static findNearest(
        valueOrLabel: number | string, filter?: (aperture: Aperture) => boolean
    ): Aperture | null {
        let aperture: number;
        if (typeof valueOrLabel === 'string') {
            const a = Aperture.forLabel(valueOrLabel);
            if (!a) {
                return null;
            }
            aperture = a.aperture;
        } else {
            aperture = (new Aperture(valueOrLabel)).aperture;
        }
        let found;
        found = Object.keys(Aperture.Values).reduce(
            (carry: null | { value: number, difference: number }, key) => {
                const current = Aperture.Values[key];
                const difference = Math.abs(current - aperture);
                if (!carry || difference < carry.difference) {
                    if (filter && !filter(new Aperture(+key))) {
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
            return new Aperture(found.value);
        }
        return null;
    }


    /**
     * Create instance for label.
     *
     * @param {string} label
     * @return {Aperture | null}
     */
    static forLabel(label: string): Aperture | null {
        if (label in Aperture.ID) {
            return new Aperture(Aperture.ID[label]);
        }
        const match = label.match(/f?(\d+(?:\.\d+)?)/);
        if (match) {
            const aperture = parseFloat(match[1]) || 0.0;
            const value = Object.keys(Aperture.Values).find(
                (straw) => Math.abs(Aperture.Values[straw] - aperture) < 0.00001
            );
            return new Aperture(+(value || -1));
        }
        return null;
    }

    // Generate: Aperture

    /**
     * @readonly
     * @enum {number}
     */
     static readonly ID: {[label: string]: number} = {"Auto":0,"NotValid":-1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Values: {[label: string]: number} = {"8":1,"11":1.1,"12":1.2,"13":1.2,"16":1.4,"19":1.6,"20":1.8,"21":1.8,"24":2,"27":2.2,"28":2.5,"29":2.5,"32":2.8,"35":3.2,"36":3.5,"37":3.5,"40":4,"43":4.5,"44":4.5,"45":5,"48":5.6,"51":6.3,"52":6.7,"53":7.1,"56":8,"59":9,"60":9.5,"61":10,"64":11,"67":13,"68":13,"69":14,"72":16,"75":18,"76":19,"77":20,"80":22,"83":25,"84":27,"85":29,"88":32,"91":36,"92":38,"93":40,"96":45,"99":51,"100":54,"101":57,"104":64,"107":72,"108":76,"109":80,"112":91,"133":3.4};

    // GenerateEnd
}
