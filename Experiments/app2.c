#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main (int argc, char **argv)
{
	FILE *file;
	file = fopen("name.txt", "w");
	
	char name [20]; 
	
	int flag = 1;
	while (flag)
	{
		printf("Insert your name here: ");
		char buffer [20];
		fgets(buffer, 20, stdin); 
		char *fullName = buffer; 
		
		if (strcmp(fullName, "END\n") == 0)
		{
			flag = 0;
			printf("Exiting...\n");
		}
		
		else
		{

			fprintf(file, "%s\n", fullName);
		}
			
	} 	
	fclose(file);
} 