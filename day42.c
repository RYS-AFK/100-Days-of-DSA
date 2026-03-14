#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for Queue
struct Queue {
    int items[MAX];
    int front, rear;
};

// Structure for Stack
struct Stack {
    int items[MAX];
    int top;
};

// Queue Functions
void enqueue(struct Queue* q, int value) {
    q->items[++(q->rear)] = value;
}

int dequeue(struct Queue* q) {
    return q->items[(q->front)++];
}

// Stack Functions
void push(struct Stack* s, int value) {
    s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {
    return s->items[(s->top)--];
}

int main() {
    struct Queue q;
    struct Stack s;
    q.front = 0; q.rear = -1;
    s.top = -1;

    int n, val;
    
    // Input N
    if (scanf("%d", &n) != 1) return 0;

    // Step 1: Fill the queue and move to stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // Move from Queue to Stack
    for (int i = 0; i < n; i++) {
        push(&s, dequeue(&q));
    }

    // Step 2: Move from Stack back to Queue (reverses order)
    q.front = 0; q.rear = -1; // Reset queue pointers
    for (int i = 0; i < n; i++) {
        enqueue(&q, pop(&s));
    }

    // Output the reversed queue
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d%s", q.items[i], i == q.rear ? "" : " ");
    }

    return 0;
}