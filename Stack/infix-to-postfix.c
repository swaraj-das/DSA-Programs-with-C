#include<stdio.h>
#include<stdlib.h>
#define MAX 50

char stack[MAX]; 
char infix[MAX];
char postfix[MAX];
int top = -1;

void push(char item){
    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
    // printf("Pushed %c, Stack top: %c\n", item, stack[top]);
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        exit(0);
    }
    // printf("Popped %c, New top: %c\n", stack[top], top > 0 ? stack[top - 1] : ' ');
    return stack[top--];
}

int precision(int symbol){
    switch(symbol){
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infix_to_postfix(){
    int i = 0, p = 0;
    char symbol, next;
    while(infix[i] != '\0'){
        symbol = infix[i];
        
        // for operators
        if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '%'){
            while(top != -1 && precision(stack[top]) >= precision(infix[i])){
                postfix[p++] = pop();
            }
            push(infix[i]);
        }
        // for open parenthesis
        else if(symbol == '('){
            push(infix[i]);
        }
        // for close parenthesis
        else if(symbol == ')'){
            while((next = pop()) != '('){  // Should compare with '('
                postfix[p++] = next;
            }
        }
        // for operands
        else{
            postfix[p++] = infix[i];
        }
        i++;
    }
    while(top != -1){
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
}

int main(void){
    printf("Enter infix expression: ");
    scanf("%s", infix);  // No need for & with array name

    infix_to_postfix();
    printf("The postfix expression: ");
    puts(postfix);

    return 0;
}
