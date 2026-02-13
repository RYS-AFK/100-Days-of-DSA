#include <stdio.h>

int main() {
    int m, n;
    
    // Read dimensions
    scanf("%d %d", &m, &n);
    
    // Declare matrices (max size based on typical constraints)
    int A[100][100], B[100][100], sum[100][100];
    
    // Read first matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    // Read second matrix  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // Compute sum: sum[i][j] = A[i][j] + B[i][j]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    
    // Print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", sum[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
