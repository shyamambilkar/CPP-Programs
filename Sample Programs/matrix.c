#include<stdio.h>

int main()
{
	int size;
	int matrix [20][20];   // matrix declaration
	int row,col = 0;
	int flag;
	int add,addrow,addcol;

	printf("\n Enter the Size of matrx :");
	scanf("%d",&size);

	// getting matrix elements 

	printf("\n Enter the Matrix Elements :");
		
	for(row = 0; row<size ;row++)
	{
		for(col = 0;col<size;col++)
		{
			scanf("%d",&matrix[row][col]);
		}
	}

	// Printing Matrix

	printf(" Given Matrix Elements are :\n");
	
	for(row=0; row<size; row++)
	{
		printf("\n");
		for(col=0; col<size;col++)
		{
			printf("\t%d",matrix[row][col]);
		}
	}

	// Add the Diagonal Elements 
	
	add = 0;
	
	for(row =0; row<size; row++)
	{
		for(col=0; col<size;col++)
		{
			if(row == col)
			{
				add += matrix[row][col];
			}
		}
	}
	printf("\n Sum = %d",add);
	
	// Add the Row Elements 
	
	
	for(row=0;row<size;row++)
	{
		addrow = 0;
		for(col=0;col<size;col++)
		{	
			addrow =addrow + matrix[row][col];
		}
	if(add == addrow)
		{
			flag =1;
		}
	else
		{
			flag = 0;
		}

	}
printf("\n Sum = %d",addrow);

	// Add the Column Elements 
	
	
	for(row=0;row<size;row++)
	{
		addcol = 0;
		for(col=0;col<size;col++)
		{	
			addcol =addcol + matrix[col][row];
		}
	if(add == addcol)
		{
			flag =1;
		}
	else
		{
			flag = 0;
		}

	}
	
	printf("\n Sum = %d",addcol);

	if(flag == 1)
	{
		printf("\n The given Matrix is Magic Square...!");
		printf("\n The Matrix Are :\n");
		for(row=0; row<size; row++)
		{
		printf("\n");
		for(col=0; col<size;col++)
			{
				printf("\t%d\n",matrix[row][col]);
			}
		}
	
	}
	else
	{
		printf("\n The given Matrix is not Square Magic...!");
	}

return 0;		
	
}
