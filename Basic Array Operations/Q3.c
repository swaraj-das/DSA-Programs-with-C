// 3. Write a C program to copy one array to another using pointers.
#include<stdio.h>
void arr(int *a,int *b,int n){
    for(int i=0;i<n;i++){
    *(b+i)=*(a+i);
    }
}

int main(){
    int a[10],b[10];
    int n;
    printf("Enter Array size: ");
    scanf("%d",&n);
    printf("Enter Array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    arr(a,b,n);
    printf("Copied Array is:\n");
    for(int i=0;i<n;i++){
    printf("-> %d\n",b[i]);
    }
    return 0;
}