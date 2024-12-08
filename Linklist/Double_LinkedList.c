#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* link;
};

struct Node* start = NULL;

void dllInsertAtBegin(int value){
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Insufficient Memory !!\n");
        return;
    }
    temp->data = value;
    temp->prev = NULL;
    temp->link = start;
    if(start!=NULL){
        start->prev = temp;
    }
    start = temp;
}

void dllInsertAtEnd(int value){
    struct Node* temp, *ptr;
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Insufficient Memory !!!");
        return;
    }
    temp->data=value;
    temp->link=NULL;
    if(start==NULL){
        start=temp;
        temp->prev=NULL;
    }
    else{
        ptr=start;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
            ptr->link=temp;
            temp->prev = ptr;
	}
}

void dllInsertAtAnyPos(int pos, int value){
    struct Node* temp, *ptr;
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Insufficient Memory !!!");
        return;
    }
    temp->data=value;
    if(pos==1){
        temp->prev = NULL;
        temp->link = start;
        if(start!=NULL){
            start->prev = temp;
        }
        start = temp;
    }
    else{
        ptr=start;
        for(int i=1; i<=pos-2 && ptr!=NULL; i++){
            ptr=ptr->link;
        }
        if(ptr==NULL){
            printf("Position not found!\n");
            free(temp);
            return;
        }
        temp->prev = ptr;
        temp->link = ptr->link;
        if(ptr->link!=NULL){
            ptr->link->prev = temp;
        }
        ptr->link = temp;
    }
}

void dllDeleteAtBegin(){
    struct Node* temp;
    if(start==NULL){
        printf("Double Linklist List is empty.\n");
        return;
    }
    temp=start;
    start=start->link;
    if(start != NULL){
        start->prev = NULL; 
    }
    free(temp);
	temp=NULL;
	printf("First node deleted successfully.\n");
}

void dllDeleteAtEnd(){
    struct Node* temp, *prev;
    if(start==NULL){
        printf("Double Linklist List is empty.\n");
        return;
    }
    temp=start;
    if (temp->link == NULL) {
        start = NULL;
        free(temp);
        printf("Last node deleted successfully.\n");
        return;
    }
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
    free(temp); 
    temp=NULL;
    printf("Last node deleted successfully.\n");
}

void dllDeleteAtAnyPos(int pos){
    struct Node* ptr, *prev, *prevptr;
    if(start==NULL){
        printf("Double Linklist List is empty.\n");
        return;
    }
    ptr=start;
    if(pos==1){
        start=start->link;
        if(start!=NULL){
            start->prev=NULL;
        }
        free(ptr);
    }
    else{
        for(int i=1; i<=pos-1; i++){
            prevptr=ptr;
            ptr=ptr->link;
            if(ptr==NULL){
                printf("Position not found!\n");
                return;
            }
        }
        prevptr->link=ptr->link;
        if(ptr->link!=NULL){
            ptr->link->prev=prevptr;
        }
        free(ptr);
        ptr=NULL;
    }
}

void dllDisplay(){
	struct Node* ptr;

	if(start==NULL){
		printf("Empty Linked List !!!");
		return;
	}
	
	ptr=start;
	printf("Start <->");
	while(ptr!=NULL){
		printf(" %d <->",ptr->data);
		ptr=ptr->link;
	}
	printf(" NULL");
}

int main(void){
    printf("------------------Double Linklist------------------\n");
    while(1){
        printf("\n1. Insertion At Begin\n2. Insertion At End\n3. Insert At Any Position\n4. Delete At Begin\n5. Delete At End\n6. Delete At Any Position\n7. Display\n8. Exit\n");
        int choice, value, pos;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                dllInsertAtBegin(value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                dllInsertAtEnd(value);
                break;
            case 3:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                dllInsertAtAnyPos(pos, value);
                break;
            case 4:
                dllDeleteAtBegin();
                break;
            case 5:
                dllDeleteAtEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                dllDeleteAtAnyPos(pos);
                break;
            case 7:
                dllDisplay();
                break;
            case 8:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
