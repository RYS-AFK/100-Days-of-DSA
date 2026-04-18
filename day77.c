#include <stdio.h>
#include <stdbool.h>

int adj[1001][1001];
bool visited[1001];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        // If there is an edge and the neighbor hasn't been visited
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    // Read number of nodes (n) and edges (m)
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency matrix and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Since it's an undirected graph
    }

    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

    // Start DFS from the first node
    dfs(1);

    // Check if all nodes were reached
    bool connected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}