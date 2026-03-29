#include <stdio.h>
#include <stdlib.h>

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

// Function to mirror the tree by swapping children
void mirror(struct Node* node) {
    if (node == NULL) return;

    // Recurse for subtrees
    mirror(node->left);
    mirror(node->right);

    // Swap the pointers
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

// Function to print Inorder Traversal
void printInorder(struct Node* node, int* first) {
    if (node == NULL) return;

    printInorder(node->left, first);
    
    if (!(*first)) printf(" ");
    printf("%d", node->data);
    *first = 0;

    printInorder(node->right, first);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree using a queue (Level-order)
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];
        if (current == NULL) continue;

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

    // Transform to Mirror Image
    mirror(root);

    // Print Result
    int first = 1;
    printInorder(root, &first);
    printf("\n");

    return 0;
}