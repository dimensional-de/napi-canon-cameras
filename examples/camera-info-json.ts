import { CameraProperty, Camera } from '../';

process.on('SIGINT', () => process.exit());

try {
    const camera = new Camera();
    if (camera) {
        camera.connect();

        const settings = [];
        for (const propertyID of Object.values(CameraProperty.ID)) {
            const p = camera.getProperty(propertyID);
            if (!p.available) {
                continue;
            }
            try {
                const value = p.value;
                settings.push(p);
            } catch (e) {
                console.error(
                    p, e
                );
            }
        }
        console.log(JSON.parse(JSON.stringify(settings)));
    }
    process.exit();
} catch (e) {
    console.error(e);
}
