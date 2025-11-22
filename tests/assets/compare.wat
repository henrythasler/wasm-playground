(module
  ;; Return 1 if i1​ is less than i2​, 0 otherwise. 
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

  ;; Return 1 if i1​ is less than or equal to i2​, 0 otherwise
  (func (export "le_s32") (param $x i32) (param $y i32) (result i32)
    local.get $x
    local.get $y
    i32.le_s
  )

  (func (export "le_u32") (param $x i32) (param $y i32) (result i32)
    local.get $x
    local.get $y
    i32.le_u
  )

  (func (export "le_s64") (param $x i64) (param $y i64) (result i32)
    local.get $x
    local.get $y
    i64.le_s
  )

  (func (export "le_u64") (param $x i64) (param $y i64) (result i32)
    local.get $x
    local.get $y
    i64.le_u
  )

  ;; Return 1 if i is zero, 0 otherwise. 
  (func (export "eqz_i32") (param $x i32) (result i32)
    local.get $x
    i32.eqz
  )

  (func (export "eqz_i64") (param $x i64) (result i32)
    local.get $x
    i64.eqz
  )
)