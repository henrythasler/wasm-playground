(module
 (export "simple_if" (func $simple_if))
 (export "nested_if" (func $nested_if))
 (export "nested_else" (func $nested_else))
 (export "simple_if_add1" (func $simple_if_add1))
 (export "nested_else_add1" (func $nested_else_add1))

 (func $simple_if (param $0 i64) (result i64)
  local.get $0
  i64.const 0
  i64.lt_s
  (if (result i64)
   (then (i64.const -1))
   (else (i64.const 1))
  )
  return
 )

 (func $nested_if (param $0 i64) (result i64)
  local.get $0
  i64.const 0
  i64.lt_s
  if (result i64)
   local.get $0
   i64.const -10
   i64.lt_s
   if (result i64)
    i64.const -100
   else
    i64.const -10
   end
  else
   i64.const 1
  end
  return
 )

(func $nested_else (param $0 i64) (result i64)
  local.get $0
  i64.const 0
  i64.lt_s
  if (result i64)
   i64.const -1
  else
   local.get $0
   i64.const 10
   i64.lt_s
   if (result i64)
    i64.const 10
   else
    i64.const 100
   end
  end
  return
 )

 (func $simple_if_add1 (param $0 i64) (result i64)
  local.get $0
  i64.const 0
  i64.lt_s
  (if (result i64)
   (then (i64.const -1))
   (else (i64.const 1))
  )
  i64.const 1
  i64.add
  return
 ) 

(func $nested_else_add1 (param $0 i64) (result i64)
  local.get $0
  i64.const 0
  i64.lt_s
  if (result i64)
   i64.const -1
  else
   local.get $0
   i64.const 10
   i64.lt_s
   if (result i64)
    i64.const 10
   else
    i64.const 100
   end
  end
  i64.const 1
  i64.add
  return
 )
)
