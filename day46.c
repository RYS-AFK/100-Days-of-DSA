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

// Function to perform Level Order Traversal
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    // Create a simple queue for nodes
    struct Node* queue[1000];
    int front = 0, rear = 0;

    // Enqueue root
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue node
        struct Node* tempNode = queue[front++];

        printf("%d ", tempNode->data);

        // Enqueue left child
        if (tempNode->left != NULL) {
            queue[rear++] = tempNode->left;
        }

        // Enqueue right child
        if (tempNode->right != NULL) {
            queue[rear++] = tempNode->right;
        }
    }
}

// Helper function to build the tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* curr = queue[front++];
        
        // Left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
        }
        
        // Right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    return root;
}

int main() {
    int n;
    // Input number of elements (including -1 for NULL)
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}