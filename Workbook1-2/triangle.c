#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int printTree(int rows)
{
	//print a space just for visual purpose
	printf("\n");
	
	//loop for rows
	for (int i = 1; i <= rows; ++i)
	{
		
		//space ( 1 is added as a space for the command line at the end of space for visual purposes) 
		int space = (rows - i) + 1; 
		for (int j = 0; j < space; ++j)
		{
			printf(" ");
		}
		
		
		//stars
		int stars = (i*2) - 1;
		for (int z = 0; z < stars; ++z)
		{
			printf("*");
		}
		
		//newline
		printf("\n");
	}
	
	//print tail ( 1 is added as a space for the command line at the end of lastSpace for visual purposes) 
	int lastSpace = (((rows * 2) - 2) / 2) + 1; 
	for (int k = 0; k < 2; ++k)
	{
		for (int y = 1; y <= lastSpace; ++y)
		{
			printf(" ");
		}
		printf("*\n");
	}
	
	//print a space just for visual purpose
	printf("\n");
}

int printTriangle(int rowsTriangle)
{
	//print a space just for visual purpose
	printf("\n");
	
	//loop for rows
	for (int i = 1; i <= rowsTriangle; ++i)
	{
		
		//space ( 1 is added as a space for the command line at the end of space for visual purposes) 
		int space = (rowsTriangle - i) + 1; 
		for (int j = 0; j < space; ++j)
		{
			printf(" ");
		}
		
		
		//stars
		int stars = (i*2) - 1;
		for (int z = 0; z < stars; ++z)
		{
			printf("*");
		}
		
		//newline
		printf("\n");
	}
	
		//print a space just for visual purpose
	printf("\n");
	}
	
	


int main (int argc, char **argv)
{
	
	int flag = 1;
	
	while (flag == 1)
	{
		//menu 
		printf("Do you want to print a Christmas Tree or a Triangle?\n");
	printf("1 Christmas Tree\n");
	printf("2 Triangle\n");
	printf("3 Exit\n");
	
	char bufferOption[20];
	fgets(bufferOption, 20, stdin);
	int option = atoi(bufferOption);
	
	char bufferRows[20];
	
	
	switch(option)
	{
		case 1:
		printf("Enter number of rows: \n");
	fgets(bufferRows, 20, stdin);
	int rows = atoi(bufferRows);
		   int tree = printTree(rows);
		   
		   break;
		   
	    case 2:
		printf("Enter number of rows: \n");
	fgets(bufferRows, 20, stdin);
	int rowsTriangle = atoi(bufferRows);
		     int triangle = printTriangle(rowsTriangle);  
			 break;
	    
		case 3:
		     printf("Goodbye!");
		     flag = 0; 
			 break;
	    
		default:
		     printf("Invalid Input");
			 break;
	}//end switch
	
		   	
	
	}//end while
	
	return 0;
}
