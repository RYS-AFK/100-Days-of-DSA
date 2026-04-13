#include <stdio.h>
#include <string.h>

int main() {
    char s[100001]; // Assuming a maximum string length
    if (scanf("%s", s) != 1) return 0;

    // Array to track if a character (a-z) has been seen
    // 0 = not seen, 1 = seen
    int seen[26] = {0};
    int found = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index] == 1) {
            // This is the first time we've encountered a character 
            // that was already seen.
            printf("%c\n", s[i]);
            found = 1;
            break;
        }

        // Mark the character as seen
        seen[index] = 1;
    }

    if (!found) {
        printf("-1\n");
    }

    return 0;
}