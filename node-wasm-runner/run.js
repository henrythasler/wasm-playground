// Assume add.wasm file exists that contains a single function adding 2 provided arguments
import fs from 'node:fs/promises';

// Use readFile to read contents of the "add.wasm" file
const wasmBuffer = await fs.readFile('tests/assets/block.wasm');

function log(msg) {
    console.log(msg);
}

const imports = { env: { log } };

// Use the WebAssembly.instantiate method to instantiate the WebAssembly module
const wasmModule = await WebAssembly.instantiate(wasmBuffer, imports);

// Exported function lives under instance.exports object
const exports = wasmModule.instance.exports;
console.log(exports);

const res = exports['type-i64-value']();
console.log(res);