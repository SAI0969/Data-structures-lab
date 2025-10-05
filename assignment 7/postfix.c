#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

int evaluate(char *exp) {
    int i = 0;
    while (exp[i] != '\0') {
        char c = exp[i];

        if (isdigit(c)) {
            push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int val1 = pop();
            int val2 = pop();

            switch (c) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        } else {
            printf("Invalid character in expression: %c\n", c);
            exit(1);
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int res = evaluate(postfix);
    printf("Result is: %d\n", res);

    return 0;
}



Enter postfix expression: 23*54*+9-
Result is: 17
