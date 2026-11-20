# C Language Practice Program

A structured **Beginner to Advanced Core C Programming** repository with runnable, commented examples.

## Learning path

| Level | Topics | File |
|---|---|---|
| 1. Beginner | Hello World, variables, data types, input/output, operators, type conversion | `01_basics.c` |
| 2. Foundations | if/else, switch, for/while/do-while, digit logic | `02_control_flow.c` |
| 3. Intermediate | Arrays, matrices, strings, functions, recursion, searching, sorting | `03_arrays_strings_functions.c` |
| 4. Core C | Pointers, pointer arithmetic, structures, unions, enums, typedef | `04_pointers_structures.c` |
| 5. Advanced | malloc/realloc/free, file handling, function pointers, bitwise operators, macros | `05_advanced_core.c` |

The repository also contains the `01_Beginner/`, `02_Intermediate/`, and `03_Advanced/` topic folders for further practice.

## Compile and run

Install GCC or Clang. From the repository root:

```bash
gcc -std=c11 -Wall -Wextra -pedantic 01_basics.c -o basics
./basics
```

For another program, replace the source filename and executable name. On Windows, run the generated `.exe` file.

## Study routine

1. Read the comments and understand each statement.
2. Compile with warnings enabled.
3. Test normal, boundary, and invalid inputs.
4. Modify the code and solve the practice tasks at the end of each file.
5. Learn to trace the program before moving to the next level.

## Further core topics to master

Storage classes, scope and lifetime, const/volatile/restrict, void pointers, command-line arguments, header files, separate compilation, preprocessor directives, linked lists, stacks, queues, trees, and safe memory management.

**Note:** These programs are learning examples. Check input and function return values, avoid out-of-bounds access, and release dynamically allocated memory.
