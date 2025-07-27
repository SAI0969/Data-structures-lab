#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node* createList(struct node *start);
struct node* addAtEnd(struct node *start, int data);
void display(struct node *start);
void findMiddle(struct node *start);

int main() {
    struct node *start = NULL;

    start = createList(start);

    printf("\nLinked List:\n");
    display(start);

    findMiddle(start);

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

void findMiddle(struct node *start) {
    if(start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *slow = start;
    struct node *fast = start;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("\nThe middle node is: %d\n", slow->info);
}



output->>

Enter number of nodes: 8
Enter data for node 1: 11
Enter data for node 2: 22
Enter data for node 3: 33
Enter data for node 4: 44
Enter data for node 5: 55
Enter data for node 6: 66
Enter data for node 7: 77
Enter data for node 8: 8

Linked List:
11 -> 22 -> 33 -> 44 -> 55 -> 66 -> 77 -> 8 -> NULL

The middle node is: 55
