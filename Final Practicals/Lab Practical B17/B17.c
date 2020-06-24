/*
	Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked list. compute and display-
	vi. Set of students who like either vanilla or butterscotch or both
	vii. Set of students who like both vanilla and butterscotch
	viii. Set of students who like only vanilla not butterscotch
	ix. Set of students who like only butterscotch not vanilla
	x. Set of students who like neither vanilla nor butterscotch 
*/
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
		for(p=head1;p!=NULL;p=p->next)
		{
		found=0;
		for(q=head2;q!=NULL;q=q->next)
		{
		if(p->data==q->data)
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
		print(head1);
		break;
		case 3:
		printf("\n***Students who like either vanilla or butterscotch***\n");
		count=uni(head,head1);
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
			sub2(head,head1);
			break;
		case 7:
			printf("\nNumber of students like nither vanilla nor butterscotch=%d",m-count);
			break;
		}
	}
	return 0;
	}
	
	/*
		OUTPUT :
		
Enter the total no. of students::4

*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice1

*****Students who like vanilla****

Enter the no of students::3

Enter the students::2

Enter the students::1

Enter the students::3

*****Students who like butterscotch***

Enter the no of students::2

Enter the students::1

Enter the students::2

*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice2

****Student who like vanilla****
        2       1       3
Total no of student=3
****Students who like butterscotch***
        1       2
Total no of student=2
*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice3

***Students who like either vanilla or butterscotch***
        2       1       3
*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice4

***Students who like both vanilla and butterscotch***
        1       2
*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice5

****Students who like only vanilla***
        3
*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice6

****Students who like only butterscotch***

*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice7

Number of students like nither vanilla nor butterscotch=1
*******Sets using SLL*******

1.Create 2. Print 3.Like either vanilla or butterscotch 4.Like both vanilla & butterscotch
5.Like vanilla only 6. Like butterscotch only 7.Like nither vanilla nor butterscotch8.Exit
Enter your choice 
	*/
