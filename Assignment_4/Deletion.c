#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Utility: Create a new node
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

// Utility: Display the list
void displayList(struct Node* head) {
    if (!head) {
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

// Insert at end for initial setup
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

// 1. Delete from beginning
void deleteBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;

    // Only one node
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    // Find last node
    struct Node* last = *head;
    while (last->next != *head)
        last = last->next;

    last->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
}

// 2. Delete from end
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;

    // Only one node
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
}

// 3. Delete after a given key
void deleteAfterKey(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    do {
        if (temp->data == key) {
            struct Node* delNode = temp->next;

            // Only one node in list
            if (delNode == temp) {
                free(delNode);
                *head = NULL;
                return;
            }

            // If node after key is head
            if (delNode == *head)
                *head = (*head)->next;

            temp->next = delNode->next;
            free(delNode);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Key %d not found.\n", key);
}

// 4. Delete before a given key
void deleteBeforeKey(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    struct Node* prevPrev = NULL;

    // Special case: if head contains key, delete last node
    if ((*head)->data == key) {
        deleteEnd(head);
        return;
    }

    do {
        prevPrev = prev;
        prev = temp;
        temp = temp->next;

        if (temp->data == key) {
            // Delete prev node
            if (prev == *head) {
                deleteBeginning(head);
                return;
            }
            prevPrev->next = temp;
            free(prev);
            return;
        }
    } while (temp != *head);

    printf("Key %d not found.\n", key);
}

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    // Initial list setup
    int n;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    while (1) {
        printf("\n--- Circular Linked List Deletion Menu ---\n");
        printf("1. Delete from beginning\n");
        printf("2. Delete from end\n");
        printf("3. Delete after a key\n");
        printf("4. Delete before a key\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteBeginning(&head);
                break;
            case 2:
                deleteEnd(&head);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteAfterKey(&head, key);
                break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteBeforeKey(&head, key);
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

Enter number of nodes to create: 5
Enter value for node 1: 10
Enter value for node 2: 20
Enter value for node 3: 30
Enter value for node 4: 40
Enter value for node 5: 50

--- Circular Linked List Deletion Menu ---
5
10 20 30 40 50

Choice: 1
(Deletes 10)
20 30 40 50

Choice: 3
Enter key: 30
(Deletes 40)
20 30 50

Choice: 4
Enter key: 30
(Deletes 20)
30 50

Choice: 2
(Deletes 50)
30
