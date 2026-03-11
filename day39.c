#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- MinHeap Structure Definition ---
typedef struct {
    int *array;
    int size;
    int capacity;
} MinHeap;

// --- Initialization and Memory Management ---
MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

void freeHeap(MinHeap* heap) {
    free(heap->array);
    free(heap);
}

// --- Helper Methods ---
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return (2 * i) + 1; }
int rightChild(int i) { return (2 * i) + 2; }

// --- Internal Maintenance Methods ---
void heapifyUp(MinHeap* heap, int i) {
    // While not at root and parent is greater than the current node
    while (i != 0 && heap->array[parent(i)] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[parent(i)]);
        i = parent(i);
    }
}

void heapifyDown(MinHeap* heap, int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    // Check if left child is smaller than current smallest
    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }

    // Check if right child is smaller than current smallest
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }

    // If smallest is not the root of this subtree, swap and continue
    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

// --- Core Operations ---
void insert(MinHeap* heap, int x) {
    // If capacity is reached, double the array size (standard dynamic array logic)
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->array = (int*)realloc(heap->array, heap->capacity * sizeof(int));
    }
    
    // Insert new element at the end
    heap->array[heap->size] = x;
    heap->size++;
    
    // Restore heap property
    heapifyUp(heap, heap->size - 1);
}

int peek(MinHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    return heap->array[0];
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // Store the minimum value
    int root = heap->array[0];
    
    // Move the last element to the root
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    
    // Restore heap property
    heapifyDown(heap, 0);
    
    return root;
}

// --- Main execution ---
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    // Pre-allocate enough capacity for 'n' operations 
    // (since at most 'n' inserts can happen, size 'n' is perfectly safe)
    MinHeap* heap = createHeap(n > 0 ? n : 10);
    
    char operation[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(heap, val);
        } else if (strcmp(operation, "extractMin") == 0) {
            printf("%d\n", extractMin(heap));
        } else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek(heap));
        }
    }
    
    // Clean up memory
    freeHeap(heap);
    return 0;
}