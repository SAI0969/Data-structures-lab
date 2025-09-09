#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return (op == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol;
    push('(');
    strcat(infix, ")");  // append closing bracket at the end

    while (infix[i] != '\0') {
        symbol = infix[i];

        // Ignore spaces
        if (symbol == ' ') {
            i++;
            continue;
        }

        if (symbol == '(') {
            push(symbol);
        }
        else if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();  // remove '('
        }
        else {  // operator case
            while (top != -1 && stack[top] != '(' &&
                   ((precedence(stack[top]) > precedence(symbol)) ||
                    (precedence(stack[top]) == precedence(symbol) && !isRightAssociative(symbol)))) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        i++;
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%[^\n]", infix);  // read input including spaces until newline

    printf("Infix Expression: %s\n", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

output :
Infix Expression: (A + B) * C - D ^ E ^ F
Postfix Expression: AB+C*DEF^^-


o
