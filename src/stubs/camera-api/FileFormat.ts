import { PropertyValue } from "./CameraProperty";

export class FileFormat implements PropertyValue {

    [Symbol.toStringTag] = 'FileFormat';

    private readonly type_: number;

    /**
     * @class FileFormat
     * @param {number} value_
     */
    constructor(
        private readonly value_: number
    ) {
        this.type_ = FileFormat.extractBits(value_, 0, 8);
    }

    private static extractBits(buffer: number, offset: number, length: number): number {
        return (((1 << length) - 1) & (buffer >> (offset)));
    }

    /**
     * @readonly
     * @type {string}
     */
    get label(): string {
        const name = Object
            .keys(FileFormat.Type)
            .find(key => FileFormat.Type[key] === this.type_);
        return name || "Unknown";
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
    get type(): number {
        return this.type_;
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
                return this.label;
            default:
                return null;
        }
    }

    // Generate: FileFormat

    /**
     * @readonly
     * @enum {number}
     */
     static readonly Type = {"CR2":6,"CR3":8,"CRW":2,"JPEG":1,"RAW":4,"Unknown":0};

    // GenerateEnd
}
