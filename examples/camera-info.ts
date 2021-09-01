import { CameraProperty, Camera } from '../';

process.on('SIGINT', () => process.exit());

try {
    const camera = new Camera();
    if (camera) {
        console.log(camera);
        camera.connect();

        const propertyNames = Object.keys(CameraProperty.ID).sort(
            (a, b) => a.localeCompare(b)
        );
        for (const propertyName of propertyNames) {
            const p = camera.getProperty(CameraProperty.ID[propertyName]);
            if (!p.available || p.identifier === CameraProperty.ID.BodyIDEx) {
                continue;
            }
            try {
                const value = p.value;
                console.log(p, p.value, p.allowedValues);
            } catch (e) {
                console.error(
                    propertyName, e.message
                );
            }
        }
    }
    process.exit();
} catch (e) {
    console.error(e);
}


