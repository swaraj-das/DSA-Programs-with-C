#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int top = -1;
char stack[MAX];

void push(char item){
    if(top==MAX-1){
        printf("\n\nStack Overflow !!!");
        return ;
    }
    stack[++top]=item;
}

char pop(){
    if(top==-1){
        printf("\n\nStack Underflow !!!");
        exit(0);
    }
    return stack[top--];
}

int main(void){
    char str[MAX];
    int i=0;

    printf("Enter the string to be reversed: ");
    gets(str);

    printf("Original String: %s",str);

    while(str[i]!='\0'){
        push(str[i]);
        i++;
    }

    i=0;

    while(top!=-1){
        str[i]=pop();
        i++;
    }

    str[i]='\0';
    printf("\nReversed String: %s",str);

    return 0;
}