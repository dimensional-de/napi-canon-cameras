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
        const propertyLabel = Object.keys(CameraProperty.ID).find(key => CameraProperty.ID[key] === propertyID_);
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
    [Symbol.toPrimitive](hint): string | number | null {
        switch (hint) {
            case 'number':
                return this.value_;
            case 'string':
                return `0x${this.value_.toString(16).padStart(8, '0')}`;
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
        const propertyID = CameraProperty.ID[propertyLabel] || null;
        if (
            propertyID &&
            propertyLabel in Option &&
            optionLabel in Option[propertyLabel]
        ) {
            return new Option(propertyID, Option[propertyLabel][optionLabel]);
        }
        return null;
    }

// Generate: Option

    /**
     * @readonly
     * @enum {number}
     */
     static readonly AEMode = {"A_DEP":5,"Av":2,"BackgroundBlur":62,"BacklitScenes":24,"Bulb":4,"CandlelightPortraits":28,"Children":26,"Closeup":14,"CreativeAuto":19,"CreativeFilter":29,"Custom":7,"DEP":6,"Fireworks":57,"Fisheye":33,"FlashOff":15,"Flexible":55,"Food":27,"Green":9,"GroupPhoto":46,"Hdr_Bold":38,"Hdr_Embossed":39,"Hdr_Standard":36,"Hdr_Vivid":37,"Landscape":13,"Lock":8,"Manual":3,"Miniature":35,"Movie":20,"Movie_DirectMono":43,"Movie_Fantasy":40,"Movie_Memory":42,"Movie_Mini":44,"Movie_Old":41,"Myself":50,"NightPortrait":10,"NightScenes":23,"OilPainting":56,"PanningAssist":45,"Panorama":53,"PhotoInMovie":21,"PlusMovieAuto":51,"Portrait":12,"ProgramAE":0,"RoughMonoChrome":30,"SCN":25,"SceneIntelligentAuto":22,"Silent":54,"SmoothSkin":52,"SoftFocus":31,"Sports":11,"StarNightScape":59,"StarPortrait":58,"StarTimelapseMovie":61,"StarTrails":60,"ToyCamera":32,"Tv":1,"Unknown":-1,"WaterColor":34};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly AEModeSelect = {"A_DEP":5,"Av":2,"BackgroundBlur":62,"BacklitScenes":24,"Bulb":4,"CandlelightPortraits":28,"Children":26,"Closeup":14,"CreativeAuto":19,"CreativeFilter":29,"Custom":7,"Custom2":16,"Custom3":17,"DEP":6,"Fireworks":57,"Fisheye":33,"FlashOff":15,"Flexible":55,"Food":27,"Green":9,"GroupPhoto":46,"Hdr_Bold":38,"Hdr_Embossed":39,"Hdr_Standard":36,"Hdr_Vivid":37,"Landscape":13,"Lock":8,"Manual":3,"Miniature":35,"Movie":20,"Movie_DirectMono":43,"Movie_Fantasy":40,"Movie_Memory":42,"Movie_Mini":44,"Movie_Old":41,"Myself":50,"NightPortrait":10,"NightScenes":23,"OilPainting":56,"PanningAssist":45,"Panorama":53,"PhotoInMovie":21,"PlusMovieAuto":51,"Portrait":12,"ProgramAE":0,"RoughMonoChrome":30,"SCN":25,"SceneIntelligentAuto":22,"Silent":54,"SmoothSkin":52,"SoftFocus":31,"Sports":11,"StarNightScape":59,"StarPortrait":58,"StarTimelapseMovie":61,"StarTrails":60,"ToyCamera":32,"Tv":1,"Unknown":-1,"WaterColor":34};
    /**
     * @readonly
     * @enum {undefined}
     */
     static readonly MovieParam = {};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly BatteryQuality = {"Full":3,"Half":1,"High":2,"Low":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly AFMode = {"AIFocus":2,"AIServo":1,"ManualFocus":3,"NotValid":-1,"OneShot":0};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Evf_HistogramStatus = {"Grayout":2,"Hide":0,"Normal":1};
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
     static readonly SaveTo = {"Both":3,"Camera":1,"Host":2};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly DC_Strobe = {"Auto":0,"Off":3,"On":1,"SlowSynchro":2};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly DriveMode = {"ContinuousShooting":1,"HighSpeedContinuous":4,"LowSpeedContinuous":5,"SelfTimer10sec":16,"SelfTimer2sec":17,"SelfTimerContinuous":7,"SilentContinuousShooting":20,"SilentHSContinuous":21,"SilentLSContinuous":22,"SilentSingleShooting":19,"SingleShooting":0,"SingleSilentShooting":6,"SuperHighSpeed14fps":18,"Video":2};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Evf_AFMode = {"ExpandAFAreaAround":6,"ExpandAFAreaCross":5,"FaceTracking":2,"FlexiZoneMulti":3,"LargeZoneAFHorizontal":7,"LargeZoneAFVertical":8,"OnePointAF":1,"Quick":0,"SpotAF":10,"TrackingAF":9,"ZoneAF":4};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Evf_OutputDevice = {"Mobile":4,"Mobile2":8,"None":0,"PC":2,"TFT":1};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Evf_WhiteBalance = {"AutoAmbiencePriority":0,"AutoWhitePriority":23,"Click":-1,"Cloudy":2,"ColorTemperature":9,"CustomPC1":10,"CustomPC2":11,"CustomPC3":12,"CustomPC4":20,"CustomPC5":21,"Daylight":1,"Flash":5,"Fluorescent":4,"Pasted":-2,"Shade":8,"Tungsten":3,"WhitePaper":6,"WhitePaper2":15,"WhitePaper3":16,"WhitePaper4":18,"WhitePaper5":19};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly Evf_Zoom = {"Fit":1,"x10":10,"x5":5};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly ISOSpeed = {"Auto":0,"ISO100":72,"ISO1000":99,"ISO10000":125,"ISO102400":152,"ISO12":48,"ISO125":75,"ISO1250":101,"ISO12800":128,"ISO160":77,"ISO1600":104,"ISO16000":131,"ISO200":80,"ISO2000":107,"ISO20000":133,"ISO204800":160,"ISO25":56,"ISO250":83,"ISO2500":109,"ISO25600":136,"ISO320":85,"ISO3200":112,"ISO32000":139,"ISO400":88,"ISO4000":115,"ISO40000":141,"ISO409600":168,"ISO50":64,"ISO500":91,"ISO5000":117,"ISO51200":144,"ISO6":40,"ISO640":93,"ISO6400":120,"ISO64000":147,"ISO800":96,"ISO8000":123,"ISO80000":149,"ISO819200":176};
    /**
     * @readonly
     * @enum {number}
     */
     static readonly ImageQuality = {"CR":6553359,"CRHEIFL":6488192,"CRHEIFLF":6488195,"CRHEIFLN":6488194,"CRHEIFMF":6488451,"CRHEIFMN":6488450,"CRHEIFS1F":6491779,"CRHEIFS1N":6491778,"CRHEIFS2F":6492035,"CRLJ":6488080,"CRLJF":6488083,"CRLJN":6488082,"CRM1J":6489360,"CRM1JF":6489363,"CRM1JN":6489362,"CRM2J":6489616,"CRM2JF":6489619,"CRM2JN":6489618,"CRMJF":6488339,"CRMJN":6488338,"CRS1JF":6491667,"CRS1JN":6491666,"CRS2JF":6491923,"CRS3JF":6492179,"CRSJ":6488592,"CRSJF":6488595,"CRSJN":6488594,"HEIFL":8453903,"HEIFLF":8650511,"HEIFLN":8584975,"HEIFMF":25427727,"HEIFMN":25362191,"HEIFS1F":243531535,"HEIFS1N":243465999,"HEIFS2F":260308751,"LargeJPEG":1113871,"LargeJPEGFine":1310479,"LargeJPEGNormal":1244943,"MR":23396111,"MRLJ":23330832,"MRLJF":23330835,"MRLJN":23330834,"MRM1J":23332112,"MRM2J":23332368,"MRMJF":23331091,"MRMJN":23331090,"MRS1JF":23334419,"MRS1JN":23334418,"MRS2JF":23334675,"MRS3JF":23334931,"MRSJ":23331344,"MRSJF":23331347,"MRSJN":23331346,"Middle1JPEG":84999951,"Middle2JPEG":101777167,"MiddleJPEGFine":18087695,"MiddleJPEGNormal":18022159,"RAW":6618895,"RAWAndLargeJPEG":6553616,"RAWAndLargeJPEGFine":6553619,"RAWAndLargeJPEGNormal":6553618,"RAWAndMiddle1JPEG":6554896,"RAWAndMiddle2JPEG":6555152,"RAWAndMiddleJPEGFine":6553875,"RAWAndMiddleJPEGNormal":6553874,"RAWAndSmall1JPEGFine":6557203,"RAWAndSmall1JPEGNormal":6557202,"RAWAndSmall2JPEGFine":6557459,"RAWAndSmall3JPEGFine":6557715,"RAWAndSmallJPEG":6554128,"RAWAndSmallJPEGFine":6554131,"RAWAndSmallJPEGNormal":6554130,"RHEIFL":6553728,"RHEIFLF":6553731,"RHEIFLN":6553730,"RHEIFMF":6553987,"RHEIFMN":6553986,"RHEIFS1F":6557315,"RHEIFS1N":6557314,"RHEIFS2F":6557571,"SR":40173327,"SRLJ":40108048,"SRLJF":40108051,"SRLJN":40108050,"SRM1J":40109328,"SRM2J":40109584,"SRMJF":40108307,"SRMJN":40108306,"SRS1JF":40111635,"SRS1JN":40111634,"SRS2JF":40111891,"SRS3JF":40112147,"SRSJ":40108560,"SRSJF":40108563,"SRSJN":40108562,"Small1JPEGFine":236191503,"Small1JPEGNormal":236125967,"Small2JPEGFine":252968719,"Small3JPEGFine":269745935,"SmallJPEG":34668303,"SmallJPEGFine":34864911,"SmallJPEGNormal":34799375,"Unknown":-1};
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
     static readonly MirrorLockUpState = {"Disable":0,"DuringShooting":2,"Enable":1};
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
     static readonly WhiteBalance = {"AutoAmbiencePriority":0,"AutoWhitePriority":23,"Click":-1,"Cloudy":2,"ColorTemperature":9,"CustomPC1":10,"CustomPC2":11,"CustomPC3":12,"CustomPC4":20,"CustomPC5":21,"Daylight":1,"Flash":5,"Fluorescent":4,"Pasted":-2,"Shade":8,"Tungsten":3,"WhitePaper":6,"WhitePaper2":15,"WhitePaper3":16,"WhitePaper4":18,"WhitePaper5":19};

    // GenerateEnd
}
