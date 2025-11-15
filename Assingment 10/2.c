#include <stdio.h>

void merge(int arr[], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = 0;

    int temp[r - l + 1];

    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);      
        mergeSort(arr, mid + 1, r);  
        merge(arr, l, mid, r);      
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
