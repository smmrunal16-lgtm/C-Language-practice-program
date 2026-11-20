/*
 * LEVEL 05: ADVANCED C PROGRAMMING
 * Topics: dynamic memory, file handling, function pointers,
 * bitwise operators, preprocessor macros.
 */
#include <stdio.h>
#include <stdlib.h>

#define SQUARE(x) ((x) * (x))

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main(void)
{
    /* Dynamic memory allocation */
    size_t count;
    printf("How many integers? ");
    if (scanf("%zu", &count) != 1 || count == 0 || count > 10000) {
        printf("Enter a count from 1 to 10000.\n");
        return 1;
    }

    int *values = malloc(count * sizeof *values);
    if (values == NULL) {
        perror("malloc failed");
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        printf("Enter value %zu: ", i + 1);
        if (scanf("%d", &values[i]) != 1) {
            printf("Invalid input.\n");
            free(values);
            return 1;
        }
    }

    printf("Stored values: ");
    for (size_t i = 0; i < count; i++)
        printf("%d ", values[i]);
    printf("\n");

    /* Resize allocated memory */
    int *resized = realloc(values, (count + 1) * sizeof *values);
    if (resized == NULL) {
        perror("realloc failed");
        free(values);
        return 1;
    }
    values = resized;
    values[count] = 999;
    printf("Extra value after realloc = %d\n", values[count]);
    free(values);
    values = NULL;

    /* File handling */
    FILE *file = fopen("c_practice.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }
    if (fprintf(file, "Learning file handling in C.\n") < 0) {
        perror("File write failed");
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        perror("File close failed");
        return 1;
    }
    printf("Wrote sample text to c_practice.txt\n");

    /* Function pointer */
    int (*operation)(int, int) = add;
    printf("Function pointer (addition): %d\n", operation(4, 5));
    operation = multiply;
    printf("Function pointer (multiplication): %d\n", operation(4, 5));

    /* Bitwise operators */
    unsigned int x = 6U; /* binary 0110 */
    unsigned int y = 3U; /* binary 0011 */
    printf("\nBitwise AND = %u\n", x & y);
    printf("Bitwise OR = %u\n", x | y);
    printf("Bitwise XOR = %u\n", x ^ y);
    printf("Left shift x by 1 = %u\n", x << 1);
    printf("Right shift x by 1 = %u\n", x >> 1);

    /* Set, clear and test bit 1 */
    unsigned int flags = 0U;
    flags |= (1U << 1);       /* set bit */
    printf("Bit 1 set: %u\n", (flags >> 1) & 1U);
    flags &= ~(1U << 1);      /* clear bit */
    printf("After clearing bit 1: %u\n", (flags >> 1) & 1U);

    /* Macro */
    printf("Square of 7 = %d\n", SQUARE(7));

    return 0;
}

/*
 * ADVANCED PRACTICE:
 * 1. Build a dynamic student record manager using malloc/realloc.
 * 2. Create a program to append, read and search records in a file.
 * 3. Build a calculator using an array of function pointers.
 * 4. Implement a singly linked list (insert, delete, display).
 * 5. Implement stack and queue using structures.
 * 6. Implement a binary search tree (insert, search, traversal).
 *
 * CORE C REVISION:
 * - Storage classes: auto, register, static, extern.
 * - Scope and lifetime of variables.
 * - const, volatile, restrict, and void pointers.
 * - Command-line arguments: int main(int argc, char *argv[]).
 * - Header files, separate compilation, and the linker.
 * - Undefined behavior, buffer bounds, and memory ownership.
 */