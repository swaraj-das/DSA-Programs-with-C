#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};
struct Node* start = NULL;
void InsertItem(int data){
    struct Node *temp, *ptr;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;
    if(temp==NULL){
        printf("Insufficient Memory!!");
        return;
    }
    else{
        if(start==NULL){
            start=temp;
        }
        else{
            ptr=start;
            while(ptr->link!=NULL){
                ptr=ptr->link;
            }
            ptr->link=temp;
        }
    }
    printf("%d inserted successfully!\n", temp->data);
}

void bubbleSort(){
    struct Node *ptr, *lptr=NULL;
    if(start==NULL){
        printf("The Linked List is empty.\n");
        return;
    }
    int swapped;
    do{
        swapped=0;
        ptr=start;
        while(ptr->link!=lptr){
            if(ptr->data > ptr->link->data){
                int temp=ptr->data;
                ptr->data=ptr->link->data;
                ptr->link->data=temp;
                swapped=1;
            }
            ptr=ptr->link;
        }
        lptr=ptr;
    }while(swapped);
}

void display(){
    struct Node *ptr;
    if(start==NULL){
        printf("Empty Single Linked List\n");
        return;
    }
    ptr=start;
    printf("Start ->");
    while(ptr!=NULL){
        printf(" %d ->", ptr->data);
        ptr=ptr->link;
    }
    printf(" NULL");
}

int main(){
    int item, ch;
    while(1){
        printf("\nSingle Linked List Menu:\n1. Insert Item\n2. Sort Linked List\n3. Display\n4. Exit\n");
        printf("The Choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter item at the end of the Single Linked List: ");
                scanf("%d",&item);
                InsertItem(item);
                break;
            case 2:
                bubbleSort();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice !!");
        }
    }
    return 0;
}