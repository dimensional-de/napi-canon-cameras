import { CameraFile } from "./CameraFile";
import { Directory } from "./Directory";

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

    getEntries(): (Directory | CameraFile)[] {
        throw new Error("Not implemented - stub only.");
    }

    [Symbol.iterator](): (Directory | CameraFile)[] {
        throw new Error("Not implemented - stub only.");
    }

    // Generate: Volume

    /**
     * @readonly
     * @enum {number}
     */
     static readonly StorageType = {"CompactFlash":2,"NoMemoryCard":0,"SDCard":1};

    // GenerateEnd
}
