import { TimeZone } from '../../src/stubs';
import * as CameraApi from '../../stubs/public_api';

const CommonTimeZoneTests = (api: typeof CameraApi) => {
    describe(
        'TimeZone',
        () => {
            test(
                'TimeZone, +00:00 UTC',
                () => {
                    const timeZone = new api.TimeZone(0xFFFF0000);
                    expect(timeZone.value).toStrictEqual(0xFFFF0000);
                    expect(timeZone.label).toStrictEqual('+00:00 UTC');
                    expect(timeZone.zone).toStrictEqual(0xFFFF);
                    expect(timeZone.difference).toStrictEqual(0);
                },
            );
            test(
                'TimeZone, +01:00 Paris',
                () => {
                    const timeZone = new api.TimeZone(0x0013003C);
                    expect(timeZone.value).toStrictEqual(0x0013003C);
                    expect(timeZone.label).toStrictEqual('+01:00 Paris');
                    expect(timeZone.zone).toStrictEqual(19);
                    expect(timeZone.difference).toStrictEqual(60);
                },
            );
            test(
                'TimeZone, -04:00 New York',
                () => {
                    const timeZone = new api.TimeZone(0x001BFF10);
                    expect(timeZone.value).toStrictEqual(0x001BFF10);
                    expect(timeZone.label).toStrictEqual('-04:00 New York');
                    expect(timeZone.zone).toStrictEqual(27);
                    expect(timeZone.difference).toStrictEqual(60 * -4);
                },
            );
            test(
                'TimeZone, -06:00 Chicago',
                () => {
                    const timeZone = new api.TimeZone(0x001CFE98);
                    expect(timeZone.value).toStrictEqual(0x001CFE98);
                    expect(timeZone.label).toStrictEqual('-06:00 Chicago');
                    expect(timeZone.zone).toStrictEqual(28);
                    expect(timeZone.difference).toStrictEqual(60 * -6);
                },
            );
            test(
                'TimeZone, -06:00 Denver',
                () => {
                    const timeZone = new api.TimeZone(0x001DFE98);
                    expect(timeZone.value).toStrictEqual(0x001DFE98);
                    expect(timeZone.label).toStrictEqual('-06:00 Denver');
                    expect(timeZone.zone).toStrictEqual(29);
                    expect(timeZone.difference).toStrictEqual(60 * -6);
                },
            );
            test(
                'TimeZone, -08:00 Los Angeles',
                () => {
                    const timeZone = new api.TimeZone(0x001EFE20);
                    expect(timeZone.value).toStrictEqual(0x001EFE20);
                    expect(timeZone.label).toStrictEqual('-08:00 Los Angeles');
                    expect(timeZone.zone).toStrictEqual(30);
                    expect(timeZone.difference).toStrictEqual(60 * -8);
                },
            );
        },
    );
};
export default CommonTimeZoneTests;
