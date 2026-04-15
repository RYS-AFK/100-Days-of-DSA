#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Comparator function for qsort to sort strings alphabetically
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for n strings
    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        votes[i] = (char *)malloc(100 * sizeof(char)); // Assuming max name length is 100
        scanf("%s", votes[i]);
    }

    // Step 1: Sort the votes alphabetically
    qsort(votes, n, sizeof(char *), compareStrings);

    char *winner = votes[0];
    int maxVotes = 0;
    
    int currentCount = 0;
    char *currentCandidate = votes[0];

    // Step 2: Traverse the sorted array and count frequencies
    for (int i = 0; i < n; i++) {
        if (strcmp(votes[i], currentCandidate) == 0) {
            currentCount++;
        } else {
            // Check if previous candidate had more votes
            if (currentCount > maxVotes) {
                maxVotes = currentCount;
                winner = currentCandidate;
            }
            // Reset for the new candidate
            currentCandidate = votes[i];
            currentCount = 1;
        }
    }

    // Final check for the last candidate in the loop
    if (currentCount > maxVotes) {
        maxVotes = currentCount;
        winner = currentCandidate;
    }

    // Step 3: Output result
    printf("%s %d\n", winner, maxVotes);

    // Free allocated memory
    for (int i = 0; i < n; i++) free(votes[i]);
    free(votes);

    return 0;
}