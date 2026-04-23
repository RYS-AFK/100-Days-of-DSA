#include <stdio.h>

// Lower Bound: First element >= x
int findLowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Default if no element is >= x
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Upper Bound: First element > x
int findUpperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Default if no element is > x
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    
    // Input size of array
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    // Input sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input target value
    scanf("%d", &x);
    
    printf("%d %d\n", findLowerBound(arr, n, x), findUpperBound(arr, n, x));
    
    return 0;
}