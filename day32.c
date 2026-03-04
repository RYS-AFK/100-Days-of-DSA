#include <stdio.h>

#define MAX 1000

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, value;

    // 1. Read number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // 2. Push n elements onto the stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (top < MAX - 1) {
            stack[++top] = value;
        }
    }

    // 3. Read number of elements to pop
    if (scanf("%d", &m) != 1) return 0;

    // 4. Perform m pops
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--; // We don't need to print the popped values here, just move the pointer
        }
    }

    // 5. Display remaining elements from top to bottom
    if (top == -1) {
        // Stack is empty
        return 0;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");

    return 0;
}