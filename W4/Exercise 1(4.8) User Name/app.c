#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/**
The app prompts for a user name and writes it to a file as text;
each name is on a new line;
the app loops until END is entered 
*/

int main (int argc, char **argv)
{
	// Create file
	FILE *file;
	file = fopen("name.txt", "w");
	
	//Create memory for name 
	char name [20]; 
	
	int flag = 1;
	while (flag)
	{
		// Print menu
		printf("NAME - Enter your name to the file.\n");
		printf("END - Exit\n");
		printf("Enter Command\n");
		
		// Read Input
		char buffer [10];
		fgets(buffer, 10, stdin); 
		char *nameStr = buffer; 
		
		if (strcmp(nameStr, "NAME\n") == 0) 
		{
			printf("Insert your name here:\n");
			fgets(name, 20, stdin);
			
			// Pass to file here
			fprintf(file, "%s\n", name);
		}
		
		else if (strcmp(nameStr, "END\n") == 0)
		{
			flag = 0;
			printf("Exiting...\n");
		}
	    
		
		
		
		
	    /**
		// Switch case
		switch (number)
		{
			case 1:
			fgets(name, 20, stdin);
			
			// Pass to file here
			fprintf(file, "%s\n", name);
				break;
			case 2:
			flag = 0;
			printf("Exiting...\n");
				break;
		}
		*/
	
	
	} //end while
	
	fclose(file); 
	
	
	
} // end main