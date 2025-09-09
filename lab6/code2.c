#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Function prototypes
void push(struct Stack *s, char ch);
char pop(struct Stack *s);
int isEmpty(struct Stack s);
int isFull(struct Stack s);
int isMatchingPair(char open, char close);
int isBalanced(char expr[]);

int main() {
    char expr[MAX];
    printf("Enter a mathematical expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Expression is Balanced\n");
    else
        printf("Expression is Not Balanced\n");

    return 0;
}

// Push operation
void push(struct Stack *s, char ch) {
    if (isFull(*s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = ch;
}

// Pop operation
char pop(struct Stack *s) {
    if (isEmpty(*s)) {
        return '\0'; // return null char if empty
    }
    return s->arr[s->top--];
}

// Check if empty
int isEmpty(struct Stack s) {
    return s.top == -1;
}

// Check if full
int isFull(struct Stack s) {
    return s.top == MAX - 1;
}

// Check if brackets match
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check balance
int isBalanced(char expr[]) {
    struct Stack s;
    s.top = -1;

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, ch)) {
                return 0; // mismatch found
            }
        }
    }
    return isEmpty(s); // balanced if stack empty
}


output :

Enter a mathematical expression: (a+b)*{c+[d-e]}
Expression is Balanced
