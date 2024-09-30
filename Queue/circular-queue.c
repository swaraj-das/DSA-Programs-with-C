#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

void CQinsertion(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } 
    else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}


int CQdeletion() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } 
    else {
        front = (front + 1) % SIZE;
    }
    
    printf("Deleted %d\n", data);
    return data;
}

void displayCQ() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    printf("\n---Circular Queue---\n");
    int value;
    while (1) {
        printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        int choice;
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                CQinsertion(value);
                break;
            case 2:
                CQdeletion();
                break;
            case 3:
                displayCQ();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
