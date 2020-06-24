#include<iostream>
using namespace std;
#define size 5
class JobQue
{
	private:
		struct queue
		{
			int que[size];
			int front,rear;
		}Q;
	public:
		JobQue();
		int Qfull();
		int insert(int);
		int Qempty();
		int delet();
		void display();
};

JobQue::JobQue() //initilization the job queue
{
	Q.front=-1; //-1indicates is it empty
	Q.rear=-1;
}

int JobQue::Qfull()
{
	if(Q.rear>=size-1)
		return 1;
	else
		return 0;
}

//The insert functiom

int JobQue::insert(int item)
{
	if(Q.front==-1)
		Q.front++;
		Q.que[++Q.rear]=item;
	return Q.rear;
}

int JobQue::Qempty()
{
	if((Q.front==-1)||(Q.front<Q.rear))
		return 1;
	else
		return 0;
}

//The delete function

int JobQue::delet()
{
	int item;
	item=Q.que[Q.front];
	Q.front++;
	cout<<"\nThe deleted job is ::"<<item;
	return Q.front;
}

void JobQue::display()
{
	int i;
	for(i=Q.front;i<=Q.rear;i++)
		cout<<""<<Q.que[i];
}

int main()
{
	int choice,item,i;
	char ans;
	JobQue obj;
	do
	{
		cout<<"\nMain Menu ::";
		cout<<"\n1.Add Job\n2.Delete Job\n3. Display Job Queue";
		cout<<"\nEnter your choice::";
		cin>>choice;
		switch(choice)		{
			case 1:
				if(obj.Qfull())  //Checking for queue overflow
					cout<<"\n Can not insert the job::";
				else
				{
					cout<<"\nEnter the job number :::";
					cin>>item;
					obj.insert(item);
				}
			break;
			case 2:
				
			if(obj.Qempty())
			cout<<"\nQueue Underflow ::";
					
			else	
			obj.delet();
				
			break;
			
			case 3:
			if(obj.insert(item))
			obj.display();
			cout<<"\ninsert element is:"<<item;
			
			break ;
			default:
				cout<<"\nWrong Choice::";
			break;

		}
		cout<<"\nDo you want to  continue?";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
return 0;

}
