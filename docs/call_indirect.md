

## emitting unpatched code

```c++
adrp x0, #0           // 0x90000000 - points nowhere
add  x0, x0, #0       // 0x91000000 - adds nothing
ldr  x0, [x0, x1, lsl #3]
blr  x0
```


```c++
adrp x0, function_table      // Encoded with actual page offset
add  x0, x0, :lo12:function_table  // Encoded with low 12 bits
ldr  x0, [x0, x1, lsl #3]    // Load <uint64_t>function_table[x1]
blr  x0                       // Call it
```
