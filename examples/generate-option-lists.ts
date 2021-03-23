import * as fs from "fs";
import { Aperture, ISOSensitivity, Option, ShutterSpeed } from "../";

type OptionsExport = [fileName: string, generator: () => (string[])[]];

const lists: OptionsExport[] = [
    [
        'aperture-values.csv',
        () => Object.keys(Aperture.Values)
            .map(
                (value) => {
                    const aperture = new Aperture(+value);
                    return [aperture.label, aperture.aperture.toString()];
                }
            )
            .sort((a, b) => +a[1] - +b[1])
    ],
    [
        'shutter-speed-values.csv',
        () => Object.keys(ShutterSpeed.Values)
            .map(
                (value) => {
                    const speed = new ShutterSpeed(+value);
                    return [speed.label, speed.seconds.toString()];
                }
            )
            .sort((a, b) => +a[1] - +b[1])
    ],
    [
        'iso-values.csv',
        () => Object.keys(ISOSensitivity.Values)
            .map(
                (value) => [(new ISOSensitivity(+value).label)]
            )
            .sort((a, b) => +a[0] - +b[0])
    ],
    [
        'white-balance.csv',
        () => Object.keys(Option.WhiteBalance)
            .map((name) => [name])
            .sort((a, b) => a[0].localeCompare(b[0]))
    ]
];

for (const list of lists) {
    const [fileName, generator] = list;
    fs.writeFileSync(
        __dirname + '/options/' + fileName,
        generator()
            .map(
                (fields: string[]) => fields
                    .map((value) => `"${value}"`)
                    .join(',')
            )
            .filter((value, index, self) => self.indexOf(value) === index)
            .join('\n')
    )
}
