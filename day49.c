#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int val) {
    // 1. If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(val);
    }

    // 2. Otherwise, recur down the tree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    // 3. Return the unchanged node pointer
    return root;
}

// Helper function for In-order traversal to verify insertion
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("In-order Traversal of BST: ");
    inorder(root);
    printf("\n");

    return 0;
}