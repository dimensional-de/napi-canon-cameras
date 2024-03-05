const fs = require('fs');
const path = require('path');
const tar = require('tar-fs');

const sourceDirectory = path.resolve(
    __dirname, '..'
);
const targetDirectory = path.resolve(
    __dirname, '..', 'dist',
);
const targetFile = path.resolve(
    targetDirectory, 'napi-canon-cameras.tgz'
);

if (!fs.existsSync(targetDirectory)) {
    fs.mkdirSync(targetDirectory, {recursive: true});
}
tar.pack(
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
        ],
        map: function (header) {
            header.name = './' + header.name;
            return header;
        }
    }
).pipe(fs.createWriteStream(targetFile));
