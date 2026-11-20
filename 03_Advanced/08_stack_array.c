#include <stdio.h>

#define CAPACITY 5

int main(void) {
    int stack[CAPACITY];
    int top = -1;

    /* Push */
    for (int value = 10; value <= 30; value += 10) {
        if (top == CAPACITY - 1) { puts("Stack overflow"); break; }
        stack[++top] = value;
    }

    /* Peek and pop */
    if (top >= 0) printf("Top element: %d\\n", stack[top]);
    while (top >= 0) printf("Popped: %d\\n", stack[top--]);
    return 0;
}
