#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
int top = -1;
char stack[MAX];
char prefix[MAX];
int x[MAX];
void push(int item){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
}

int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int prefix_evaluation (){
    int i=0,a,b;
    strrev(prefix);

    while(prefix[i] !='\0'){
        if(isalpha(prefix[i])){
            push(x[strlen(prefix)-i-1]);
        }
        else{
            b=pop();
            a=pop();
            switch(prefix[i]){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
        i++;
    }
    return pop();
}

int main(){
    printf("Enter the prefix expression: ");
    gets(prefix);

    int i=0;
    while (prefix[i] !='\0'){
        if(isalpha(prefix[i])){
            printf("Enter the value of %c: ", prefix[i]);
            scanf("%d", &x[i]);
        }
        i++;
    }

    printf("The result is: %d\n", prefix_evaluation());
    return 0;
}
    