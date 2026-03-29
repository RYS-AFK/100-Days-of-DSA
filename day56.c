#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to check if two subtrees are mirrors
bool isMirror(struct Node* root1, struct Node* root2) {
    // If both are NULL, they are mirrors
    if (root1 == NULL && root2 == NULL)
        return true;

    // If only one is NULL, or values differ, they aren't mirrors
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left);

    return false;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0 || arr[0] == -1) {
        printf("YES\n");
        return 0;
    }

    // Build the tree from level-order array
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];

        // Assign Left Child
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }

        // Assign Right Child
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }

    if (isMirror(root, root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}