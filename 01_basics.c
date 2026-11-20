/* LEVEL 01: BEGINNER C — input/output, variables, operators, type conversion */
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");

    int age;
    float marks;
    printf("Enter your age and marks: ");
    if (scanf("%d %f", &age, &marks) != 2) {
        puts("Invalid input.");
        return 1;
    }
    printf("Age = %d, Marks = %.2f\n", age, marks);

    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        puts("Invalid input.");
        return 1;
    }
    printf("Addition = %d\n", a + b);
    printf("Subtraction = %d\n", a - b);
    printf("Multiplication = %d\n", a * b);
    if (b != 0) printf("Division = %.2f\n", (double)a / b);
    else puts("Division by zero is not allowed.");

    printf("Is a even? %s\n", a % 2 == 0 ? "Yes" : "No");
    return 0;
}

/* Practice: circle area, simple interest, temperature conversion, swap two numbers. */
