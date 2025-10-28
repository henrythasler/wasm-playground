(module
    (func $echo32 (param $argument i32) 
        (result i32)
        local.get $argument
    )

    (func $echo64 (param $argument i64) 
        (result i64)
        local.get $argument
    )

    (func $geti64  
        (result i64)
        i64.const 0x123456789ABCDEF0
    )

    (func $geti64max
        (result i64)
        i64.const 0x7fffffffffffffff
    )

    (export "echo32" (func $echo32))
    (export "echo64" (func $echo64))
    (export "geti64" (func $geti64))
    (export "geti64max" (func $geti64max))
)