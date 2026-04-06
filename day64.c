#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Queue implementation for BFS
int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_NODES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

// Graph structure using Adjacency Matrix for simplicity
// (Can be swapped for Adjacency List for O(V+E) efficiency)
int adj[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

void bfs(int n, int startNode) {
    for (int i = 0; i < n; i++) visited[i] = false;

    visited[startNode] = true;
    enqueue(startNode);

    printf("BFS traversal order: ");

    while (!isQueueEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, source;

    // Input number of nodes and edges
    if (scanf("%d %d", &n, &edges) != 2) return 0;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Input edges
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Assuming directed graph
        adj[v][u] = 1; // Uncomment for undirected graph
    }

    // Input source node
    scanf("%d", &source);

    bfs(n, source);

    return 0;
}