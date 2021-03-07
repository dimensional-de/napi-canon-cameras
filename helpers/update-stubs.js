const fs = require("fs");
const path = require('path');
const api = require("../camera-api.js");

const stubsPath = path.resolve(__dirname, '../src/stubs/camera-api');
const pattern = /((?:\/\*|\/\/)\s+Generate:\s*(\w+)\s*?(?:\*\/|\n)).*?((?:\/\*|\/\/)\s*GenerateEnd|$)/s;

const files = fs.readdirSync(stubsPath, {withFileTypes: true});
files.forEach(
    (file) => {
        if (!file.isFile()) {
            return;
        }
        const stubFile = path.resolve(stubsPath,  file.name);
        const isTypeScript = stubFile.endsWith('.ts');
        let stub = fs.readFileSync(stubFile, {encoding: "utf8"});
        const r = stub.match(pattern);
        if (r && r[2] in api) {
            const objectName = r[2];
            let data = "";
            const tab = isTypeScript ? '    ' : '';
            for (const staticValue of Object.keys(api[objectName])) {
                data += "\n";
                let value = api[objectName][staticValue];
                switch (typeof api[objectName][staticValue]) {
                    case "string":
                        data += `${tab}/**\n${tab} * @readonly\n${tab} * @type {"${api[objectName][staticValue]}"}\n${tab} */`;
                        break
                    case "number":
                        data += `${tab}/**\n${tab} * @readonly\n${tab} * @type {number}\n${tab} */`;
                        break
                    case "object":
                        const unordered = Object.assign({}, api[objectName][staticValue]);
                        value = Object.keys(unordered).sort().reduce(
                            (ordered, key) => {
                                ordered[key] = unordered[key];
                                return ordered;
                            },
                            {}
                        );
                        const valueType = (typeof Object.values(value)[0]) || undefined;
                        data += `${tab}/**\n${tab} * @readonly\n${tab} * @enum {${valueType}}\n${tab} */`;
                        break
                    default:
                        //data += `/**\n * @type {${typeof api[objectName][staticValue]}}\n */`;
                }
                if (isTypeScript) {
                    data += `\n${tab} static readonly ` + staticValue + " = " + JSON.stringify(value) + ";";
                } else {
                    data += `\n${tab}` + objectName + "." + staticValue + " = " + JSON.stringify(value) + ";";
                }
            }
            stub = stub.replace(pattern, "$1" + data + (r[3].trim() !== '' ? "\n\n"+ tab +"$3" : "\n"));
            fs.writeFileSync(stubFile, stub);
            console.log("Update: " + stubFile);
        }
    }
)