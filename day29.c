#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || n <= 1) return head;

    // Adjust k in case k >= n
    k = k % n;
    if (k == 0) return head;

    // Step 1: Find the current tail
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Step 2: Connect tail to head to make it circular
    tail->next = head;

    // Step 3: Find the new tail at (n - k) position
    struct Node* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {
        newTail = newTail->next;
    }

    // Step 4: The node after newTail is the new head
    head = newTail->next;
    newTail->next = NULL;

    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d%s", head->data, head->next ? " " : "");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL, *temp = NULL;

    // Build the list from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    // Rotate and print
    head = rotateRight(head, k, n);
    printList(head);

    // Free memory (good practice)
    while (head) {
        struct Node* toDelete = head;
        head = head->next;
        free(toDelete);
    }

    return 0;
}