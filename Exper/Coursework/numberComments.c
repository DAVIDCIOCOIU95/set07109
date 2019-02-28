#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numberComments.h"

#define myLength 1000000


// 2.Number of Comments 
void numberComments(char *filename)
{
	FILE *myFile;
	myFile = fopen(filename, "r");

	if (myFile == NULL)
	{
		printf("Couldn't open your file.txt\n");
		exit(1);
	}

	char line[myLength];

	// Set counters
	int counterLines = 0;
	int counterComment = 0;
	while (!feof(myFile))
	{
		//read in line
		if (fgets(line, myLength, myFile) != NULL)
		{
			// Count the total lines
			counterLines++;

			// Iterate through each character of the line 
			// Check if it is equal to / and if char + 1 is equal to /
			// increment counter if so 
			// strlen - 1: blank line equals to nothing and nothing equals to a char 

			for (int i = 0; i < (strlen(line) - 1); ++i)
			{
				// printf("Char at i is: %d\n", line[i]);
				if (line[i] == '/' && line[i + 1] == '/')
				{
					counterComment++;
					break;
				}
			}

		}
	}

	printf("The total number of lines is: %d\n", counterLines);
	printf("Number of comments is: %d\n", counterComment);

	fclose(myFile);
}