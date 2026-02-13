#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int matrix[100][100];
    
    // Read matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Check 1: Must be square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }
    
    // Check 2: matrix[i][j] == matrix[j][i] for all i,j
    int isSymmetric = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {  // Only check upper triangle
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }
    
    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }
    
    return 0;
}
