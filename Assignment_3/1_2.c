#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create the doubly linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

// Function to display the list in forward direction
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nDoubly linked list in forward direction:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a key in the list
void searchKey(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("\nKey %d found at position %d.\n", key, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        printf("\nKey %d not found in the list.\n", key);
    }
}

// Main function
int main() {
    int n, key;
    struct Node* head;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    displayList(head);

    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    searchKey(head, key);

    return 0;
}

output ->>

Enter the number of nodes: 5
Enter data for node 1: 1
Enter data for node 2: 2
Enter data for node 3: 3
Enter data for node 4: 4
Enter data for node 5: 5

Doubly linked list in forward direction:
1 2 3 4 5

Enter the key to search: 9

Key 9 not found in the list.
