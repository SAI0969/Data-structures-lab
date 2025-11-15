#include <stdio.h>
int main(){
    int i, n, key, j;

    printf("Enter the no of elements in the array : ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n ; i++){
        printf("Enter %d element in array: ", i + 1);
        scanf("%d", &arr[i]);
    }

   
    for(i = 1; i < n ; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("Sorted array is : ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
