(module
 (export "simple_if" (func $simple_if))
 (export "nested_if" (func $nested_if))

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
)
