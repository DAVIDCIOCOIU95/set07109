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

struct definePairs
{
    char constName[30];
    char value[30];
};

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
    struct definePairs arrayDefine[30];
    int arrayCounter = 0;

    
    while (!feof(myFile))
    {
        if (fgets(line, myLength, myFile) != NULL)
        {
            // Process Include
            for (int c = 0; c < strlen(line); ++c)
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
                        if(fgets(headerLine, myLength, myHeaderFile) != NULL)
                        {
                            fprintf(fileIn, "%s", headerLine);
                        }
                        
                    }
                    fclose(myHeaderFile);
                    break;
                }

                // Define
                else if (strstr(line, defineString))
                {
                    struct definePairs definePairs1;
                    int defineLength = strlen(defineString);
                    int flag = 1;
                    // Get from the line the const and the value
                    int counterValue = 0;
                    int counterConst = 0;
                    for (int d = 0; d < strlen(line); ++d)
                    {
                        if (line[d + defineLength] == '\n')
                        {
                            definePairs1.constName[counterConst] = '\0';
                            definePairs1.value[counterValue] = '\0';
                            break;
                        }

                        if (line[d + defineLength] != ' ' && line[d + defineLength] != '\t' && line[d + defineLength] != '\n')
                        {
                            if (flag == 1)
                            {
                                definePairs1.constName[counterConst] = line[d + defineLength];
                                counterConst++;
                            }

                            if (flag == 0)
                            {
                                definePairs1.value[counterValue] = line[d + defineLength];
                                counterValue++;
                            }
                        }

                        else if (line[d + defineLength] == ' ' && counterConst > 0)
                        {
                            flag = 0;
                        }
                    }
                    arrayDefine[arrayCounter] = definePairs1;
                    arrayCounter++;
                    break;
                }

                else if (strcmp(input, "-c") == 0)
                {
                    for (int i = 0; i < strlen(line); ++i)
                    {

                        // Counter that checks each constName present in the array of defines
                        for (int p = 0; p < arrayCounter; ++p)
                        {
                            if (strstr(line, arrayDefine[p].constName))
                            {
                                char *strBegin = strstr(line, arrayDefine[p].constName);
                                //char *endConstName = strBegin + strlen(arrayDefine[p].constName);
                                if (line[i] == strBegin[0])
                                {
                                    for (int c = 0; c < strlen(arrayDefine[p].value); ++c)
                                    {
                                        fprintf(fileIn, "%c", arrayDefine[p].value[c]);
                                    }

                                    i = i + strlen(arrayDefine[p].constName);
                                }
                            }
                        }
                        fprintf(fileIn, "%c", line[i]);
                    }
                    break;
                }

                else if (strcmp(input, "-i") == 0)
                {
                    for (int i = 0; i < strlen(line); ++i)
                    {
                        if (line[i] != '/' && line[i + 1] != '/')
                        {
                            // Counter that checks each constName present in the array of defines
                            for (int p = 0; p < arrayCounter; ++p)
                            {
                                if (strstr(line, arrayDefine[p].constName))
                                {
                                    char *strBegin = strstr(line, arrayDefine[p].constName);
                                    //char *endConstName = strBegin + strlen(arrayDefine[p].constName);
                                    if (line[i] == strBegin[0])
                                    {
                                        for (int c = 0; c < strlen(arrayDefine[p].value); ++c)
                                        {
                                            fprintf(fileIn, "%c", arrayDefine[p].value[c]);
                                        }

                                        i = i + strlen(arrayDefine[p].constName);
                                    }
                                }
                            }
                            fprintf(fileIn, "%c", line[i]);
                        }

                        else if (line[i] == '/' && line[i + 1] == '/')
                        {
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    fclose(myFile);
    fclose(fileIn);
    printf("Number of #define is: %d\n", arrayCounter);
}

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "-i") == 0 && argv[3] == NULL)
    {
        char *filename = argv[2];
        char *input = argv[1];
        nonEmptyLines(filename);
        numberComments(filename);
        preprocessor(filename, input);
    }

    else if (strcmp(argv[3], "-c") == 0)
    {
        char *filename = argv[2];
        char *input = argv[3];
        nonEmptyLines(filename);
        numberComments(filename);
        preprocessor(filename, input);
    }
    return 0;
}