
#include<iostream>
//#include<process>
using namespace std;
#define size 5
struct queue
{
	int que[size];
	int front,rear;
}Q;
	
class DeQue
{
	public:
		DeQue();
		int Qfull();
		int Qempty();
		int insert_rear(int item);
		int delete_front();
		int insert_front(int item);
		int delete_rear();
		void display();
};

DeQue::DeQue()
{
	Q.front=-1;
	Q.rear=-1;
	for(int i=0;i<size;i++)
		Q.que[i]=-1;
}

int DeQue::Qfull()
{
	if(Q.rear==size-1)
		return 1;
	else
		return 0;
}

int DeQue::Qempty()
{
	if((Q.front>Q.rear)||(Q.front==-1&&Q.rear==-1))
		return 1;
	else
		return 0;
}

int DeQue::insert_rear(int item)
{
	if(Q.front==-1 && Q.rear==-1)
		Q.front++;
		Q.que[++Q.rear]=item;
		return Q.rear;
}

int DeQue::delete_front()
{
	int item;
	if(Q.front==-1)
		Q.front++;
		item=Q.que[Q.front];
		Q.que[Q.front]=-1;
		Q.front++;
		return item;
}

int DeQue::insert_front(int item)
{
	int i,j;
	if(Q.front==-1)
		Q.front++;
		i=Q.front-1;
		while(i>=0)
		{
			Q.que[i+1]=Q.que[i];
			i--;
		}
	i=Q.rear;
	while(j>=Q.front)
	{
		Q.que[i+1]=Q.que[j];
		j--;
	}
	Q.rear++;
	Q.que[Q.front]=item;
	return Q.front;
}

int DeQue::delete_rear()
{
	int item;
	item=Q.que[Q.rear];
	Q.que[Q.rear]=-1; //logical deletion
	Q.rear--;
	return item;
}

void DeQue::display()
{
	int i;
	cout<<"\nStrength Queue is ::\n";
	for(i=Q.front;i<=Q.rear;i++)
		cout<<""<<Q.que[i];
}

int main()
{
	int choice,item;
	char ans;
	ans='y';
	DeQue obj;
	cout<<"\n\t\t Program for simulation of doubly ended queues using arrays ::";
	do
	{
		cout<<"\n1.Insert by rear\n2.Delete by front\n3.Insert by front\n4.Delete by rear";
		cout<<"\n5.display\n6.Exit";
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(obj.Qfull())
					cout<<"\nDoubly ended Queue is full";
				else
				{
					cout<<"\nEnter the item to be inserted";
					cin>>item;
					Q.rear=obj.insert_rear(item);
				}
			break;
			case 2:
				if(obj.Qempty())
					cout<<"\nDoubly ended queue is Empty";
				else
				{
					item=obj.delete_front();
					cout<<"\nThe item deleted from queue is"<<item;
				}
			break;
			case 3:
				if(obj.Qfull())
					cout<<"\n Doubly link queued is full";
				else
				{
					cout<<"\nEnter the item to be inserted::";
					cin>>item;
					Q.front=obj.insert_front(item);
				}
			break;
			case 4:
				if(obj.Qempty())
					cout<<"\nDoubly ended Queue is empty::";
				else
				{
					item=obj.delete_rear();
					cout<<"\nThe item deleted from queue is"<<item;
				}
			break;
			case 5:
				obj.display();
			break;
			case 6:
				exit(0);
		}
		cout<<"\nDo you want to continue?";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}
