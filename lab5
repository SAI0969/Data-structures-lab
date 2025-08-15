#include <stdio.h>
#define MAX 5 // maximum size of stack

// Structure to hold stack data
struct Stack {
    int arr[MAX];
    int top;
};

// Function prototypes
void push(struct Stack *s, int value);
int pop(struct Stack *s);
void display(struct Stack s);
int isEmpty(struct Stack s);
int isFull(struct Stack s);

int main() {
    struct Stack s;
    s.top = -1; // stack is empty initially
    int choice, value;

    while (1) {
        printf("\n--- Stack using Array ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Check isEmpty\n5. Check isFull\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;
        case 2:
            value = pop(&s);
            if (value != -1)
                printf("Popped element: %d\n", value);
            break;
        case 3:
            display(s);
            break;
        case 4:
            if (isEmpty(s))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
        case 5:
            if (isFull(s))
                printf("Stack is full\n");
            else
                printf("Stack is not full\n");
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Push operation
void push(struct Stack *s, int value) {
    if (isFull(*s)) {
        printf("Overflow! Cannot push %d\n", value);
        return;
    }
    s->top++;
    s->arr[s->top] = value;
    printf("%d pushed to stack\n", value);
}

// Pop operation
int pop(struct Stack *s) {
    if (isEmpty(*s)) {
        printf("Underflow! Stack is empty\n");
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

// Display operation
void display(struct Stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s.top; i >= 0; i--)
        printf("%d ", s.arr[i]);
    printf("\n");
}

// Check if empty
int isEmpty(struct Stack s) {
    return s.top == -1;
}

// Check if full
int isFull(struct Stack s) {
    return s.top == MAX - 1;
}