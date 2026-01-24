(module
  (global $const0 i32 (i32.const -2))
  (global $const1 i64 (i64.const -5))
  (global $mut0 (mut i32) (i32.const -12))
  (global $mut1 (mut i64) (i64.const -15))
  (export "get_const0" (func $get_const0))
  (func $get_const0 (result i32)
    global.get $const0
  )
)