# C Language Practice Program

A structured **Beginner to Advanced Core C Programming** practice repository. Each source file focuses on one concept and includes a small runnable example.

## Learning roadmap

### 1. Beginner
- Hello World and program structure
- Variables, data types, constants
- Input and output with `printf` and `scanf`
- Arithmetic and relational operators
- `if/else`, loops, and multiplication tables

### 2. Intermediate
- Functions and recursion
- Arrays and strings
- Pointers and pass-by-address
- Structures and unions
- File handling and standard library basics

### 3. Advanced Core C
- Dynamic memory: `malloc`, `calloc`, `realloc`, `free`
- Function pointers and callbacks
- Bitwise operators
- Command-line arguments
- Linked lists, stacks, queues, and searching/sorting (planned practice topics)

## Repository structure

```text
01_Beginner/
02_Intermediate/
03_Advanced/
```

## Compile and run

Install GCC or Clang. From the repository root, compile any program like this:

```bash
gcc -std=c11 -Wall -Wextra -pedantic 01_Beginner/01_hello_world.c -o hello
./hello
```

On Windows, run the generated executable with:

```powershell
.\\hello.exe
```

## Recommended practice routine

1. Read the source and understand each statement.
2. Compile with warnings enabled.
3. Run with normal, boundary, and invalid inputs.
4. Modify the program and solve a similar problem without looking.
5. Keep notes about errors and what you learned.

**Note:** These examples are educational starting points. Complete the planned topics and add your own exercises as you progress.
