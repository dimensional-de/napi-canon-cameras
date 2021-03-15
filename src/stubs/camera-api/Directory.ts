export interface DirectoryEntry {
    name: string
}

let STUB = 0;
/**
 * @interface DirectoryEntry
 * @property {string} name
 */
STUB = 1;

export class Directory implements DirectoryEntry {

    /**
     * @class Directory
     * @implements DirectoryEntry
     */
    private constructor() {
        throw new Error("Not implemented - stub only.");
    }

    [Symbol.toStringTag] = 'Directory';

    /**
     * @readonly
     * @return {string}
     */
    get name(): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Entry count
     * @return {number}
     */
    get length(): number {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @return {DirectoryEntry[]}
     */
    getEntries(): DirectoryEntry[] {
        throw new Error("Not implemented - stub only.");
    }

    [Symbol.iterator](): DirectoryEntry[] {
        throw new Error("Not implemented - stub only.");
    }

    // Generate: Directory


    // GenerateEnd
}
