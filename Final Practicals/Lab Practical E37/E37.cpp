/*
	Write C++ program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using quick sort 
*/
#include<iostream>
using namespace std;
#define SIZE 20

class Quick
{
	private:
		float arr[SIZE];
	public:
		int get_data();
		void quicksort(int,int);
		int partition(int,int);
		void swap(int,int);
		void display(int);
};

/* This function is to input the elements */

int Quick::get_data()
{
	int i,n;
	cout<<"\n Enter Total numbers student ::";
	cin>>n;
	cout<<"\nEnter Percentage Marks of each students ::";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	return n;
}

/* This function is to sort elements in a submits */

void Quick::quicksort(int p, int q)
{
	int j;
	if(p<q)
	{
		j=partition(p,q+1); //setting pivot elements
		quicksort(p,j-1);  //splitting of list
		quicksort(j+1,q);  //splitting of list
	}
}

/* This function is to partition a list and decide the pivot elements */

int Quick::partition(int m,int p)
{
	float pivot=arr[m];
	int i=m,j=p;
	do
	{
		do
		{
			i++;
		}
		while(arr[i]<pivot);
		do
		{
			j--;
		}
		while(arr[j]>pivot);
		if(i<j)
			swap(i,j);
		}
		while(i<j);
		arr[m]=arr[j];
		arr[j]=pivot;
		return j;
}

void Quick::swap(int i,int j)
{
	float temp;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

/* This function is to display the Top five scores */

void Quick::display(int n)
{
	cout<<"\n\n\t Percentage Marks of Top Five Students ...!!!\n";
	for(int i=n-1;i>=n-5;i--)
		cout<<" "<<arr[i];
}

int main()
{
	Quick obj; // for integer elements
	int n;
	cout<<"\n\t\t Quick Sort Methods \n";
	n=obj.get_data();
	obj.quicksort(0,n-1);
	obj.display(n);
	return 0;
}
/*
	OUTPUT :
	
                 Quick Sort Methods

 Enter Total numbers student ::5

Enter Percentage Marks of each students ::78
56
79
67
88


         Percentage Marks of Top Five Students ...!!!
 88 79 78 67 56 
*/
