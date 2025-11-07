Source: https://chatgpt.com

> Prompt: when i generate and execute jit code with c++ for aarch64, how can i use setjmp and longjmp to abort jit-execution

Excellent and deep systems-level question — using `setjmp`/`longjmp` to abort *JIT-compiled* execution on **AArch64** (ARM64) is nontrivial but absolutely doable. Let’s break it down carefully.

---

## 🧩 Problem Summary

You are dynamically generating and executing machine code (JIT) on AArch64, but you want a way to **abort execution mid-flight** (for example, due to a runtime exception, trap, or signal), and then return safely to the C++ caller.

You’re thinking of using `setjmp()` and `longjmp()` to “bail out” — like a manual exception unwind — from JIT code back into a stable C++ context.

---

## ⚙️ How `setjmp` / `longjmp` Work

* `setjmp(jmp_buf env)` saves the current register state (including the **stack pointer**, **program counter**, and **callee-saved registers**) into `env`.
* `longjmp(env, val)` restores those saved registers and resumes execution at the corresponding `setjmp`.

This means it **restores CPU context**, including the stack frame pointer and link register — it’s essentially a lightweight non-local jump mechanism.

---

## 🧠 The Core Idea for JIT Abort

### 1. Establish a recovery point

Before running JIT code, set up a jump buffer:

```cpp
#include <setjmp.h>
#include <cstdint>

jmp_buf g_jit_env;

int run_jit_code(uint8_t* code, size_t size) {
    if (setjmp(g_jit_env) == 0) {
        // Execute your JIT code
        using JitFn = void (*)();
        auto fn = reinterpret_cast<JitFn>(code);
        fn();
        return 0;  // normal completion
    } else {
        // longjmp landed here: handle abort
        return -1; // aborted
    }
}
```

---

### 2. In your JIT code, detect abort conditions

You can insert a call back to a known C function (or generate one) that triggers `longjmp`:

```cpp
extern "C" void jit_abort() {
    longjmp(g_jit_env, 1);
}
```

Then, your JIT compiler can emit a **direct branch** or **BL** (branch-and-link) to `jit_abort` when it detects an exceptional situation (division by zero, invalid opcode, etc.).

---

### 3. Ensure the stack frame is consistent

This is **crucial** for AArch64:

When you call into JIT code, you must make sure that the stack alignment and ABI are respected (16-byte aligned).
If your JIT code calls `jit_abort()` using `BL`, then `longjmp` will unwind correctly, because it restores all the registers to the `setjmp` context.

If you emit a **bare branch (`B`)**, you must ensure the stack frame pointer (SP, FP) is still valid; otherwise, `longjmp` may restore to inconsistent state.

---

## 🔒 ABI and Signal Safety Notes (AArch64)

* **Stack alignment:** Before calling JIT code, align SP to 16 bytes.
* **Non-volatile registers:** `setjmp` saves/restores callee-saved registers (x19–x29, SP, PC).
  Your JIT code must follow the AAPCS64 calling convention unless you know you’re not calling out of it.
* **`longjmp` skips destructors:** This is fine for low-level “abort JIT” semantics, but do *not* rely on it for normal flow control.
* **Signals (optional):** If your JIT may crash, you can install a signal handler (for SIGILL/SIGSEGV) and call `longjmp` from there too — but that’s only async-signal-safe if you’re careful (better to `siglongjmp` with a `sigjmp_buf`).

---

## ✅ Example Flow Summary

```cpp
jmp_buf env;

void jit_abort() {
    longjmp(env, 1);
}

int main() {
    if (setjmp(env) == 0) {
        run_jit_function();  // emitted JIT code calls jit_abort on error
        printf("Normal exit\n");
    } else {
        printf("JIT aborted!\n");
    }
}
```

---

## 🧩 Implementation Gotchas

