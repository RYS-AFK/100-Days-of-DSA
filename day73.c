#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int freq[26] = {0};
    int n = strlen(s);

    // Step 1: Count frequency of each character
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find the first character with frequency 1
    for (int i = 0; i < n; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100001]; // Assuming max length based on typical competitive programming limits
    
    // Read input string
    if (scanf("%s", s) == 1) {
        char result = firstNonRepeating(s);
        printf("%c\n", result);
    }

    return 0;
}