#include <stdio.h>
#define MAX 100  // maximum stack size

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function prototypes
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int isEmpty(struct Stack s);
int isFull(struct Stack s);

int main() {
    struct Stack s;
    s.top = -1;

    int n;
    printf("Enter number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        push(&s, arr[i]); // push elements into stack
    }

    // Pop from stack and put back into array (reverses order)
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }

    printf("Reversed list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Push operation
void push(struct Stack *s, int value) {
    if (isFull(*s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

// Pop operation
int pop(struct Stack *s) {
    if (isEmpty(*s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

// Check if empty
int isEmpty(struct Stack s) {
    return s.top == -1;
}

// Check if full
int isFull(struct Stack s) {
    return s.top == MAX - 1;
}


output :


Enter number of elements in the list: 5
Enter 5 integers:
10 20 30 40 50
Reversed list:
50 40 30 20 10
