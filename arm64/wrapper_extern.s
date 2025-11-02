.global asmabs
.type asmabs, "function"
.p2align 4

asmabs:
    sub	sp, sp, #0x10
    str	w0, [sp, #16]
    ldr	w9, [sp, #16]
    mov	w10, #0x0            
    cmp	w9, w10
    b.lt _skip
    mov	w9, wzr
    b.lt _done
_skip:
    mov	w9, #0x1             
_done:
    cbz	w9, _else
    mov	w9, #0x0             
    ldr	w10, [sp, #16]
    sub	w9, w9, w10
    b _ret
_else:    
    ldr	w9, [sp, #16]
_ret:
    mov	w0, w9
    ret
