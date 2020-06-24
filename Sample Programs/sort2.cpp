#include<iostream>
using namespace std;
#define MAX 20

class Sort
{
	private:
		float A[MAX];
		int n;
	public:
		Sort();
		void get_data();
		void Insert_sort();
		void Shell_sort();
		void display();
};

Sort::Sort()
{
	for(int i=0;i<MAX;i++)
		A[i]=0;
}

void Sort::Insert_sort()
{
	int i,j;
	float temp;
	for(i=1;i<=n-1;i++)
	{
		temp=A[i];
		j=i-1;
		while((j>=0)&&(A[j]>temp))
		{
			A[j+1]=A[j];
			j=j+1;
		}
	A[j+1]=temp;
	}
}

void Sort::get_data()
{
	cout<<"\nHow many students are there?";
	cin>>n;
	cout<<"\nEnter the percentage marks of each students\n";
	for(int i=0;i<n;i++)
		cin>>A[i];
}

void Sort::Shell_sort()
{
	int i,j,d,k;
	float value;
	d=(n+1)/2;
	for(i=d;i>=1;i=i/2)
	{
		for(j=i;j<=n-1;j++)
		{
			value=A[j];
			k=j-1;
			while(k>=0&&value<A[k])
			{
				A[k+1]=A[k];
				k=k-1;
			}
			A[k+i]=value;
		}
	}
}

void Sort::display()
{
	cout<<"\n The percentage marks of Top Five Students..!!!\n";
	for(int i=n-1;i>=n-5;i--)
	cout<<"\n "<<A[i];
}

int main()
{
	Sort obj;
	int choice;
	char ans='y';
	obj.get_data();
	do
	{
		cout<<"\nMain Menu";
		cout<<"\n1.Insertion Sort\n2.Shell Sort\n3.Exit";
		cout<<"\nEnter your choice::";
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.Insert_sort();
				obj.display();
			break;
			case 2:
				obj.Shell_sort();
				obj.display();
			break;
		 //	case 3:
				//exit(0);
		}
	cout<<"\nDo you want to continue?";
	cin>>ans;
	}
	while(ans=='y' || ans=='Y');
return 0;
}
