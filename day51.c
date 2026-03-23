#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Standard BST Insertion
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

// Function to find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        // If both n1 and n2 are smaller than root, LCA is in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
        // If both n1 and n2 are greater than root, LCA is in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        else
            break;
    }
    return root;
}

int main() {
    int n, val, n1, n2;
    struct Node* root = NULL;

    // Input Number of nodes
    if (scanf("%d", &n) != 1) return 0;

    // Input array elements to build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input the two nodes to find LCA for
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);
    
    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}