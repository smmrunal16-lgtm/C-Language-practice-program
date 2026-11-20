/*
 * 07_algorithms.c
 * Binary search, merge sort, quick sort and graph BFS.
 * Build: gcc -std=c11 -Wall -Wextra -Wpedantic 07_algorithms.c -o algorithms
 */
#include <stdio.h>
#include <stdlib.h>

static int binary_search(const int a[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) low = mid + 1; else high = mid - 1;
    }
    return -1;
}
static void merge(int a[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; ++i) a[i] = temp[i];
}
static void merge_sort_range(int a[], int temp[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort_range(a, temp, left, mid);
    merge_sort_range(a, temp, mid + 1, right);
    merge(a, temp, left, mid, right);
}
static int merge_sort(int a[], int n) {
    int *temp = malloc((size_t)n * sizeof *temp);
    if (!temp) return 0;
    if (n > 0) merge_sort_range(a, temp, 0, n - 1);
    free(temp); return 1;
}
static void quick_sort(int a[], int low, int high) {
    if (low >= high) return;
    int pivot = a[low + (high - low) / 2], i = low, j = high;
    while (i <= j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;
        if (i <= j) {
            int t = a[i]; a[i] = a[j]; a[j] = t;
            ++i; --j;
        }
    }
    if (low < j) quick_sort(a, low, j);
    if (i < high) quick_sort(a, i, high);
}
#define V 5
static void bfs(const int graph[V][V], int start) {
    int visited[V] = {0}, queue[V], front = 0, rear = 0;
    visited[start] = 1; queue[rear++] = start;
    printf("BFS: ");
    while (front < rear) {
        int u = queue[front++]; printf("%d ", u);
        for (int v = 0; v < V; ++v)
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1; queue[rear++] = v;
            }
    }
    putchar('\n');
}
static void print_array(const int a[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    putchar('\n');
}
int main(void) {
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = (int)(sizeof a / sizeof a[0]);
    if (!merge_sort(a, n)) { fputs("Memory allocation failed\n", stderr); return 1; }
    printf("Merge sort: "); print_array(a, n);
    printf("Index of 43: %d\n", binary_search(a, n, 43));
    int b[] = {9, 4, 7, 3, 10, 5};
    int m = (int)(sizeof b / sizeof b[0]);
    quick_sort(b, 0, m - 1);
    printf("Quick sort: "); print_array(b, m);
    const int graph[V][V] = {
        {0,1,1,0,0}, {1,0,0,1,0}, {1,0,0,1,1},
        {0,1,1,0,1}, {0,0,1,1,0}
    };
    bfs(graph, 0);
    return 0;
}
