#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j;

    printf("Enter a string: ");
    scanf("%s", s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            printf("NO");
            return 0;
        }
        i++;
        j--;
    }

    printf("YES");
    return 0;
}