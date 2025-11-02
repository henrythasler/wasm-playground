(module
;; return 1 if x <= y; otherwise 0
  (func $lt_s (param $x i32) (param $y i32) (result i32)
    (i32.lt_s (local.get $x) (local.get $y))
  )

  (export "lt_s" (func $lt_s))
)