/* Advanced pointers: arithmetic, double pointers, callbacks. Compile: gcc -std=c11 -Wall -Wextra -Wpedantic pointers_and_function_pointers.c -o pointers */
#include <stdio.h>
#include <stddef.h>

static int add(int a, int b) { return a + b; }
static int multiply(int a, int b) { return a * b; }

static void change_value(int **address, int *replacement) {
    *address = replacement;
}

int main(void) {
    int values[] = {10, 20, 30, 40};
    int *ptr = values;
    printf("Pointer arithmetic: ");
    for (size_t i = 0; i < sizeof values / sizeof values[0]; ++i)
        printf("%d ", *(ptr + i));

    int first = 5, second = 99;
    int *selected = &first;
    int **double_ptr = &selected;
    change_value(double_ptr, &second);
    printf("\nDouble pointer changed selected value: %d\n", *selected);

    int (*operation)(int, int) = add;
    printf("Function pointer (add): %d\n", operation(7, 3));
    operation = multiply;
    printf("Function pointer (multiply): %d\n", operation(7, 3));
    return 0;
}
