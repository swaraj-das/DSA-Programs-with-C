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
		return ;
	}
	temp->data = item;
	temp->link = start; 
	start=temp;
	
}
void sllDisplay(){
	
	struct node * ptr;
	if(start==NULL){
		printf("Empty Linked List !!!");
		return;
	}
	
	ptr=start;
	printf("Start->");
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("NULL");
	
}
int main(void){
	int ch,item;
	do{
		
		printf("\n1.Insert at begin\n");
		printf("2.Display\n");
		
		printf("Enter your choice:");
		scanf("%d",&ch);
		
		switch(ch){
			
			case 1:
                printf("Enter the item :");
                scanf("%d",&item);
                sllInsertAtBegin(item);
                break;
			case 2:
                sllDisplay();
                break;
            default:
				printf("Wrong option !!!");
		}
	}while(1);
		
	return 0;
}


