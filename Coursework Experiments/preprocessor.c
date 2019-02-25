#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nonEmptyLines.h"


/*
Removes the comments in the file; 
A comment is identified as beginning with // and ending at the end of that line;
you do not need to consider multiple lines comments
*/
void removeComments(char *filename)
{
	FILE *myFile;
	myFile = fopen(filename, "r");

	if (myFile == NULL)
	{
		printf("Couldn't open your file.txt\n");
		exit(1);
	}

	// Write a file 
	FILE *fileIn;
	fileIn = fopen("preprocessed.o", "w");

	// Define a line array
	char line[myLength];

	while (!feof(myFile))
	{
		//read in line
		if (fgets(line, myLength, myFile) != NULL)
		{
			// Iterate through each character of the line 
			// Check if it is equal to / and if char + 1 is equal to /
			// increment counter if so 
			for (int i = 0; i < strlen(line); ++i)
			{

				// printf("Char at i is: %d\n", line[i]);
				if (line[i] != '/' && line[i + 1] != '/')
				{
					// Copy contents of line[i] into fileIn up to //
					fprintf(fileIn, "%c", line[i]);

				}

				// Else just stop the for loop and get the next line 
				else if (line[i] == '/' && line[i + 1] == '/')
				{
					// Prints a new line after the comment
					fprintf(fileIn, "\n");
					i = strlen(line);
				}
			}

		}
	}

	
	fclose(myFile);
	printf("Comments removal completed\n");
}

void processInclude()
{
	FILE *myFile;
	myFile = fopen("preprocessed.o" , "r");

	if (myFile == NULL)
	{
		printf("Couldn't open your file.txt\n");
		exit(1);
	}

	// Write a file 
	FILE *fileIn;
	fileIn = fopen("preprocessed.o", "w");

	// Define a line array
	char line[myLength];

	while (!feof(myFile))
	{
		//read in line
		if (fgets(line, myLength, myFile) != NULL)
		{
			// Iterate through each character of the line 
			for (int i = 0; i < strlen(line); ++i)
			{
				if (line[0] == '#' && line[1] == 'i' && line[2] == 'n' && line[3] == 'c' && line[4] == 'l')
				{ 
					//open file 
					//another loop 
					//copy it 
					//also make sure it is not included already


				}

				// Else read in the line
				else 
				{
					// Copy contents of line[i] into fileIn
					fprintf(fileIn, "%c", line[i]);
				}
			}

		}
	}


	fclose(myFile);
	printf("Inclusion completed.\n");
}


	





int main(int argc, char **argv)
{
	//MENU
	printf("             ************************\n");
	printf("             *      Coursework      *\n");
	printf("             ************************\n");
	printf("\nHello, what would you like to do today?\n");

	// Read Input
	char buffer[20];

	int flag = 1;
	while (flag)
	{
		
		printf("\n");
		printf("********************** MENU ***********************\n");
		printf("* LINES - Get the n* of non-empty lines of a file.*\n");
		printf("* COMMENTS - Count comments in a file.            *\n");
		printf("* PREPROCESS - Output an .o preprocessed file.    *\n");
		printf("* EXIT - To exit the app.                         *\n");
		printf("***************************************************\n");

		printf("\nPlease type your choiche here: ");

		// Read Input
		fgets(buffer, 20, stdin);
		char *choice = buffer;

		printf("\n");

		char filename[20];

		// Get non empty lines
		if (strcmp(choice, "LINES\n") == 0)
		{
			printf("Please insert the name of your file here: ");
			scanf("%s", filename);
			printf("\n");

			nonEmptyLines(filename);
		}

		// Counts the comments 
		if (strcmp(choice, "COMMENTS\n") == 0)
		{
			printf("Please insert the name of your file here: ");
			scanf("%s", filename);
			printf("\n");

			numberComments(filename);
		}

		if (strcmp(choice, "PREPROCESS\n") == 0)
		{
			printf("Please insert the name of your file here: ");
			scanf("%s", filename);
			printf("\n");

			removeComments(filename);
		}

		if (strcmp(choice, "EXIT\n") == 0)
		{
			flag = 0;
			printf("Exiting...\n");
		}
		
		
		
	}

	return 0;
}

