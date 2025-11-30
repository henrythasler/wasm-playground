(module
    (func $basic (result i64)
        call $one
    )

    (func $one (result i64)
        i64.const 1
    )

    (export "basic" (func $basic))
    (export "one" (func $one))
)