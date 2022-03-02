import { CameraProperty, PropertyValue } from "./CameraProperty";

export class Option implements PropertyValue {

    [Symbol.toStringTag] = 'Option';

    private readonly label_: string;

    /**
     * Option represents a property value from a property specific list.
     * It provides constants for all possible property values. However it depends
     * on the camera and the camera status which option values are available.
     *
     * @class Option
     * @param {number} propertyID_
     * @param {number} value_
     */
    constructor(
        private readonly propertyID_: number,
        private readonly value_: number
    ) {
        this.label_ = `0x${value_.toString(16).padStart(8, '0')}`;
        const propertyLabel = Object.keys(CameraProperty.ID).find(key => CameraProperty.ID[key as any] === propertyID_);
        if (propertyLabel && propertyLabel in Option) {
            const optionLabels = Option[propertyLabel];
            const optionLabel = Object.keys(optionLabels).find(key => optionLabels[key] === value_);
            if (optionLabel) {
                this.label_ = propertyLabel + '.' + optionLabel;
            }
        }
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
     * @readonly
     * @type {number}
     */
    get propertyID(): number {
        return this.propertyID_;
    }

    /**
     * Allows type cast to number and string.
     * The string will be a hexadecimal code representation of the number
     * @param {string} hint
     * @return {string | number | null}
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
     * Create instance for label.
     *
     * @param {string} label
     * @return {Option | null}
     */
    static forLabel(label: string): Option | null {
        const [propertyLabel, optionLabel] = label.split('.', 2);
        const propertyID = CameraProperty.ID[propertyLabel as any] || null;
        if (
            propertyID &&
            propertyLabel in Option &&
            optionLabel in Option[propertyLabel as any]
        ) {
            return new Option(propertyID, Option[propertyLabel as any][optionLabel as any]);
        }
        return null;
    }

// Generate: Option

    /**
     * @readonly
     * @enum {number}
     */
     static readonly AEMode = {"A_DEP":5,"Av":2,"BackgroundBlur":62,"BacklitScenes":24,"Bulb":4,"CandlelightPortraits":28,"Children":26,"Closeup":14,"CreativeAuto":19,"CreativeFilter":29,"Custom":7,"DEP":6,"Fireworks":57,"Fisheye":33,"FlashOff":15,"Flexible":55,"Food":27,"Green":9,"GroupPhoto":46,"Hdr_Bold":38,"Hdr_Embossed":39,"Hdr_Standard":36,"Hdr_Vivid":37,"Landscape":13,"Lock":8,"Manual":3,"Miniature":35,"Movie":20,"Movie_DirectMono":43,"Movie_Fantasy":40,"Movie_Memory":42,"Movie_Mini":44,"Movie_Old":41,"Myself":50,"NightPortrait":10,"NightScenes":23,"OilPainting":56,"PanningAssist":45,"Panorama":53,"PhotoInMovie":21,"PlusMovieAuto":51,"Portrait":12,"ProgramAE":0,"RoughMonoChrome":30,"SCN":25,"SceneIntelligentAuto":22,"Silent":54,"SmoothSkin":52,"SoftFocus":31,"Sports":11,"StarNightScape":59,"StarPortrait":58,"StarTimelapseMovie":61,"StarTrails":60,"ToyCamera":32,"Tv":1,"Unknown":-1,"VideoBlog":63,"WaterColor":34};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly AEModeSelect = {"A_DEP":5,"Av":2,"BackgroundBlur":62,"BacklitScenes":24,"Bulb":4,"CandlelightPortraits":28,"Children":26,"Closeup":14,"CreativeAuto":19,"CreativeFilter":29,"Custom":7,"Custom2":16,"Custom3":17,"DEP":6,"Fireworks":57,"Fisheye":33,"FlashOff":15,"Flexible":55,"Food":27,"Green":9,"GroupPhoto":46,"Hdr_Bold":38,"Hdr_Embossed":39,"Hdr_Standard":36,"Hdr_Vivid":37,"Landscape":13,"Lock":8,"Manual":3,"Miniature":35,"Movie":20,"Movie_DirectMono":43,"Movie_Fantasy":40,"Movie_Memory":42,"Movie_Mini":44,"Movie_Old":41,"Myself":50,"NightPortrait":10,"NightScenes":23,"OilPainting":56,"PanningAssist":45,"Panorama":53,"PhotoInMovie":21,"PlusMovieAuto":51,"Portrait":12,"ProgramAE":0,"RoughMonoChrome":30,"SCN":25,"SceneIntelligentAuto":22,"Silent":54,"SmoothSkin":52,"SoftFocus":31,"Sports":11,"StarNightScape":59,"StarPortrait":58,"StarTimelapseMovie":61,"StarTrails":60,"ToyCamera":32,"Tv":1,"Unknown":-1,"WaterColor":34};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly AFMode = {"AIFocus":2,"AIServo":1,"ManualFocus":3,"NotValid":-1,"OneShot":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly BatteryQuality = {"Full":3,"Half":1,"High":2,"Low":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Bracket = {"AEBracket":1,"BracketOff":-1,"FEBracket":8,"ISOBracket":2,"WBBracket":4};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly ColorSpace = {"AdobeRGB":2,"Unknown":-1,"sRGB":1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly DCStrobe = {"Auto":0,"Off":3,"On":1,"SlowSynchro":2};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly DriveMode = {"ContinuousShooting":1,"HighSpeedContinuous":4,"LowSpeedContinuous":5,"SelfTimer10sec":16,"SelfTimer2sec":17,"SelfTimerContinuous":7,"SilentContinuousShooting":20,"SilentHSContinuous":21,"SilentLSContinuous":22,"SilentSingleShooting":19,"SingleShooting":0,"SingleSilentShooting":6,"SuperHighSpeed14fps":18,"Video":2};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly EvfAFMode = {"ExpandAFAreaAround":6,"ExpandAFAreaCross":5,"FaceTracking":2,"FlexiZoneMulti":3,"LargeZoneAFHorizontal":7,"LargeZoneAFVertical":8,"OnePointAF":1,"Quick":0,"SpotAF":10,"TrackingAF":9,"ZoneAF":4};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly EvfHistogramStatus = {"Grayout":2,"Hide":0,"Normal":1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly EvfOutputDevice = {"None":0,"PC":2,"SmallPC":8,"TFT":1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly EvfZoom = {"Fit":1,"x10":10,"x5":5};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly LensBarrelStatus = {"Inner":0,"Outer":1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly LensStatus = {"Attached":1,"NotAttached":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly MeteringMode = {"CenterWeightedAverage":5,"Evaluative":3,"NotValid":-1,"Partial":4,"Spot":1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly MirrorUpStatus = {"Disable":0,"DuringShooting":2,"Enable":1};
    /**
     * @readonly
     * @enum {undefined}
     */
     static readonly MovieQuality = {};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly NoiseReduction = {"Auto":4,"Off":0,"On1":1,"On2":2,"On3":3};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly RedEye = {"Invalid":-1,"Off":0,"On":1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Record = {"Begin":4,"End":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly SaveTo = {"Both":3,"Camera":1,"Host":2};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly WhiteBalance = {"AutoAmbiencePriority":0,"AutoWhitePriority":23,"Click":-1,"Cloudy":2,"ColorTemperature":9,"CustomPC1":10,"CustomPC2":11,"CustomPC3":12,"CustomPC4":20,"CustomPC5":21,"Daylight":1,"Flash":5,"Fluorescent":4,"Pasted":-2,"Shade":8,"Tungsten":3,"WhitePaper":6,"WhitePaper2":15,"WhitePaper3":16,"WhitePaper4":18,"WhitePaper5":19};

    // GenerateEnd
}
