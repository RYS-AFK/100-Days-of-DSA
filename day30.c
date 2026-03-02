#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new term node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to display the polynomial in standard form
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    int first = 1; // Flag to handle the first term's formatting

    while (temp != NULL) {
        // Skip terms with coefficient 0 unless it's the only term (handled by input usually)
        if (temp->coeff == 0) {
            temp = temp->next;
            continue;
        }

        // Print " + " between terms, but not before the first term
        if (!first) {
            printf(" + ");
        }

        // Print Coefficient and Variable logic
        if (temp->exp == 0) {
            // Constant term
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            // Linear term (x^1 is just x)
            printf("%dx", temp->coeff);
        } else {
            // Higher degree terms
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        first = 0;
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, c, e;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        struct Node* newNode = createNode(c, e);

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    displayPolynomial(head);

    // Memory Cleanup
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}