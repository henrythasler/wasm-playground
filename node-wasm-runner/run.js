// Assume add.wasm file exists that contains a single function adding 2 provided arguments
import fs from 'fs';
import { PNG } from 'pngjs';
// const { PNG } = require('pngjs');

// Use readFile to read contents of the "add.wasm" file
const wasmBuffer = fs.readFileSync('tests/assets/fractal.wasm');

function log(msg) {
    console.log(msg);
}

function myPrintf(msg, argsPtr) {
    const nullTerminatedString = new Uint8Array(wasmModule.instance.exports.memory.buffer, msg);

    // clip at the first null byte
    const nullByteIndex = nullTerminatedString.indexOf(0);
    const msgBytes = nullTerminatedString.slice(0, nullByteIndex);

    const msgStr = new TextDecoder().decode(msgBytes, {});
    console.log(msgStr);
}

function write_png(filename, w, h, comp, dataPtr, stride_in_bytes) {
    const nullTerminatedString = new Uint8Array(wasmModule.instance.exports.memory.buffer, filename);

    // clip at the first null byte
    const nullByteIndex = nullTerminatedString.indexOf(0);
    const filenameBytes = nullTerminatedString.slice(0, nullByteIndex);

    const filenameStr = new TextDecoder().decode(filenameBytes, {});
    console.log(`writing PNG to ${filenameStr}, w: ${w}, h: ${h}, comp: ${comp}, dataPtr: ${dataPtr}, stride_in_bytes: ${stride_in_bytes}`);

    // Your raw bitmap buffer (RGBA, 4 bytes per pixel)
    const bitmapBuffer = new Uint8Array(wasmModule.instance.exports.memory.buffer, dataPtr, w * h * comp);
    const rawPixels = new Uint8Array(bitmapBuffer);
    const png = new PNG({ width: w, height: h });

    // Convert RGB → RGBA
    for (let i = 0, j = 0; i < rawPixels.length; i += 3, j += 4) {
        png.data[j] = rawPixels[i];     // R
        png.data[j + 1] = rawPixels[i + 1]; // G
        png.data[j + 2] = rawPixels[i + 2]; // B
        png.data[j + 3] = 255;        // A (fully opaque)
    }

    const buffer = PNG.sync.write(png);
    fs.writeFileSync(filenameStr, buffer);
}

const imports = { env: { log, write_png, myPrintf } };

// Use the WebAssembly.instantiate method to instantiate the WebAssembly module
const wasmModule = await WebAssembly.instantiate(wasmBuffer, imports);

// Exported function lives under instance.exports object
const exports = wasmModule.instance.exports;
console.log(exports);

const res = exports['_start']();
console.log(res);