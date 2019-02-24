#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) 
{
	// flag (1 or 0) to indicate if we should continue
	int flag = 1;
	//while loop
	while (flag)
	{
		//character array to read number into
		char buffer[10];
		printf("How many stars? (0 to quit) ");
		//read in value
		fgets(buffer, 10, stdin);
		//convert string to number int var(number)  
		int number = atoi(buffer);
		// if number equals 0 then set flag and continue
		if (!number)
		{
			flag = 0;
			continue;
		}
		//print stars
		//rows
		for (int i = 0; i < number; ++i)
		{    
	        //stars
			for (int j = -1; j < i; ++j)
				
			  printf("*");
		      printf("\n");
	          int lastRow = j;  
		}
		
		//get the len of last row, start printing
		for (int i = 0; i < number; ++i) 
		{
			printf
		}
		
	}//say goodbye
	printf("Goodbye!\n");
	
	return 0;
	
	
}