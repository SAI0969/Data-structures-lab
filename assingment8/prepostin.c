#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* leftchild;
  struct node* rightchild;
};

struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated");
        exit(1);
    }
    newnode->data=data;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    return newnode;
}
struct node* insertLevelOrder(int arr[], int i, int n) {
    struct node* root = NULL;
    if (i < n) {
        root = createnode(arr[i]);
        root->leftchild = insertLevelOrder(arr, 2 * i + 1, n);
        root->rightchild = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void Preorder(struct node* node){
    if(node != NULL){
        printf("%d", node->data);
        Preorder(node->leftchild);
        Preorder(node->rightchild);
    }
}

void Inorder(struct node* node){
    if(node != NULL){
        Inorder(node->leftchild);
        printf("%d", node->data);
        Inorder(node->rightchild);
    }
}

void Postorder(struct node* node){
    if(node != NULL){
        Postorder(node->leftchild);
        Postorder(node->rightchild);
        printf("%d", node->data);
    }
}



int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements : ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    struct node* root = insertLevelOrder(arr, 0, n);
    
    printf("\nPreorder is : ");
    Preorder(root);
    
    printf("\nInorder is : ");
    Inorder(root);
    
    printf("\nPostorder is : ");
    Postorder(root);
}


Enter number of elements : 5
Enter 5 elements : 1
2
3
4
5

Preorder is : 12453
Inorder is : 42513
Postorder is : 45231
