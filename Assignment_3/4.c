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
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at end (for demo purposes)
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

// Display the list
void displayList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        return NULL;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
    return head;
}

// Delete node after a given key
struct Node* deleteAfterKey(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("No node found after key %d.\n", key);
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL)
        nodeToDelete->next->prev = temp;

    printf("Deleted %d after key %d.\n", nodeToDelete->data, key);
    free(nodeToDelete);
    return head;
}

// Delete node before a given key
struct Node* deleteBeforeKey(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->prev == NULL) {
        printf("No node found before key %d.\n", key);
        return head;
    }

    struct Node* nodeToDelete = temp->prev;

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = temp;
        temp->prev = nodeToDelete->prev;
    } else {
        // nodeToDelete is the head
        head = temp;
        head->prev = NULL;
    }

    printf("Deleted %d before key %d.\n", nodeToDelete->data, key);
    free(nodeToDelete);
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Delete after key\n");
        printf("5. Delete before key\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 2:
                head = deleteFromBeginning(head);
                break;

            case 3:
                head = deleteFromEnd(head);
                break;

            case 4:
                printf("Enter key after which to delete: ");
                scanf("%d", &key);
                head = deleteAfterKey(head, key);
                break;

            case 5:
                printf("Enter key before which to delete: ");
                scanf("%d", &key);
                head = deleteBeforeKey(head, key);
                break;

            case 6:
                displayList(head);
                break;

            case 7:
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
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 1
Enter data to insert: 5

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 1
Enter data to insert: 6

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 6
List: 5 6

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 1
Enter data to insert: 7

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 1
Enter data to insert: 8

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 6
List: 5 6 7 8

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 2
Deleted 5 from beginning.

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 3
Deleted 8 from end.

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 4
Enter key after which to delete: 6
Deleted 7 after key 6.

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 6
List: 6

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 5
Enter key before which to delete: 6
No node found before key 6.

Menu:
1. Insert at end
2. Delete from beginning
3. Delete from end
4. Delete after key
5. Delete before key
6. Display list
7. Exit
Enter choice: 7
Exiting.
