import { PropertyValue } from "./CameraProperty";

export class FileFormat implements PropertyValue {

    [Symbol.toStringTag] = 'FileFormat';

    private readonly label_: string;

    /**
     * @class FileFormat
     * @param {number} value_
     */
    constructor(
        private readonly value_: number
    ) {
        this.label_ = Object
            .keys(FileFormat.ID)
            .find(key => FileFormat.ID[key as any] === this.value_) ||
                `0x${value_.toString(16).padStart(8, '0')}`;
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
     * Allows type cast to number - returns the value.
     * @param {string} hint
     * @return {number|string|null}
     */
    [Symbol.toPrimitive](hint: string): string | number | null {
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
     static readonly ID = {"CR2":45315,"CR3":45320,"HEIF_CODE":45323,"JPEG":14337,"MP4":47490,"Unknown":0};

    // GenerateEnd
}
