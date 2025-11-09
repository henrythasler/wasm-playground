Source: https://claude.ai

# WebAssembly Block and br_if Instructions

## Block Instruction

The `block` instruction in WebAssembly creates a **structured control flow construct** that groups a sequence of instructions together. Think of it as a labeled section of code that you can branch out of.

**Syntax:**
```wasm
block [result_type]
  ;; instructions
end
```

Key characteristics:
- Blocks define a **label** that can be targeted by branch instructions
- They can optionally specify a result type (the type of value the block produces)
- Blocks are indexed by depth: the innermost block is at depth 0, the next outer is at depth 1, etc.
- Control flows sequentially through the block unless a branch instruction redirects it

**Example:**
```wasm
block (result i32)
  i32.const 42
  ;; if we reach here, 42 will be the block's result
end
;; 42 is now on the stack
```

## br_if Instruction

The `br_if` (branch if) instruction performs a **conditional branch** to a target label. It's like an "if" statement that jumps to a specific point in your code.

**Syntax:**
```wasm
br_if $label_depth
```

**Behavior:**
1. Pops an `i32` value from the stack (the condition)
2. If the value is **non-zero** (true), branches to the specified label
3. If the value is **zero** (false), continues to the next instruction
4. When branching, it "breaks out" of the target block/loop

**Example - Simple conditional exit:**
```wasm
block $exit
  i32.const 10
  i32.const 20
  i32.gt_s        ;; is 10 > 20? (false, pushes 0)
  br_if $exit     ;; doesn't branch because condition is 0
  
  i32.const 99    ;; this executes
end
;; 99 is on the stack
```

**Example - Early exit pattern:**
```wasm
block $check
  local.get $value
  i32.const 0
  i32.eq          ;; is value == 0?
  br_if $check    ;; if true, skip to end of block
  
  ;; do something with non-zero value
  local.get $value
  i32.const 2
  i32.mul
end
```

## Combining Block and br_if

These instructions work together to create conditional logic:

```wasm
;; Implement: if (x > 5) { result = x * 2 } else { result = 0 }
block $else (result i32)
  local.get $x
  i32.const 5
  i32.le_s        ;; x <= 5?
  br_if $else     ;; if true, jump to else case
  
  ;; then case
  local.get $x
  i32.const 2
  i32.mul
  br 0            ;; jump past else
  
  ;; else case (label $else points here)
  i32.const 0
end
```

The combination allows you to build if-else logic, early returns, and various control flow patterns in WebAssembly's structured programming model.

# The br Instruction

The `br` (branch) instruction performs an **unconditional branch** to a target label. Unlike `br_if`, it always jumps—no condition required.

## Syntax

```wasm
br $label_depth
```

The `$label_depth` is a number indicating which enclosing block/loop/if to branch to:
- `0` = innermost enclosing construct
- `1` = next outer construct
- `2` = next outer, and so on...

## Behavior

