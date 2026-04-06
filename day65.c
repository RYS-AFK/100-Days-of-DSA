#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n;

// DFS function to detect cycle
bool isCyclicUtil(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        // If there is an edge between v and i
        if (adj[v][i]) {
            // If adjacent node is not visited, recurse
            if (!visited[i]) {
                if (isCyclicUtil(i, v))
                    return true;
            }
            // If adjacent node is visited and not the parent, cycle found
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic() {
    for (int i = 0; i < n; i++) visited[i] = false;

    // Check for cycle in different connected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;

    // Input number of nodes and edges
    if (scanf("%d %d", &n, &edges) != 2) return 0;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Input edges for undirected graph
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (isCyclic()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}