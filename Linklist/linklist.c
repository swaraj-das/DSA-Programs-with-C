#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* start=NULL;
                      
void sllInsertAtBegin(int item){	
	struct node* temp; 
	
	temp =(struct node*) malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Insufficient Memory !!!");
		return;
	}

	temp->data = item;
	temp->link = start; 
	start=temp;	
}

void sllInsertAtEnd(int item){
	struct node* temp, *ptr;
	temp=(struct node*) malloc(sizeof(struct node));
	if(temp==NULL){
        printf("Insufficient Memory !!!");
        return;
    }
	temp->data = item;
	temp->link = NULL;

	if(start==NULL){
        start=temp;
    }
	else{
		ptr=start;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=temp;
	}
}

void sllInsertAtanyPos(int pos, int item){
	struct node* temp, *ptr;
	temp=(struct node*) malloc(sizeof(struct node));
	if(temp==NULL){
        printf("Insufficient Memory !!!");
        return;
    }
	temp->data = item;
	if(pos==1){
		temp->link = start; 
		start=temp;	
	}
	else{
		ptr=start;
		for(int i=1; i<=pos-2 && ptr!=NULL; i++){
			ptr=ptr->link;
		}
		if(ptr==NULL){
			printf("Invalid Position !!!!");

			free(temp);
			temp=NULL;	
			return;		
		}
		temp->link=ptr->link; 
		ptr->link=temp;
	}
}

void sllDisplay(){
	struct node* ptr;

	if(start==NULL){
		printf("Empty Linked List !!!");
		return;
	}
	
	ptr=start;
	printf("Start->");
	while(ptr!=NULL){
		printf(" %d ->",ptr->data);
		ptr=ptr->link;
	}
	printf(" NULL");
}
int main(void){
	int ch, item, pos;
	printf("------------Singly Linked List Operations: --------------\n");
	while(1){
		printf("\n1. Insert at begin\n");
		printf("2. Insert at end\n");
		printf("3. Insert at specific position\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
                printf("Enter the item : ");
                scanf("%d",&item);
                sllInsertAtBegin(item);
                break;
			case 2:
                printf("Enter the item : ");
                scanf("%d",&item);
                sllInsertAtEnd(item);
                break;
			case 3:
			    printf("Enter the position : ");
				scanf("%d",&pos);
				printf("Enter the item : ");
                scanf("%d",&item);
                sllInsertAtanyPos(pos, item);
				break;
			case 4:
                sllDisplay();
                break;
			case 5:
				printf("Thank you for using !! Bye.");
				exit(0);
            default:
				printf("Wrong option !!! Please select a valid option\n");
		}
	}
		
	return 0;
}
