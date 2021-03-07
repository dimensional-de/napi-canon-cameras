import * as CameraApi from "../../stubs/public_api";

const CommonObjectEventTests = (api: typeof CameraApi) => {
    describe(
        'ObjectEvent',
        () => {
            test(
                'ObjectEvent.identifier',
                () => {
                    const event = new api.ObjectEvent(api.ObjectEvent.ID.DirItemRequestTransfer);
                    expect(event.identifier).toStrictEqual(api.ObjectEvent.ID.DirItemRequestTransfer);
                }
            );
            test(
                'ObjectEvent.label',
                () => {
                    const event = new api.ObjectEvent(api.ObjectEvent.ID.DirItemRequestTransfer);
                    expect(event.label).toStrictEqual('DirItemRequestTransfer');
                }
            );
            test(
                'ObjectEvent.toJSON()',
                () => {
                    const event = new api.ObjectEvent(api.ObjectEvent.ID.DirItemRequestTransfer);
                    const json = JSON.parse(JSON.stringify(event));
                    expect(json).toStrictEqual(
                        {
                            "identifier": api.ObjectEvent.ID.DirItemRequestTransfer,
                            "label": "DirItemRequestTransfer"
                        }
                    );
                }
            );
            test(
                'ObjectEvent.equalTo()',
                () => {
                    const event = new api.ObjectEvent(api.ObjectEvent.ID.DirItemRequestTransfer);
                    expect(event.equalTo(api.ObjectEvent.ID.DirItemRequestTransfer)).toStrictEqual(true);
                    expect(event.equalTo(api.ObjectEvent.ID.DirItemContentChanged)).toStrictEqual(false);
                }
            );
            test(
                'ObjectEvent[@@toPrimitive]',
                () => {
                    const event = new api.ObjectEvent(api.ObjectEvent.ID.DirItemRequestTransfer);
                    expect(String(event)).toStrictEqual('0x00000208');
                    expect(+(event)).toStrictEqual(api.ObjectEvent.ID.DirItemRequestTransfer);
                }
            );
            test(
                'ObjectEvent[@@toStringTag]',
                () => {
                    const event = new api.ObjectEvent(api.ObjectEvent.ID.DirItemRequestTransfer);
                    expect(Object.prototype.toString.call(event)).toStrictEqual('[object ObjectEvent]');
                }
            );
        }
    );
}
export default CommonObjectEventTests;