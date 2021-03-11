const directoryToTgz = require('directory-to-tgz');
const fs = require('fs');
const path= require('path');

const sourceDirectory = path.resolve(
    __dirname, '..'
)
const targetDirectory = path.resolve(
    __dirname,  '../..', 'node_packages/@dimensional'
);
const targetFile = path.resolve(
    targetDirectory, 'napi-canon-camera.tgz'
);

if (!fs.existsSync(targetDirectory)){
    fs.mkdirSync(targetDirectory);
}
directoryToTgz(
    sourceDirectory,
    {
        entries: [
            'prebuilds/',
            'src/',
            'stubs/',
            'binding.gyp',
            'camera-api.d.ts',
            'camera-api.js',
            'camera-api-stubs.js',
            'LICENSE',
            'package.json',
            'package-lock.json',
            'README.md'
        ]
    }
).pipe(fs.createWriteStream(targetFile));
