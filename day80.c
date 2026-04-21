#include <stdio.h>

#define INF 1000000 // Defining a large value for infinity

void floydWarshall(int n, int graph[100][100]) {
    int dist[100][100];
    int i, j, k;

    // Initialize the distance matrix with the input graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == -1 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = graph[i][j];
        }
    }

    // Triple nested loop to update distances through intermediate vertex k
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j, update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the resulting shortest distance matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1");
            else
                printf("%d", dist[i][j]);
            
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    int graph[100][100];

    // Read number of vertices
    if (scanf("%d", &n) != 1) return 0;

    // Read adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(n, graph);

    return 0;
}