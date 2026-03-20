#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // If tree is empty
    if (root == NULL) {
        return 0;
    }
    
    // If node is a leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // Recursive call for left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Example Tree Construction:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Total Leaf Nodes: %d\n", countLeafNodes(root));

    return 0;
}