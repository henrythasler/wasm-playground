(module
    (func $const (result i64)
        call $one
    )

    (func $one (result i64)
        i64.const 1
    )

    (export "const" (func $const))
)