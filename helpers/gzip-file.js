const zlib = require('zlib');
const path = require('path');
const fs = require('fs');

const files = process.argv.slice(2);

if (files.length > 0) {
    const sourceFile = path.resolve(files[0]);
    if (fs.existsSync(sourceFile)) {
        process.stdout.write(
            zlib.gzipSync(fs.readFileSync(sourceFile))
        );
    } else {
        throw new Error(`File not found: ${sourceFile}`);
    }
} else {
    throw new Error('File argument missing.');
}
