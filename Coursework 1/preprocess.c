/* Author: David Ciocoiu 
   Last Modification: 28/02/2019
   Purpose of the program: this program takes in as an input 
   a file.c outputting a preprocessed document file.o. 
   The program will count: the number of lines and non empty lines in our file.c
   along with the number of comments in the file (any line preceded by //).
   The file.o will be a preprocessed document including eny eventual header code,
   #define constants sobsituted through the file with the appropriate value.
   We can also choose wether to leave the comments in the file.o or remove them.
   Read readme document for further information.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define myLength 30000

// Non-empty lines
/* Returns the number of non empty lines into a file;
a non empty line is defined as having a char different than \t \n or space.
The function takes in a file.c as a parameter to be openned passed in from the command line. 
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
a comment is defined as following a // .
The function takes in a file.c as a parameter to be openned an analyzed. 
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
/* See each section for detailed description.
The function takes in as parameters a file.c passed from the command line 
and an input deriving from the command line argv[], equivalent to -i or -c.
*/

// struct used to get in the #define const_name and value if present in our file.c
// The struct will be saved into an array from which it will be retrieved into a loop to 
// check if the file in its lines contains any const_name and sobstitutes it with the appropriate value if true. 
struct definePairs
{
    char constName[30];
    char value[30];
};

