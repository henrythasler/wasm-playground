// Assume add.wasm file exists that contains a single function adding 2 provided arguments
import fs from 'node:fs/promises';

// Use readFile to read contents of the "add.wasm" file
const wasmBuffer = await fs.readFile('wasm/n_sum.wasm');

function log(msg) {
    console.log(msg);
    return 42;
}

const imports = { env: { log } };

// Use the WebAssembly.instantiate method to instantiate the WebAssembly module
const wasmModule = await WebAssembly.instantiate(wasmBuffer, imports);

// Exported function lives under instance.exports object
const { run } = wasmModule.instance.exports;

const sum = run(4);

console.log(sum); // Outputs: 10