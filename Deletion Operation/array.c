#include<stdio.h>
int deleteElement(int a[], int item, int n){
    int i, j;
    for(i=0; i<n; i++){
        if(item==a[i]){
            n=n-1;
            for(j=i; j<n; j++){
                a[j]=a[j+1];
            }
        }
    }

    printf("After deleting the element %d, the array is: ", item);
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int a[50],n,item;

    printf("Enter the range <=50: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the element for delete : ");
    scanf("%d",&item);

    deleteElement(a, item, n);
}