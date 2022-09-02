import {
    Camera, CameraFile, Directory, FileFormat,
} from '../';

process.on('SIGINT', () => process.exit());

interface JSONFile {
    name: string;
    format: FileFormat
}

interface JSONDirectory {
    name: string;
    entries: (JSONDirectory | JSONFile)[],
}

interface JSONVolume {
    label: string,
    entries: (JSONDirectory | JSONFile)[],
}

try {
    const camera = new Camera();
    camera.connect();

    const directoryToJSON = (directory: Directory) => {
        const json: JSONDirectory = { name: directory.name, entries: [] };
        for (const entry of directory.getEntries()) {
            if (entry instanceof Directory) {
                json.entries.push(directoryToJSON(entry));
            } else {
                json.entries.push(
                    { name: entry.name, format: (entry as CameraFile).format },
                );
            }
        }
        return json;
    };

    for (const volume of camera.getVolumes()) {
        const json: JSONVolume = { label: volume.label, entries: [] };
        for (const entry of volume.getEntries()) {
            if (entry instanceof Directory) {
                json.entries.push(directoryToJSON(entry));
            } else {
                json.entries.push(
                    { name: entry.name, format: (entry as CameraFile).format },
                );
            }
        }
        console.dir(json, { depth: 20 });
    }
} catch (e) {
    console.log(e);
}

process.exit();
