#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
	//char array to read n into
	char buffer [20];
	
	//set height
	printf("Please set the height of your tree by inputting a number and press enter: ");
	fgets(buffer, 20, stdin);
	//parse char to int; also:  row = heigth
	int rows = atoi(buffer);
	
	
	
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
	
	return 0;
}
		
		
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	//print tree
	for (int i = 1; i <= rows; ++i)
	{
		//print space
		//space decrement (rows -1 each loop)
		
		for (int r = 0; r < row; ++r)
		{
			printf(" ");
		}
		
		printf("*");
		
		//print *; increment by 2: starting at 0 each row and adding one will increment by two each line
		for (int j = 0; j < i; ++j) 
		{
		  printf("*");
		  
		  
		}
		
		
		
		
		printf("\n");
	}
	
		return 0;
}

*/
	
	

	

