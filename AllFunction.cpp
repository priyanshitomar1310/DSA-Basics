#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}list;
list* create_node()
{
	list* newnode;
	newnode=(list*)malloc(sizeof(list));
	newnode->next=0;
	printf("Enter the data");
	scanf("%d",&newnode->data);
	return newnode;
}
list* add_begin(list* head)
{
	list * newnode;
	newnode=create_node();
	newnode->next=head;
	head=newnode;
	return head;
}
list * add_end(list * head)
{
	list *newnode,*temp;
	newnode=create_node();
	if(head==0)
	{
		head=newnode;
		return head;
	}
	temp=head;
	while(temp->next!=0)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	return head;
}
list *delete_begin(list* head)
{
	list * temp;
	if(head==0)
	{
		printf("List does not exist");
		return 0;
	}
	temp=head;
	head=head->next;
	printf("Deleting data is   %d",temp->data);
	free(temp);
	return head;	
}
list * delete_end(list* head)
{
	list * temp;
	if(head==0)
	{
		printf("List does not exist");
		return 0;
	}
	if(head->next==0)
	{
		printf("\nDeleting data is  %d",head->data);
		free(head);
		return 0;
	}
	temp=head;
	while(temp->next->next!=0)
	{
		temp=temp->next;
	}
	printf("\nDeleting data is %d ",temp->next->data);
	temp->next=0;
	return head;	
}
void display_list(list* head)
{
	if(head==0)
	{
		printf("List doesn't exist");
		return;
	}
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}
int main()
{
	list * Head=0;
	int choice;
	while(1)
	{
		printf("\nEnter 1 to add a node at beginning\n 2 delete node from beginning \n 3 to display \n 4 to add last");
		printf("\n 5 to delete at end\n 6 to exit");
		printf("\n Enter your choice");
		scanf("%d",&choice);
	  	switch(choice)
	{
		case 1:
			{
				Head=add_begin(Head);
				break;
			}
		case 2:
			{
				Head=delete_begin(Head);
				break;
			}
		case 3:
			{
				display_list(Head);
				break;
			}
		case 4:
			{
				Head=add_end(Head);
				break;
			}
		case 5:
			{
				Head=delete_end(Head);
				break;
			}		
		default:
			{
				printf("Not a valid choice better luck next time");
				exit(0);
			}
					
	}	
	}

}
