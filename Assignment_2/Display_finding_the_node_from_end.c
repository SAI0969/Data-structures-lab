#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node* createList(struct node *start);
struct node* addAtEnd(struct node *start, int data);
void display(struct node *start);
struct node* reverse(struct node* start);
void findNthFromEnd(struct node *start, int n);

int main() {
    struct node *start = NULL;
    int n;

    start = createList(start);

    printf("\nOriginal List:\n");
    display(start);

    start = reverse(start);

    printf("\nReversed List:\n");
    display(start);

    printf("\nEnter n to find nth node from end: ");
    scanf("%d", &n);
    findNthFromEnd(start, n);

    return 0;
}

struct node* createList(struct node *start) {
    int n, data, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
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

struct node* reverse(struct node* start) {
    struct node *prev = NULL, *curr = start, *next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    start = prev;
    return start;
}

void findNthFromEnd(struct node *start, int n) {
    if(start == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *first = start;
    struct node *second = start;

    for(int i = 0; i < n; i++) {
        if(first == NULL) {
            printf("n = %d is greater than the length of the list.\n", n);
            return;
        }
        first = first->next;
    }

    while(first != NULL) {
        first = first->next;
        second = second->next;
    }

    printf("The %dth node from the end is: %d\n", n, second->info);
}


output->>

Enter number of nodes: 9
Enter data for node 1: 11
Enter data for node 2: 22
Enter data for node 3: 33
Enter data for node 4: 44
Enter data for node 5: 55
Enter data for node 6: 66
Enter data for node 7: 77
Enter data for node 8: 88
Enter data for node 9: 99

Original List:
11 -> 22 -> 33 -> 44 -> 55 -> 66 -> 77 -> 88 -> 99 -> NULL

Reversed List:
99 -> 88 -> 77 -> 66 -> 55 -> 44 -> 33 -> 22 -> 11 -> NULL

Enter n to find nth node from end: 6
The 6th node from the end is: 66
