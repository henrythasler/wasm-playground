(module
 (export "ctz-i32" (func $ctz-i32))
 (export "ctz-i64" (func $ctz-i64))
 
 (func $ctz-i32 (param $0 i32) (result i32)
  local.get $0
  i32.ctz
 )

 (func $ctz-i64 (param $0 i64) (result i64)
  local.get $0
  i64.ctz
 ) 
)
