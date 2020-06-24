/*
		Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' for N students. Compute
		I. The average score of class
		ii. Highest score and lowest score of class
		iii. Marks scored by most of the students
		iv. list of students who were absent for the test 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
	int roll;
	char name[20];
	int marks;
}stud;

int main()
{
	stud s[10];
	int n,i,tot=0,avg,high=0,low=999,highfreq=0,freq[11],highgroup,pre=0;
	for(i=0;i<=10;i++)
		freq[i]=0;
		printf("\nEnter the no.of students::");
		scanf("%d",&n);
		printf("\nEnter the data of students::");
		for(i=0;i<n;i++)
		{
			printf("\nStudent %d",i+1);
			printf("\nEnter the roll no.:");
			scanf("%d",&s[i].roll);
			printf("\nEnter the name");
			scanf("%s",s[i].name);
			printf("\nEnter the marks::");
			scanf("%d",&s[i].marks);
		}
		printf("\n*****Students Record******");
		for(i=0;i<n;i++)
			printf("\nRoll no::%d Name=%s Marks=%d",s[i].roll,s[i].name,s[i].marks);
			for(i=0;i<n;i++)
		{
		if(s[i].marks!=0)
		{
			tot=tot+s[i].marks;
			pre++;
		}
		}
		avg=tot/pre;
		printf("\nAvarage score of class::%d",avg);
		for(i=0;i<n;i++)
		{
			if(high<s[i].marks)
				high=s[i].marks;
				freq[s[i].marks/10]++;
			if(highfreq<freq[s[i].marks/10])
			{
				highfreq=freq[s[i].marks/10];
				highgroup=s[i].marks/10;
			}
		}
		printf("\nHighest marks::%d",high);
		for(i=0;i<n;i++)
		{
			if(s[i].marks!=0)
			{
			if(low>s[i].marks)
			low=s[i].marks;
			}
		}
		printf("\nlowest marks::%d",low);
		printf("\nMaximum students scored marks between%d to %d",highgroup*10,highgroup*10+9);
		for(i=0;i<n;i++)
			if(s[i].marks==0)
			printf("\nRoll No::%d Name=%s",s[i].roll,s[i].name);
			return 0;
	}
	
	/*
		OUTPUT :
		
Enter the no.of students::5

Enter the data of students::
Student 1
Enter the roll no.:1

Enter the nameravi

Enter the marks::65

Student 2
Enter the roll no.:2

Enter the namesanjay

Enter the marks::55

Student 3
Enter the roll no.:3

Enter the namevinay

Enter the marks::78

Student 4
Enter the roll no.:4

Enter the nameraj

Enter the marks::88

Student 5
Enter the roll no.:aakash

Enter the name
Enter the marks::66

*****Students Record******
Roll no::1 Name=ravi Marks=65
Roll no::2 Name=sanjay Marks=55
Roll no::3 Name=vinay Marks=78
Roll no::4 Name=raj Marks=88
Roll no::32 Name=aakash Marks=66
Avarage score of class::70
Highest marks::88
lowest marks::55
Maximum students scored marks between60 to 69 
	*/
