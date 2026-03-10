#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int count;
} Deque;

// Initialization
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->head = dq->tail = NULL;
    dq->count = 0;
    return dq;
}

// O(1) Operations
void push_front(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = dq->head;
    newNode->prev = NULL;
    if (dq->head) dq->head->prev = newNode;
    dq->head = newNode;
    if (!dq->tail) dq->tail = newNode;
    dq->count++;
}

void push_back(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = dq->tail;
    newNode->next = NULL;
    if (dq->tail) dq->tail->next = newNode;
    dq->tail = newNode;
    if (!dq->head) dq->head = newNode;
    dq->count++;
}

void pop_front(Deque* dq) {
    if (!dq->head) return;
    Node* temp = dq->head;
    dq->head = dq->head->next;
    if (dq->head) dq->head->prev = NULL;
    else dq->tail = NULL;
    free(temp);
    dq->count--;
}

void pop_back(Deque* dq) {
    if (!dq->tail) return;
    Node* temp = dq->tail;
    dq->tail = dq->tail->prev;
    if (dq->tail) dq->tail->next = NULL;
    else dq->head = NULL;
    free(temp);
    dq->count--;
}

// O(n) Operations
void reverse(Deque* dq) {
    if (!dq->head) return;
    Node *curr = dq->head;
    Node *temp = NULL;
    dq->tail = dq->head; // New tail is the old head
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        dq->head = curr; // Keep updating head to the last non-null node
        curr = curr->prev; // Move to next node (which is now in the 'prev' slot)
    }
}

void clear(Deque* dq) {
    while (dq->count > 0) {
        pop_front(dq);
    }
}

void printDeque(Deque* dq) {
    Node* curr = dq->head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}