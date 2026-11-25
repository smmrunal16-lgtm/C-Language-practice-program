/* malloc, calloc, realloc and free. Compile with: gcc -std=c11 -Wall -Wextra -Wpedantic dynamic_memory_management.c -o memory */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t count = 3;
    int *numbers = malloc(count * sizeof *numbers);
    if (numbers == NULL) { perror("malloc"); return EXIT_FAILURE; }
    for (size_t i = 0; i < count; ++i) numbers[i] = (int)(i + 1) * 10;

    int *zeroed = calloc(3, sizeof *zeroed);
    if (zeroed == NULL) { free(numbers); perror("calloc"); return EXIT_FAILURE; }

    size_t new_count = 6;
    int *grown = realloc(numbers, new_count * sizeof *numbers);
    if (grown == NULL) {
        free(numbers); free(zeroed); perror("realloc"); return EXIT_FAILURE;
    }
    numbers = grown;
    for (size_t i = count; i < new_count; ++i) numbers[i] = (int)(i + 1) * 10;

    printf("Reallocated array: ");
    for (size_t i = 0; i < new_count; ++i) printf("%d ", numbers[i]);
    printf("\nCalloc starts at: %d\n", zeroed[0]);

    free(numbers);
    free(zeroed);
    numbers = NULL;
    zeroed = NULL;
    return EXIT_SUCCESS;
}
