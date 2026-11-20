# Contributing

Thanks for taking an interest in this C programming practice repository.

## Contribution workflow

1. Fork the repository.
2. Create a focused branch, for example `feat/linked-list-search`.
3. Make one small, meaningful improvement.
4. Compile with warnings enabled:
   ```bash
   gcc -std=c11 -Wall -Wextra -Wpedantic your_file.c -o program
   ```
5. Test normal cases, edge cases, and invalid input.
6. Open a pull request describing the change and how it was tested.

## Code expectations

- Use standard C where practical and mention the required C version.
- Keep functions focused and names descriptive.
- Check pointers, allocation results, and file-operation results.
- Avoid undefined behavior and unsafe input handling.
- Free dynamically allocated memory.
- Include sample input/output for interactive programs.
- Do not commit generated binaries or editor-specific temporary files.

## Commit message style

Use a short, descriptive prefix:

- `feat:` new functionality
- `fix:` bug fix
- `docs:` documentation
- `test:` tests or test coverage
- `refactor:` code cleanup without behavior changes

Examples:

- `feat: add queue implementation`
- `fix: handle empty linked list deletion`
- `docs: explain graph traversal examples`

Please submit original work and explain any external references used.