// Beginning of our preprocessor function 
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

    // Various arrays and values used to store #include, #define, lines or counters
    char line[myLength];
    char myHeaderName[100];
    char *includeString = "#include";
    char headerLine[myLength];
    char *defineString = "#define";
    struct definePairs arrayDefine[30];
    int arrayCounter = 0;

    // Loop thourgh the file to check each line
    while (!feof(myFile))
    {
        // Get each line 
        if (fgets(line, myLength, myFile) != NULL)
        {
            // INCLUDE PREPROCESS
            for (int c = 0; c < strlen(line); ++c)
            {
                // Check if the line includes #include 
                if (strstr(line, includeString))
                {
                    // Get from the line the name of the header file;
                    // store the header name into an array myHeaderName
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
                    // Open the Header File;
                    // Get ready to sobstitute its content
                    FILE *myHeaderFile;
                    myHeaderFile = fopen(myHeaderName, "r");

                    if (myHeaderFile == NULL)
                    {
                        printf("Couldn't open your file.txt\n");
                    }

					// Pass content of file.h to file.o 
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

                // DEFINE PREPROCESS
				// Check if the line includes #define 
				// Store every define into an array made of struct with const_name and value 
                else if (strstr(line, defineString))
                {
					// Initialize the struct 
                    struct definePairs definePairs1;
					// Get the length of the  #define   string
                    int defineLength = strlen(defineString);
                    int flag = 1;
                    // Set two counters for const_name and value
                    int counterValue = 0;
                    int counterConst = 0;
					// Iterate through each char in the line 
                    for (int d = 0; d < strlen(line); ++d)
                    {
						// If it is the end of the line then null terminate the two strings in the struct at this index 
                        if (line[d + defineLength] == '\n')
                        {
                            definePairs1.constName[counterConst] = '\0';
                            definePairs1.value[counterValue] = '\0';
                            break;
                        }

						// If line after our #define string is not an empty line then evaluate the two flags
                        if (line[d + defineLength] != ' ' && line[d + defineLength] != '\t' && line[d + defineLength] != '\n')
                        {
							// Starting flag: allows the program to get in the constant name of #define 
                            if (flag == 1)
                            {
                                definePairs1.constName[counterConst] = line[d + defineLength];
                                counterConst++;
                            }

							// Second flag: allows the program to get in the value of #define
                            if (flag == 0)
                            {
                                definePairs1.value[counterValue] = line[d + defineLength];
                                counterValue++;
                            }
                        }
						// If the line after #define is a space char and we already got in something in counterConst (meaning the counter is > 0)
						// then set the flag to 0 (allows the loop at the stage above to start getting in the value of #define)
                        else if (line[d + defineLength] == ' ' && counterConst > 0)
                        {
                            flag = 0;
                        }
                    }
					// Now that we have the our struct for #define we store it in the array for structs
                    arrayDefine[arrayCounter] = definePairs1;
					// Setting the counter of our array containing structs plus one (will store the next struct in the next index)
                    arrayCounter++;
                    break;
                }
                // -c  INPUT
				// Allows us to keep the comments in the .o file
				// Runs instead of -i
				// The input parameter comes from the command line 
				// Also checks if the line contains the define constantName and replaces it with the value 
                else if (strcmp(input, "-c") == 0)
                {
                    for (int i = 0; i < strlen(line); ++i)
                    {

                        // Counter that checks each constName present in the array of structs with the define features
                        for (int p = 0; p < arrayCounter; ++p)
                        {
							// If the line contains the constant of #define then swap constant with value in the file.o
                            if (strstr(line, arrayDefine[p].constName))
                            {
								// Get the beggining of our current #define constant
                                char *strBegin = strstr(line, arrayDefine[p].constName);
                                
								// If the char at line[i] equal to our pointer start sobstituting const with value
                                if (line[i] == strBegin[0])
                                {
									// Print the value to the file.o
                                    for (int c = 0; c < strlen(arrayDefine[p].value); ++c)
                                    {
                                        fprintf(fileIn, "%c", arrayDefine[p].value[c]);
                                    }

									// Get to the end of the constant to get in the next of the line 
                                    i = i + strlen(arrayDefine[p].constName);
                                }
                            }
                        }
						// Print the what is left in the line 
                        fprintf(fileIn, "%c", line[i]);
                    }
                    break;
                }

                // -i   INPUT 
				// Removes comments
				// Sobstitutes #define const_names with values stored into a an array made of structs
                else if (strcmp(input, "-i") == 0)
                {
                    // Get each char in line to check for // 
                    for (int i = 0; i < strlen(line); ++i)
                    {
                        if (line[i] != '/' && line[i + 1] != '/')
                        {   
                            // Counter that checks each constName present in the array of defines
                            for (int p = 0; p < arrayCounter; ++p)
                            {
                                // Check for the constant name presence in the line
                                if (strstr(line, arrayDefine[p].constName))
                                {
                                    // Set the beginning of constant_name in the line
                                    char *strBegin = strstr(line, arrayDefine[p].constName);
                                    
                                    // If line at index i begins with pointer to strBegin(constName)
                                    if (line[i] == strBegin[0])
                                    {
                                        // Print to the const_name position in the file the respective value
                                        for (int counter = 0; counter < strlen(arrayDefine[p].value); ++counter)
                                        {
                                            fprintf(fileIn, "%c", arrayDefine[p].value[counter]);
                                        }
                                        // Get to the end of const name and print what you find after
                                        i = i + strlen(arrayDefine[p].constName);
                                    }
                                }
                                
                            }
							// Print rest of the line 
                            fprintf(fileIn, "%c", line[i]); 
                        }

						// Printing the / value 
                        else if (line[i] == '/' && line[i + 1] != '/')
                        {
							// Necessary to print the / in the line 
                            fprintf(fileIn, "%c", line[i - 1]);
                            fprintf(fileIn, "%c", line[i]);
                        }
                        
						// If the line is a comment then set the line to end and break 
                        else if (line[i] == '/' && line[i + 1] == '/')
                        {
                            fprintf(fileIn, "%c", '\n');
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
	// Close the files
    fclose(myFile);
    fclose(fileIn);
   // printf("Number of #define is: %d\n", arrayCounter);
}

int main(int argc, char **argv)
{
	// If argv in commant line at 1 is -i and argv at position 3 is null then get get non empty lines; number comments and a preprocessd file.o without comments
    if (strcmp(argv[1], "-i") == 0 && argv[3] == NULL)
    {
        char *filename = argv[2];
        char *input = argv[1];
        nonEmptyLines(filename);
        numberComments(filename);
        preprocessor(filename, input);
    }

	// Leaves the comments in the file.o if argv at position 3 in command line is -c 
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