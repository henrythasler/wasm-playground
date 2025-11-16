(module
  (func $lt_s (param $x i32) (param $y i32) (result i32)
    (i32.lt_s (local.get $x) (local.get $y))
  )

  (func $abs (param $x i32) (result i32)
    ;; Check if the number is negative
    (i32.lt_s (local.get $x) (i32.const 0))

    ;; If negative, return the negation of the number
    (if (result i32)

      (then
        (i32.sub (i32.const 0) (local.get $x))
      )
      ;; Else, return the number itself
      (else
        (local.get $x)
      )
    )
  )
  (export "abs" (func $abs))
  (export "lt_s" (func $lt_s))
)