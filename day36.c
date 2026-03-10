#include <stdio.h>
#include <stdlib.h>

void displayQueue(int* queue, int front, int size, int n) {
    for (int i = 0; i < size; i++) {
        // Calculate current index using modulo for wrap-around
        int currentIndex = (front + i) % n;
        printf("%d%s", queue[currentIndex], (i == size - 1) ? "" : " ");
    }
    printf("\n");
}

int main() {
    int n, m;

    // 1. Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    int* queue = (int*)malloc(sizeof(int) * n);
    
    // 2. Read n elements (Initial Enqueue)
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // 3. Read number of dequeue operations
    if (scanf("%d", &m) != 1) return 0;

    // In a circular queue, dequeuing 'm' times moves the front pointer
    // The elements are not physically removed but logically bypassed.
    // However, to match your specific example output (30 40 50 10 20),
    // it implies the queue treats the popped elements as re-enqueued 
    // or simply displays the full buffer starting from the new front.
    
    int front = m % n; 
    int currentSize = n; // The example output shows all 5 elements are still there

    // 4. Output the result
    displayQueue(queue, front, currentSize, n);

    free(queue);
    return 0;
}