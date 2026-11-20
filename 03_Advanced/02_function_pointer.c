#include <stdio.h>

int multiply(int a, int b) { return a * b; }

int main(void) {
    int (*operation)(int, int) = multiply;
    printf("Result = %d\\n", operation(6, 7));
    return 0;
}
