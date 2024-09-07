#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include<stdlib.h>
#define MAX 50
char postfix[MAX];
char stack[MAX];
int x[MAX];
int top = -1;

void push(int item){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
}

int pop(){
    if(top==-1){
        printf("Stack Overflow\n");
        exit(0);
    }
    return stack[top--];
}

int postfixEvaluation(){
    int i, a, b;
    for(i=0; postfix[i]!='\0'; i++){
        if(isalpha(postfix[i])){
            push(x[i]);
        }
        else{
            a = pop();
            b = pop();
            switch (postfix[i]) {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
            }
        }
    }
    return pop();
}

int main(void){
    printf("Enter the Postfix Expression: ");
    gets(postfix);

    for(int i = 0; postfix[i]!='\0';i++){
        if(isalpha(postfix[i])){
            printf("Enter the value of %c: ", postfix[i]);
            scanf("%d", &x[i]);
        }
    }

    printf("Result of Postfix Evaluation: %d\n", postfixEvaluation());
    return 0;
}