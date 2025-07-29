#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the front
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    return head;
}

// Insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert after a given key
struct Node* insertAfterKey(struct Node* head, int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key %d not found.\n", key);
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

// Insert before a given key
struct Node* insertBeforeKey(struct Node* head, int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    // Special case: key is at the head
    if (head->data == key)
        return insertAtFront(head, data);

    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key %d not found.\n", key);
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;

    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    printf("Current List (Forward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to demonstrate all insertions
int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after key\n");
        printf("4. Insert before key\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                break;

            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAfterKey(head, key, data);
                break;

            case 4:
                printf("Enter key before which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertBeforeKey(head, key, data);
                break;

            case 5:
                displayList(head);
                break;

            case 6:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}



output ->>

Menu:
1. Insert at front
2. Insert at end
3. Insert after key
4. Insert before key
5. Display list
6. Exit
Enter choice: 1
Enter data to insert at front: 5

Menu:
1. Insert at front
2. Insert at end
3. Insert after key
4. Insert before key
5. Display list
6. Exit
Enter choice: 2
Enter data to insert at end: 6

Menu:
1. Insert at front
2. Insert at end
3. Insert after key
4. Insert before key
5. Display list
6. Exit
Enter choice: 3
Enter key after which to insert: 5
Enter data to insert: 12

Menu:
1. Insert at front
2. Insert at end
3. Insert after key
4. Insert before key
5. Display list
6. Exit
Enter choice: 4
Enter key before which to insert: 6
Enter data to insert: 16

Menu:
1. Insert at front
2. Insert at end
3. Insert after key
4. Insert before key
5. Display list
6. Exit
Enter choice: 5
Current List (Forward): 5 12 16 6

Menu:
1. Insert at front
2. Insert at end
3. Insert after key
4. Insert before key
5. Display list
6. Exit
Enter choice: 6
Exiting.
