#include <stdio.h>
int main(){
    int key, n, i;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++){
        printf("Enter the number at %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search : ");
    scanf("%d", &key);

    int found = 0;
    for(int i = 0; i < n ; i++){
        if(arr[i] == key){
            printf("The element %d is found at %d", key, i + 1);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Element %d is not found in the array", key);
    }
}


output :

Enter the number of elements in array : 9
Enter the number at 1 : 1
Enter the number at 2 : 2
Enter the number at 3 : 3
Enter the number at 4 : 4
Enter the number at 5 : 5
Enter the number at 6 : 6
Enter the number at 7 : 7
Enter the number at 8 : 8
Enter the number at 9 : 9
Enter the element to search : 15
Element 15 is not found in the array


best case complexity is of order 0(1)
    
The element is found at the first position of the list.
    
worst case complexity is of order 0(n)

The element is not present in the list, or
It is present at the last position.


Average case complexity is of order 0(n)
Element somewhere in the middle
