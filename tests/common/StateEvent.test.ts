import * as CameraApi from "../../stubs/public_api";

const CommonStateEventTests = (api: typeof CameraApi) => {
    describe(
        'StateEvent',
        () => {
            test(
                'StateEvent.identifier',
                () => {
                    const event = new api.StateEvent(api.StateEvent.ID.CaptureError);
                    expect(event.identifier).toStrictEqual(api.StateEvent.ID.CaptureError);
                }
            );
            test(
                'StateEvent.label',
                () => {
                    const event = new api.StateEvent(api.StateEvent.ID.CaptureError);
                    expect(event.label).toStrictEqual('CaptureError');
                }
            );
            test(
                'StateEvent.toJSON()',
                () => {
                    const event = new api.StateEvent(api.StateEvent.ID.CaptureError);
                    const json = JSON.parse(JSON.stringify(event));
                    expect(json).toStrictEqual(
                        {
                            "identifier": api.StateEvent.ID.CaptureError,
                            "label": "CaptureError"
                        }
                    );
                }
            );
            test(
                'StateEvent.equalTo()',
                () => {
                    const event = new api.StateEvent(api.StateEvent.ID.CaptureError);
                    expect(event.equalTo(api.StateEvent.ID.CaptureError)).toStrictEqual(true);
                    expect(event.equalTo(api.StateEvent.ID.JobStatusChanged)).toStrictEqual(false);
                }
            );
            test(
                'StateEvent[@@toPrimitive]',
                () => {
                    const event = new api.StateEvent(api.StateEvent.ID.CaptureError);
                    expect(String(event)).toStrictEqual('0x00000305');
                    expect(+(event)).toStrictEqual(api.StateEvent.ID.CaptureError);
                }
            );
            test(
                'StateEvent[@@toStringTag]',
                () => {
                    const event = new api.StateEvent(api.StateEvent.ID.CaptureError);
                    expect(Object.prototype.toString.call(event)).toStrictEqual('[object StateEvent]');
                }
            );
        }
    );
}
export default CommonStateEventTests;