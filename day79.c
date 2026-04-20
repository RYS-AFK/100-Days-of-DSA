#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent an adjacency list node
struct Node {
    int target, weight;
    struct Node* next;
};

// Structure to represent a Min-Heap node
struct HeapNode {
    int v, dist;
};

// Structure for the Min-Heap
struct MinHeap {
    int size, capacity;
    int* pos; 
    struct HeapNode** array;
};

struct Node* createNode(int target, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->target = target;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct HeapNode* createHeapNode(int v, int dist) {
    struct HeapNode* newNode = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    newNode->v = v;
    newNode->dist = dist;
    return newNode;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return minHeap;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = minHeap->array[smallest];
        struct HeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;

    struct HeapNode* root = minHeap->array[0];
    struct HeapNode* lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(int n, struct Node** adj, int src) {
    int dist[n + 1];
    struct MinHeap* minHeap = createMinHeap(n + 1);

    for (int v = 1; v <= n; ++v) {
        dist[v] = INF;
        minHeap->array[v - 1] = createHeapNode(v, dist[v]);
        minHeap->pos[v] = v - 1;
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = n;

    while (minHeap->size != 0) {
        struct HeapNode* heapNode = extractMin(minHeap);
        int u = heapNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            if (minHeap->pos[v] < minHeap->size && dist[u] != INF && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, u, v, w, src;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    scanf("%d", &src);
    dijkstra(n, adj, src);

    return 0;
}