#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List size must be greater than zero.\n");
        return 0;
    }

    // Create circular linked list
    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    // Link last node to head
    temp->next = head;

    // Traverse and display list
    printf("\nCircular Linked List elements:\n");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");

    return 0;
}

Output: 

Enter the number of nodes: 4
Enter value for node 1: 10
Enter value for node 2: 20
Enter value for node 3: 30
Enter value for node 4: 40

Circular Linked List elements:
10 20 30 40
