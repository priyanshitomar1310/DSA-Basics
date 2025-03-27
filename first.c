#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}lt;

lt * makenode()
{
    lt* p;
    p=(lt*)malloc(sizeof(lt));
    p->next=0;
    printf("enter the data ");
    scanf("%d",&p->data);
    return p;
}

lt* addfirst(lt *head)
{
    lt*p;
    p=makenode();
    p->next= head;
    return p;
}

lt* delfirst(lt *head)
{
    lt * t;
    if( head==0)
    {
        printf("List does not exist ");
        return head;
    }
    t=head;
    head=head->next;
    printf("deleting data is %d \n",t->data);
    free(t);
    return head;
}

void display (lt* head )
{
    if(head==0)
    {
        printf("List doesn't exist ");
        return ;
    }
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    
}

int main() {
    lt *Head=NULL;
    int ch;
    while(1)
    {
        printf("\nenter 1 to Add first");
        printf("\n enter 2 to delete first");
        printf("\n enter 3 to display ");
        printf("\n enter 4 to exit");
        printf("enter choices ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
            {
                Head= addfirst(Head);
                break;
            }
            case 2: 
            {
                Head=delfirst(Head);
                break;
            }
            case 3:
            {
                display(Head);
                break;
            }
            default:
            printf(" Thanks a lot");
            exit(0);
        }
    }
    
    return 0;
}
