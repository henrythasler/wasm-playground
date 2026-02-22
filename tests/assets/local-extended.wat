(module
  (export "many_locals" (func $many_locals))
  (func $many_locals (param $value i32) (result i32)
    (local $var0 i32) (local $var1 i32) (local $var2 i32) (local $var3 i32) (local $var4 i32) (local $var5 i32) (local $var6 i32) (local $var7 i32) (local $var8 i32) (local $var9 i32) (local $var10 i32) (local $var11 i32) (local $var12 i64) (local $var13 i64) (local $var14 i64) (local $var15 i32) (local $var16 i32) (local $var17 i32) (local $var18 i32) (local $var19 i32) (local $var20 i32) (local $var21 i32)
    local.get $value
    local.set $var0
    local.get $var0
    local.set $var1
    local.get $var1
    local.set $var2
    local.get $var2
    local.set $var3
    local.get $var3
    local.set $var4

    local.get $var4
    local.set $var5
    local.get $var5
    local.set $var6
    local.get $var6
    local.set $var7
    local.get $var7
    local.set $var8
    local.get $var8
    local.set $var9

    local.get $var9
    local.set $var10
    local.get $var10
    local.set $var11

    i64.const 1
    local.set $var12
    i64.const 2
    local.set $var13
    i64.const 3
    local.set $var14

    local.get $var11
    local.set $var15
    local.get $var15
    local.set $var16
    local.get $var16
    local.set $var17
    local.get $var17
    local.set $var18
    local.get $var18
    local.set $var19

    local.get $var19
    local.set $var20

    local.get $var20
    local.set $var21

    local.get $var21
  )  
)