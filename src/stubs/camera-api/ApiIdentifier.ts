
export abstract class ApiIdentifier {

    [Symbol.toStringTag] = "ApiIdentifier";

    private readonly label_: string;

    /**
     * Superclass for identifier wrappers. Provides the identifiers as class constants and string representations.
     *
     * @class ApiIdentifier
     * @param {number} identifier_
     * @param {Object.<number>} labels
     * @protected
     */
    protected constructor(
        private readonly identifier_: number,
        private readonly labels: {[label: string]: number}
    ) {
       this.label_ = Object.keys(labels).find(key => labels[key] === identifier_) ||
           `0x${this.identifier_.toString(16).padStart(8, '0')}`;
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
    get identifier(): number {
        return this.identifier_;
    }

    /**
     * Allows type cast to number and string.
     * The string will be a hexadecimal code representation of the number
     *
     * @name Symbol_toPrimitive
     * @memberOf ApiIdentifier
     * @instance
     * @function
     * @param {string} hint
     * @return {string|number|null}
     */
    [Symbol.toPrimitive](hint: string): string | number | null {
        switch(hint) {
            case 'number':
                return this.identifier_;
            case 'string':
                return `0x${this.identifier_.toString(16).padStart(8, '0')}`;
            default:
                return null;
        }
    }

    /**
     * @param {number} other Value to compare with
     * @return {boolean}
     */
    equalTo(other: number): boolean {
        return this.identifier_ === +other;
    }

    /**
     * @return {{identifier: number, label: string}}
     */
    toJSON(): {identifier: number, label: string} {
        return {
            identifier: this.identifier_,
            label: this.label_
        }
    }
}
