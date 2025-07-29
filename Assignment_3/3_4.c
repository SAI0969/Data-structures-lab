#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Utility to create a new node
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

// Insert at front
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) return newNode;

    struct Node* temp = head;
    while (temp->next) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert after key
struct Node* insertAfterKey(struct Node* head, int key, int data) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;

    if (!temp) {
        printf("Key %d not found.\n", key);
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Insert before key
struct Node* insertBeforeKey(struct Node* head, int key, int data) {
    if (!head) return NULL;
    if (head->data == key) return insertAtFront(head, data);

    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;

    if (!temp) {
        printf("Key %d not found.\n", key);
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev) temp->prev->next = newNode;
    temp->prev = newNode;

    return head;
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    if (!head->next) {
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        return NULL;
    }

    while (temp->next) temp = temp->next;

    temp->prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
    return head;
}

// Delete after key
struct Node* deleteAfterKey(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;

    if (!temp || !temp->next) {
        printf("No node found after key %d.\n", key);
        return head;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next) delNode->next->prev = temp;

    printf("Deleted %d after key %d.\n", delNode->data, key);
    free(delNode);
    return head;
}

// Delete before key
struct Node* deleteBeforeKey(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp && temp->data != key) temp = temp->next;

    if (!temp || !temp->prev) {
        printf("No node found before key %d.\n", key);
        return head;
    }

    struct Node* delNode = temp->prev;

    if (delNode->prev) {
        delNode->prev->next = temp;
        temp->prev = delNode->prev;
    } else {
        // delNode is the head
        head = temp;
        head->prev = NULL;
    }

    printf("Deleted %d before key %d.\n", delNode->data, key);
    free(delNode);
    return head;
}

// Display list
void displayList(struct Node* head) {
    printf("List: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main menu
int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after key\n");
        printf("4. Insert before key\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete after key\n");
        printf("8. Delete before key\n");
        printf("9. Display list\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 3:
                printf("Enter key to insert after: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAfterKey(head, key, data);
                break;

            case 4:
                printf("Enter key to insert before: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertBeforeKey(head, key, data);
                break;

            case 5:
                head = deleteFromBeginning(head);
                break;

            case 6:
                head = deleteFromEnd(head);
                break;

            case 7:
                printf("Enter key to delete after: ");
                scanf("%d", &key);
                head = deleteAfterKey(head, key);
                break;

            case 8:
                printf("Enter key to delete before: ");
                scanf("%d", &key);
                head = deleteBeforeKey(head, key);
                break;

            case 9:
                displayList(head);
                break;

            case 10:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
