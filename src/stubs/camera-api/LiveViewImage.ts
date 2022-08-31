import { Option } from './Option';

interface Position {
    left: number;
    right: number;
}

interface Size {
    width: number;
    height: number;
}

interface Rectangle extends Position, Size {

}

interface Histogram {
    y: Uint32Array;
    r: Uint32Array;
    g: Uint32Array;
    b: Uint32Array;
}

export class LiveViewImage {

    /**
     * Provided in {@link Camera#getLiveViewImage}. Allows to download the file from camera.
     * @class LiveViewImage
     */
    constructor() {
        throw new Error('Not implemented - stub only.');
    }

    [Symbol.toStringTag] = 'LiveViewImage';


    /**
     * Return as data url, the image will be base64 encoded.
     *
     * @return {string} data url
     */
    getDataURL(): string {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Coordinate system of the live view image
     *
     * @readonly
     * @returns {Size}
     */
    get coordinateSystem(): Size {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * @readonly
     * @returns {Histogram}
     */
    get histogram(): Histogram {
        throw new Error('Not implemented - stub only.');
    }
    /**
     * @readonly
     * @returns {Option}
     */
    get histogramStatus(): Option {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Cropping position of the enlarged live view image
     * @readonly
     * @returns {Position}
     */
    get position(): Position {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Visible area information according to Canon camera aspect settings
     *
     * @readonly
     * @returns {Rectangle}
     */
    get visibleArea(): Rectangle {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * The zoom factor
     *
     * @readonly
     * @returns {Option}
     */
    get zoom(): Option {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * The focus and zoom border position
     *
     * @readonly
     * @returns {Position}
     */
    get zoomPosition(): Position {
        throw new Error('Not implemented - stub only.');
    }

    /**
     * Focus and zoom border rectangle
     *
     * @readonly
     * @returns {Rectangle}
     */
    get zoomArea(): Rectangle {
        throw new Error('Not implemented - stub only.');
    }
}
