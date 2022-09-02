const fs = require('fs');
const path = require('path');
const api = require('../camera-api.js');

const stubsPath = path.resolve(__dirname, '../src/stubs/camera-api');
const pattern = /((?:\/\*|\/\/)\s+Generate:\s*(\w+)\s*?(?:\*\/|\n)).*?((?:\/\*|\/\/)\s*GenerateEnd|$)/s;
const tab = '    ';

const files = fs.readdirSync(stubsPath, {withFileTypes: true});
files.forEach(
    (file) => {
        if (!(file.isFile() && file.name.endsWith('.ts'))) {
            return;
        }
        const stubFile = path.resolve(stubsPath, file.name);
        const isTypeScript = true;
        let stub = fs.readFileSync(stubFile, {encoding: 'utf8'});
        const r = stub.match(pattern);
        if (r && r[2] in api) {
            const objectName = r[2];
            let data = '';
            for (const propertyName of Object.keys(api[objectName])) {
                data += '\n';
                data += generateValueSource(propertyName, api[objectName][propertyName]);
            }
            stub = stub.replace(
                pattern,
                `$1${data}${r[3].trim() !== '' ? '\n' + tab + '$3' : '\n'}`
            );
            fs.writeFileSync(stubFile, stub);
            console.log(`Update: ${stubFile}`);
        }
    }
);

function getIndentedSource(source, depth = 0) {
    const indent = depth > 1 ? tab.repeat(depth) : tab;
    return source.replace(/^(.+)/gm, indent + '$1');
}

function generateValueSource(name, value, indent = 1) {
    switch (typeof value) {
        case 'string':
            return getIndentedSource(
                generateStringSource(name, value),
                indent
            );
        case 'object':
            return getIndentedSource(
                generateObjectSource(name, value),
                indent
            );
        default:
            return getIndentedSource(
                generateTypedSource(name, value),
                indent
            );
    }
}

function generateTypedSource(name, value) {
    let code = `/**\n * @readonly\n * @type {${typeof value}}\n */\n`;
    code += `static readonly ${name} = ${JSON.stringify(value)};\n`;
    return code;
}

function generateStringSource(name, value) {
    let code = `/**\n * @readonly\n * @type {${quoteString(value)}\n */\n`;
    code += `static readonly ${name} = ${quoteString(value)};\n`;
    return code;
}

function quoteString(value) {
    const hasDoubleQuotes = value.indexOf('"') >= 0;
    const hasSingleQuotes = value.indexOf("'") >= 0;
    if (hasSingleQuotes && !hasDoubleQuotes) {
        return `"${value}"`;
    } else {
        return `'${value.replace(/'/, "\\'")}'`;
    }
}

function generateObjectSource(name, values) {
    const valueType = (typeof Object.values(values)[0]) || undefined;
    const typeScriptType = `{[key: string]: ${valueType || 'any'}}`;
    let code = `/**\n * @readonly\n * @enum {${valueType}}\n */\n`;
    code += `static readonly ${name}: ${typeScriptType} = {`;
    code += getIndentedSource(
        Object
            .keys(values)
            .sort(
                (a, b) => {
                    return a.localeCompare(
                        b, undefined, {
                            numeric: true,
                            sensitivity: 'base'
                        }
                    );
                }
            )
            .reduce(
                (carry, key) => {
                    return carry + `\n'${key}': ${JSON.stringify(values[key])},`;
                },
                ''
            ),
        1
    );
    code += '\n}\n';
    return code;
}
