#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "removeComments.h"

#define myLength 1000000

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

	// Create a .o from filename
	int length = strlen(filename) - 1;
	filename[length] = 'o';
	char *fileO = filename;
	// Write a file 
	FILE *fileIn;
	fileIn = fopen(fileO, "w");

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
					break;
					// i = strlen(line);
				}
			}

		}
	}

	
	fclose(myFile);
	fclose(fileIn);
	printf("Comments removal completed\n");
}