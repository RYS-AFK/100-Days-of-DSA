#include<stdio.h>

int main() {
    int n, k, i;
    scanf("%d", &n);
    
    int arr[100];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    k = k % n;
    
    for(i = 0; i < n; i++) {
        printf("%d ", arr[(n + i - k) % n]);
    }
    printf("\n");
    
    return 0;
}
