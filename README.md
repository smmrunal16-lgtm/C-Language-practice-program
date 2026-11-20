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

<p align="center">
  <a href="https://github.com/smmrunal16-lgtm/C-Language-practice-program/stargazers"><img src="https://img.shields.io/github/stars/smmrunal16-lgtm/C-Language-practice-program?style=social" alt="GitHub stars"></a>
  <a href="https://github.com/smmrunal16-lgtm/C-Language-practice-program/network/members"><img src="https://img.shields.io/github/forks/smmrunal16-lgtm/C-Language-practice-program?style=social" alt="GitHub forks"></a>
  <a href="https://github.com/smmrunal16-lgtm/C-Language-practice-program/actions/workflows/c-build.yml"><img src="https://github.com/smmrunal16-lgtm/C-Language-practice-program/actions/workflows/c-build.yml/badge.svg" alt="C build checks"></a>
</p>

## ⭐ Why this repository?

- Clear, runnable examples from C fundamentals to systems concepts.
- Data structures and algorithms implemented in plain C.
- Compiler warnings enabled to encourage clean code.
- GitHub Actions automatically checks that examples compile.
- Useful for CSE students, interview preparation, lab practice, and self-learning.

## 🧭 Learning roadmap

| File | Topics |
|---|---|
| `01_basics.c` | Variables, data types, input/output, operators, type conversion |
| `02_control_flow.c` | Conditions, switch, loops, number logic |
| `03_arrays_strings_functions.c` | Arrays, matrices, strings, functions, recursion, searching, sorting |
| `04_pointers_structures.c` | Pointers, pointer arithmetic, structures, unions, enums, typedef |
| `05_advanced_core.c` | Dynamic memory, files, function pointers, bitwise operations, macros |
| `06_data_structures.c` | Stack, circular queue, linked list, binary search tree |
| `07_algorithms.c` | Binary search, merge sort, quick sort, graph BFS |
| `08_modern_c.c` | C11 static assertions, callbacks, qsort, safe integer parsing, byte inspection |
| `09_avl_and_hash_table.c` | AVL self-balancing tree, rotations, open-addressed hash table |
| `10_graph_algorithms.c` | Dijkstra, Floyd-Warshall, topological sorting, cycle detection |
| `11_generic_vector.c` | Generic dynamic vector, memory growth, binary file serialization |

## ⚙️ Compile and run

Install GCC or Clang, then open a terminal in the repository folder.

```bash
# Compile one example
gcc -std=c11 -Wall -Wextra -Wpedantic 06_data_structures.c -o structures

# Run it
./structures
```

On Windows with MinGW, run the generated executable, for example `structures.exe`.

Compile any other file by replacing the source filename and output name. Each numbered source file has its own `main()`, so compile examples separately.

## 🧪 Automatic build checks

GitHub Actions runs on pushes and pull requests to `main`. It compiles the standalone C examples using GCC and common warning flags. Check the **Actions** tab to see the latest result.

## 🎯 Practice challenges

Try these after studying the examples:

- [ ] Implement a doubly linked list with insert, delete, and search.
- [ ] Add deletion to the binary search tree.
- [x] Implement an open-addressed hash table with collision handling.\n- [ ] Add hash-table resizing and load-factor management.
- [x] Implement Dijkstra's shortest-path algorithm.\n- [x] Implement Floyd-Warshall and topological sorting.
- [ ] Build a student-record manager using file storage.
- [ ] Create a mini shell with a small set of commands.
- [ ] Add unit tests for data structures and algorithms.

## 🤝 Contribute

Found a bug or have a useful C example? Contributions are welcome.

1. Fork this repository.
2. Create a branch for your improvement.
3. Add a focused example with comments and compile instructions.
4. Compile with `-std=c11 -Wall -Wextra -Wpedantic`.
5. Open a pull request explaining what you added.

Please keep examples beginner-friendly, portable where possible, and safe with memory allocation and input handling.

## 📣 Support the project

If this repository helps you learn C, consider giving it a ⭐ on GitHub and sharing it with classmates and fellow developers. Stars and shares help other learners discover the project, but they do not guarantee viral reach.

## 👨‍💻 Author

**Mrunal Mhetre** — CSE Engineering Student

- GitHub: [@smmrunal16-lgtm](https://github.com/smmrunal16-lgtm)
- Repository: [C Programming Mastery](https://github.com/smmrunal16-lgtm/C-Language-practice-program)

---
<p align="center"><i>Keep coding. Keep learning. Build something meaningful. 💻</i></p>
