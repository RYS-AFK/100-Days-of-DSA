#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int main() {
    int n, m;
    int graph[MAX][MAX];

    // Initialize graph with Infinity
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    // Read nodes and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Adjusting for 1-based indexing from sample input
        if (w < graph[u-1][v-1]) {
            graph[u-1][v-1] = w;
            graph[v-1][u-1] = w;
        }
    }

    int key[MAX];
    bool visited[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    // Starting Prim's from the first node
    key[0] = 0;
    int mst_weight = 0;

    for (int count = 0; count < n; count++) {
        int min = INF, u = -1;

        // Pick the minimum key vertex from the set of non-visited vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) break; // Graph is disconnected

        visited[u] = true;
        mst_weight += key[u];

        // Update key values of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", mst_weight);

    return 0;
}