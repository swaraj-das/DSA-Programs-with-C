#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root=NULL;

struct Node* createBST(struct Node* root, int item){
    struct Node *temp, *parent=NULL, *ptr;
    ptr=root;
    while(ptr!=NULL){
        parent=ptr;
        if(ptr->data>item){
            ptr=ptr->lchild;
        }
        else if(ptr->data<item){
            ptr=ptr->rchild;
        }
    }
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Insufficient memory!\n");
        return;
    }
    temp->data=item;
    temp->lchild=NULL;
    temp->rchild=NULL;
    if(parent==NULL){
        root=temp;
    }
    else if(item<parent->data){
        parent->lchild=temp;
    }
    else{
        parent->rchild=temp;
    }
}

int main(){
    int choice, item;
    printf("------------Non-Recursive Binary Search Tree--------------------\n");
    while(1){
        printf("1. Create binary search tree\n");
        printf("2. Pre-order Traversal\n");
        printf("3. In-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data in the tree: ");
                scanf("%d",&item);
                root=createBST(root, item);
                break;
            case 2:
                printf("Pre-order traversal of binary search tree is: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("In-order traversal of binary search tree is: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal of binary search tree is: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}