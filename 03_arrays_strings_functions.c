/*
 * LEVEL 03: ARRAYS, STRINGS AND FUNCTIONS
 * Topics: 1D arrays, 2D arrays, strings, functions, recursion,
 * linear search and bubble sort.
 */
#include <stdio.h>
#include <string.h>

int factorial(int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int linear_search(const int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
        if (array[i] == target) return i;
    return -1;
}

void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main(void)
{
    int marks[5] = {78, 90, 65, 88, 72};
    int sum = 0;

    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", marks[i]);
        sum += marks[i];
    }
    printf("\nAverage = %.2f\n", (double) sum / 5);

    /* 2D array / matrix */
    int matrix[2][2] = {{1, 2}, {3, 4}};
    printf("\n2 x 2 matrix:\n");
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++)
            printf("%d ", matrix[row][col]);
        printf("\n");
    }

    /* String handling */
    char name[50];
    printf("\nEnter your first name (no spaces): ");
    if (scanf("%49s", name) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Hello, %s! Length = %zu\n", name, strlen(name));

    /* Functions and recursion */
    int n;
    printf("Enter a number from 0 to 12 for factorial: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 12) {
        printf("Please enter an integer from 0 to 12.\n");
        return 1;
    }
    printf("%d! = %d\n", n, factorial(n));

    /* Searching */
    int target;
    printf("Enter a mark to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int position = linear_search(marks, 5, target);
    if (position >= 0)
        printf("Found at index %d (position %d).\n", position, position + 1);
    else
        printf("Not found.\n");

    /* Sorting */
    bubble_sort(marks, 5);
    printf("Sorted marks: ");
    for (int i = 0; i < 5; i++) printf("%d ", marks[i]);
    printf("\n");

    return 0;
}

/*
 * PRACTICE:
 * 1. Find the second largest element in an array.
 * 2. Add and multiply two matrices.
 * 3. Reverse a string without using strrev().
 * 4. Check whether a string is a palindrome.
 * 5. Implement binary search on a sorted array.
 */