#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find index of a value in inorder array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to build the tree
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    // Pick current node from postorder traversal using postIndex
    struct Node* node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) return node;

    // Find the index of this node in Inorder traversal
    int inIndex = findIndex(inorder, inStart, inEnd, node->data);

    // Build right subtree before left subtree for postorder logic
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Function to print preorder traversal
void printPreorder(struct Node* node, int* first) {
    if (node == NULL) return;
    
    if (!(*first)) printf(" ");
    printf("%d", node->data);
    *first = 0;
    
    printPreorder(node->left, first);
    printPreorder(node->right, first);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    int first = 1;
    printPreorder(root, &first);
    printf("\n");

    return 0;
}