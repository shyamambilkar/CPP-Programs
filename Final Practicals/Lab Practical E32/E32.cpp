/*
	a) Write C++ program to store roll numbers of student in array who attended training program in random order. Write function for searching whether particular student attended training program or not using linear search and sentinel search.
	b) Write C++ program to store roll numbers of student array who attended training program in sorted order. Write function for searching whether particular student attended training program or not using binary search 
*/
#include<iostream>
using namespace std;
#define N 10

int SentinelSearch(int A[N+1],int nmax,int s)
{
	int i;
	A[nmax]=s;
	i=0;
	while(A[i]!=s)
		i++;
	A[nmax]=-1;
	if(i!=nmax)
		return 1;
	else
		return 0;
}

int LinearSearch(int A[N],int nmax,int s)
{
	for(int i=0;i<nmax;i++)
	{
		if(A[i]==s)
			return 1;
	}
return 0;
}

int binsearch(int A[N],int x,int low,int high)
{
	int mid;
	if(low>high)
		return(-1);
		mid=(low+high)/2;
	if(x==A[mid])
		binsearch(A,x,low,mid-1);
	else if(x<A[mid])
		binsearch(A,x,low,mid-1);
	else
		binsearch(A,x,mid+1,high);
return 0;
}

int Fib(int n)
{
	int a,b,f;
	if(n<1)
		return n;
	a=0;b=1;
	while(b<n)
	{
		f=a+b;
		a=b;
		b=f;
	}
	return a;
}

void Fibsearch(int A[N],int n,int key,int f,int b,int a)
{
	if(f<1||f>n)
		cout<<"\n The Students has not attended the training program::";
	else if(key<A[f-1])
	{
		if(a<=0)
			cout<<"\nThe students has not attended the training program::";
		else
			Fibsearch(A,n,key,f-a,a,b-a);
	}
	else if(key>A[f])
	{
		if(b<=1)
			cout<<"\nThe student has not attended the training program::";
		else
			Fibsearch(A,n,key,f+a,b-a,a-b);
	}
	else
		cout<<"\nThe student attended the training program";
}

int main()
{
	int S,choice;
	int nmax,result;
	char ans;
	int Array[N+1]={11,13,15,17,21,25,28,31,35,39,-1};
	nmax=10;
	cout<<"\nThe roll numbers of the students are ...!!!\n";
	for(int i=0;i<nmax;i++)
		cout<<" "<<Array[i];
	do
	{
		cout<<"\nEnter the roll number to search::";
		cin>>S;
		cout<<"\nMain Menu";
		cout<<"\n1.Linear Search\n2.Sentinel Search\n3.Binary Search\n4.Fibonacci Search";
		cout<<"\nEnter choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(LinearSearch(Array,nmax-1,S)==1)
					cout<<"\nThe Student attended the training program::";
				else
					cout<<"\nThe Student has not attended the training programs::";
			break;
			case 2:
				if(SentinelSearch(Array,nmax,S)==1)
					cout<<"\nThe student attended the training programs";
				else
					cout<<"\nThe student has not attended the training programs";
			break;
			case 3:
				result=binsearch(Array,S,0,nmax-1);
				if(result!=-1)
					cout<<"\nThe students attended the training programs::";
				else
					cout<<"\nThe students has not attrended the training programs";
			break;
			case 4:
				Fibsearch(Array,nmax-1,S,nmax-1,Fib(nmax-1),Fib(Fib(nmax-1)));
			break;
		}
		cout<<"\nDo you want to continue::";
		cin>>ans;
	}
	while(ans=='Y'||ans=='y');
return 0;
}

/*
	OUTPUT :
	
The roll numbers of the students are ...!!!
 11 13 15 17 21 25 28 31 35 39
Enter the roll number to search::15

Main Menu
1.Linear Search
2.Sentinel Search
3.Binary Search
4.Fibonacci Search
Enter choice1

The Student attended the training program::
Do you want to continue::y

Enter the roll number to search::2

Main Menu
1.Linear Search
2.Sentinel Search
3.Binary Search
4.Fibonacci Search
Enter choice3

The students attended the training programs::
Do you want to continue::y

Enter the roll number to search::17

Main Menu
1.Linear Search
2.Sentinel Search
3.Binary Search
4.Fibonacci Search
Enter choice2

The student attended the training programs
Do you want to continue::

 
*/
