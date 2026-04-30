#include <stdio.h>
#include <stdbool.h>

// Function to check if a distribution is possible with 'maxPages' limit
bool isPossible(int arr[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentPagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages, impossible
        if (arr[i] > maxPages) return false;

        if (currentPagesSum + arr[i] > maxPages) {
            studentsRequired++;
            currentPagesSum = arr[i]; // Assign this book to the next student
            if (studentsRequired > m) return false;
        } else {
            currentPagesSum += arr[i];
        }
    }
    return true;
}

int allocatePages(int arr[], int n, int m) {
    // If students are more than books, allocation is impossible 
    // per the "each student gets at least one book" rule
    if (m > n) return -1;

    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int low = maxVal; // Minimum possible answer
    int high = sum;   // Maximum possible answer
    int result = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;    // Try to find a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;   // Increase the limit
        }
    }
    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocatePages(arr, n, m));

    return 0;
}