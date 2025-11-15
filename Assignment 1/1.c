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

