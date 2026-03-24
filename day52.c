#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If current node is either n1 or n2, it's a potential LCA
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);

    // If both return non-NULL, current node is the LCA
    if (left_lca && right_lca) return root;

    // Otherwise return the non-NULL child
    return (left_lca != NULL) ? left_lca : right_lca;
}

// Helper function to build tree from level-order array (standard for these challenges)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    struct Node* root = newNode(arr[0]);
    struct Node* queue[100]; // Simple queue for level-order insertion
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
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
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, n1, n2);

    if (lca) printf("%d\n", lca->data);
    
    return 0;
}