/*
 * 10_graph_algorithms.c
 * Dijkstra shortest paths, Floyd-Warshall all-pairs paths, topological sort.
 * Graphs use adjacency matrices; 0 means no edge in the first two examples.
 * Build: gcc -std=c11 -Wall -Wextra -Wpedantic 10_graph_algorithms.c -o graph_algorithms
 */
#include <stdio.h>
#include <limits.h>

#define N 5
#define INF (INT_MAX / 4)

static void dijkstra(const int graph[N][N], int source) {
    int dist[N], used[N] = {0};
    for (int i = 0; i < N; ++i) dist[i] = INF;
    dist[source] = 0;
    for (int count = 0; count < N; ++count) {
        int u = -1;
        for (int i = 0; i < N; ++i)
            if (!used[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (u == -1 || dist[u] == INF) break;
        used[u] = 1;
        for (int v = 0; v < N; ++v)
            if (graph[u][v] > 0 && !used[v] &&
                dist[u] <= INF - graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Dijkstra distances from %d:\n", source);
    for (int i = 0; i < N; ++i)
        if (dist[i] == INF) printf("%d: unreachable\n", i);
        else printf("%d: %d\n", i, dist[i]);
}
static void floyd_warshall(int dist[N][N]) {
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] <= INF - dist[k][j] &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
#define DAG_N 6
static int topological_sort(const int graph[DAG_N][DAG_N], int output[DAG_N]) {
    int indegree[DAG_N] = {0}, queue[DAG_N], front = 0, rear = 0, count = 0;
    for (int u = 0; u < DAG_N; ++u)
        for (int v = 0; v < DAG_N; ++v)
            if (graph[u][v]) ++indegree[v];
    for (int i = 0; i < DAG_N; ++i)
        if (indegree[i] == 0) queue[rear++] = i;
    while (front < rear) {
        int u = queue[front++];
        output[count++] = u;
        for (int v = 0; v < DAG_N; ++v)
            if (graph[u][v] && --indegree[v] == 0) queue[rear++] = v;
    }
    return count; /* less than DAG_N means a directed cycle exists */
}
int main(void) {
    const int weighted[N][N] = {
        {0, 10, 0, 5, 0}, {0, 0, 1, 2, 0}, {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2}, {7, 0, 6, 0, 0}
    };
    dijkstra(weighted, 0);

    int all[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            all[i][j] = i == j ? 0 : (weighted[i][j] ? weighted[i][j] : INF);
    floyd_warshall(all);
    printf("\nFloyd-Warshall distance 0 -> 4: %d\n", all[0][4]);

    const int dag[DAG_N][DAG_N] = {
        {0,1,1,0,0,0}, {0,0,0,1,0,0}, {0,0,0,1,1,0},
        {0,0,0,0,0,1}, {0,0,0,0,0,1}, {0,0,0,0,0,0}
    };
    int order[DAG_N], count = topological_sort(dag, order);
    printf("Topological order: ");
    if (count != DAG_N) puts("cycle detected");
    else {
        for (int i = 0; i < count; ++i) printf("%d ", order[i]);
        putchar('\n');
    }
    return 0;
}
