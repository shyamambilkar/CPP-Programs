#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
	
node *createnode()
{
	int i,n;
	node *p,*head,*t;
	head=NULL;
	printf("\nEnter the no of students::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
		printf("\nEnter the students::");
		scanf("%d",&(p->data));
		p->next=NULL;
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
		int cnt=0;
		p=head;
		while(p!=NULL)
		{
		printf("\t%d",p->data);
		p=p->next;
		cnt++;
		}
		printf("\nTotal no of student=%d",cnt);
	}
	int uni(node *head1,node *head2)
	{
		node *p,*q;
		int found=0,count=0;
		p=head1;
		while(p!=NULL)
		{
			printf("\t%d",p->data);
			p=p->next;
			count++;
		}
		for(q=head2;q!=NULL;q=q->next)
		{
			found=0;
			for(p=head1;p!=NULL;p=p->next)
		{
			if(q->data==p->data)
			{
			found=1;
			break;
			}
		}
		if(found!=1)
		{
		printf("\t%d",q->data);
		count++;
		}
		}
		return count;
	}
	void inter(node *head1,node *head2)
	{
		node *p,*q;
		int found=0;
		for(q=head2;q!=NULL;q=q->next)
		{
			found=0;
	for(p=head1;p!=NULL;p=p->next)
	{
		if(q->data==p->data)
		{
		found=1;
		break;
		}
	}
	if(found==1)
		printf("\t%d",q->data);
	}
	}
	void sub1(node *head1,node *head2)
	{
		node *p,*q;
		int found=0;
		for(p=head2;p!=NULL;p=p->next)
		{
		found=0;
		for(q=head2;q!=NULL;q=q->next)
		{
		if(p->next==q->data)
		{
		 found=1;
		break;
		}
	}
	if(found!=1)
		printf("\t%d",p->data);
	}
	}
void sub2(node *head1,node *head2)
{
	node *p,*q;
	int found=0;
	for(q=head2;q!=NULL;q=q->next)
	{
		found=0;
		for(p=head1;p!=NULL;p=p->next)
		{
		if(q->data==p->data)
	{
		found=1;
		break;
	}
	}
	if(found!=1)
		printf("\t%d",q->data);
	}
	}
	int main()
	{
		node *head,*head1;
		int ch=0,ele,loc,m,count;
		head=head1=NULL;
		printf("\nEnter the total no. of students::");
		scanf("%d",&m);
		head=NULL;
	while(ch!=8)
	{
	printf("\n*******Sets using SLL*******\n");
	printf("\n1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch");
	printf("\n5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch");
	printf("8.Exit\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("\n*****Students who like vanilla****\n");
		head=createnode();
		printf("\n*****Students who like butterscotch***\n");
		head1=createnode();
		break;
		case 2:
			printf("\n****Student who like vanilla****\n");
		print(head);
		printf("\n****Students who like butterscotch***\n");
		printf(head1);
		break;
		case 3:
		printf("\n***Students who like either vanilla or butterscotch***\n");
		inter(head,head1);
		break;
		case 4:
			printf("\n***Students who like both vanilla and butterscotch***\n");
			inter(head,head1);
			break;
		case 5:
			printf("\n****Students who like only vanilla***\n");
			sub1(head,head1);
			break;
		case 6:
			printf("\n****Students who like only butterscotch***\n");
			sub1(head,head1);
			break;
		case 7:
			printf("\nNumber of students like nither vanilla nor butterscotch=%d",m-count);
			break;
		}
	}
	return 0;
	}
	
