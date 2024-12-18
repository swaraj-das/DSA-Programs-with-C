#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start = NULL;

void sllInsertAtBegin(int item)
{
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient Memory !!!");
		return;
	}

	temp->data = item;
	temp->link = start;
	start = temp;
}

void sllInsertAtEnd(int item)
{
	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient Memory !!!");
		return;
	}
	temp->data = item;
	temp->link = NULL;

	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = temp;
	}
}

void sllInsertAtanyPos(int pos, int item)
{
	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient Memory !!!");
		return;
	}
	temp->data = item;
	if (pos == 1)
	{
		temp->link = start;
		start = temp;
	}
	else
	{
		ptr = start;
		for (int i = 1; i <= pos - 2 && ptr != NULL; i++)
		{
			ptr = ptr->link;
		}
		if (ptr == NULL)
		{
			printf("Invalid Position !!!!");

			free(temp);
			temp = NULL;
			return;
		}
		temp->link = ptr->link;
		ptr->link = temp;
	}
}

void sllDeleteAtBegin()
{
	struct node *temp;
	if (start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	temp = start;
	start = start->link;
	free(temp);
	temp = NULL;
	printf("First node deleted successfully.\n");
}

void sllDeleteAtEnd()
{
	struct node *temp, *prev;
	if (start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	temp = start;
	while (temp->link != NULL)
	{
		prev = temp;
		temp = temp->link;
	}
	prev->link = NULL;
	free(temp);
	temp = NULL;
	printf("Last node deleted successfully.\n");
}

void sllDeleteAtanyPos(int pos)
{
	struct node *temp, *prev;
	if (start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	temp = start;
	if (pos == 1)
	{
		start = start->link;
		free(temp);
		temp = NULL;
		printf("First node deleted successfully.\n");
		return;
	}
	for (int i = 1; i <= pos - 2 && temp != NULL; i++)
	{
		prev = temp;
		temp = temp->link;
	}
	if (temp == NULL)
	{
		printf("Invalid Position!!!");
		return;
	}
	prev->link = temp->link;
	free(temp);
	temp = NULL;
	printf("Node deleted successfully at position %d.\n", pos);
}

void sllDisplay()
{
	struct node *ptr;

	if (start == NULL)
	{
		printf("Empty Linked List !!!");
		return;
	}

	ptr = start;
	printf("Start->");
	while (ptr != NULL)
	{
		printf(" %d ->", ptr->data);
		ptr = ptr->link;
	}
	printf(" NULL");
}

void FindMaxMin()
{
	struct node *ptr;
	int max, min;
	max = min = start->data;
	ptr = start->link;
	if (start == NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		while (ptr != NULL)
		{
			if (max < ptr->data)
			{
				max = ptr->data;
			}
			else if (min > ptr->data)
			{
				min = ptr->data;
			}
			ptr = ptr->link;
		}
	}
	printf("Maximum value: %d\n", max);
	printf("Minimum value: %d\n", min);
}

int CountNodes()
{
	struct node *ptr;
	int count = 0;
	if (start == NULL)
	{
		return 0;
	}
	ptr = start;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	return count;
}

void DeleteValuesGreaterThanX(int item){
	if(start==NULL){
		printf("No node to delete...");
	    return;
	}
	struct node *ptr, *prev;
	ptr=start;
	while(ptr!=NULL){
		if(start->data>item){
			printf("Deleting %d\n", start->data);
			start=start->link;
			free(ptr);
			ptr=start;
		}
		else if(ptr->data>item){
			printf("Deleting %d\n", ptr->data);
			prev->link=ptr->link;
            free(ptr);
            ptr=prev->link;
		}
		else{
			prev=ptr;
            ptr=ptr->link;
		}
	}
}

int main(void)
{
	int ch, item, pos;
	printf("------------Singly Linked List Operations: --------------\n");
	while (1)
	{
		printf("\n1. Insert at begin\n");
		printf("2. Insert at end\n");
		printf("3. Insert at specific position\n");
		printf("4. Delete at begin\n");
		printf("5. Delete at end\n");
		printf("6. Delete at specific position\n");
		printf("7. Display\n");
		printf("8. Find Max & Min Value\n");
		printf("9. Count the Nodes\n");
		printf("10. Delete values greater than x\n");
		printf("11. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("Enter the item : ");
			scanf("%d", &item);
			sllInsertAtBegin(item);
			break;
		case 2:
			printf("Enter the item : ");
			scanf("%d", &item);
			sllInsertAtEnd(item);
			break;
		case 3:
			printf("Enter the position : ");
			scanf("%d", &pos);
			printf("Enter the item : ");
			scanf("%d", &item);
			sllInsertAtanyPos(pos, item);
			break;
		case 4:
			sllDeleteAtBegin();
			break;
		case 5:
			sllDeleteAtEnd();
			break;
		case 6:
			printf("Enter the position : ");
			scanf("%d", &pos);
			sllDeleteAtanyPos(pos);
			break;
		case 7:
			sllDisplay();
			break;
		case 8:
			FindMaxMin();
			break;
		case 9:
			printf("The Number of Nodes: %d", CountNodes());
			break;
		case 10:
			printf("Enter the value: ");
			scanf("%d", &item);
			DeleteValuesGreaterThanX(item);
			break;
		case 11:
			printf("Thank you for using !! Bye.");
			exit(0);
		default:
			printf("Wrong option !!! Please select a valid option\n");
		}
	}

	return 0;
}
