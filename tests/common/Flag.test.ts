import * as CameraApi from '../../stubs/public_api';

const CommonFlagTests = (api: typeof CameraApi) => {
  describe(
    'Flag',
    () => {
      test(
        'Flag.value for "Flag.True"',
        () => {
          const flag = new api.Flag(api.Flag.True);
          expect(flag.value).toStrictEqual(api.Flag.True);
        },
      );
      test(
        'Flag.value for boolean "True"',
        () => {
          const flag = new api.Flag(true);
          expect(flag.value).toStrictEqual(api.Flag.True);
        },
      );
      test(
        'Flag.value for "Flag.False"',
        () => {
          const flag = new api.Flag(api.Flag.False);
          expect(flag.value).toStrictEqual(api.Flag.False);
        },
      );
      test(
        'Flag.value for boolean "False"',
        () => {
          const flag = new api.Flag(false);
          expect(flag.value).toStrictEqual(api.Flag.False);
        },
      );
      test(
        'Flag.label for "True"',
        () => {
          const flag = new api.Flag(true);
          expect(flag.label).toStrictEqual('true');
        },
      );
      test(
        'Flag.label for "False"',
        () => {
          const flag = new api.Flag(false);
          expect(flag.label).toStrictEqual('false');
        },
      );
      test(
        'Flag.forLabel("True")',
        () => {
          const flag = api.Flag.forLabel('true');
          expect(flag).toBeTruthy();
          if (flag) {
            expect(flag.value).toStrictEqual(api.Flag.True);
          }
        },
      );
      test(
        'Flag.forLabel("Yes")',
        () => {
          const flag = api.Flag.forLabel('Yes');
          expect(flag).toBeTruthy();
          if (flag) {
            expect(flag.value).toStrictEqual(api.Flag.True);
          }
        },
      );
      test(
        'Flag.forLabel("1")',
        () => {
          const flag = api.Flag.forLabel('Yes');
          expect(flag).toBeTruthy();
          if (flag) {
            expect(flag.value).toStrictEqual(api.Flag.True);
          }
        },
      );
      test(
        'Flag.forLabel("On")',
        () => {
          const flag = api.Flag.forLabel('Yes');
          expect(flag).toBeTruthy();
          if (flag) {
            expect(flag.value).toStrictEqual(api.Flag.True);
          }
        },
      );
      test(
        'Flag.forLabel("False")',
        () => {
          const flag = api.Flag.forLabel('false');
          expect(flag).toBeTruthy();
          if (flag) {
            expect(flag.value).toStrictEqual(api.Flag.False);
          }
        },
      );
    },
  );
};
export default CommonFlagTests;
