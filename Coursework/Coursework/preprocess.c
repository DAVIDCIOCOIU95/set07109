#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define myLength 30000

// Non-empty lines
/* Returns the number of non empty lines into a file;
a non empty line is defined as having a char different than \t \n or space
*/
void nonEmptyLines(char *filename)
{
    FILE *myFile;
    myFile = fopen(filename, "r");

    if (myFile == NULL)
    {
        printf("Couldn't open your file.txt\n");
        exit(1);
    }

    char line[myLength];
    int counterLines = 0;
    int counterFullLine = 0;
    while (!feof(myFile))
    {
        if (fgets(line, myLength, myFile) != NULL)
        {
            counterLines++;
            for (int i = 0; i < (strlen(line)); ++i)
            {
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

// Number Comments
/* Counts the number of comments in a file;
a comment is defined as following a // 
*/
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
    int counterLines = 0;
    int counterComment = 0;
    while (!feof(myFile))
    {
        if (fgets(line, myLength, myFile) != NULL)
        {
            for (int i = 0; i < (strlen(line) - 1); ++i)
            {
                if (line[i] == '/' && line[i + 1] == '/')
                {
                    counterComment++;
                    break;
                }
            }
        }
    }

    printf("Number of comments is: %d\n", counterComment);

    fclose(myFile);
}

// Preprocess
/* Includes the header files into a .o file
created after our .c file;
removes the comments found 
*/
void preprocessor(char *filename, char *input)
{
    FILE *myFile;
    myFile = fopen(filename, "r");
    // Create a .o from filename
    int position_O = strlen(filename) - 1;
    filename[position_O] = 'o';
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
    char *includeString = "#include";
    char headerLine[myLength];
    char *defineString = "#define";

    // Process Include
    while (!feof(myFile))
    {
        if (fgets(line, myLength, myFile) != NULL)
        {
            if (strstr(line, includeString))
            {
                // Get from the line the name of the header file
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
                // Open the Header File
                FILE *myHeaderFile;
                myHeaderFile = fopen(myHeaderName, "r");

                if (myHeaderFile == NULL)
                {
                    printf("Couldn't open your file.txt\n");
                }

                while (!feof(myHeaderFile))
                {

                    fgets(headerLine, myLength, myHeaderFile);
                    fprintf(fileIn, "%s", headerLine);
                }
                fclose(myHeaderFile);
            }
/*
            else if(strstr(line, defineString))
            {

            }
            */

            else if(strcmp(input, "-i") == 0)
            {
                for (int i = 0; i < strlen(line); ++i)
                {
                    if (line[i] != '/' && line[i + 1] != '/')
                    {
                        fprintf(fileIn, "%c", line[i]);
                    }

                    else if (line[i] == '/' && line[i + 1] == '/')
                    {
                        break;
                    }
                }
            }

             else if(strcmp(input, "-c") == 0)
            {
                fprintf(fileIn, "%s", line);  
            }
        }
    }
    fclose(myFile);
    fclose(fileIn);
}



int main(int argc, char **argv)
{
    if (strcmp(argv[1], "-i") == 0)
    {
        char *filename = argv[2];
        char *input = argv[1];
        nonEmptyLines(filename);
        numberComments(filename);
        preprocessor(filename, input);
    }

    else if (strcmp(argv[1], "-c") == 0)
    {
        char *filename = argv[2];
        char *input = argv[1];
        nonEmptyLines(filename);
        numberComments(filename);
        preprocessor(filename, input);
        
     
    }
    return 0;
}