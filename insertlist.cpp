#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node*next;
};
void push(struct node**head,int data)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void printlist(struct node*head)
{
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}
void insertmiddle(struct node* prevnode, int newdata)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=prevnode->next;
	prevnode->next=newnode;	
}
void insertend(struct node** head,int newdata)
{ 
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=NULL;
	struct node *last = *head;
	if(*head==NULL)
	{
		*head=newnode;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=newnode;	
}
void deletelist(struct node**head,int key)
{
	struct node *temp=*head, *prev;
	if(temp->data==key)
	{
		*head=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}	
	if(temp==NULL)	
		return;
	prev->next=temp->next;
	free(temp);
}
void deleteatpos(struct node **head,int position)
{
	struct node *prev;
	struct node *temp=*head;
	if(position==0)
	{
		*head=temp->next;
		free(temp);
		return;
	}
	for(int i=0;i<position;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);	
}
int main()
{
	struct node*head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,8);
	insertend(&head,7);
	insertmiddle(head->next->next,3);
	printlist(head);
	deletelist(&head,3);
	deleteatpos(&head,3);
	printlist(head);
	return 0;
}
