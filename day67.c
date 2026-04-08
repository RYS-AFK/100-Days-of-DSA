#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack to store the topological sort
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

// Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

// Graph structure
struct Graph {
    struct Node* head[MAX];
};

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

void dfs(int v, int visited[], struct Graph* graph) {
    visited[v] = 1;

    struct Node* temp = graph->head[v];
    while (temp != NULL) {
        if (!visited[temp->dest]) {
            dfs(temp->dest, visited, graph);
        }
        temp = temp->next;
    }

    // Push to stack after all neighbors are visited
    push(v);
}

void topologicalSort(struct Graph* graph, int V) {
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph);
        }
    }

    // Print contents of stack
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int V, E;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    
    for (int i = 0; i < MAX; i++) graph->head[i] = NULL;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph, V);

    return 0;
}