#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a circular linked list
struct Node* createCircularList(int n) {
    if (n <= 0) return NULL;

    struct Node *head = NULL, *tail = NULL;
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->next = head; // Maintain the circle
            tail = newNode;
        }
    }
    return head;
}

// Function to traverse and print the circular linked list
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we wrap around to the head
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    struct Node* head = createCircularList(n);
    display(head);

    return 0;
}