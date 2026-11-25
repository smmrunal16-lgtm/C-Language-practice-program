# 🚀 C Programming Mastery — Beginner to Advanced

<p align="center">
  <b>Learn C by building, experimenting, and solving problems.</b><br>
  A practical C programming collection by <a href="https://github.com/smmrunal16-lgtm">Mrunal Mhetre</a>.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C11-blue?style=for-the-badge&logo=c" alt="C11">
  <img src="https://img.shields.io/badge/Level-Beginner%20to%20Advanced-purple?style=for-the-badge" alt="Beginner to Advanced">
  <img src="https://img.shields.io/badge/Build-GCC-success?style=for-the-badge&logo=gnu" alt="GCC">
  <img src="https://img.shields.io/badge/Contributions-Welcome-orange?style=for-the-badge" alt="Contributions welcome">
</p>

## ⭐ What's included?

- Beginner, intermediate and advanced C examples.
- Pointer arithmetic, double pointers and function pointers.
- Dynamic memory allocation with `malloc`, `calloc`, `realloc` and `free`.
- Text and binary file handling.
- Structures, unions, enumerations and bitwise operations.
- Stack, queue, linked list, trees, graphs and algorithms.
- Six practical console projects with file storage where appropriate.

## 🧭 Learning roadmap

| Path | Topics |
|---|---|
| `01_basics.c` | Variables, data types, input/output, operators |
| `02_control_flow.c` | Conditions, switch, loops |
| `03_arrays_strings_functions.c` | Arrays, matrices, strings, functions, recursion |
| `04_pointers_structures.c` | Pointers, structures, unions, enums |
| `05_advanced_core.c` | Dynamic memory, files, function pointers, bitwise operations |
| `06_data_structures.c` | Stack, queue, linked list, binary search tree |
| `07_algorithms.c` | Searching, sorting, graph traversal |
| `08_modern_c.c` | C11 features, callbacks, safe parsing |
| `09_avl_and_hash_table.c` | AVL tree and hash table |
| `10_graph_algorithms.c` | Dijkstra, Floyd-Warshall, topological sorting |
| `11_generic_vector.c` | Generic dynamic vector and binary serialization |
| `12_Advanced/` | Pointer arithmetic, double pointers, function pointers |
| `13_Advanced/` | malloc, calloc, realloc and free |
| `14_Advanced/` | File read, write, append and binary files |
| `15_Advanced/` | Structures, unions, enums and bitwise operators |
| `16_Advanced/` | Stack, queue and linked list demonstrations |
| `17_Advanced/` | Binary search, insertion sort and recursion |
| `18_Projects/` | Banking system |
| `19_Projects/` | Student management with text-file storage |
| `20_Projects/` | Library issue/return tracker |
| `21_Projects/` | Contact management with file storage |
| `22_Projects/` | Inventory management with file storage |
| `23_Projects/` | Multiple-choice quiz application |

## ⚙️ Compile and run

Install GCC or Clang. Open a terminal in the repository folder and compile one source file at a time:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic 12_Advanced/pointers_and_function_pointers.c -o pointers
./pointers
```

For a project, change the source path and executable name:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic 19_Projects/student_management.c -o students
./students
```

On Windows with MinGW, run the generated `.exe` file. Each source file has its own `main()`, so compile files separately. File-based projects create their data files in the current working directory.

## 🧠 Important learning notes

- Always check whether memory allocation returns `NULL`.
- Release dynamically allocated memory with `free()`.
- Check file-opening and file-read/write results.
- Binary files containing C structures are intended for learning on the same platform/compiler; they are not a portable interchange format.
- The banking, library and inventory examples are educational console demonstrations, not production systems.
- Some sample projects intentionally keep a small feature set so learners can extend them.

## 🎯 Suggested improvements

- Add edit/delete/search features to the student and contact managers.
- Store multiple books and members in the library application.
- Add account creation and transaction history to the banking demo.
- Add update/delete and low-stock alerts to inventory management.
- Add more questions and randomized order to the quiz.
- Add unit tests and input validation to every program.

## 🤝 Contribute

1. Fork this repository.
2. Create a branch for your improvement.
3. Add a focused example with comments and compile instructions.
4. Compile with `-std=c11 -Wall -Wextra -Wpedantic`.
5. Open a pull request explaining what you added.

## 👨‍💻 Author

**Mrunal Mhetre** — CSE Engineering Student

- GitHub: [@smmrunal16-lgtm](https://github.com/smmrunal16-lgtm)
- Repository: [C Programming Mastery](https://github.com/smmrunal16-lgtm/C-Language-practice-program)

---
<p align="center"><i>Keep coding. Keep learning. Build something meaningful. 💻</i></p>
