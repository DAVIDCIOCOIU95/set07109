#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nonEmptyLines.h"
#include "numberComments.h"
#include "removeComments.h"

#define myLength 300000


void processInclude(char *filename)
{
	FILE *myFile;
	myFile = fopen(filename, "r");
	// Create a .o from filename
	int length = strlen(filename) - 1;
	filename[length] = 'o';
	char *fileO = filename;
	// Write a file 
	FILE *fileIn;
	fileIn = fopen(fileO, "w");

	if (myFile == NULL)
	{
		printf("Couldn't open your file.c\n");
		exit(1);
	}

	if (fileIn == NULL)
	{
		printf("Couldn't open your file.txt\n");
		exit(1);
	}

	char line[myLength];
	char myHeaderName[100];
	// Holds include therm 
	char *includeString = "#include";
	char headerLine[myLength];

	while (!feof(myFile))
	{
		// Reading the line into line[]
		if (fgets(line, myLength, myFile) != NULL)
		{
			if (strstr(line, includeString))
			{
				printf("It's an include line!\n");

				// Get from the line the name removing #include and quotes 
				for (int k = 0; k < strlen(line); ++k)
				{
					if (line[k + 10] != '"')
					{
						myHeaderName[k] = line[k + 10];
					}

					else if (line[k + 10] == '"')
					{
						myHeaderName[k] = '\0';
						break;
					}


				}

				printf("%s\n", myHeaderName);



				//Open the .h file
				FILE *myHeaderFile;
				myHeaderFile = fopen("string_functions.h", "r");

				if (myHeaderFile == NULL)
				{
					printf("Couldn't open your file.txt\n");

				}

				else
				{
					printf("File is working\n");
				}





				while (!feof(myHeaderFile))
				{

					printf("Hello\n");
					// Reading the line into line[]
					fgets(headerLine, myLength, myHeaderFile);
					printf("%s", headerLine);



				}
				fclose(myHeaderFile);

				break;
			}

			//} // End if #


			/*
			else if (line[0] != '#')
			{
				fprintf(fileIn, "%s", line);
			}
			*/

			//}
		}
	}

	fclose(myFile);
	fclose(fileIn);
	printf("Inclusion completed.\n");

}











int main(int argc, char **argv)
{
	if (strcmp(argv[1], "-i") == 0)
	{
		char *filename = argv[2];

		nonEmptyLines(filename);
		numberComments(filename);
		removeComments(filename);
		//processInclude();
	}

	else if (strcmp(argv[1], "-c") == 0)
	{
		char *filename = argv[2];
		//nonEmptyLines(filename);
		//numberComments(filename);
		processInclude(filename);

		/*// just create an .o file
		// Create a .o from filename
		int length = strlen(filename) - 1;
		filename[length] = 'o';
		char *fileO = filename;
		// Write a file
		FILE *fileIn;
		fileIn = fopen(fileO, "w");
		fclose(fileIn);
		fclose(fileIn);
		*/
	}

	return 0;
}















/*
	// MENU
	printf("             ************************\n");
	printf("             *      Coursework      *\n");
	printf("             ************************\n");
	printf("\nHello, what would you like to do today?\n");

	int flag = 1;
	while (flag)
	{
		// Read Input
		char buffer[20];

		printf("\n");
		printf("********************** MENU ***********************\n");
		printf("* LINES - Get the n* of non-empty lines of a file.*\n");
		printf("* COMMENTS - Count comments in a file.            *\n");
		printf("* PREPROCESS - Output an .o preprocessed file.  (no comments, include headers)  *\n");
		printf("* EXIT - To exit the app.                         *\n");
		printf("***************************************************\n");

		printf("\nPlease type your choice here: ");

		// Read Input
		fgets(buffer, 20, stdin);

		char filename[20];

		// Get non empty lines
		if (strcmp(buffer, "LINES\n") == 0)
		{

			printf("Please insert the name of your file here: ");
			scanf("%s", filename);
			printf("\n");

			nonEmptyLines(filename);
		}

		// Counts the comments
		if (strcmp(buffer, "COMMENTS\n") == 0)
		{

			printf("Please insert the name of your file here: ");
			scanf("%s", filename);
			printf("\n");

			numberComments(filename);
		}

		// Preprocess: removes comments; pass headers with inlcude
		if (strcmp(buffer, "PREPROCESS\n") == 0)
		{

			//printf("Please insert the name of your file here: ");
			//canf("%s", filename);
			//printf("\n");

			//removeComments(filename);
			processInclude();
		}

		if (strcmp(buffer, "EXIT\n") == 0)
		{
			flag = 0;
			printf("Exiting...\n");
		}

		buffer[0] = '\0';
	}
	*/
