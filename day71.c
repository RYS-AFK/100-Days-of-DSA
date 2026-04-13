#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EMPTY -1

int main() {
    int m, n;
    // Read table size (m) and number of operations (n)
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int hash_table[m];
    for (int i = 0; i < m; i++) {
        hash_table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "INSERT") == 0) {
            scanf("%d", &key);
            int h_k = key % m;
            for (int j = 0; j < m; j++) {
                int pos = (h_k + j * j) % m;
                if (hash_table[pos] == EMPTY) {
                    hash_table[pos] = key;
                    break;
                }
            }
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            scanf("%d", &key);
            int h_k = key % m;
            int found = 0;
            for (int j = 0; j < m; j++) {
                int pos = (h_k + j * j) % m;
                if (hash_table[pos] == key) {
                    found = 1;
                    break;
                } else if (hash_table[pos] == EMPTY) {
                    // Optimization: if we hit an empty slot, key isn't there
                    break;
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}