#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int rear = -1;
int front = -1;
int deque[MAX];

void dqinsert_at_front(int item) {
    if ((rear + 1) % MAX == front) {
        printf("\nQueue is full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front = (front + MAX - 1) % MAX;
    }
    deque[front] = item;
}

void dqinsert_at_rear(int item) {
    if ((rear + 1) % MAX == front) {
        printf("\nQueue is full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = item;
}

void dqdelete_from_front() {
    if (front == -1) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nDeleted item from front is: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;  // Reset the queue when it becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}

void dqdelete_from_rear() {
    if (front == -1) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nDeleted item from rear is: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear + MAX - 1) % MAX;
    }
}

void dqdisplay1() {
    if (front == -1) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue from front to rear: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {  // Fix loop condition
            printf("%d ", deque[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

void dqdisplay2() {
    if (front == -1) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue from rear to front: ");
    if (front <= rear) {
        for (int i = rear; i >= front; i--) {
            printf("%d ", deque[i]);
        }
    } else {
        for (int i = rear; i >= 0; i--) {
            printf("%d ", deque[i]);
        }
        for (int i = MAX - 1; i >= front; i--) {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int ch, item;
    while (1) {
        printf("\n1. Insertion at rear\n2. Insertion at front\n3. Delete from front\n4. Delete from rear\n5. Display1\n6. Display2\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                dqinsert_at_rear(item);
                break;
            case 2:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                dqinsert_at_front(item);
                break;
            case 3:
                dqdelete_from_front();
                break;
            case 4:
                dqdelete_from_rear();
                break;
            case 5:
                dqdisplay1();
                break;
            case 6:
                dqdisplay2();
                break;
            case 7:
                printf("\nExiting...\nThanks for using our application !!");
                exit(0);
            default:
                printf("\nWrong Input!\nPlease enter a valid input.\n");
        }
    }
    return 0;
}
