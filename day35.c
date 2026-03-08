#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the Queue structure to keep track of both ends
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Add an element to the rear
void enqueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to display the queue elements
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    
    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue();

    // Read n integers and enqueue them
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            enqueue(q, value);
        }
    }

    // Print the queue
    display(q);

    return 0;
}
