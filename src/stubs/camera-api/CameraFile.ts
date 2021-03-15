import { DirectoryEntry } from "./Directory";

export class CameraFile implements DirectoryEntry {

    /**
     * Provided in the {@link DownloadRequestEvent}. Allows to download the file from camera.
     * @class CameraFile
     */
    private constructor() {
        throw new Error("Not implemented - stub only.");
    }

    [Symbol.toStringTag] = 'CameraFile';

    /**
     * Camera provided file name (without path)
     * @readonly
     */
    get name(): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Local file name including path after download.
     * @readonly
     */
    get localFile(): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Multiple formats of the same picture share an ID
     * @readonly
     */
    get groupID(): number {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * File/image size in bytes
     * @readonly
     */
    get size(): number {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Format
     * @readonly
     */
    get format(): number {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Download into a path using camera provided file name
     *
     * @param {string} path
     * @return {string} local file name
     */
    downloadToPath(path: string): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Download into a specific file
     *
     * @param {string} fileName
     * @return {string} local file name
     */
    downloadToFile(fileName: string): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * Download into a base64 encoded string
     *
     * @return {string} base64 encoded string
     */
    downloadToString(): string {
        throw new Error("Not implemented - stub only.");
    }
}
