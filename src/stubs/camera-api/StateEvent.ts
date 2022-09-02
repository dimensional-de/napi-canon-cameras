import { ApiIdentifier } from './ApiIdentifier';

export class StateEvent extends ApiIdentifier {

    [Symbol.toStringTag] = 'StateEvent';

    /**
     * Encapsulate Object Event Identifiers For Easy Read And Debug
     * @class StateEvent
     * @extends ApiIdentifier
     * @param {number} identifier
     */
    constructor(identifier: number) {
        super(identifier, StateEvent.ID);
    }

    /**
     * @param {number | StateEvent} other The other value
     * @return {boolean}
     */
    equalTo(other: number | StateEvent): boolean {
        return super.equalTo(+other);
    }

    // Generate: StateEvent

    /**
     * @readonly
     * @enum {number}
     */
    static readonly ID: {[key: string]: number} = {
        'AfResult': 777,
        'All': 768,
        'BulbExposureTime': 784,
        'CaptureError': 773,
        'InternalError': 774,
        'JobStatusChanged': 770,
        'PowerZoomInfoChanged': 785,
        'Shutdown': 769,
        'ShutDownTimerUpdate': 772,
        'WillSoonShutDown': 771,
    };

    // GenerateEnd
}
