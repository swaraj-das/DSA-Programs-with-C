// 4. Write a C program to reverse an array using pointers.
#include<stdio.h>
int revArr(int *a, int n){
    int temp[n];
    int *tempPtr=temp;
    for (int i = n - 1; i >= 0; i--) {
        *tempPtr = *(a + i);
        tempPtr++;
    }
    for (int i = 0; i < n; i++) {
        *(a + i) = temp[i];
    }
}

int main(){
    int a[10],n;
    printf("Enter Array size: ");
    scanf("%d",&n);
    printf("Enter Array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    revArr(a,n);
    printf("After reverse of the array: \n");
    for(int i=0;i<n;i++){
        printf("->%d\n",a[i]);
    }
}