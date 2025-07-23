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


//2


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *next;
};

// Function Prototypes
struct node* createList(int n);
void display(struct node *start);
struct node* reverse(struct node *start);

int main() {
    struct node *start = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    start = createList(n);

    printf("\nOriginal List:\n");
    display(start);

    start = reverse(start);

    printf("\nReversed List:\n");
    display(start);

    return 0;
}

// 🔧 Create a linked list of n nodes
struct node* createList(int n) {
    struct node *start = NULL, *newNode, *temp;
    int data, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = data;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return start;
}

// 📃 Display the linked list
void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (start != NULL) {
        printf("%d -> ", start->info);
        start = start->next;
    }
    printf("NULL\n");
}

// 🔁 Reverse the linked list
struct node* reverse(struct node* start) {
    struct node *prev = NULL, *current = start, *nextNode;

    while (current != NULL) {
        nextNode = current->next;   // Store next
        current->next = prev;       // Reverse current node's pointer
        prev = current;             // Move prev and current one step forward
        current = nextNode;
    }

    return prev; // New head of reversed list
}



//output 

Enter the number of nodes: 5
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Enter data for node 5: 50

Original List:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Reversed List:
50 -> 40 -> 30 -> 20 -> 10 -> NULL



//3 


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *next;
};

// Function Prototypes
struct node* createList(int n);
void display(struct node *start);
void findNthFromEnd(struct node *start, int n);

int main() {
    struct node *start = NULL;
    int n, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    start = createList(n);
    printf("\nLinked List: ");
    display(start);

    printf("\nEnter n to find nth node from the end: ");
    scanf("%d", &pos);

    findNthFromEnd(start, pos);

    return 0;
}

// Create list with n nodes
struct node* createList(int n) {
    struct node *start = NULL, *newNode, *temp;
    int data, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = data;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return start;
}

// Display the list
void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (start != NULL) {
        printf("%d -> ", start->info);
        start = start->next;
    }
    printf("NULL\n");
}

// Find nth node from end using two-pointer method
void findNthFromEnd(struct node *start, int n) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (n <= 0) {
        printf("Invalid value of n: %d\n", n);
        return;
    }

    struct node *first = start, *second = start;
    int count = 0;

    // Move first pointer n nodes ahead
    while (count < n) {
        if (first == NULL) {
            printf("n = %d is greater than the length of the list.\n", n);
            return;
        }
        first = first->next;
        count++;
    }

    // Move both pointers until first reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    printf("The %dth node from the end is: %d\n", n, second->info);
}


// output 

Enter number of nodes: 5
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Enter data for node 5: 50

Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

Enter n to find nth node from the end: 2
The 2th node from the end is: 40



//4


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct node {
    int info;
    struct node *next;
};

// Function Prototypes
struct node* createList(int n);
void display(struct node *start);
bool isPalindrome(struct node *start);
struct node* reverse(struct node *head);
bool compareLists(struct node* head1, struct node* head2);

int main() {
    struct node *start = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    start = createList(n);

    printf("\nLinked List: ");
    display(start);

    if (isPalindrome(start))
        printf("\nThe list is a palindrome.\n");
    else
        printf("\nThe list is NOT a palindrome.\n");

    return 0;
}

// 🔧 Create a list
struct node* createList(int n) {
    struct node *start = NULL, *newNode, *temp;
    int data, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = data;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return start;
}

// 🖨️ Display list
void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (start != NULL) {
        printf("%d -> ", start->info);
        start = start->next;
    }
    printf("NULL\n");
}

// 🔁 Reverse a linked list
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *nextNode;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// 🔍 Compare two lists
bool compareLists(struct node* head1, struct node* head2) {
    while (head1 && head2) {
        if (head1->info != head2->info)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

// 🔁 Check if list is palindrome
bool isPalindrome(struct node *start) {
    if (start == NULL || start->next == NULL)
        return true;

    struct node *slow = start, *fast = start;
    struct node *prev_slow = NULL;

    // Step 1: Find middle
    while (fast && fast->next) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    struct node *secondHalf, *midNode = NULL;

    // For odd number of nodes, skip middle
    if (fast != NULL) {
        midNode = slow;
        slow = slow->next;
    }

    // Step 2: Reverse second half
    secondHalf = reverse(slow);
    prev_slow->next = NULL;

    // Step 3: Compare
    bool result = compareLists(start, secondHalf);

    // Step 4 (optional): Restore original list
    secondHalf = reverse(secondHalf);
    if (midNode) {
        prev_slow->next = midNode;
        midNode->next = secondHalf;
    } else {
        prev_slow->next = secondHalf;
    }

    return result;
}


//output
Enter number of nodes: 5
Enter data for node 1: 1
Enter data for node 2: 2
Enter data for node 3: 3
Enter data for node 4: 2
Enter data for node 5: 1

Linked List: 1 -> 2 -> 3 -> 2 -> 1 -> NULL
The list is a palindrome.



//5


