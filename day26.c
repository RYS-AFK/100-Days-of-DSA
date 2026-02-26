#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n;
    struct Node *head = NULL, *tail = NULL;

    // Read number of nodes
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // Build the Doubly Linked List
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            // First node becomes both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Link the new node with the current tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; // Update tail to the new node
        }
    }

    // Forward Traversal
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");

    // Memory Cleanup
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}