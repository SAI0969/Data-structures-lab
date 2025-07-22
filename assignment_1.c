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