#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nonEmptyLines.h"

#define myLength 1000000

// 1 - number of non empty lines
void nonEmptyLines(char *filename)
{
	// Get the file in first
	FILE *myFile;
	myFile = fopen(filename, "r");

	if (myFile == NULL)
	{
		printf("Couldn't open your file.txt\n");
		exit(1);
	}

	char line[myLength];

	//get in lines with chars and count them 
	int counterLines = 0;
	int counterFullLine = 0;
	while (!feof(myFile))
	{
		//read in line
		if (fgets(line, myLength, myFile) != NULL)
		{
			// Count the total lines
			counterLines++;

			// Iterate through each character of the line 
			// Check if it is different than '\n', ' ', or '\t'
			// strlen - 1: blank line equals to nothing and nothing equals to a char 

			for (int i = 0; i < (strlen(line)); ++i)
			{
				// printf("Char at i is: %d\n", line[i]);
				if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				{
					counterFullLine++;
					break;
				}
			}

		}
	}

	printf("The total number of lines is: %d\n", counterLines);
	printf("Non-empty lines number: %d\n", counterFullLine);

	fclose(myFile);
}
