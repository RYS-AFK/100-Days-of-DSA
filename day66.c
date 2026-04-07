#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int V, E;
bool visited[MAX];
bool recStack[MAX];

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all vertices adjacent to this vertex
        for (int i = 0; i < V; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    // Remove the vertex from recursion stack before returning
    recStack[v] = false;
    return false;
}

bool isCyclic() {
    // Initialize visited and recStack as false
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the utility function for all vertices to handle disconnected graphs
    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i))
            return true;
    }

    return false;
}

int main() {
    int u, v;
    
    // Input Number of Vertices and Edges
    if (scanf("%d %d", &V, &E) != 2) return 0;

    // Initialize Adjacency Matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Input Edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed Edge
    }

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}