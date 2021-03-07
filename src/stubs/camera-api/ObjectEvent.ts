import {ApiIdentifier} from "./ApiIdentifier";

export class ObjectEvent extends ApiIdentifier {

    [Symbol.toStringTag] = 'ObjectEvent';

    /**
     * Encapsulate Object Event Identifiers For Easy Read And Debug
     * @class ObjectEvent
     * @extends ApiIdentifier
     * @param {number} identifier
     */
    constructor(identifier: number) {
        super(identifier, ObjectEvent.ID);
    }

    /**
     * @param {number | ObjectEvent} other The other value
     * @return {boolean}
     */
    equalTo(other: number | ObjectEvent): boolean {
        return super.equalTo(+other);
    }

    // Generate: ObjectEvent

    /**
     * @readonly
     * @enum {number}
     */
     static readonly ID = {"All":512,"DirItemCancelTransferDT":522,"DirItemContentChanged":519,"DirItemCreated":516,"DirItemInfoChanged":518,"DirItemRemoved":517,"DirItemRequestTransfer":520,"DirItemRequestTransferDT":521,"FolderUpdateItems":515,"VolumeAdded":524,"VolumeInfoChanged":513,"VolumeRemoved":525,"VolumeUpdateItems":514};

    // GenerateEnd
}