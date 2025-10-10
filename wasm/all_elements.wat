(module
  ;; Import globals that can be used in element offset expressions
  (import "env" "offset1" (global $importedOffset1 i32))
  (import "env" "offset2" (global $importedOffset2 i32))
  (import "env" "offset3" (global $importedOffset3 i32))
  
  ;; Import a table to populate with elements
  (import "env" "importedTable" (table 30 funcref))
  
  ;; Define multiple functions to reference in element sections
  (func $func0 (result i32)
    i32.const 0
  )
  
  (func $func1 (result i32)
    i32.const 1
  )
  
  (func $func2 (result i32)
    i32.const 2
  )
  
  (func $func3 (result i32)
    i32.const 3
  )
  
  (func $func4 (result i32)
    i32.const 4
  )
  
  (func $func5 (result i32)
    i32.const 5
  )
  
  (func $func6 (result i32)
    i32.const 6
  )
  
  (func $func7 (result i32)
    i32.const 7
  )
  
  (func $func8 (param i32) (result i32)
    local.get 0
    i32.const 10
    i32.add
  )
  
  (func $func9 (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.mul
  )
  
  ;; Additional functions with different signatures
  (func $func10 (param i32) (result i32)
    local.get 0
    i32.const 2
    i32.mul
  )
  
  (func $func11 (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.sub
  )
  
  (func $func12 (result i32)
    i32.const 100
  )
  
  (func $func13 (param i32) (result i32)
    local.get 0
    i32.const 1
    i32.add
  )
  
  (func $func14 (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.add
  )
  
  ;; Element section 1: Active segment at offset 0 with constant offset
  (elem (i32.const 0) $func0 $func1 $func2)
  
  ;; Element section 2: Active segment using imported global offset
  (elem (global.get $importedOffset1) $func3 $func4 $func5)
  
  ;; Element section 3: Active segment at offset 10 with mixed signatures
  (elem (i32.const 10) $func6 $func8 $func7 $func9)
  
  ;; Element section 4: Active segment using second imported global
  (elem (global.get $importedOffset2) $func10 $func11 $func12)
  
  ;; Element section 5: Dense packing - single element at offset 3
  (elem (i32.const 3) $func12)
  
  ;; Element section 6: Another segment at offset 8
  (elem (i32.const 8) $func0 $func1)
  
  ;; Element section 7: Using third imported global offset
  (elem (global.get $importedOffset3) $func5 $func6)
  
  ;; Element section 8: Segment with all parameter-taking functions
  (elem (i32.const 20) $func8 $func9 $func10 $func11 $func13 $func14)
  
  ;; Element section 9: Segment with all no-parameter functions
  (elem (i32.const 5) $func0 $func1 $func2 $func3 $func4 $func5 $func6 $func7 $func12)
  
  ;; Define types for call_indirect
  (type $type0 (func (result i32)))
  (type $type1 (func (param i32) (result i32)))
  (type $type2 (func (param i32 i32) (result i32)))
  
  ;; Export functions for testing
  (export "func0" (func $func0))
  (export "func1" (func $func1))
  (export "func2" (func $func2))
  (export "func3" (func $func3))
  (export "func4" (func $func4))
  (export "func5" (func $func5))
  (export "func6" (func $func6))
  (export "func7" (func $func7))
  (export "func8" (func $func8))
  (export "func9" (func $func9))
  (export "func10" (func $func10))
  (export "func11" (func $func11))
  (export "func12" (func $func12))
  (export "func13" (func $func13))
  (export "func14" (func $func14))
  
  ;; Function to call table entries indirectly (no parameters)
  (func (export "callTable") (param $tableIdx i32) (result i32)
    local.get $tableIdx
    call_indirect (type $type0)
  )
  
  ;; Function to call table entry with one parameter
  (func (export "callTableWith1Param") (param $tableIdx i32) (param $arg i32) (result i32)
    local.get $arg
    local.get $tableIdx
    call_indirect (type $type1)
  )
  
  ;; Function to call table entry with two parameters
  (func (export "callTableWith2Params") (param $tableIdx i32) (param $arg1 i32) (param $arg2 i32) (result i32)
    local.get $arg1
    local.get $arg2
    local.get $tableIdx
    call_indirect (type $type2)
  )
  
  ;; Helper function to get table size
  (func (export "getTableSize") (result i32)
    i32.const 30
  )
)