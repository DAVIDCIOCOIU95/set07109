#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//an app that has a menu system using an enum and case stament
//it provides the abilit to enter a student's details, print the students details or exit the system
//only one student variable should be in existence (should overwrite details when a new student is entered)

enum CHOICE 
{
	ENTER = 0,
	PRINT = 1,
	EXIT = 2
};

struct student
{
	int matric;
	char *name;
	char *address;
};

void printStudent(struct student s)
{
	printf("Student matric is: %d\n", s.matric);
	printf("Student name is: %s\n", s.name);
	printf("Student address is: %s\n", s.address);
}


int main(int argc, char **argv)
{
	int flag = 1;
	
	
	//student default
	struct student s;
	
	//buffers
	char buffer1[20];
	 char buffer2[20];
	 char buffer3[20];
	 char buffer[20];
	
	
	
	
	
	
	while (flag)
	{
		
		
		//display menu
		printf("\n");
		printf("Hello, please select one of the following options: \n");
		printf("0 - Enter a student's details.\n");
		printf("1 - Print student's details.\n");
		printf("2 - Exit the application.\n");
		printf("Please enter a number here and press enter: \n");
		
		//get the input into the CHOICE variable
		fgets(buffer, 20, stdin);	
		enum CHOICE ch = atoi(buffer);
		
		//following week 3 exercises I noticed I could store these values from fgets into arrays or strings that are already in the struct 
		//however I won't change the code here 
		switch (ch)
		{
			case ENTER:
			     printf("Enter student's matric: \n");
				 fgets(buffer1, 20, stdin);
				 int matriculation = atoi (buffer1);
				 s.matric = matriculation;
				 
				 printf("Enter student's name: \n");
				 fgets(buffer2, 20, stdin);
				 s.name = buffer2;
				 
				  printf("Enter student's address: \n");
				 fgets(buffer3, 20, stdin);
				 s.address = buffer3;	
                 				 
			break;
			
			case PRINT:
			     printStudent(s);
		    break;
			
			case EXIT:
			     printf("Exiting...\n");
				 flag = 0;
		    break;
			
			default:
			       printf("Invalid Input\n");
			break;
		}
		
		
	}//end while
	
	return 0;
}