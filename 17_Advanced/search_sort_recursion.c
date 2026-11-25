/* Searching, sorting and recursion examples. */
#include <stdio.h>
#include <stddef.h>

static int binary_search(const int a[], size_t n, int target) {
    size_t low = 0, high = n;
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        if (a[mid] == target) return (int)mid;
        if (a[mid] < target) low = mid + 1; else high = mid;
    }
    return -1;
}
static void insertion_sort(int a[], size_t n) {
    for (size_t i = 1; i < n; ++i) {
        int key = a[i]; size_t j = i;
        while (j > 0 && a[j - 1] > key) { a[j] = a[j - 1]; --j; }
        a[j] = key;
    }
}
static unsigned long factorial(unsigned int n) {
    return n < 2 ? 1UL : n * factorial(n - 1);
}
int main(void) {
    int data[] = {9, 2, 7, 1, 5};
    size_t n = sizeof data / sizeof data[0];
    insertion_sort(data, n);
    printf("Sorted: ");
    for (size_t i = 0; i < n; ++i) printf("%d ", data[i]);
    printf("\nBinary search for 7: index %d\n", binary_search(data, n, 7));
    printf("Factorial 5: %lu\n", factorial(5));
    return 0;
}
