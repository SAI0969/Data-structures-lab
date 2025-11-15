#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void push(struct Node **top, int value);
int pop(struct Node **top);
void display(struct Node *top);
int isEmpty(struct Node *top);

int main() {
    struct Node *top = NULL; // stack is empty initially
    int choice, value;

    while (1) {
        printf("\n--- Stack using Linked List ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Check isEmpty\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&top, value);
            break;
        case 2:
            value = pop(&top);
            if (value != -1)
                printf("Popped element: %d\n", value);
            break;
        case 3:
            display(top);
            break;
        case 4:
            if (isEmpty(top))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Push operation
void push(struct Node **top, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", value);
}

// Pop operation
int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Underflow! Stack is empty\n");
        return -1;
    }
    struct Node *temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Display operation
void display(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Check if empty
int isEmpty(struct Node *top) {
    return top == NULL;
}
