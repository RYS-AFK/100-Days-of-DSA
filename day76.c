#include <stdio.h>
#include <stdbool.h>

#define MAX 1001

int adj[MAX][MAX];
bool visited[MAX];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        // If there is an edge and v is not visited
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    // Input n (nodes) and m (edges)
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        for (int j = 0; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Because it's an undirected graph
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++; // Found a new component
            dfs(i);       // Mark all nodes in this component
        }
    }

    printf("%d\n", components);

    return 0;
}