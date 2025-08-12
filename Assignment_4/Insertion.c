#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insert at the front
void insertFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Insert at the end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Insert after a node with a given key
void insertAfterKey(struct Node** head, int key, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    do {
        if (temp->data == key) {
            struct Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Key %d not found.\n", key);
}

// Insert before a node with a given key
void insertBeforeKey(struct Node** head, int key, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *prev = NULL, *curr = *head;

    // Special case: key is in head
    if (curr->data == key) {
        insertFront(head, value);
        return;
    }

    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            struct Node* newNode = createNode(value);
            prev->next = newNode;
            newNode->next = curr;
            return;
        }
    } while (curr != *head);

    printf("Key %d not found.\n", key);
}

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a key\n");
        printf("4. Insert before a key\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfterKey(&head, key, value);
                break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeforeKey(&head, key, value);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}


output :
--- Circular Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after a key
4. Insert before a key
5. Display list
6. Exit
Enter choice: 1
Enter value: 10

Enter choice: 2
Enter value: 20

Enter choice: 2
Enter value: 30

Enter choice: 3
Enter key: 20
Enter value: 25

Enter choice: 4
Enter key: 30
Enter value: 28

Enter choice: 5
10 20 25 28 30
