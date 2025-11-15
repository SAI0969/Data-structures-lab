#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *next;
};

// Function Prototypes
void display(struct node *start);
struct node* addAtBegin(struct node *start, int data);
struct node* addAtEnd(struct node *start, int data);
struct node* addAfter(struct node *start, int key, int data);
struct node* addBefore(struct node *start, int key, int data);

int main() {
    struct node *start = NULL;

    // Example operations
    start = addAtBegin(start, 30); // List: 30
    start = addAtBegin(start, 20); // List: 20 -> 30
    start = addAtEnd(start, 40);   // List: 20 -> 30 -> 40
    start = addAfter(start, 30, 35);   // List: 20 -> 30 -> 35 -> 40
    start = addBefore(start, 20, 10);  // List: 10 -> 20 -> 30 -> 35 -> 40

    display(start); // Final list

    return 0;
}

// 🔁 Display List
void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (start != NULL) {
        printf("%d -> ", start->info);
        start = start->next;
    }
    printf("NULL\n");
}

// 🔼 Add at Beginning
struct node* addAtBegin(struct node *start, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = start;
    return newNode;
}

// 🔽 Add at End
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

// ➕ Add After Key
struct node* addAfter(struct node *start, int key, int data) {
    struct node *temp = start;
    while (temp != NULL) {
        if (temp->info == key) {
            struct node *newNode = (struct node*)malloc(sizeof(struct node));
            newNode->info = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return start;
        }
        temp = temp->next;
    }
    printf("Key %d not found. Cannot insert after it.\n", key);
    return start;
}

// ➕ Add Before Key
struct node* addBefore(struct node *start, int key, int data) {
    // If list is empty
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    // If key is at first node
    if (start->info == key) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = data;
        newNode->next = start;
        return newNode;
    }

    struct node *temp = start;
    while (temp->next != NULL && temp->next->info != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Key %d not found. Cannot insert before it.\n", key);
    } else {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return start;
}


//output :

Linked List: 10 -> 20 -> 30 -> 35 -> 40 -> NULL
