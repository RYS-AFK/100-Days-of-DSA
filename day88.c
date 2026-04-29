#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if k cows can be placed with at least 'dist' distance
int isPossible(int stalls[], int n, int k, int dist) {
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPosition >= dist) {
            cowsPlaced++;
            lastPosition = stalls[i];
        }
        if (cowsPlaced >= k) return 1;
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary Search on the distance
    int low = 1, high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(stalls, n, k, mid)) {
            result = mid;   // Save possible answer
            low = mid + 1;  // Try for a larger distance
        } else {
            high = mid - 1; // Try for a smaller distance
        }
    }

    printf("%d\n", result);

    return 0;
}