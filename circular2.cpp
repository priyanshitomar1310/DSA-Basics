#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}cl;
cl * makenode()
{
	cl *newnode=(cl*)malloc(sizeof(cl));
	newnode->next=NULL;
	printf("\nEnter data");
	scanf("%d",&newnode->data);
	return newnode;	
}
cl *add_first(cl *head)
{
	cl *t,*newnode;
	newnode=makenode();
	if(head==NULL)
	{
		newnode->next=newnode;
		return newnode;
	}
	t=head;
	while(t->next!=head)
	{
		t=t->next;
	}
	t->next=newnode;
	newnode->next=head;
	return newnode;	
}
cl * delete_begin(cl *head)
{
	cl *t,*p;
	if(head==NULL)
	{
		printf("\nList is already empty");
		return head;
	}
	if(head->next==head)
	{
		printf("\nDeleting data is %d ",head->data);
		free(head);
		return 0;
	}
	t=head;
	while(t->next!=head)
	{
		t=t->next;
	}
	p=head;
	head=head->next;
	t->next=head;
	printf("\nDeleting data is %d ",p->data);
	free(p);
	return head;	
}
cl *add_last(cl *head)
{
	cl *temp,*newnode;
	newnode=makenode();
	if(head==NULL)
	{
		newnode->next=newnode;
		return newnode;
	}
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	newnode->next=head;
	temp->next=newnode;
	return head;
}
cl *delete_last(cl *head)
{
	cl *temp,*p;
	if(head==NULL)
	{
		printf("\nList is already empty");
		return head;
	}
	if (head->next == head)
	{
		printf("\nDeleting data is %d ", head->data);
		free(head);
		return NULL;
	}
	temp=head;
	while(temp->next->next!=head)
	{
		temp=temp->next;
	}
	p=temp->next;
	temp->next=head;
	printf("\nDeleting data is %d ",p->data);
	free(p);
	return head;
}
 void display_list(cl *head)
{
	cl *temp;
	if(head==NULL)
	{
		printf("\nList is already empty");
		return ;
	}
	temp=head;
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp->next!=head);
}
int main()
{
	cl *Head=NULL;
	int choice;
	while(1)
	{
		printf("\n1 to add first\n2 to delete first\n3 to add last\n4 to delete last\n5 dispaly");
		printf("\nEnter choice");
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
			    	Head=delete_begin(Head);
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
			    	printf("\nBetter luck next time");
			    	exit(0);
				}		
		}
	}
}
