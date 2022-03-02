import {Camera} from "./Camera";

let STUB = 1;
export interface PropertyValue {
}
/**
 * @interface PropertyValue
 */
STUB = 1;
export interface MatchablePropertyValue extends PropertyValue {
    findNearest<T>(needle: number|string, filter: (value: T) => boolean): number | string;
}
/**
 * @interface MatchablePropertyValue
 */
STUB = 1;
/**
 * @callback MatchablePropertyValue#findNearestFilter
 * @param {MatchablePropertyValue} value
 * @return {boolean} isAllowed
 */
STUB = 1;
/**
 * @method MatchablePropertyValue#findNearest
 * @param {string|number} needle
 * @param {MatchablePropertyValue~findNearestFilter}
 */
STUB = 1;

interface PropertyDateTime extends PropertyValue {
    year: number;
    month: number;
    day: number;
    hour: number;
    minute: number;
    second: number;
    milliseconds: number;
}
/**
 * @interface PropertyDateTime
 * @extends PropertyValue
 * @property {number} year
 * @property {number} month
 * @property {number} day
 * @property {number} hour
 * @property {number} minute
 * @property {number} seconds
 * @property {number} milliseconds
 */
STUB = 1;
interface PropertyStyleDescription extends PropertyValue {
    contrast: number;
    sharpness: number;
    saturation: number;
    colorTone: number;
    filterEffect: number;
    toningEffect: number;
    sharpFineness: number;
    sharpThreshold: number;
}
/**
 * @interface PropertyStyleDescription
 * @extends PropertyValue
 * @property {number} contrast
 * @property {number} sharpness
 * @property {number} saturation
 * @property {number} colorTone
 * @property {number} filterEffect
 * @property {number} toningEffect
 * @property {number} sharpFineness
 * @property {number} sharpThreshold
 */
STUB = 1;
/**
 * @typedef {string|number|number[]|PropertyValue} CameraPropertyValue
 */
STUB = 1;

export type CameraPropertyValue = string|number|number[]|PropertyValue;

export class CameraProperty {

    [Symbol.toStringTag] = 'CameraProperty';

    /**
     * Camera property/setting.
     *
     * @class CameraProperty
     * @param {Camera} camera
     * @param {number} propertyID
     * @param {number} [propertySpecifier=0]
     *
     * @example
     * ```typescript
     * const property = camera.getProperty(Property.ID.Av);
     * console.log(property.value, property.allowedValues);
     * ```
     */
    constructor(camera: Camera, propertyID: number, propertySpecifier: number = 0) {
        throw new Error("Not implemented - stub only.");
    }
    /**
     * @readonly
     * @type {string}
     */
    get label(): string {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @readonly
     * @type {number}
     */
    get identifier(): number {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @readonly
     * @type {number}
     */
    get specifier(): number {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @readonly
     * @type {boolean}
     */
    get available(): boolean {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @type {CameraPropertyValue}
     */
    get value(): CameraPropertyValue {
        throw new Error("Not implemented - stub only.");
    }

    set value(value: CameraPropertyValue) {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @type {CameraPropertyValue[]}
     */
    get allowedValues(): CameraPropertyValue[] {
        throw new Error("Not implemented - stub only.");
    }

    /**
     * @return {{label: string, value: CameraPropertyValue, identifier: number, specifier: (number|undefined)}}
     */
    toJSON(): {label: string, identifier: number, specifier?: number, value: CameraPropertyValue} {
        throw new Error("Not implemented - stub only.");
    }

    // Generate: CameraProperty

    /**
     * @readonly
     * @enum {number}
     */
     static readonly ID: {[label: string]: number} = {"AEBracket":1038,"AEMode":1024,"AEModeSelect":1078,"AFMode":1028,"Artist":1048,"AutoPowerOffSetting":16778334,"Av":1029,"AvailableShots":1034,"BatteryLevel":8,"BatteryQuality":16,"BodyIDEx":21,"Bracket":1035,"CFn":9,"ColorSpace":269,"ColorTemperature":263,"Copyright":1049,"CurrentFolder":13,"CurrentStorage":12,"DC_Strobe":1537,"DC_Zoom":1536,"DateTime":6,"DepthOfField":1051,"DriveMode":1025,"EFCompensation":1054,"EVF_RollingPitching":16778564,"Evf_AFMode":1294,"Evf_ClickWBCoeffs":16778502,"Evf_ColorTemperature":1283,"Evf_CoordinateSystem":1344,"Evf_DepthOfFieldPreview":1284,"Evf_FocusAid":1289,"Evf_Histogram":1290,"Evf_HistogramB":1304,"Evf_HistogramG":1303,"Evf_HistogramR":1302,"Evf_HistogramStatus":1292,"Evf_HistogramY":1301,"Evf_ImageClipRect":1349,"Evf_ImagePosition":1291,"Evf_Mode":1281,"Evf_OutputDevice":1280,"Evf_PowerZoom_CurPosition":1360,"Evf_PowerZoom_MaxPosition":1361,"Evf_PowerZoom_MinPosition":1362,"Evf_WhiteBalance":1282,"Evf_Zoom":1287,"Evf_ZoomPosition":1288,"Evf_ZoomRect":1345,"ExposureCompensation":1031,"FEBracket":1039,"FirmwareVersion":7,"FixedMovie":16778274,"FlashCompensation":1032,"FlashMode":1044,"FlashOn":1042,"FocalLength":1033,"FocusInfo":260,"GPSAltitude":2054,"GPSAltitudeRef":2053,"GPSDateStamp":2077,"GPSLatitude":2050,"GPSLatitudeRef":2049,"GPSLongitude":2052,"GPSLongitudeRef":2051,"GPSMapDatum":2066,"GPSSatellites":2056,"GPSStatus":2057,"GPSTimeStamp":2055,"GPSVersionID":2048,"HDDirectoryStructure":32,"ICCProfile":259,"ISOBracket":1040,"ISOSpeed":1026,"ImageQuality":256,"JpegQuality":257,"LensBarrelStatus":1541,"LensName":1037,"LensStatus":1046,"MakerName":5,"ManualWhiteBalanceData":16777732,"MeteringMode":1027,"MirrorLockUpState":16778273,"MirrorUpSetting":16778296,"MovieParam":16778275,"MyMenu":14,"NoiseReduction":1041,"Orientation":258,"OwnerName":4,"PictureStyle":276,"PictureStyleCaption":512,"PictureStyleDescription":277,"PowerZoom_Speed":1092,"ProductName":2,"Record":1296,"RedEye":1043,"SaveTo":11,"SummerTimeSetting":16777240,"TemperatureStatus":16778261,"TimeZone":16777239,"Tv":1030,"UTCTime":16777238,"WhiteBalance":262,"WhiteBalanceBracket":1036,"WhiteBalanceShift":264};

    // GenerateEnd
}


