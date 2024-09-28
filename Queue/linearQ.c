#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];

int front = -1;
int rear = -1;

void qinsertion(int item){
    if(rear==MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear++;
    queue[rear]=item;
}

void qdeletion(){
    if(front==-1){
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted Item : %d\n",queue[front]);
    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}

void qdisplay(){
    if(front==-1){
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void main(){
    int ch, item;
    printf("\n----QUEUE OPERATION----\n");
    while(1){
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch) {
        case 1:
            printf("Enter Element: ");
            scanf("%d",&item);
            qinsertion(item);
            break;
        case 2:
            qdeletion();
            break;
        case 3:
            qdisplay();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}