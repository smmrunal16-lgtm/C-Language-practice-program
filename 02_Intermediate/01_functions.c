#include <stdio.h>

int add(int x, int y) { return x + y; }

int main(void) {
    int a, b;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;
    printf("Sum = %d\\n", add(a, b));
    return 0;
}
