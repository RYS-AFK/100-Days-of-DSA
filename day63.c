#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure for the adjacency list
struct AdjList {
    struct Node* head;
};

// Function to create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// DFS Recursive Function
void DFS(int vertex, struct AdjList* adj, bool* visited) {
    // Mark the current node as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);

    // Traverse all adjacent vertices
    struct Node* temp = adj[vertex].head;
    while (temp != NULL) {
        int connectedVertex = temp->dest;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, edges, s;
    
    // Input: Number of vertices and starting vertex
    if (scanf("%d", &n) != 1) return 0;
    
    struct AdjList* adj = (struct AdjList*)malloc(n * sizeof(struct AdjList));
    for (int i = 0; i < n; i++) {
        adj[i].head = NULL;
    }

    // Input: Adjacency List construction
    // (Assuming input format provides number of edges then pairs)
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u].head;
        adj[u].head = newNode;
        
        // If undirected, add edge v -> u
        newNode = createNode(u);
        newNode->next = adj[v].head;
        adj[v].head = newNode;
    }

    scanf("%d", &s); // Starting vertex

    bool* visited = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    printf("DFS traversal order: ");
    DFS(s, adj, visited);
    printf("\n");

    return 0;
}