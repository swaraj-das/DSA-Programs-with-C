#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};
struct Node* top = NULL;

void push(int data){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Insufficient Memory!!\n");
        return;
    }
    temp->data = data;
    temp->link = top;
    top = temp;
    printf("%d pushed to stack\n", data);
}

void pop(){
    struct Node *temp;
    if(top == NULL){
        printf("Stack is empty!!\n");
        return;
    }
    temp = top;
    printf("%d popped from stack\n", temp->data);
    top = top->link;
    free(temp);
    temp = NULL;
}

void peek(){
    if(top == NULL){
        printf("Stack is empty!!\n");
        return;
    }
    printf("Top element of the stack is: %d\n", top->data);
    return;
}

void display(){
    struct Node *ptr;
    ptr = top;
    if(ptr == NULL){
        printf("Stack is empty!\n");
        return;
    }
    printf("Linked Stack elements are: ");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(void){
    int ch, data;
    printf("-----------Linked Stack-----------\n");
    for(;;){
        printf("\nLinked Stack Operations:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}