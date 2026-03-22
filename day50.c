#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search a given key in BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's data
    if (root->data < key)
        return search(root->right, key);
 
    // Key is smaller than root's data
    return search(root->left, key);
}

int main() {
    // Creating a simple BST
    //        50
    //       /  \
    //      30   70
    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);

    int key = 30;
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element %d found in BST.\n", key);
    else
        printf("Element %d not found.\n", key);

    return 0;
}