| Problem                                                         | Solution                                        |
| --------------------------------------------------------------- | ----------------------------------------------- |
| Stack misalignment                                              | Ensure SP is 16-byte aligned before calling JIT |
| Register clobbering                                             | Follow AAPCS64; preserve x19–x29                |
| Exception inside signal                                         | Use `sigsetjmp` / `siglongjmp` instead          |
| JIT code doesn’t call `jit_abort()` but traps (SIGILL, SIGSEGV) | Handle via signal handler + `siglongjmp`        |
| Executing `longjmp` from inline asm or custom trampoline        | Ensure you restore SP and PC properly           |

---

## 🧠 Pro Tip — Trampoline Safety

If your JIT code doesn’t follow ABI or can crash, consider wrapping it in a **trampoline**:

```cpp
extern "C" void jit_entry(void (*fn)()) {
    if (setjmp(g_jit_env) == 0)
        fn();
}
```

Then your JIT only needs to call `longjmp(g_jit_env, 1)` (either directly or through `jit_abort()`).

---

## 🔧 Alternative Approaches

If you want safer aborts or deeper integration:

* **C++ exceptions:** Possible but requires your JIT to generate unwind info.
* **Signal handling:** Catch signals (`SIGSEGV`, `SIGFPE`), use `sigsetjmp`/`siglongjmp`.
* **Manual stack unwinding:** Very low-level; use unwinder libraries or unwind tables.

---

### ✅ TL;DR

To abort JIT execution on AArch64 using `setjmp`/`longjmp`:

1. Call `setjmp` before executing JIT code.
2. Have JIT emit a call (`BL`) to `jit_abort()` when abort is needed.
3. `jit_abort` calls `longjmp(env, 1)`.
4. Ensure JIT respects AArch64 ABI (SP alignment, callee-saved regs).
5. Optionally use `sigsetjmp`/`siglongjmp` for signal-based aborts.

---

Would you like me to show a **minimal working example** (in C++) that JIT-generates AArch64 machine code to call `jit_abort()` via `BL` and demonstrates aborting execution?

Great — below is a **minimal, self-contained C++ example** that demonstrates using `setjmp` / `longjmp` to abort AArch64 JIT-execution.
Idea: the JIT code is a tiny function (machine code placed in an `mmap`-ed RWX page) that **calls the C `jit_abort()` function via the function-pointer passed in register `x0`** (i.e. it executes `BLR x0`), then returns. `jit_abort()` does `longjmp(...)` to the recovery point set in the caller.

> Important: this example targets **Linux AArch64** with the usual AAPCS64 calling convention. It assumes `BLR X0` and `RET` encodings used are valid (they are standard AArch64 opcodes). Build & run on an aarch64 Linux box.

---

### jit_abort_example.cpp

```cpp
// Compile on aarch64 Linux: g++ -O2 -Wall -std=c++17 jit_abort_example.cpp -o jit_abort_example
// Run: ./jit_abort_example

#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>
#include <setjmp.h>
#include <errno.h>

// Global jump buffer used by setjmp/longjmp
static jmp_buf g_jmpbuf;

// Called by JIT code to abort execution
extern "C" void jit_abort() {
    // Note: longjmp is NOT signal-safe; do not call from arbitrary signal handler here.
    longjmp(g_jmpbuf, 1);
}

// Type for JIT function: takes a function pointer (abort callback) in x0 per AAPCS64
using JitFn = void(*)(void(*)());

int main() {
    // Machine code for the JIT function:
    //   BLR X0        ; call the function-pointer passed in x0 (calls jit_abort)
    //   RET            ; return
    //
    // Encodings (little-endian):
    // BLR X0 = 0xD63F0000 -> bytes: 00 00 3F D6
    // RET     = 0xD65F03C0 -> bytes: C0 03 5F D6
    //
    // Full code bytes:
    const uint8_t code[] = {
        0x00, 0x00, 0x3F, 0xD6,    // blr x0
        0xC0, 0x03, 0x5F, 0xD6     // ret
    };

    // Allocate an executable page:
    size_t pagesz = sysconf(_SC_PAGESIZE);
    if (pagesz == (size_t)-1) pagesz = 4096;
    void* mem = mmap(nullptr, pagesz, PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Copy machine code into mapped page
    memcpy(mem, code, sizeof(code));

    // Ensure instruction cache coherency on some platforms (ARM requires icache flush).
    // Use GCC builtin on AArch64 to flush instruction cache for the code region:
#if defined(__aarch64__) || defined(__arm__)
    __builtin___clear_cache(reinterpret_cast<char*>(mem),
                            reinterpret_cast<char*>(mem) + sizeof(code));
#endif

    JitFn fn = reinterpret_cast<JitFn>(mem);

    printf("Setting recovery point with setjmp...\n");
    if (setjmp(g_jmpbuf) == 0) {
        // Normal path: call JIT code, pass pointer to jit_abort in x0 (per ABI)
        printf("Calling JIT function (it will call back jit_abort -> longjmp)...\n");
        fn(&jit_abort);
        // If JIT returns normally (no abort), this prints.
        printf("JIT returned normally (no abort)\n");
    } else {
        // longjmp landed back here
        printf("longjmp landed: JIT aborted and returned to caller via setjmp/longjmp\n");
    }

    // Clean up
    if (munmap(mem, pagesz) != 0) {
        perror("munmap");
    }

    return 0;
}
```

