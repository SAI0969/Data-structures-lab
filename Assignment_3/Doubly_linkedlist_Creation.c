#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL, *newNode;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("Doubly linked list in forward direction:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}


output ->>

Enter the number of elements: 5
Enter data for node 1: 11
Enter data for node 2: 22
Enter data for node 3: 33
Enter data for node 4: 44
Enter data for node 5: 55
Doubly linked list in forward direction:
11 22 33 44 55
