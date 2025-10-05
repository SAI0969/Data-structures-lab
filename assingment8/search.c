#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* leftchild;
    struct node* rightchild;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }
    newnode->data = data;
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;
    return newnode;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return createnode(data);
    }

    if (data < node->data)
        node->leftchild = insert(node->leftchild, data);
    else if (data > node->data)
        node->rightchild = insert(node->rightchild, data);

    return node;
}

struct node* search(struct node* node, int key) {
    if (node == NULL || node->data == key)
        return node;

    if (key < node->data)
        return search(node->leftchild, key);
    else
        return search(node->rightchild, key);
}


void Preorder(struct node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        Preorder(node->leftchild);
        Preorder(node->rightchild);
    }
}

void Inorder(struct node* node) {
    if (node != NULL) {
        Inorder(node->leftchild);
        printf("%d ", node->data);
        Inorder(node->rightchild);
    }
}

void Postorder(struct node* node) {
    if (node != NULL) {
        Postorder(node->leftchild);
        Postorder(node->rightchild);
        printf("%d ", node->data);
    }
}

int main() {
    struct node* root = NULL;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        root = insert(root, arr[i]); 
    }

    printf("\nPreorder traversal: ");
    Preorder(root);

    printf("\nInorder traversal: ");
    Inorder(root);

    printf("\nPostorder traversal: ");
    Postorder(root);

    int key;
    printf("\n\nEnter element to search: ");
    scanf("%d", &key);
    struct node* found = search(root, key);

    if (found != NULL)
        printf("Element %d found in tree.\n", key);
    else
        printf("Element %d not found in tree.\n", key);

    return 0;
}



Enter number of elements: 5
Enter 5 elements: 50 30 70 20 40

Preorder traversal: 50 30 20 40 70
Inorder traversal: 20 30 40 50 70
Postorder traversal: 20 40 30 70 50

Enter element to search: 40
Element 40 found in tree.

