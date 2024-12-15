#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};
struct Node *front=NULL, *rear=NULL;

void insert(int item){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Insufficient Memory!!");
        return;
    }
    temp->data=item;
    temp->link=NULL;
    if(front==NULL){
        front=temp;
    }
    else{
        rear->link=temp;
    }
    rear=temp;
}

void delete(){
    struct Node *temp;
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted item: %d\n",front->data);
    temp=front;
    front=front->link;
    if(front==NULL){
        rear=NULL;
    }
    free(temp);
    temp=NULL;
}

void display(){
    struct Node* ptr;
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    ptr=front;
    printf("Linked Queue elements are: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

int main(){
    int ch, item;
    printf("-------------Linked Queue-----------------------\n");
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter item: ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}