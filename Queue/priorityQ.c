//For Ascending Priority Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int pqueue[MAX];
int front = -1;
int rear = -1;

void pqinsertion(int item){
    if(rear == MAX-1){
        printf("Queue is Full !!\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    pqueue[rear] = item;
    for (int i = front; i <= rear; i++){
        for (int j = i + 1; j <= rear; j++){
            if (pqueue[i] > pqueue[j]){
                int temp = pqueue[i];
                pqueue[i] = pqueue[j];
                pqueue[j] = temp;
            }
        }
    }
}

void pqdeletion(){
    if(front == -1){
        printf("Queue is empty !!\n");
        return;
    }
    printf("Deleted item: %d\n", pqueue[front]);
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void pqdisplay(){
    if(front == -1){
        printf("Queue is empty!!\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i=front; i<=rear; i++){
        printf("%d ", pqueue[i]);
    }
    printf("\n");
}


int main(void){
    int ch, item;
    printf("\n\n********** Priority Queue **********");
    while(1){
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                pqinsertion(item);
                break;
            case 2:
                pqdeletion();
                break;
            case 3:
                pqdisplay();
                break;
            case 4:
                printf("Exiting....!!!\nThank you for choosing our application.");
                exit(0);
            default:
                printf("Wrong choice!\n Please choose different option.");
        }
    }
    return 0;
}