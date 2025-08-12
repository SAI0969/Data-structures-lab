#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i, value, key, pos, found;

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

    // Display the list
    printf("\nCircular Linked List elements:\n");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");

    // Search for a key (multiple occurrences)
    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    temp = head;
    pos = 1;
    found = 0;
    do {
        if (temp->data == key) {
            printf("Key %d found at position %d.\n", key, pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found) {
        printf("Key %d not found in the list.\n", key);
    }

    return 0;
}



output :
Enter the number of nodes: 6
Enter value for node 1: 10
Enter value for node 2: 20
Enter value for node 3: 30
Enter value for node 4: 20
Enter value for node 5: 50
Enter value for node 6: 20

Circular Linked List elements:
10 20 30 20 50 20

Enter the key to search: 20
Key 20 found at position 2.
Key 20 found at position 4.
Key 20 found at position 6.
