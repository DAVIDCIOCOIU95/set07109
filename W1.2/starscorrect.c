#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) 
{
		//character array to read number into
		char buffer[10];
		printf("How many stars? (0 to quit) ");
		//read in value
		fgets(buffer, 10, stdin);
		//convert string to number int var(number)  
		int number = atoi(buffer);
		//print stars
		for (int i = 1; i <= number; ++i)
		{
			
			  printf("*");
		  printf("\n");
	}//say goodbye
	printf("Goodbye!\n");
	
	return 0;
	
	
}