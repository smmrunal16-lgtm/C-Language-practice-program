# C Programming Challenge Lab

A practical challenge track to strengthen C programming, problem-solving, data structures, and algorithmic thinking.

## How to use this file

1. Solve each task without copying a ready-made solution.
2. Compile with warnings enabled: `gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o app`.
3. Test normal, boundary, and invalid inputs.
4. Commit your solution with a descriptive message.

## Level 1 — Core programming

- [ ] Reverse a string without using a second string buffer.
- [ ] Check whether a number is prime using an efficient loop bound.
- [ ] Find the second-largest distinct element in an array.
- [ ] Count character frequency while ignoring letter case.
- [ ] Build a menu-driven calculator with input validation.

## Level 2 — Pointers and memory

- [ ] Implement your own versions of `strlen`, `strcpy`, and `strcmp`.
- [ ] Dynamically allocate a matrix and release all allocated memory.
- [ ] Write a safe dynamic integer array with capacity growth.
- [ ] Parse a line of integers using `strtol` and handle invalid input.
- [ ] Implement a singly linked list with insert, delete, search, and free operations.

## Level 3 — Data structures

- [ ] Implement stack and queue using arrays.
- [ ] Implement a circular queue.
- [ ] Implement a binary search tree with traversal and deletion.
- [ ] Implement an AVL tree with rotations.
- [ ] Implement a hash table using open addressing.

## Level 4 — Algorithms

- [ ] Implement binary search iteratively and recursively.
- [ ] Implement merge sort and quick sort.
- [ ] Compare sorting algorithms on identical input data.
- [ ] Implement breadth-first and depth-first graph traversal.
- [ ] Implement Dijkstra's shortest-path algorithm for non-negative edge weights.

## Level 5 — Mini projects

- [ ] Student record manager using file handling.
- [ ] Contact book with search and update features.
- [ ] Library management program with persistent storage.
- [ ] Text-file word frequency analyzer.
- [ ] Command-line expense tracker with CSV export.

## Quality checklist

- Check every return value from allocation and file operations.
- Avoid buffer overflows; prefer bounded input functions.
- Free every dynamically allocated resource.
- Use meaningful names and small functions.
- Compile with warnings and fix them rather than hiding them.
- Test empty input, boundary values, and malformed input.

## Suggested commit messages

- `feat: add circular queue implementation`
- `fix: validate input before parsing integers`
- `test: cover binary search boundary cases`
- `docs: add C programming challenge roadmap`

Happy coding — consistency and genuine practice matter more than commit count.
