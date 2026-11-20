/*
 * LEVEL 04: CORE C PROGRAMMING
 * Topics: pointers, pointer arithmetic, arrays and pointers,
 * structures, unions, enums, typedef.
 */
#include <stdio.h>

typedef struct {
    int roll_number;
    char name[40];
    float percentage;
} Student;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    /* Pointer basics */
    int value = 25;
    int *pointer = &value;
    printf("Value = %d\n", value);
    printf("Address of value = %p\n", (void *) pointer);
    printf("Value through pointer = %d\n", *pointer);

    *pointer = 50;
    printf("Updated value = %d\n", value);

    /* Swap using pointers */
    int first = 10, second = 20;
    swap(&first, &second);
    printf("After swap: first=%d second=%d\n", first, second);

    /* Array and pointer relationship */
    int numbers[] = {5, 10, 15, 20};
    int *p = numbers;
    printf("Array using pointer arithmetic: ");
    for (size_t i = 0; i < sizeof numbers / sizeof numbers[0]; i++)
        printf("%d ", *(p + i));
    printf("\n");

    /* Structure */
    Student student = {101, "Mrunal", 88.5f};
    printf("\nStudent record\n");
    printf("Roll number: %d\n", student.roll_number);
    printf("Name: %s\n", student.name);
    printf("Percentage: %.2f\n", student.percentage);

    Student *student_pointer = &student;
    printf("Access using structure pointer: %s\n", student_pointer->name);

    /* Union: members share the same memory */
    union Data {
        int integer;
        float decimal;
    } data;

    data.integer = 100;
    printf("\nUnion integer = %d\n", data.integer);
    data.decimal = 12.5f; /* This overwrites the shared storage. */
    printf("Union decimal = %.2f\n", data.decimal);

    /* Enum */
    enum Day { MONDAY = 1, TUESDAY, WEDNESDAY };
    enum Day today = WEDNESDAY;
    printf("Enum value for Wednesday = %d\n", today);

    return 0;
}

/*
 * PRACTICE:
 * 1. Create an array of 5 student structures.
 * 2. Find the length of a string using pointers.
 * 3. Demonstrate pointer to pointer (int **).
 * 4. Pass a structure to a function.
 * 5. Compare structure and union memory usage using sizeof.
 */