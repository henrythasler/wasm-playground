(module
  (func (export "div_s32") (param $x i32) (param $y i32) (result i32) (i32.div_s (local.get $x) (local.get $y)))
  (func (export "div_u32") (param $x i32) (param $y i32) (result i32) (i32.div_u (local.get $x) (local.get $y)))
  (func (export "div_s64") (param $x i64) (param $y i64) (result i64) (i64.div_s (local.get $x) (local.get $y)))
  (func (export "div_u64") (param $x i64) (param $y i64) (result i64) (i64.div_u (local.get $x) (local.get $y)))  
)