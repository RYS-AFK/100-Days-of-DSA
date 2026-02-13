#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    
    int matrix[100][100];
    
    // Read matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Spiral traversal boundaries
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    
    while (top <= bottom && left <= right) {
        // Top row (left → right)
        for (int j = left; j <= right; j++) {
            printf("%d ", matrix[top][j]);
        }
        top++;
        
        // Right column (top → bottom)
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;
        
        // Bottom row (right → left), if valid
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%d ", matrix[bottom][j]);
            }
            bottom--;
        }
        
        // Left column (bottom → top), if valid
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    
    printf("\n");
    return 0;
}
