const fs = require('fs');
const path= require('path');

const sourceDirectory = path.resolve(
    __dirname, '../src/stubs'
)
const targetDirectory = path.resolve(
    __dirname,  '../stubs'
);
if (!fs.existsSync(targetDirectory)){
    fs.mkdirSync(targetDirectory);
}

fs.copyFileSync(
    path.resolve(sourceDirectory, 'package.json'),
    path.resolve(targetDirectory, 'package.json')
);
