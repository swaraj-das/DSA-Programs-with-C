#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* link;
};

struct Node* insertPoly(struct Node* start){
    int n, a, b;
    struct Node* temp, *ptr;
    temp=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the number of terms or nodes: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        printf("Enter coefficient of term %d: ", i);
        scanf("%d", &a);
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &b);
        temp->coeff=a;
        temp->exp=b;
        if(start==NULL){
            temp->link=start;
            start=temp;
        }
        else{
            ptr=start;
            while(ptr->link!=NULL){
                ptr=ptr->link;
            }
            temp->link=ptr->link;
            ptr->link=temp;
        }
    }
    return start;
}

void addPoly(struct Node *p, struct Node *q){
    struct Node *start=NULL, *temp, *ptr;
    while(p!=NULL && q!=NULL){
        if(p->exp > q->exp){
            temp=(struct Node*)malloc(sizeof(struct Node));
            temp->coeff=p->coeff;
            temp->exp=p->exp;
            temp->link=NULL;
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
            p=p->link;
        }
        else if(p->exp < q->exp){
            temp=(struct Node*)malloc(sizeof(struct Node));
            temp->coeff=q->coeff;
            temp->exp=q->exp;
            temp->link=NULL;
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
            q=q->link;
        }
        else if(p->exp == q->exp){
            temp=(struct Node*)malloc(sizeof(struct Node));
            temp->coeff=p->coeff + q->coeff;
            temp->exp=p->exp;
            temp->link=NULL;
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
            p=p->link;
            q=q->link;
        }
    }
}

int main(void){
    int ch;
    struct Node* start1 = NULL, *start2 = NULL, *result = NULL;
    printf("\n-----------Polynomial Addition--------------------\n");
    do{
        printf("\nMenu:\n1. Insert 1st Polynomial\n2. Insert 2nd Polynomial\n3. Addition of 1st & 2nd polynomial\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                start1=insertPoly(start1);
                break;
            case 2:
                start2=insertPoly(start2);
                break;
            case 3:
                addPoly(start1, start2);
                break;
            case 4:
                displayPoly();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(1);
    return 0;
}