#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n;
    printf("How many integers? ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > 1000000) return 1;

    int *values = malloc(n * sizeof *values);
    if (values == NULL) {
        fprintf(stderr, "Memory allocation failed.\\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        printf("Value %zu: ", i + 1);
        if (scanf("%d", &values[i]) != 1) {
            free(values);
            return 1;
        }
    }
    printf("Values: ");
    for (size_t i = 0; i < n; i++) printf("%d ", values[i]);
    printf("\\n");
    free(values); /* Always release dynamically allocated memory. */
    return 0;
}
