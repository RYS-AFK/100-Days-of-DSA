#include <stdio.h>

int main() {
    int n, m;
    // Using a fixed size or dynamic allocation based on constraints
    // For n up to 100 as per common practice in this challenge
    int adj[101][101] = {0};

    // Input number of vertices (n) and edges (m)
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Input m pairs of edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Assuming 0-based indexing for vertices
        // For an undirected graph:
        adj[u][v] = 1;
        adj[v][u] = 1; 
        
        // Note: For a directed graph, remove 'adj[v][u] = 1'
    }

    // Output the n x n adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", adj[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}