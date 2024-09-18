#include <stdio.h>
#define SIZE 5 // Define the size of the queue

int queue[SIZE]; // Array to store queue elements
int front = -1;  // Index of the front element
int rear = -1;   // Index of the rear element

// Function to check if the queue is full
int isFull() {
    if (rear == SIZE - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    } 
    else {
        if (front == -1) {
            front = 0;  // Set front to 0 if it's the first insertion
        }
        rear++;
        queue[rear] = value;
        printf("Inserted : %d\n", value);
    }
}

// Function to remove an element from the queue (Dequeue)
int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } 
    else {
        item = queue[front];
        front++;
        if (front > rear) {  // Reset the queue if all elements are dequeued
            front = rear = -1;
        }
        printf("Removed : %d\n", item);
        return item;
    }
}

// Function to display the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
