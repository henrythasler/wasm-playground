// Assume add.wasm file exists that contains a single function adding 2 provided arguments
import fs from 'node:fs/promises';

// Use readFile to read contents of the "add.wasm" file
const wasmBuffer = await fs.readFile('tests/assets/fractal.wasm');

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
}

const imports = { env: { log, write_png, myPrintf } };

// Use the WebAssembly.instantiate method to instantiate the WebAssembly module
const wasmModule = await WebAssembly.instantiate(wasmBuffer, imports);

// Exported function lives under instance.exports object
const exports = wasmModule.instance.exports;
console.log(exports);

const res = exports['_start']();
console.log(res);