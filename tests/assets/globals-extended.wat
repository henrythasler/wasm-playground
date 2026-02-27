(module
  (global $const0 i32 (i32.const -2))
  (global $const1 i64 (i64.const -5))
  (global $mut0 (mut i32) (i32.const -12))
  (global $mut1 (mut i64) (i64.const 100))
  ;; this is a special case where the LEB128 encoded number has 0x0B as it's last byte which collides with the init_exp terminator
  (global $mut3 (mut i32) (i32.const 186384))
  (export "get_const0" (func $get_const0))
  (export "get_const1" (func $get_const1))
  (export "get_mut0" (func $get_mut0))
  (export "get_mut1" (func $get_mut1))
  (export "store_mut0" (func $store_mut0))
  (export "store_mut1" (func $store_mut1))
  (func $get_const0 (result i32)
    global.get $const0
  )
  (func $get_const1 (result i64)
    global.get $const1
  )
  (func $get_mut0 (result i32)
    global.get $mut0
  )
  (func $get_mut1 (result i64)
    global.get $mut1
  )
  (func $store_mut0 (param $arg i32) (result i32)
    local.get $arg
    global.set $mut0
    global.get $mut0    
  )
  (func $store_mut1 (param $arg i64) (result i64)
    local.get $arg
    global.set $mut1
    global.get $mut1    
  )
)