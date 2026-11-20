#include <stdio.h>

int main(void) {
    int a[] = {64, 25, 12, 22, 11};
    size_t n = sizeof a / sizeof a[0];

    for (size_t i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

    printf("Sorted: ");
    for (size_t i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
