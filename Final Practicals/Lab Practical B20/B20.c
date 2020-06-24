#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev,*next;
}node;

node *createnode()
{
	int i,n;
	node *p,*head,*t;
	head=NULL;
	printf("\nEnter the no of nodes::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
		printf("\nEnter the data");
		scanf("%d",&(p->data));
		p->next=NULL;
		p->prev=NULL;
		if(head==NULL)
			head=p;
		else
		{
			t=head;
			while(t->next!=NULL)
				t=t->next;
				t->next=p;
		}
	}
return head;
}

void print(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d=>",p->data);
		p=p->next;
	}
}

node *sort(node *head)
{
	node *p;
	int i,j,temp,cnt=0;
	p=head;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	for(i=1;i<cnt;i++)
	{
		p=head;
		for(j=0;j<cnt-i;j++,p=p->next)
		if(p->data>p->next->data)
		{
			temp=p->data;
			p->data=p->next->data;
			p->next->data=temp;
		}
	}
return head;
}

node *merge(node *head,node *head1)
{
	node *p,*head3;
	if(head==NULL)
	{
		head3=head1;
		head1=NULL;
	return;
	}
	if(head1==NULL)
	{
		head3=head;
		head=NULL;
	return;
	}
	if(head->data<head1->data)
	{
		head3=p=head;
		head=head->next;
	}
	else
	{
		head3=p=head1;
		head1=head1->next;
	}
	while(head!=NULL&&head1!=NULL)
	{
		if(head->data<head1->data)
		{
			p->next=head;
			head->prev=p;
			head=head->next;
			p=p->next;
		}
		else
		{
			p->next=head1;
			head1->prev=p;
			head1=head1->next;
			p=p->next;
		}
	}
	if(head!=NULL)
	{
		p->next=head;
		head->prev=p;
	}
	if(head1!=NULL)
	{
		p->next=head1;
		head1->prev=p;
	}
	head=head1=NULL;
return head3;
}

int main()
{
	node *head,*head1,*head2;
	int ch=0;
	head=head1=NULL;
	printf("\nEnter first list::");
	head=createnode();
	printf("\nEnter second list::");
	head1=createnode();
	head=sort(head);
	head1=sort(head1);
	head2=merge(head,head1);
	printf("\nMerged Linked List::");
	print(head2);
	return 0;
}

/*
	OUTPUT :
	
Enter first list::
Enter the no of nodes::3

Enter the data12

Enter the data34

Enter the data55

Enter second list::
Enter the no of nodes::4

Enter the data1

Enter the data33

Enter the data44

Enter the data55

Merged Linked List::1=>12=>33=>34=>44=>55=>55=> 
*/
