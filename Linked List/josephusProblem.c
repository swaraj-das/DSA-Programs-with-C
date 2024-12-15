#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

int main(){
    int nodes, num;
    printf("------------Josephus Problem--------------------");
    printf("\nEnter the number of nodes: ");
    scanf("%d",&nodes);
    printf("\nEnter a positive number: ");
    scanf("%d",&num);

    struct Node *temp, *ptr;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=1;
    ptr=temp;

    for(int i=2; i<=nodes; i++){
        temp->link=(struct Node*)malloc(sizeof(struct Node));
        temp=temp->link;
        temp->data=i;
    }
    temp->link=ptr;

    while(temp!=temp->link){
        for(int i=1; i<num; i++){
            temp=temp->link;
        }
        printf("Deleting ...%d\n",temp->link->data);
        ptr=temp->link;
		temp->link=ptr->link;	
		free(ptr);
		ptr=NULL;
    }
    printf("\nThe last man standing is: %d",temp->data);
    return 0;
}