When `br` executes:
1. **Immediately jumps** to the end of the target block (or beginning if it's a loop)
2. **Unwinds the stack** to match the target's signature
3. **No conditions** are checked—it always branches

## Key Difference from br_if

| Instruction | Behavior | Stack Before | Stack After |
|-------------|----------|--------------|-------------|
| `br 0` | Always branches | `[values...]` | Matching target type |
| `br_if 0` | Branches if top is non-zero | `[values...] i32` | `[values...]` (if no branch) |

## Examples

### Basic unconditional jump:
```wasm
block $exit
  i32.const 10
  br $exit      ;; always jumps to end of block
  i32.const 20  ;; this never executes (unreachable)
end
;; 10 is on the stack
```

### Implementing if-else:
```wasm
block $else (result i32)
  block $then
    local.get $condition
    i32.eqz
    br_if $then      ;; if false, skip then block
    
    ;; else case
    i32.const 0
    br $else         ;; unconditionally jump to end
  end
  
  ;; then case
  i32.const 1
end
;; result (0 or 1) is on the stack
```

### Early return pattern:
```wasm
block $return (result i32)
  local.get $x
  i32.const 0
  i32.lt_s
  if
    i32.const -1
    br $return     ;; early exit with -1
  end
  
  local.get $x
  i32.const 100
  i32.add
  ;; falls through with x + 100
end
```

### Loop with break:
```wasm
block $break
  loop $continue
    ;; loop body
    local.get $counter
    i32.const 10
    i32.ge_s
    br_if $break      ;; conditional break out of loop
    
    ;; increment counter
    local.get $counter
    i32.const 1
    i32.add
    local.set $counter
    
    br $continue      ;; unconditional jump back to loop start
  end
end
```

## Important Distinction: Block vs Loop

The target type matters:

- **`br` to a block**: Jumps to the **end** of the block (exits it)
- **`br` to a loop**: Jumps to the **beginning** of the loop (continues it)

```wasm
loop $repeat
  ;; do work
  local.get $done
  i32.eqz
  br_if $repeat    ;; if not done, go back to loop start
end

block $exit
  ;; do work
  local.get $error
  br_if $exit      ;; if error, jump to end (exit block)
end
```

## Summary

- **`br`**: Unconditional branch (always jumps)
- **`br_if`**: Conditional branch (jumps if condition is true)
- **`block`**: Creates a label you can branch to

Together, these three instructions form the foundation of all control flow in WebAssembly!

# Managing the Stack Before and After a Block

Understanding stack management with blocks is crucial in WebAssembly. Let's break it down systematically.

## Block Type Signatures

Blocks have a **type signature** that specifies what they consume and produce:

```wasm
block [blocktype]
  ;; instructions
end
```

The `blocktype` can be:
- **Empty**: `block` - consumes nothing, produces nothing
- **Single result**: `block (result i32)` - consumes nothing, produces one i32
- **Function type**: `block (param i32) (result i64)` - consumes i32, produces i64

## Stack Rules

### Rule 1: Block Entry
When entering a block, the stack must have the **input values** (params) required by the block's signature.

```wasm
;; Stack before: [... other_values]
i32.const 42
i32.const 10
;; Stack: [... other_values, 42, 10]

block (param i32 i32) (result i32)
  ;; Stack inside block: [42, 10]
  ;; The block "captures" the top 2 values as its inputs
  i32.add
  ;; Stack: [52]
end
;; Stack after: [... other_values, 52]
```

### Rule 2: Block Exit (Normal)
When the block ends normally (no branches), the stack must have exactly the **result values** specified by the block type.

```wasm
block (result i32)
  i32.const 100
  ;; Must have exactly 1 i32 on stack when block ends
end
;; 100 is now available after the block
```

### Rule 3: Block Exit (via Branch)
When branching out with `br` or `br_if`, the stack must match the block's result type.

```wasm
block $exit (result i32)
  i32.const 5
  i32.const 10
  i32.const 1    ;; condition
  br_if $exit    ;; branches with value 10 on stack
  
  ;; This part doesn't execute
  i32.const 99
end
;; Stack has 10
```

## Practical Examples

### Example 1: Empty Block (no params, no results)
```wasm
;; Stack before: [...]
block
  ;; Stack: [...]
  i32.const 42
  drop           ;; must clean up!
  ;; Stack: [...]
end
;; Stack after: [...]
```

### Example 2: Block with Result
```wasm
;; Stack before: [...]
block (result i32)
  i32.const 10
  i32.const 20
  i32.add
  ;; Stack: [30]
  ;; Must leave exactly 1 i32 on stack
end
;; Stack after: [..., 30]
```

### Example 3: Block with Params and Result
```wasm
;; Stack before: [...]
i32.const 5
i32.const 3
;; Stack: [..., 5, 3]

block (param i32 i32) (result i32)
  ;; Stack inside: [5, 3]
  i32.mul
  ;; Stack: [15]
end
;; Stack after: [..., 15]
```

### Example 4: Conditional with Different Paths
```wasm
;; Both paths must produce the same stack state!
block $check (result i32)
  local.get $condition
  if (result i32)
    ;; Path 1
    i32.const 100
  else
    ;; Path 2
    i32.const 200
  end
  ;; Stack must have 1 i32 here regardless of path
end
;; Stack: [100 or 200]
```

### Example 5: Early Exit with br
```wasm
block $outer (result i32)
  i32.const 42
  
  local.get $early_exit
  br_if $outer    ;; exits with 42 if true
  
  drop            ;; remove 42
  i32.const 99    ;; use 99 instead
end
;; Stack has either 42 or 99
```

## Common Patterns

### Pattern 1: Preserving Values Across Block
```wasm
;; Want to keep value on stack while doing work
local.get $important_value
;; Stack: [important_value]

block
  ;; Do some work that doesn't affect the stack top
  call $some_function
end

;; Stack: [important_value] - still there!
```

### Pattern 2: Accumulating Results
```wasm
;; Start with initial value
i32.const 0

;; Multiple blocks can transform it
block (param i32) (result i32)
  i32.const 10
  i32.add
end

block (param i32) (result i32)
  i32.const 5
  i32.mul
end

;; Stack: [50] (0 + 10) * 5
```

### Pattern 3: Cleanup Before Branch
```wasm
block $exit (result i32)
  i32.const 100
  i32.const 200
  i32.const 300
  ;; Stack: [100, 200, 300]
  
  local.get $error
  if
    ;; Need to clean up extra values!
    drop    ;; remove 300
    drop    ;; remove 200
    ;; Stack: [100]
    br $exit  ;; exit with just 100
  end
  
  ;; Normal path: use all three values
  i32.add
  i32.add
  ;; Stack: [600]
end
```

## Debugging Stack Issues

### Issue: Stack Polymorphism with Unreachable Code
```wasm
block (result i32)
  i32.const 1
  if
    i32.const 42
    return        ;; function returns, makes rest unreachable
  end
  ;; This point is unreachable, stack type is polymorphic
  ;; No need to produce i32 here!
end
```

### Issue: Mismatched Stack Heights
```wasm
;; ❌ WRONG
block (result i32)
  i32.const 10
  i32.const 20
  ;; Stack: [10, 20] - too many values!
end

;; ✅ CORRECT
block (result i32)
  i32.const 10
  i32.const 20
  i32.add
  ;; Stack: [30] - exactly 1 i32
end
```

## Key Takeaways

1. **Block entry**: Stack must have the block's input parameters
2. **Block exit**: Stack must have exactly the block's output results
3. **All paths must match**: Every branch and fall-through must produce the same stack shape
4. **Clean up extras**: Use `drop` to remove unwanted values before branching
5. **Stack discipline**: Track your stack mentally or use comments to stay organized

The WebAssembly validator enforces these rules strictly, so any stack mismatches will be caught at validation time!