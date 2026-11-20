#include <stdio.h>

int main(void) {
    int age = 20;
    float percentage = 85.5f;
    double distance = 12345.678;
    char grade = 'A';

    printf("Age: %d\\n", age);
    printf("Percentage: %.2f\\n", percentage);
    printf("Distance: %.3lf\\n", distance);
    printf("Grade: %c\\n", grade);
    return 0;
}
