(module
    (func $basic (result i64)
        call $one
    )

    (func $one (result i64)
        i64.const 1
    )

    (func $back (result i64)
        call $one
    )

    (func $four (result i64)
        i64.const 3
        call $one
        i64.add
    )

    (export "basic" (func $basic))
    (export "one" (func $one))
    (export "back" (func $back))
    (export "four" (func $four))
)