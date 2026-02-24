#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to delete the first occurrence of a key
struct Node* deleteKey(struct Node* head, int key) {
    // 1. Handle case where list is empty
    if (head == NULL) return NULL;

    // 2. Handle case where the head node itself holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // 3. Traverse to find the key while keeping track of the previous node
    struct Node* prev = head;
    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data == key) {
            // Found the key: bypass the current node
            prev->next = current->next;
            free(current);
            return head; // Exit after first occurrence is deleted
        }
        prev = current;
        current = current->next;
    }

    // Key not found
    return head;
}

// Function to print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n, key, val;
    struct Node *head = NULL, *tail = NULL;

    // Input size
    if (scanf("%d", &n) != 1) return 0;

    // Build the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Input the key to delete
    scanf("%d", &key);

    // Perform deletion
    head = deleteKey(head, key);

    // Output final list
    printList(head);

    return 0;
}