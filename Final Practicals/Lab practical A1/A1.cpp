/* 
	Second year Computer Engineering class, set A of students play cricket and set B of students play badminton. Write C/C++ program to find and display-
	i. Set of students who play either cricket or badminton or both
	ii. Set of students who play both cricket and badminton
	iii. Set of students who play only cricket
	iv. Set of students who play only badminton
	v. Set of students who play neither cricket nor badminton
	(Note- While realizing the set duplicate entries are to avoided) */
 
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 10
#define SIZE 20

int main()
{
	int Union(char a[MAX][SIZE],char b[MAX][SIZE],char c[MAX][SIZE],int,int);
	void intersection(char a[MAX][SIZE],char b[MAX][SIZE],int,int);
	void difference(char a[MAX][SIZE],char b[MAX][SIZE],int,int);
	void display(char a[MAX][SIZE],char b[MAX][SIZE],int term1,int term2);
	char a[MAX][SIZE],b[MAX][SIZE],c[MAX][SIZE],U[MAX][SIZE];
	int i,term,term1,term2,term3;

	char ans;
	int choice;

	printf("\nHow many elements are there in Universal Set ?");
	scanf("%d",&term);
	printf("\nEnter the elements in Universal Set\n");
	for(i=0;i<term;i++)
		scanf("%s",&U[i]);
		printf("\nHow many memebers play cricket ?");
		scanf("%d",&term1);
		printf("\nEnter the names of the players\n");
	for(i=0;i<term1;i++)
		scanf("%s",&a[i]);
		printf("\n How many members play badminton");
		scanf("%d",&term2);
		printf("\nEnter the names of the players\n");
	for(i=0;i<term2;i++)
		scanf("%s",&b[i]);
	do
	{
		printf("\n\t\tMain Menu::");
		printf("\n1. Set of  students who play either cricket or badminton or both");
		printf("\n2. Set of Students who play both  cricket and badminton");
		printf("\n3. Set students who play only cricket");
		printf("\n4.Set of students who play only badminton");
		printf("\n5.Set of students who  play naither cricket nor badminton");
		printf("\n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{0
			case 1:
				display(a,b,term1,term2);
				term3=Union(a,b,c,term1,term2);
			break;
			case 2:
				display(a,b,term1,term2);
				intersection(a,b,term1,term2);
			break;
			case 3:
				display(a,b,term1,term2);
				difference(a,b,term1,term2);
			break;
			case 4:
				display(a,b,term1,term2);
				difference(b,a,term2,term1);
			break;
			case 5:
				display(a,b,term1,term2);
				difference(U,c,term,term3);
			break;
		}}while(choice!=0);
	printf("\nDo you want to continue ?");
	ans=getch();
	if(ans=='y')
		return 0;
}

void display(char a[MAX][SIZE],char b[MAX][SIZE],int term1,int term2)
{
	int i;
	printf("\n A={");
	for(i=0;i<term1;i++)
		printf("%s",a[i]);
	printf("}");
	printf("\nB={");
	for(i=0;i<term2;i++)
		printf("%s",b[i]);
		printf("}");
}

int Union(char a[MAX][SIZE],char b[MAX][SIZE],char c[MAX][SIZE],int term1,int term2)
{
	int i,j,k,n,flag;
	k=0;
	flag=0;
	for(i=0;i<term1;i++)
	{
		strcpy(c[k],a[i]);
		k++;
	}
	for(j=0;j<term2;j++)
	{
		flag=0;
		for(i=0;i<term1;i++)
		{
			if((strcmp(a[i],b[j]))==0)
				flag=1;
		}
		if(flag==0)
		{
			strcpy(c[k],b[j]);
			k++;
		}
	}
	n=k;
	printf("\n{");
	for(k=0;k<n;k++)
		printf("%s",c[k]);
	printf("}");
	return n;
}

void intersection(char a[MAX][SIZE],char b[MAX][SIZE],int term1,int term2)
{
	char c[MAX][SIZE];
	int i,j,k,n,flag;
	k=0;
	flag=0;
	for(i=0;i<term1;i++)
	{
		flag=1;
		for(j=0;j<term2;j++)
		{
			if((strcmp(a[i],b[j]))==0)
			flag=0;
		}
		if(flag==0)
		{
			strcpy(c[k],a[i]);
			k++;
		}
	}
	n=k;
	printf("\n{");
	for(k=0;k<n;k++)
		printf("%s",c[k]);
		printf("}");
}

void difference(char a[MAX][SIZE],char b[MAX][SIZE],int term1,int term2)
{
	char c[MAX][SIZE];
	int i,j,k,n,flag;
	k=0;
	flag=0;
	for(i=0;i<term1;i++)
	{
		flag=1;
		for(j=0;j<term2;j++)
		{
			if((strcmp(a[i],b[j])==0))
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			strcpy(c[k],a[i]);
			k++;
		}
	}
	n=k;
	printf("\n{");
	for(k=0;k<n;k++)
		printf("%s",c[k]);
	printf("}");
}

/* OUTPUT :

How many elements are there in Universal Set ?7

Enter the elements in Universal Set
1 2 3 4 5 6 7

How many memebers play cricket ?3

Enter the names of the players
ravi
raj
sanjay

 How many members play badminton2

Enter the names of the players
vinay
akash

                Main Menu::
1. Set of  students who play either cricket or badminton or both
2. Set of Students who play both  cricket and badminton
3. Set students who play only cricket
4.Set of students who play only badminton
5.Set of students who  play naither cricket nor badminton
 Enter your choice1

 A={ravirajsanjay}
B={vinayakash}
{ravirajsanjayvinayakash}
                Main Menu::
1. Set of  students who play either cricket or badminton or both
2. Set of Students who play both  cricket and badminton
3. Set students who play only cricket
4.Set of students who play only badminton
5.Set of students who  play naither cricket nor badminton
 Enter your choice2

 A={ravirajsanjay}
B={vinayakash}
{}
                Main Menu::
1. Set of  students who play either cricket or badminton or both
2. Set of Students who play both  cricket and badminton
3. Set students who play only cricket
4.Set of students who play only badminton
5.Set of students who  play naither cricket nor badminton
 Enter your choice3

 A={ravirajsanjay}
B={vinayakash}
{ravirajsanjay}
                Main Menu::
1. Set of  students who play either cricket or badminton or both
2. Set of Students who play both  cricket and badminton
3. Set students who play only cricket
4.Set of students who play only badminton
5.Set of students who  play naither cricket nor badminton
 Enter your choice4

 A={ravirajsanjay}
B={vinayakash}
{vinayakash}
                Main Menu::
1. Set of  students who play either cricket or badminton or both
2. Set of Students who play both  cricket and badminton
3. Set students who play only cricket
4.Set of students who play only badminton
5.Set of students who  play naither cricket nor badminton
 Enter your choice5

 A={ravirajsanjay}
B={vinayakash}
{1234567}
                Main Menu::
1. Set of  students who play either cricket or badminton or both
2. Set of Students who play both  cricket and badminton
3. Set students who play only cricket
4.Set of students who play only badminton
5.Set of students who  play naither cricket nor badminton
 Enter your choice
 
*/
