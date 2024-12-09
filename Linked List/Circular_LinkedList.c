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

void cllInsertAtAny(int pos, int item) {
    struct Node *temp, *ptr;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Insufficient Memory !!\n");
        return;
    }
    temp->data = item;
    if (pos == 1) {
        if (last == NULL) {
            last = temp;
            temp->link = temp; // Fix: Properly initialize circular link
        } else {
            temp->link = last->link;
            last->link = temp;
        }
    } else {
        if (last == NULL) {
            printf("Invalid Position !!\n");
            free(temp);
            return;
        }
        ptr = last->link;
        for (int i = 1; i < pos - 1; i++) { // Fix: Start loop from 1 and stop at pos - 1
            ptr = ptr->link;
            if (ptr == last->link) { // Loop back to starting point
                printf("Invalid Position !!\n");
                free(temp);
                return;
            }
        }
        temp->link = ptr->link;
        ptr->link = temp;
        if (ptr == last) {
            last = temp;
        }
    }
}

void cllDeleteFromBegin(){
    struct Node *ptr;
    if(last==NULL){
        printf("Circular Linked List is Empty !!\n");
        return;
    }
    ptr=last->link;
    if(last==last->link){
        last=NULL;
    }
    else{
        last->link=ptr->link;
    }
    free(ptr);
    ptr=NULL;
}

void cllDeleteFromEnd(){
    struct Node *ptr, *prevptr;
    if(last==NULL){
        printf("Circular Linked List is Empty !!\n");
        return;
    }
    ptr=last->link;
    if(last==last->link){
        last=NULL;
    }
    else{
        while(ptr!=last){
            prevptr=ptr;
            ptr=ptr->link;
        }
        prevptr->link=last->link;
        last=prevptr;
    }
    free(ptr);
    ptr=NULL;
}

void cllDeleteFromAny(int pos) {
    struct Node *ptr, *prevptr;
    ptr=last->link;
    if(pos==1){
        cllDeleteFromBegin();
    }
    else{
        for(int i=1; i<=pos-1; i++){
            prevptr=ptr;
            ptr=ptr->link;
            if(ptr==last->link){
                printf("Invalid Position!!\n");
                return;
            }
        }
        prevptr->link=last->link;
        if(ptr=last){
            last=prevptr;
        }
    }
    free(ptr);
    ptr=NULL;
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
    int ch, data, pos;
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
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("The data to the inserted: ");
                scanf("%d", &data);
                cllInsertAtAny(pos, data);
                break;
            case 4:
                cllDeleteFromBegin();
                break;
            case 5:
                cllDeleteFromEnd();
                break;
            case 6:
                printf("The position: ");
                scanf("%d", &pos);
                cllDeleteFromAny(pos);
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
