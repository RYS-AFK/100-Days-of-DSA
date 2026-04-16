#include <stdio.h>

int main() {
    int n;
    // Reading the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_len = 0;

    // Nested loops to check all possible subarrays
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];

            // If sum of subarray arr[i...j] is 0, update max_len
            if (current_sum == 0) {
                int length = j - i + 1;
                if (length > max_len) {
                    max_len = length;
                }
            }
        }
    }

    // Output the result
    printf("%d\n", max_len);

    return 0;
}