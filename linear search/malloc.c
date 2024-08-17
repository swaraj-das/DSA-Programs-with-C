#include<stdio.h>
#include<stdlib.h>
void linearsearch(int* arr, int n, int item){
    for(int i = 0; i < n; i++){
        if(arr[i] == item){
            printf("%d found at position %d\n", item, i+1);
        }
    }
}

int main(void){
    int n, i, item;
    int* ptr;
    printf("Enter the range: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n*sizeof(int));
    printf("Enter elements in the array:");
	for(i=0;i<n;i++){
		scanf("%d",ptr+i);
    }

    printf("Enter an item to be search :");
	scanf("%d",&item);

    linearsearch(ptr, n, item);
}