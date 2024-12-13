#include <stdio.h>
#include <stdlib.h>

void binary_search(int arr[], int low, int high, int item){
    do{
        int mid = (low + high) / 2;
        if(arr[mid]==item){
            printf("%d found at position %d\n", item, mid+1);
            return;
        }
        else if (arr[mid]<item){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }while(low <= high);
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