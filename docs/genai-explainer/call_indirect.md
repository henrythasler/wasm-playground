Type canonicalization is **not required by the WebAssembly specification**. It's an **implementation optimization** that compilers and runtimes can choose to do.

## What the spec says

The WebAssembly specification defines types **structurally** - two function types are considered equal if they have the same parameter and return types in the same order. However:

- The **binary format** allows modules to define duplicate type definitions
- Each type definition gets its own index in the type section
- The spec does **not** require deduplication

## Example from the spec's perspective

```wasm
(type $t0 (func (param i32) (result i32)))
(type $t1 (func (param i32) (result i32)))  ;; structurally identical

(func $f0 (type $t0) ...)
(func $f1 (type $t1) ...)
```

According to the spec:
- `$t0` has index 0
- `$t1` has index 1  
- They are **distinct** indices, even though structurally equal
- A `call_indirect (type $t0)` will **only match** functions with type index 0
- Calling `$f1` (which has type index 1) through `call_indirect (type $t0)` would **trap**, even though the signatures are identical

## When canonicalization happens

**At compile time (toolchain)**: Tools like `wasm-opt` can deduplicate identical type definitions before emitting the final binary:

```bash
wasm-opt --vacuum input.wasm -o output.wasm
```

This is the most common approach - the toolchain produces a module where structurally identical types share the same index.

**At load time (runtime)**: Some VMs canonicalize during module instantiation:

```c
// Pseudocode for runtime canonicalization
HashMap<FunctionType, uint32_t> canonical_types;

for (each type in module->types) {
    if (canonical_types.contains(type)) {
        // Remap this type index to existing canonical one
        type_remap[i] = canonical_types[type];
    } else {
        canonical_types[type] = i;
        type_remap[i] = i;
    }
}

// When storing functions in table, use remapped type
table[idx].type_index = type_remap[func.type_index];
```

**Never (strict spec compliance)**: Some implementations just use type indices as-is, requiring exact index matches.

## Why it matters for your compiler

If you're writing an ARM64 compiler, you have choices:

**Option 1: Trust the module** (assume toolchain canonicalized)
```asm
; Simple index comparison
cmp w7, w8
b.ne trap
```

**Option 2: Full structural check** (spec-compliant fallback)
```asm
; Compare indices first
cmp w7, w8
b.eq match  ; fast path

; Slow path: compare actual signatures
bl check_structural_equality
cbz x0, trap

match:
; proceed with call
```

**Option 3: Canonicalize at load time**
- When loading the module, build a canonical type table
- Remap all type indices to canonical ones
- Then runtime check is just index comparison

## Real-world behavior

Most WebAssembly toolchains (Emscripten, wasm-pack, TinyGo, etc.) already canonicalize types during compilation, so in practice:
- Well-formed modules have no duplicate types
- Simple index comparison works 99.9% of the time
- Full structural checking is rare

But strictly speaking, **the spec allows duplicates**, so a fully conformant implementation should handle the structural equality case, even if it's rarely encountered.