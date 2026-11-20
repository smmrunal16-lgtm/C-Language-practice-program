#include <stdio.h>

int main(void) {
    /* Binary search requires the array to be sorted. */
    int a[] = {3, 8, 12, 17, 23, 31, 45};
    int target = 23;
    int low = 0, high = (int)(sizeof a / sizeof a[0]) - 1;
    int found = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) { found = mid; break; }
        if (a[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (found >= 0) printf("%d found at index %d.\\n", target, found);
    else printf("%d not found.\\n", target);
    return 0;
}
