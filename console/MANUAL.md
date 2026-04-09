# MLang Programming Language Manual

## Version 1.3.3

**Machine Learning Pipeline Automator (MLAuto) Console Language**

MLang is a dynamically-typed, interpreted programming language designed for the MLAuto console. It supports variables, control structures, functions, lists, arithmetic, comparisons, and built-in utilities. The language is implemented in Python with components like lexer (`lex.py`), parser (`parser.py`), interpreter (`intpret.py`), nodes (`nodes.py`), tokenizer (`tok.py`), and error handling (`error.py`).

Run MLang via `console/MLang.py` for the interactive REPL.

## Quick Start

```
MLang >> VAR x = 10
MLang >> print(x)
10
MLang >> VAR names = ["Alice", "Bob"]
MLang >> print(len(names))
2
```

## Syntax Overview

### 1. Variables

Declare with `VAR`:

```
VAR x = 42        # Numbers (int/float)
VAR name = "MLang" # Strings
VAR lst = [1, 2, 3] # Lists
```

Variables are dynamically typed and scoped via symbol tables (`symtable.py`, `ctx.py`).

### 2. Arithmetic & Operators

```
+ - * / ^   # Add, subtract, multiply, divide, power
== != < > <= >=  # Comparisons (return 1/true or 0/false)
AND OR NOT  # Logical
```

Examples:

```
VAR a = 10 + 5 * 2  # 20
VAR b = a > 15      # 1 (true)
```

### 3. Strings

```
VAR s = "Hello \\nWorld"  # Escapes: \\n, \\t
s + "!"  # Concat: "Hello \\nWorld!"
s * 3    # Repeat
```

### 4. Lists

```
VAR lst = [1, "two", [3]]
lst[0]          # 1 (index with /)
append(lst, 4)  # Mutates: [1, "two", [3], 4]
pop(lst, 0)     # Removes/returns 1
extend(lstA, lstB)
len(lst)
```

### 5. Control Flow

#### If/Elif/Else

```
IF condition THEN
  statements
ELIF condition THEN
  statements
ELSE
  statements
END
```

Single-line: `IF x > 0 THEN print("Positive") END`

#### For Loops

```
FOR var = start TO end [STEP step] THEN
  body
END
```

Example:

```
FOR i = 1 TO 5 THEN
  print(i)
END
```

#### While Loops

```
WHILE condition THEN
  body
END
```

#### Break/Continue

Supported in loops.

### 6. Functions

```
FUN name(arg1, arg2) -> return expr

# Or multi-line:
FUN name(arg1)
  VAR x = arg1 * 2
  RETURN x
END
```

Call: `name(10, 20)`

Anonymous: `FUN(x) -> x * 2`

### 7. Return

```
RETURN value
```

## Built-in Functions (`intpret.py`)

| Function               | Args         | Description                   |
| ---------------------- | ------------ | ----------------------------- |
| `print(value)`         | value        | Prints value                  |
| `print_ret(value)`     | value        | Returns string representation |
| `input()`              | -            | Reads string input            |
| `input_int()`          | -            | Reads integer input           |
| `clear()`              | -            | Clears console                |
| `is_number(value)`     | value        | 1 if number                   |
| `is_string(value)`     | value        | 1 if string                   |
| `is_list(value)`       | value        | 1 if list                     |
| `is_function(value)`   | value        | 1 if function                 |
| `append(list, value)`  | list, value  | Appends to list               |
| `pop(list, index)`     | list, index  | Pops from list                |
| `extend(listA, listB)` | listA, listB | Extends listA                 |
| `len(list)`            | list         | List length                   |
| `run("file.mlang")`    | filename     | Runs MLang file               |

Constants: `null` (0), `false` (0), `true` (1), `math_PI`.

## Comments

```
# This is a comment
```

## Errors

Handled by `error.py`: IllegalChar, InvalidSyntax, Runtime (with traceback via contexts).

Lexing skips `#` comments (`lex.py`).

## REPL Usage (`MLang.py`)

- Interactive console.
- Multi-line input supported.
- Errors show position with arrows (`strings_with_arrows.py`).

## Language Implementation

- **Lexer** (`lex.py`): Tokenizes input (numbers, strings, IDs, operators).
- **Parser** (`parser.py`): Builds AST (`nodes.py`).
- **Interpreter** (`intpret.py`): Executes AST with runtime results (`RTRes.py`).
- **Positions** (`pos.py`): Tracks source locations.

## Examples

### Factorial

```
FUN fact(n)
  IF n <= 1 THEN
    RETURN 1
  END
  RETURN n * fact(n - 1)
END

print(fact(5))  # 120
```

### List Sum

```
FUN sum(lst)
  VAR total = 0
  FOR i = 0 TO len(lst) - 1 STEP 1 THEN
    total = total + lst[i]
  END
  RETURN total
END
```

## Running Files

Save as `.mlang`, use `run("script.mlang")` in REPL.

For more, explore source files in `console/`.

---

_Copyright (c) Akshay_babu, All rights reserved!_
