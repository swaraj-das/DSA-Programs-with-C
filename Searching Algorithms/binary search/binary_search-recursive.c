#include <stdio.h>
#include <stdlib.h>

void binary_search(int arr[], int low, int high, int item){
    if(low > high){
        printf("%d not found in the array.\n", item);
        return;
    }

    int mid = (low + high) / 2;

    if(arr[mid] == item){
        printf("%d found at position %d\n", item, mid + 1);
    }
    else if(arr[mid] < item){
        binary_search(arr, mid + 1, high, item);
    }
    else{
        binary_search(arr, low, mid - 1, item);
    }
}

int main(void){
    int *arr, item, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &item);

    binary_search(arr, 0, n-1, item);

    free(arr);
    return 0;
}
