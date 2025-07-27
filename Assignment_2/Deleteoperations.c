#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node* createList(struct node *start);
struct node* addAtEnd(struct node *start, int data);
void display(struct node *start);

struct node* deleteFirst(struct node *start);
struct node* deleteLast(struct node *start);
struct node* deleteAfter(struct node *start, int key);
struct node* deleteBefore(struct node *start, int key);

int main() {
    struct node *start = NULL;
    int choice, data, key;

    start = createList(start);

    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Display\n2. Delete First\n3. Delete Last\n4. Delete After Key\n5. Delete Before Key\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display(start);
                break;
            case 2:
                start = deleteFirst(start);
                break;
            case 3:
                start = deleteLast(start);
                break;
            case 4:
                printf("Enter key after which to delete: ");
                scanf("%d", &key);
                start = deleteAfter(start, key);
                break;
            case 5:
                printf("Enter key before which to delete: ");
                scanf("%d", &key);
                start = deleteBefore(start, key);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

struct node* createList(struct node *start) {
    int i, n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        start = addAtEnd(start, data);
    }
    return start;
}

struct node* addAtEnd(struct node *start, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = NULL;

    if(start == NULL)
        return newNode;

    struct node *temp = start;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return start;
}

void display(struct node *start) {
    struct node *temp = start;
    if(temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* deleteFirst(struct node *start) {
    if(start == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
    printf("First node deleted.\n");
    return start;
}

struct node* deleteLast(struct node *start) {
    if(start == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if(start->next == NULL) {
        free(start);
        return NULL;
    }
    struct node *temp = start;
    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted.\n");
    return start;
}

struct node* deleteAfter(struct node *start, int key) {
    struct node *temp = start;
    while(temp != NULL && temp->info != key)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL) {
        printf("No node found after the key %d to delete.\n", key);
        return start;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Node after %d deleted.\n", key);
    return start;
}

struct node* deleteBefore(struct node *start, int key) {
    if(start == NULL || start->next == NULL) {
        printf("Not enough nodes to perform deleteBefore.\n");
        return start;
    }

    if(start->next->info == key) {
        struct node *temp = start;
        start = start->next;
        free(temp);
        printf("Node before %d deleted.\n", key);
        return start;
    }

    struct node *prev = NULL, *curr = start, *next = start->next;

    while(next != NULL && next->info != key) {
        prev = curr;
        curr = next;
        next = next->next;
    }

    if(next == NULL) {
        printf("Key %d not found in list.\n", key);
        return start;
    }

    if(prev != NULL) {
        prev->next = next;
        free(curr);
        printf("Node before %d deleted.\n", key);
    }

    return start;
}
