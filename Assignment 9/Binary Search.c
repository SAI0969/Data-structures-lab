#include <stdio.h>
int main(){
    int arr[100], key, n, l, u, mid, i, found = 0;

    printf("Enter the no of elements in array : ");
    scanf("%d", &n);

    for(i = 0; i < n ; i++){
        printf("Enter the number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search : ");
    scanf("%d", &key);

    l = 0;
    u = n - 1;

    while(l <= u){
        mid = (l + u) / 2;

        if(arr[mid] == key){
            printf("Element %d is found at position %d\n", key, mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] > key){
            u = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    if (!found){
        printf("Element %d is not in array\n", key);
    }

    return 0;
}
