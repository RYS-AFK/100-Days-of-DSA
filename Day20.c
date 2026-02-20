#include <stdio.h>
#include <stdlib.h>

long long countZeroSumSubarrays(int n, int arr[]) {
    long long count = 0;
    long long current_sum = 0;
    
    // Using a simple hash-like structure to store frequency of prefix sums.
    // In a real competitive programming scenario, you'd use a Hash Table.
    // For simplicity, let's assume we use a Map or a large frequency array.
    
    // To handle the logic: 
    // We need to store how many times each prefix sum has appeared.
    // Using a hash map (Pseudo-code logic):
    // map[0] = 1; // Base case: a sum of 0 has been seen once
    
    // Because C doesn't have a native Map, here is the algorithmic flow:
    // 1. Calculate prefix sums: [1, 0, 2, 0, 3, 0] for input [1, -1, 2, -2, 3, -3]
    // 2. Count occurrences of each sum.
    // 3. If a sum 'S' appears 'k' times, it contributes k*(k-1)/2 to the count.
    
    // Let's implement the counting logic:
    long long *prefix_sums = (long long *)malloc((n + 1) * sizeof(long long));
    prefix_sums[0] = 0;
    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        prefix_sums[i + 1] = current_sum;
    }

    // Sort prefix sums to group identical values together (O(n log n))
    // This mimics a Hash Map's frequency counting in standard C.
    qsort(prefix_sums, n + 1, sizeof(long long), [](const void* a, const void* b) {
        long long arg1 = *(const long long*)a;
        long long arg2 = *(const long long*)b;
        return (arg1 > arg2) - (arg1 < arg2);
    });

    long long freq = 1;
    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            freq++;
        } else {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }
    count += (freq * (freq - 1)) / 2; // Add last group

    free(prefix_sums);
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", countZeroSumSubarrays(n, arr));

    free(arr);
    return 0;
}