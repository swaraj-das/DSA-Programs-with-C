#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};
struct Node *start=NULL;

void InsertItem(int item){
    struct Node *temp, *ptr;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=item;
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

void reverseList(){
    struct Node *curr, *prev=NULL, *next=NULL;
    curr=start;
    if (start==NULL){
        printf("The Linked List is empty.\n");
        return;
    }
    while(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
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
        printf("\nSingle Linked List Menu:\n1. Insert Item\n2. Reverse Linked List\n3. Display\n4. Exit\n");
        printf("The Choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter item at the end of the Single Linked List: ");
                scanf("%d",&item);
                InsertItem(item);
                break;
            case 2:
                reverseList();
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
    