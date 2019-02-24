#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//other functions here
//function for choices
enum CHOICE
{
	
	TREE = 0,
	TRIANGLE = 1,
	NAME = 2,
	EXIT = 3
};

//tree
void printTree(int treeRows)
{
	//print a space just for visual purpose
	printf("\n");
	
	//loop for rows
	for (int i = 1; i <= treeRows; ++i)
	{
		
		//space ( 1 is added as a space for the command line at the end of space for visual purposes) 
		int space = (treeRows - i) + 1; 
		for (int j = 0; j < space; ++j)
		{
			printf(" ");
		}
		
		
		//stars
		int stars = (i*2) - 1;
		for (int z = 0; z < stars; ++z)
		{
			printf("*");
		}
		
		//newline
		printf("\n");
	}
	
	//print tail ( 1 is added as a space for the command line at the end of lastSpace for visual purposes) 
	int lastSpace = (((treeRows * 2) - 2) / 2) + 1; 
	for (int k = 0; k < 2; ++k)
	{
		for (int y = 1; y <= lastSpace; ++y)
		{
			printf(" ");
		}
		printf("*\n");
	}
	
	//print a space just for visual purpose
	printf("\n");

}

//triangle
void printTriangle(int triangleRows)
{
	//print a space just for visual purpose
	printf("\n");
	
	//loop for rows
	for (int i = 1; i <= triangleRows; ++i)
	{
		
		//space ( 1 is added as a space for the command line at the end of space for visual purposes) 
		int space = (triangleRows - i) + 1; 
		for (int j = 0; j < space; ++j)
		{
			printf(" ");
		}
		
		
		//stars
		int stars = (i*2) - 1;
		for (int z = 0; z < stars; ++z)
		{
			printf("*");
		}
		
		//newline
		printf("\n");
	}
	
		//print a space just for visual purpose
	printf("\n");
	
	
}

//name
//remove newline after name
void remove_newline(char *str)
{
	int len = strlen(str);
	if (len > 0 && str[len-1] == '\n')
		str[len-1] = '\0';
}

int myName()
{ 
 //declare character arrays to store name
 char firstName [20];
 char lastName [20];
 char fullName [50];
 
 //prompt for first name and remove newline
 printf("Please insert your name: ");
 fgets(firstName, 20, stdin);
 remove_newline(firstName);
 
 //prompt for first name and remove newline
 printf("Please enter your last name: ");
 fgets(lastName, 20, stdin);
 remove_newline(lastName);
 
 //join the strings
 //strcat looks for null terminator, sert first character of full name
 fullName [0] = '\0';
 //add first
 strcat(fullName, firstName);
 //add space
 strcat(fullName, " ");
 //add second
 strcat(fullName, lastName);
 
 
 //plus:  just as long as we want it for the spaces in between the * 
 //strlen takes only the string and not the escape char \0
 int len = strlen(fullName) + 4; 
 for (int i = 0; i < len; ++i)
 {
	 printf("*");
 }
 printf("\n");
 printf("* %s *\n", fullName);
 for (int i = 0; i < len; ++i)
 {
	 printf("*");
 }
}

//main here
int main(int argc, char* argv)
{
	
	
	
	int flag =1;
	while (flag)
	{
		//buffers
        char choiceBuffer[10];
	    char treeRowsBuffer[20];
	    char triangleRowsBuffer[20];
		
		printf(" \n");
	
		//optionMenu
		printf("Hello, please select an option: \n");
		//options
		printf(" \n");
		printf("0- Print Christmas Tree\n");
		printf("1- Print Triangle\n");
		printf("2- Print your name surrounded by stars\n");
		printf("3- Exit the application. \n");
		printf(" \n");
		
		//get the choice
		printf("Insert a number here: \n");
		fgets(choiceBuffer, 10, stdin);
		enum CHOICE ch = atoi (choiceBuffer);
		printf(" \n");
		
		//switch between choices
		switch (ch)
		{
			case TREE:
			    //rows
			    printf("Insert a number of rows: \n");
				fgets(treeRowsBuffer, 20, stdin);
				int treeRows = atoi(treeRowsBuffer);
				printTree(treeRows);
			    break;
			case TRIANGLE:
			    printf("Insert a number of rows: \n");
				fgets(triangleRowsBuffer, 20, stdin);
				int triangleRows = atoi(triangleRowsBuffer);
				printTriangle(triangleRows);
			
			    break;
			
			case NAME:
			   myName(); 
			   
			    break;
				
		    case EXIT:
			    printf("Exiting... \n");
				flag = 0;
			    break;
	        default:
			    break;
		}
	}
	return 0;
}//end main
