
/*
	A magic square is an n * n matrix of the integers 1 to n2 such that the sum of each row, column, and diagonal is the same. 
	The figure given below is an example of magic square for case n=5. In this example, the common sum is 65. 
	Write C/C++ Program for magic square. 
		 15      8       1       24      17

        16      14      7       5       23

        22      20      13      6       4

        3       21      19      12      10

        9       2       25      18      11
*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 50

void Magic(int n,int s[][MAX])
{
	int nc,nr,i,j;
	//int sr[MAX][MAX];
	int Row,Col;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			s[i][j]=0;
			nr=0; //Top of most row to start with
			nc=(int)(n/2);  //computes middle of top row
			s[nr][nc]=1;
		for(i=2;i<=n*n;i++)
		{
			Row=nr;
			Col=nc;
			nr--;
			if(nr<0)
				nr=n-1;
				nc--;
			if(nc<0)
				nc=n-1;
			if(s[nr][nc]!=0)
			{
				nr=++Row;
				nc=Col;
			}
			s[nr][nc]=i;
		}
}

void display(int n,int s[][MAX])
{
	int i,j;
	printf("Now printing the magic square of n %d\n",n);
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("\t%d",s[i][j]);
			printf("\n\n");
		}
}

int main()
{
	int n,sq[MAX][MAX];
	printf("Enter the order of the matrix::");
	scanf("%d",&n);
	if(n>MAX)
	{
		printf("Error:Size of the sqaure exceeded\n");
		printf("Press any key to abort");
		getch();
		exit(1);
	}
	if(n%2==0)
	{
		printf("Error,Number of row/cols should be odd\n");
		printf("Press any key to terminate");
		getch();
		exit(1);
	}
	Magic(n,sq);
	display(n,sq);
	printf("Press any key to terminate\n");
	return 0;
}

/*
		OUTPUT :
		Enter the order of the matrix::5
Now printing the magic square of n 5


        15      8       1       24      17

        16      14      7       5       23

        22      20      13      6       4

        3       21      19      12      10

        9       2       25      18      11

Press any key to terminate 
*/
