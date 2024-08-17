#include<stdio.h>
int main(void){
    int a[50],n,i,item; //memory wasted for static allocation 200bytes

    printf("Enter the range <=50: ");
    scanf("%d",&n);

    printf("Enter %d integers: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the item to be searched: ");
    scanf("%d",&item);
    for(i=0;i<n;i++){
        if(a[i]==item){
            printf("%d found at position %d.\n",item, i+1);
            break;
        }
    }
    if(n==i){
        printf("%d not found in the array.\n",item);
    }

return 0;
}