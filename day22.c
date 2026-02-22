#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int count_nodes(struct Node* head) {
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    
    return 0;
}