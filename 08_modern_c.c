/*
 * 08_modern_c.c
 * C11 features, callbacks, qsort, safe parsing and byte inspection.
 * Build: gcc -std=c11 -Wall -Wextra -Wpedantic 08_modern_c.c -o modern_c
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

typedef int (*Comparator)(const void *, const void *);
static int compare_ints(const void *lhs, const void *rhs) {
    int a = *(const int *)lhs, b = *(const int *)rhs;
    return (a > b) - (a < b); /* avoids subtraction overflow */
}
static void apply_to_array(int *a, size_t n, void (*fn)(int *)) {
    for (size_t i = 0; i < n; ++i) fn(&a[i]);
}
static void square(int *value) { *value *= *value; }

static int parse_int(const char *text, int *out) {
    char *end = NULL;
    errno = 0;
    long value = strtol(text, &end, 10);
    if (text == end || *end != '\0' || errno == ERANGE ||
        value < INT_MIN || value > INT_MAX) return 0;
    *out = (int)value;
    return 1;
}
static void print_bytes(const void *object, size_t size) {
    const unsigned char *bytes = object;
    for (size_t i = 0; i < size; ++i) printf("%02X ", bytes[i]);
    putchar('\n');
}

int main(int argc, char **argv) {
    int values[] = {42, 7, 19, 7, 100, -3};
    size_t count = sizeof values / sizeof values[0];
    qsort(values, count, sizeof values[0], (Comparator)compare_ints);
    printf("qsort result: ");
    for (size_t i = 0; i < count; ++i) printf("%d ", values[i]);
    putchar('\n');

    int callback_values[] = {2, 3, 4};
    apply_to_array(callback_values, 3, square);
    printf("Callback squares: %d %d %d\n",
           callback_values[0], callback_values[1], callback_values[2]);

    int parsed;
    const char *input = argc > 1 ? argv[1] : "2026";
    if (parse_int(input, &parsed)) printf("Parsed integer: %d\n", parsed);
    else fprintf(stderr, "Invalid integer: %s\n", input);

    uint32_t marker = UINT32_C(0x12345678);
    printf("Integer bytes (platform byte order): ");
    print_bytes(&marker, sizeof marker);

    /* C11 compile-time assertion */
    _Static_assert(sizeof(uint32_t) == 4, "uint32_t must be 4 bytes");
    return 0;
}
