/* 
	Write C++ program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and
*/
#include<iostream>
using namespace std;

void in(float marks[20],int n)
{
	int i,j;
	float temp;
	for(i=1;i<n;i++)
	{
		temp=marks[i];
		for(j=i-1;j>=0 && marks[j]>temp;j--)
			marks[j+1]=marks[j];
			marks[j+1]=temp;
	}
	cout<<"\nTop five scores are ::";
	for(i=n-1;i>=n-5;i--)
		cout<<"\t"<<marks[i];
}

void shell(float marks[20],int n)
{
	int i,j,step;
	float temp;
	for(step=n/2;step>0;step=step/2)
	for(i=step;i<n;i++)
	{
		temp=marks[i];
		for(j=i;j>=step;j=j-step)
		if(temp<marks[j-step])
			marks[j]=marks[j-step];
		else
			break;
		marks[j]=temp;
	}
	cout<<"\nTop five scores are::";
	for(i=n-1;i>=n-5;i--)
	cout<<"\t"<<marks[i];
}

int main()
{
	float marks[20];
	int i,n,ch;
	cout<<"\nEnter the total no.of students::";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the percenatge marks for second year student"<<i+1<<"::";
		cin>>marks[i];
	}
	while(ch!=3)
	{
		cout<<"\n1.Insertion Sort 2. Shell Sort 3. Exit";
		cout<<"\nEnter your choice::";
		cin>>ch;
		switch(ch)
		{
		case 1:
			in(marks,n);
		break;
		case 2:
			shell(marks,n);
		break;
		}
	}
return 0;
}
/*
	OUTPUT :
	
Enter the total no.of students::4

Enter the percenatge marks for second year student1::60

Enter the percenatge marks for second year student2::55

Enter the percenatge marks for second year student3::77

Enter the percenatge marks for second year student4::76

1.Insertion Sort 2. Shell Sort 3. Exit
Enter your choice::1

Top five scores are ::  77      76      60      55      0
1.Insertion Sort 2. Shell Sort 3. Exit
Enter your choice::2

Top five scores are::   77      76      60      55      0
1.Insertion Sort 2. Shell Sort 3. Exit
Enter your choice::
 
*/