---

### What this does / why it works

* The program sets `setjmp(g_jmpbuf)` before invoking the JIT function.
* The JIT function is tiny: it `BLR x0` — i.e., it branches to the address in `x0` (the abort callback). We call the JIT function with the C function pointer `&jit_abort` in `x0` (the first argument, per AAPCS64).
* `jit_abort()` calls `longjmp(g_jmpbuf, 1)`, restoring the register context and returning execution to the `setjmp` site — so the C++ caller regains control.
* Because `setjmp` saves SP, PC, and callee-saved registers, `longjmp` safely restores execution back to the C world.

---

### Notes, caveats & robustness tips

1. **Stack alignment / ABI** — Always respect the AArch64 calling convention: SP 16-byte aligned at calls, preserve callee-saved regs (x19–x29) if your JIT-generated code wants to use them across calls into C. Here we only `BLR x0`, no stack frame change, so alignment is simple.

2. **Instruction cache** — After writing executable bytes, flush the instruction cache for the written region. I used `__builtin___clear_cache` (GCC/Clang). On some toolchains/OSs you may need explicit syscalls.

3. **Signal safety** — `longjmp` is not async-signal-safe. If you intend to `longjmp` from a signal handler (for example, catching `SIGSEGV` to abort JIT code), use `sigsetjmp`/`siglongjmp` and ensure the handler is written carefully. Even then, restoring to a point that expects C++ stack invariants can be dangerous.

4. **C++ destructors** — `longjmp` will *not* run C++ destructors for automatic objects on the path being skipped. Do not rely on this for normal control flow; use it only for abort / recovery in low-level JIT contexts.

5. **BLR encoding** — The example uses `BLR X0` so the JIT can call the supplied function pointer without absolute address relocation. This avoids embedding absolute addresses in generated code.

6. **When JIT code may crash** — If your JIT could fault (invalid memory, illegal instruction), you can combine a signal handler for `SIGSEGV`/`SIGILL` with `siglongjmp` (and a `sigsetjmp`) to recover. Be extremely careful: signal handlers are restricted in what functions they can call, and the restored context must be valid.

7. **Thread-local state** — If multiple threads run JIT code, do not use a single global `jmp_buf`. Use thread-local buffers or pass a pointer to the `jmp_buf` into the context that will `longjmp` to it.

---

If you'd like, I can:

* Provide a variant that uses `sigsetjmp`/`siglongjmp` + a signal handler for `SIGSEGV`/`SIGILL` to catch traps from the JIT code; or
* Extend the JIT machine code to do something slightly more interesting (e.g., check a condition in registers and only call the abort callback in the "abort" case); or
* Produce an assembly listing and explain the binary encodings in detail.

Which would you prefer?
