#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflowed !!\n");
        return;
    }
    top++;
    stack[top] = item; 
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow !!\n");
        return;
    }
    int popped_item = stack[top];
    top--;
    printf("Popped item: %d\n", popped_item);
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("The elements in the stack are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main(void) {
    int choice, item;
    printf("\n\n----------STACK DATA STRUCTURE-----------\n\n");
    while(1) {
        printf("1. PUSH 2. POP 3. DISPLAY 4. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nThank you for using the stack\n");
                exit(0);
            default:
                printf("Invalid Input !!\nPlease enter a valid option.\n");
        }
    }
    return 0;
}
