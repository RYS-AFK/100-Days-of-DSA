#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int matrix[100][100];  // Fixed size assuming m,n <= 100 [memory:1]
    
    // Read matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    // Sum primary diagonal: matrix[i][i] for valid i
    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];  // 1+5+9=15 for example [memory:1]
    }
    
    printf("%d\n", sum);
    return 0;
}
