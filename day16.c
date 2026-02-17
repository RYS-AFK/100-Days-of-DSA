#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];  // Assuming n <= 100
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Count frequencies of distinct elements
    int i = 0;
    while(i < n) {
        int elem = arr[i];
        int count = 0;
        while(i < n && arr[i] == elem) {
            count++;
            i++;
        }
        printf("%d:%d", elem, count);
        if(i < n) printf(" ");
    }
    printf("\n");
    return 0;
}
