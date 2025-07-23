//1

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *next;
};

// Function Prototypes
void display(struct node *start);
struct node* addAtEnd(struct node *start, int data); // for demo purposes

struct node* deleteFirst(struct node *start);
struct node* deleteLast(struct node *start);
struct node* deleteAfter(struct node *start, int key);
struct node* deleteBefore(struct node *start, int key);

int main() {
    struct node *start = NULL;

    // Sample list creation
    start = addAtEnd(start, 10);
    start = addAtEnd(start, 20);
    start = addAtEnd(start, 30);
    start = addAtEnd(start, 40);
    start = addAtEnd(start, 50);

    printf("Initial list:\n");
    display(start);

    // Delete operations
    start = deleteFirst(start);        // Removes 10
    start = deleteLast(start);         // Removes 50
    start = deleteAfter(start, 20);    // Removes 30 (after 20)
    start = deleteBefore(start, 40);   // Removes 20 (before 40)

    printf("\nFinal list after deletions:\n");
    display(start);

    return 0;
}

// 👀 Display function
void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (start != NULL) {
        printf("%d -> ", start->info);
        start = start->next;
    }
    printf("NULL\n");
}

// ➕ Helper: Add at end
struct node* addAtEnd(struct node *start, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = NULL;

    if (start == NULL)
        return newNode;

    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return start;
}

// ❌ Delete First Node
struct node* deleteFirst(struct node *start) {
    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct node *temp = start;
    start = start->next;
    printf("Deleted first node: %d\n", temp->info);
    free(temp);

    return start;
}

// ❌ Delete Last Node
struct node* deleteLast(struct node *start) {
    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (start->next == NULL) {
        printf("Deleted last node: %d\n", start->info);
        free(start);
        return NULL;
    }

    struct node *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted last node: %d\n", temp->next->info);
    free(temp->next);
    temp->next = NULL;

    return start;
}

// ❌ Delete After Key
struct node* deleteAfter(struct node *start, int key) {
    struct node *temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Cannot delete after key %d.\n", key);
        return start;
    }

    struct node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted node after %d: %d\n", key, toDelete->info);
    free(toDelete);

    return start;
}

// ❌ Delete Before Key
struct node* deleteBefore(struct node *start, int key) {
    if (start == NULL || start->next == NULL) {
        printf("Not enough nodes to delete before key %d.\n", key);
        return start;
    }

    // If the second node is the key
    if (start->next->info == key) {
        struct node *temp = start;
        start = start->next;
        printf("Deleted node before %d: %d\n", key, temp->info);
        free(temp);
        return start;
    }

    struct node *prev = NULL, *curr = start;

    while (curr->next != NULL && curr->next->info != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == NULL) {
        printf("Key %d not found. Cannot delete before it.\n", key);
        return start;
    }

    // Delete curr node (before key)
    if (prev != NULL) {
        prev->next = curr->next;
        printf("Deleted node before %d: %d\n", key, curr->info);
        free(curr);
    }

    return start;
}


// output 

Initial list:
List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Deleted first node: 10
Deleted last node: 50
Deleted node after 20: 30
Deleted node before 40: 20

Final list after deletions:
List: 40 -> NULL