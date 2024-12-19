#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node* createBST(struct Node *ptr, int item){
    if(ptr==NULL){
        ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->data=item;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
    }
    else if(ptr->data>=item){
        ptr->lchild=createBST(ptr->lchild,item);
    }
    else if(ptr->data<item){
        ptr->rchild=createBST(ptr->rchild,item);
    }
    return ptr;
}

void preOrder(struct Node *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->data);
        preOrder(ptr->lchild);
        preOrder(ptr->rchild);
    }
}

void inOrder(struct Node *ptr){
    if(ptr!=NULL){
        inOrder(ptr->lchild);
        printf("%d ",ptr->data);
        inOrder(ptr->rchild);
    }
}

void postOrder(struct Node *ptr){
    if(ptr!=NULL){
        postOrder(ptr->lchild);
        postOrder(ptr->rchild);
        printf("%d ",ptr->data);
    }
}

int main(void){
    int ch, value;
    struct Node *root=NULL;
    printf("--------------------Binary Search Tree Creation with Recursion--------------------------\n");
    while(1){
        printf("1. Create binary search tree\n");
        printf("2. Pre-order Traversal\n");
        printf("3. In-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter data in the tree: ");
                scanf("%d",&value);
                root=createBST(root, value);
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