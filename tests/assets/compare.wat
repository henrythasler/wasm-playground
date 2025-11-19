(module
  ;; return 1 if x < y; otherwise 0
  (func (export "lt_s32") (param $x i32) (param $y i32) (result i32)
    local.get $x
    local.get $y
    i32.lt_s
  )

  (func (export "lt_u32") (param $x i32) (param $y i32) (result i32)
    local.get $x
    local.get $y
    i32.lt_u
  )

  (func (export "lt_s64") (param $x i64) (param $y i64) (result i32)
    local.get $x
    local.get $y
    i64.lt_s
  )

  (func (export "lt_u64") (param $x i64) (param $y i64) (result i32)
    local.get $x
    local.get $y
    i64.lt_u
  )  
)