
### Function body

```asm
// Prologue: create a new stack frame
stp fp, lr, [sp, #-16]!     // FD7BBFA9
mov fp, sp                  // FD030091

// Allocate 64 bytes on stack
sub sp, sp, #64             // FF0301D1

// store (2) params on stack
str     x0, [sp, 24]        // E00F00F9
str     x1, [sp, 16]        // E10B00F9

/**
* insert business logic here
*/

// deallocate stack memory
add sp, sp, #64          // FF030191

// Epilogue: destroy stack frame
ldp fp, lr, [sp], #16       // FD7BC1A8
ret                         // C0035FD6
```
