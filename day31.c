#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // Defining a maximum size for the array

int main() {
    int stack[MAX];
    int top = -1; // Represents an empty stack
    int n, choice, value;

    // Read the number of operations
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &choice);

        if (choice == 1) { // Push
            scanf("%d", &value);
            if (top >= MAX - 1) {
                // Technically Stack Overflow, though not requested in output
            } else {
                stack[++top] = value;
            }
        } 
        else if (choice == 2) { // Pop
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top--]);
            }
        } 
        else if (choice == 3) { // Display
            if (top == -1) {
                // Optional: handle empty display if needed
                printf("\n"); 
            } else {
                for (int j = top; j >= 0; j--) {
                    printf("%d%s", stack[j], (j == 0 ? "" : " "));
                }
                printf("\n");
            }
        }
    }

    return 0;
}