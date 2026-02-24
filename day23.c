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

// Function to merge two sorted lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    // 1. Create a dummy node to act as the starting point
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // 2. Compare nodes and link the smaller one
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // 3. Attach the remaining nodes of whichever list is not empty
    if (l1 != NULL) tail->next = l1;
    else if (l2 != NULL) tail->next = l2;

    return dummy.next;
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
    int n, m, val;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL;

    // Input for first list
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (head1 == NULL) {
            head1 = newNode(val);
            temp = head1;
        } else {
            temp->next = newNode(val);
            temp = temp->next;
        }
    }

    // Input for second list
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        if (head2 == NULL) {
            head2 = newNode(val);
            temp = head2;
        } else {
            temp->next = newNode(val);
            temp = temp->next;
        }
    }

    // Merge and output
    struct Node* mergedHead = mergeSortedLists(head1, head2);
    printList(mergedHead);

    return 0;
}