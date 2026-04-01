#include <stdio.h>
#include <stdbool.h>

/**
 * Function to check if the given array satisfies the Min-Heap property.
 * @param arr The level-order traversal array
 * @param n Total number of elements
 * @return true if valid Min-Heap, false otherwise
 */
bool isMinHeap(int arr[], int n) {
    // We only need to check nodes that have at least one child
    // Last internal node is at index (n-2)/2
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Check left child
        if (arr[i] > arr[2 * i + 1]) {
            return false;
        }

        // Check right child (if it exists)
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    
    // Input number of elements
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Input level-order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Validate and print result
    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}