#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int info;
    struct node *next;
};

struct node* createList(struct node *start);
struct node* addAtEnd(struct node *start, int data);
void display(struct node *start);
bool isPalindrome(struct node *start);
struct node* reverseList(struct node *head);

int main() {
    struct node *start = NULL;

    start = createList(start);

    printf("\nList:\n");
    display(start);

    if(isPalindrome(start))
        printf("\nThe list is a palindrome.\n");
    else
        printf("\nThe list is NOT a palindrome.\n");

    return 0;
}

struct node* createList(struct node *start) {
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        start = addAtEnd(start, data);
    }
    return start;
}

struct node* addAtEnd(struct node *start, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = NULL;

    if(start == NULL)
        return newNode;

    struct node *temp = start;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;

    return start;
}

void display(struct node *start) {
    struct node *temp = start;
    if(temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct node *start) {
    if(start == NULL || start->next == NULL)
        return true;

    struct node *slow = start;
    struct node *fast = start;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *secondHalf = reverseList(slow->next);

    struct node *firstHalf = start;
    struct node *temp = secondHalf;
    bool isPalin = true;
    while(temp != NULL) {
        if(firstHalf->info != temp->info) {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    slow->next = reverseList(secondHalf);

    return isPalin;
}

output ->>

Enter number of nodes: 1
Enter data for node 1: 15

List:
15 -> NULL

The list is a palindrome.
