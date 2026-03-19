#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
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

// Function to find the height of the tree
int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        // Compute the height of each subtree
        int lHeight = getHeight(node->left);
        int rHeight = getHeight(node->right);

        // Use the larger one
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

int main() {
    /* Constructed binary tree is
            1
          /   \
         2     3
        / \
       4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the tree is: %d\n", getHeight(root));

    return 0;
}