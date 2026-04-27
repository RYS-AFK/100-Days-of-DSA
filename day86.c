#include <stdio.h>

int integerSquareRoot(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int left = 1, right = n;
    int ans = 0;

    while (left <= right) {
        // Use long long to prevent overflow during mid * mid
        long long mid = left + (right - left) / 2;

        if (mid * mid == n) {
            return mid;
        }

        if (mid * mid < n) {
            // mid is a potential answer, but look for a larger one
            ans = mid;
            left = mid + 1;
        } else {
            // mid * mid is too large
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", integerSquareRoot(n));
    }
    return 0;
}