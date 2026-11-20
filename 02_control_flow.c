/* LEVEL 02: CONDITIONS AND LOOPS — if/else, switch, for, while, do-while */
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        puts("Invalid input.");
        return 1;
    }

    if (n > 0) puts("Positive");
    else if (n < 0) puts("Negative");
    else puts("Zero");

    printf("%d is %s\n", n, n % 2 == 0 ? "even" : "odd");

    printf("Multiplication table of %d:\n", n);
    for (int i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);

    int temp = n, digits = 0;
    if (temp == 0) digits = 1;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    printf("Number of digits = %d\n", digits);

    int choice;
    do {
        printf("Enter 0 to exit: ");
        if (scanf("%d", &choice) != 1) {
            puts("Invalid input.");
            return 1;
        }
    } while (choice != 0);

    return 0;
}

/* Practice: largest of three, calculator with switch, factorial, prime test,
   reverse a number, palindrome number, Fibonacci series, star patterns. */
