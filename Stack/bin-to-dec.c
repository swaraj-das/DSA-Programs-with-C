#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int rem){
    if (top == MAX - 1) {
        printf("Stack Overflowed !!\n");
        return;
    }
    stack[++top] = rem;
}

int pop(){
    if(top == - 1){
        printf("Stack Underflowed !!\n");
        return -1;
    }
    return stack[top--];
}

int main(void){
    int num;
    printf("Enter a decimal number : ");
    scanf("%d",&num);
    
    while(num!=0){
        int rem = num%2;
        push(rem);
        num /= 2;
    }

    printf("Binary equivalent : ");
    while(top!= -1){
        printf("%d",pop());
    }
    printf("\n");
    
    return 0;
}