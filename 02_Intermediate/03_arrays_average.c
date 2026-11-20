#include <stdio.h>

int main(void) {
    int values[5];
    int sum = 0;
    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; i++) {
        if (scanf("%d", &values[i]) != 1) return 1;
        sum += values[i];
    }
    printf("Average = %.2f\\n", sum / 5.0);
    return 0;
}
