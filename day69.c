#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

// Structure to represent a neighbor in the adjacency list
struct Node {
    int target, weight;
    struct Node* next;
};

// Structure for the Min-Heap
struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    struct HeapNode* array;
};

// Function to create a new adjacency list node
struct Node* createNode(int target, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->target = target;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Dijkstra's Algorithm
void dijkstra(struct Node* adj[], int V, int src) {
    int dist[MAX_NODES];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // In a production C environment, you'd implement a Min-Heap here.
    // For simplicity in competitive programming, a basic search or 
    // standard heap structure is used to find the minimum distance.
    int visited[MAX_NODES] = {0};

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        
        // Pick the minimum distance vertex from the set of non-visited vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (dist[u] == INT_MAX) break;
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    // Print the calculated shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V, E, src;
    struct Node* adj[MAX_NODES] = {NULL};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(adj, V, src);

    return 0;
}