import {
    Camera, Directory, DirectoryEntry, watchCameras
} from '../';

process.on('SIGINT', () => process.exit());

try {
    const camera = new Camera();
    camera.connect();

    const directoryToJSON = (directory: Directory) => {
        const json: {name: string, entries: any[] } = {name: directory.name, entries: []};
        for (const entry of directory.getEntries()) {
            if (entry instanceof Directory) {
                json.entries.push(directoryToJSON(entry));
            } else {
                json.entries.push(
                    { name: entry.name, format: (entry as any).format }
                );
            }
        }
        return json;
    }

    for (const volume of camera.getVolumes()) {
        const json = {label: volume.label, entries: []};
        for (const entry of volume.getEntries()) {
            if (entry instanceof Directory) {
                json.entries.push(directoryToJSON(entry));
            } else {
                json.entries.push(entry.name);
            }
        }
        console.dir(json, {depth: 20});
    }
} catch (e) {
    console.log(e);
}

process.exit();
