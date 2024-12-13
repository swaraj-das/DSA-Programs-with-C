// 2. Write a C Program to swap two given numbers using call by reference.
#include<stdio.h>
void swap(int *a,int *b, int *c){
    *c=*a;
    *a=*b;
    *b=*c;
}

int main(){
    int a,b,c;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    swap(&a,&b,&c);
    printf("After swapping x= %d\ty= %d",a,b);
    return 0;
}