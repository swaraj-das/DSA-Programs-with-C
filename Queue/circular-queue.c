#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    // If the queue is empty, set front and rear to 0
    if (isEmpty()) {
        front = rear = 0;
    } else {
        // Move rear to the next position in a circular manner
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove an element from the circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }

    int data = queue[front];
    
    // If only one element was present, reset the queue
    if (front == rear) {
        front = rear = -1;
    } else {
        // Move front to the next position in a circular manner
        front = (front + 1) % SIZE;
    }
    
    printf("Dequeued %d\n", data);
    return data;
}

// Function to display the elements of the queue
void displayQueue() {
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
        printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
        int choice;
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
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
