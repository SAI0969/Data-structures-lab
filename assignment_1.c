// 1st


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int info;
	struct node *next;
};

// Function Prototype
struct node *createList(struct node*);
void display(struct node*);
int main(){
	struct node *head = NULL;
	head = createList(head);
	display(head);
	getch();
	return 0;
}

// Create List Method
struct node *createList(struct node *start){
	int i, n , data;
	struct node *newNode;
	printf("\nEnter the number of nodes in list: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		newNode = (struct node *)malloc(sizeof(struct node));
		if (newNode == NULL){
			printf("Memory not available");
			exit(1);
		}
		printf("\nEnter the value to be inserted: ");
		scanf("%d", &data);
		newNode -> info = data;
		newNode -> next = start;
		start = newNode;
	}
	return start;
}

// Display Method
void display (struct node *start){
	if (start == NULL){
		printf("\nEmpty List");
		return;
	}
	printf("\nList: ");
	while(start != NULL){
		printf("%d\n", start -> info);
		start = start -> next;
	}
}



// 2nd 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int info;
    struct node *next;
};

// Function Prototypes
struct node *createList(struct node *);
void display(struct node *);
void search(struct node *, int); // 🔍 Function declaration

int main() {
    struct node *head = NULL;
    int key;

    head = createList(head);
    display(head);

    printf("\nEnter the element to search for: ");
    scanf("%d", &key);

    search(head, key);  // 🔍 Function call

    getch();
    return 0;
}

// Create List Method (Inserts at Beginning)
struct node *createList(struct node *start) {
    int i, n, data;
    struct node *newNode;

    printf("\nEnter the number of nodes in list: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory not available");
            exit(1);
        }
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &data);

        newNode->info = data;
        newNode->next = start;
        start = newNode;
    }

    return start;
}

// Display Method
void display(struct node *start) {
    if (start == NULL) {
        printf("\nEmpty List");
        return;
    }

    printf("\nList: ");
    while (start != NULL) {
        printf("%d\n", start->info);
        start = start->next;
    }
}

// 🔍 Search Function
void search(struct node *start, int key) {
    int position = 1;
    int found = 0;

    while (start != NULL) {
        if (start->info == key) {
            printf("\nElement %d found at position %d.", key, position);
            found = 1;
            break;
        }
        start = start->next;
        position++;
    }

    if (!found) {
        printf("\nElement %d not found in the list.", key);
    }
}

// output
Enter the number of nodes in list: 3
Enter the value to be inserted: 1
Enter the value to be inserted: 2
Enter the value to be inserted: 3

List:
3
2
1

Enter the element to search for: 2
Element 2 found at position 2



// 3rd


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

