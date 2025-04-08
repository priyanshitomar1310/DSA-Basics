#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *prev,*next;
}dl;
dl * create_node()
{
	dl *newnode;
	newnode=(dl*)malloc(sizeof(dl));
	newnode->prev=newnode->next=NULL;
	printf("\nEnter the data");
	scanf("%d",&newnode->data);
	return newnode;
}
dl *add_first(dl *head)
{
	dl *newnode;
	newnode=create_node();
	newnode->next=head;
	if(head!=NULL)
	{
		head->prev=newnode;
	}
	head=newnode;
	return head;
}
dl *add_last(dl *head)
{
	dl *newnode,*temp;
	newnode=create_node();
	if(head==NULL)
	{
		head=newnode;
		return head;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	return head;
}
dl *delete_first(dl *head)
{
	dl *temp;
	if(head==NULL)
	{
		printf("\nList doesn't exist");
		return head;
	}
	temp=head;
	head=head->next;
	if(head!=NULL)
	{
		head->prev=0;
	}
	printf("\nDeleting data is %d ",temp->data);
	free(temp);
	return head;
}
dl *delete_last(dl *head)
{
	dl *temp,*prev;
	if(head==NULL)
	{
		printf("\nList doesn't exist");
		return head;
	}
	if(head->next==NULL)
	{
		printf("\nDeleting data is %d ",head->data);
		free(head);
		return 0;
	}
	prev=head;
	while(prev->next->next!=NULL)
	{
		prev=prev->next;
	}
	temp=prev->next;
	prev->next=NULL;
	printf("\nDeleting data is %d",temp->data);
	temp->prev=NULL;
	free(temp);
	return head;
}
void display_list(dl *head)
{
	if(head==0)
	{
		printf("List doesn't exist");
		return ;
	}
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}
int main()
{
	dl *Head=0;
	int choice;
	while(1)
	{
		printf("\n1 to add at beginning\n2to delete first\n3 to add last\n4 to delete last\n5 to dispaly\n 6 to exit");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					Head=add_first(Head);
					break;
				}
			case 2:
			{
			     Head=delete_first(Head);
				 break;
				 	
			}
			case 3:
			{
			   Head=add_last(Head);	
			   break;	
			}
			case 4:
			{
			   Head=delete_last(Head);	
			   break;	
			}
			case 5:
			{
				display_list(Head);
				break;
			}
			default:
			{
			   printf("\nNot a valid choice to perform operation");
			   exit(0);	
			}	
		}
	}
}
