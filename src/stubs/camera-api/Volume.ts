
export class Volume {

    /**
     * @class Volume
     */
    private constructor() {
        throw new Error("Not implemented - stub only.");
    }

    [Symbol.toStringTag] = 'Volume';

    /**
     * @readonly
     * @return {string}
     */
    get label(): string {
        throw new Error("Not implemented - stub only.");
    }
    /**
     * Storage type
     * @readonly
     * @see Volume.StorageType
     * @return {number}
     */
    get type(): number {
        throw new Error("Not implemented - stub only.");
    }
    /**
     * @return {boolean}
     */
    get isReadable(): boolean {
        throw new Error("Not implemented - stub only.");
    }
    /**
     * @return {boolean}
     */
    get isWritable(): boolean {
        throw new Error("Not implemented - stub only.");
    }
    /**
     * @return {number}
     */
    get freeSpace(): number {
        throw new Error("Not implemented - stub only.");
    }
    /**
     * @return {number}
     */
    get maximumCapacity(): number {
        throw new Error("Not implemented - stub only.");
    }
    /**
     * Entry count
     * @return {number}
     */
    get length(): number {
        throw new Error("Not implemented - stub only.");
    }


    // Generate: Volume

    // GenerateEnd
}
