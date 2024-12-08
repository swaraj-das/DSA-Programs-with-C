#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node *last=NULL;
void cllInsertAtBegin(int item){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Insufficient Memory !!");
        return;
    }
    temp->data=item;
    if(last==NULL){
        last=temp;
    }
    else{
        temp->link=last->link;
    }
    last->link=temp;
}

void cllInsertAtEnd(int item){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Insufficient Memory !!");
        return;
    }
    temp->data=item;
    if(last==NULL){
        temp->link=temp;
    }
    else{
        temp->link=last->link;
        last->link=temp;
    }
    last=temp;
}

void cllDisplay(){
    struct Node *ptr;
    if(last==NULL){
        printf("Empty Circular LinkList\n");
        return;
    }
    ptr=last->link;
    while(ptr!=last){
        printf("%d -> ",ptr->data);
        ptr=ptr->link;
    }
    printf(" %d",last->data);
}

int main(void){
    printf("\n---------Circular LinkList-----------\n");
    int ch, data;
    while(1){
        printf("\n1. Insert at Begin");
        printf("\n2. Insert at End");
        printf("\n3. Insert at any Position");
        printf("\n4. Delete from Begin");
        printf("\n5. Delete from End");
        printf("\n6. Delete from any Position");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("The data to the inserted: ");
                scanf("%d", &data);
                cllInsertAtBegin(data);
                break;
            case 2:
                printf("The data to the inserted: ");
                scanf("%d", &data);
                cllInsertAtEnd(data);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cllDisplay();
                break;
            case 8:
                printf("Exiting...");
                exit(0);
                break;
        }
    }
    return 0;
}
