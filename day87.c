#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort to ensure the array is sorted
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Iterative Binary Search Function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow
        
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Target not found
}

int main() {
    int n, target;
    
    // Input: Size of array
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    
    // Input: Array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Binary Search requires a sorted array
    qsort(arr, n, sizeof(int), compare);
    
    // Output: Print sorted array as per example requirement
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    /* Note: If the problem specifically asks to search for a value 
    after sorting, you would call binarySearch(arr, n, target) here.
    */

    return 0;
}