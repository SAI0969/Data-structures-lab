// 1. To print right angled triangled shaped stars
// *
// **
// ***
// ****
// *****


#include <stdio.h>
int main(){
	int i , j, n = 5;
	for(i = 0; i <= n; i++){
		for (j = 0; j <= i; j++){
			printf("*");
		}
	printf("\n");
	}
}


// 2. To print pascal shaped triangled stars(Equilateral triangle)
//     *
//    ***
//   *****
//  *******
// *********


#include <stdio.h>
int main(){
	int i, j, k, n = 5;
	for (i = 0; i < n ; i++){
		for (j = 0; j < n- i - 1; j++){
			printf(" ");
		}
		for (k = 0; k < 2 * i + 1; k++){
			printf("*");
		}
		printf("\n");
	}
}



// 3. Print the factorial of a number 

#include <stdio.h>
int main(){
	int i, j, k;
	i = 6;
	j = 1;
	for (k = 1; k <= i; k++){
		j = j * k;
	}
	printf("%d", j);
}


// output -> 720


// 4. To find the min and max of two numbers.

#include <stdio.h>
int main() {
	int num[5];
	int i;

	for (i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}

	int min = num[0];
	int max = num[0];

	for (i = 1; i < 5; i++) {
		if (num[i] < min) {
			min = num[i];
		}
	}

	for (i = 1; i < 5; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}

	printf("The min value is %d\n", min);
	printf("The max value is %d\n", max);

	return 0;
}



// 5. To find even or odd

#include <stdio.h>
int main(){
	int num[5];
	int i;
	for (i = 0; i < 5; i++){
		scanf("%d", &num[i]);
	}
	for (i = 0; i < 5 ; i++){
		if (num[i] % 2 == 0){
			printf("The even numbers are %d\n", num[i]);
		}
		else{
			printf("The odd numbers are %d\n", num[i]);
		}
	}
}


// 6. Reversing a array

#include <stdio.h>
int main(){
	int n = 5;
	int num[n];
	int i, a;

	for(i = 0; i < n ; i++){
		scanf("%d", &num[i]);
	}
	for (i = 0; i < n / 2; i++){
		a = num[i];
		num[i] = num[4 - i];
		num[4 - i] = a;
	}
	printf("Reversed Array: ");

	for(i = 0; i < 5; i++){
		printf("%d", num[i]);
	}
}


// 7. Write a C program to create a singly linked list and display its contents after creation. You must implement the following two functions:
// a.	struct node *createList(struct node *start)
// ➤ This function should create the singly linked list by inserting nodes based on user input.
// b.	void display(struct node *start)
// ➤ This function should traverse the list and display the elements one by one.


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
