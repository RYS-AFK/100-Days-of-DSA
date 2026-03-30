#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
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

// Function to find the index of a value in inorder array
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to construct the tree
struct Node* buildTree(int in[], int pre[], int inStrt, int inEnd, int* preIdx) {
    if (inStrt > inEnd) return NULL;

    // Pick current node from Preorder traversal using preIdx and increment preIdx
    struct Node* tNode = newNode(pre[(*preIdx)++]);

    // If this node has no children then return
    if (inStrt == inEnd) return tNode;

    // Else find the index of this node in Inorder traversal
    int inIdx = search(in, inStrt, inEnd, tNode->data);

    // Using index in Inorder traversal, construct left and right subtrees
    tNode->left = buildTree(in, pre, inStrt, inIdx - 1, preIdx);
    tNode->right = buildTree(in, pre, inIdx + 1, inEnd, preIdx);

    return tNode;
}

// Function to print postorder traversal
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int preIdx = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIdx);

    printPostorder(root);
    printf("\n");

    return 0;
}