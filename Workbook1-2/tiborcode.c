// stdio contains standard C input - output functions
#include <stdio.h>
// contains hleper functions for strings
#include <string.h>
#include <stdlib.h>


/*
double calculate_wage(double rate, double hours)
{
	return rate * hours;
}

void remove_newline(char *str)
{
	int len = strlen(str);
	if (len > 0 && str[len-1] == '\n')
	{
		str[len-1] = ' ';
	}
}
void xmas(int rows)
{
	int n, spaceN;
	for(int i = 1; i<=rows; i++)
	{
		n = i*2-1;
		spaceN = i+rows-n;
		
		for (int j = 0; j<spaceN; j++)
		{
			printf("%c",' ');
		}
		for (int k = 0; k<n; k++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
	
	for(int l = 0; l<2; l++)
	{
				
		for (int m = 0; m<(rows*2+1)/2; m++)
		{
			printf("%c",' ');
		}
		printf("%c\n",'*');
	}
}

void triangle(int rows)
{
	int n, spaceN;
	for(int i = 1; i<=rows; i++)
	{
		n = i*2-1;
		spaceN = i+rows-n;
		
		for (int j = 0; j<spaceN; j++)
		{
			printf("%c",' ');
		}
		for (int k = 0; k<n; k++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
}
	
	*/

// Our main function .
// argc is the number of command line arguments
// argv are the command line arguments
// We will look at these later

int main (int argc , char **argv )
{
	
	//--------------------------------------------- HELLO WORLD ---------------------------------------------
	
	/*
	// Print hello world to the screen
	
	printf ("Hello World!\n");
	printf ("Hello World!_2\n");
	
	char msg_1[6] = {'H','e','l','l','o','\0'};
	char msg_2[8] = " World!";
	
	char msg_3[9] = "Goodbye!\0";
	
	char msg_4[] = "Compiler worked out my size!";
	
	char *msg_5 = "Compiler worked out my size too!";
	
	*/
		
	//--------------------------------------------- NAME ---------------------------------------------
	
	/*
	printf("%s\n", msg_1);
	printf("%s\n", msg_2);
	printf("%s\n", msg_3);
	printf("%s\n", msg_4);
	printf("%s\n", msg_5);
	

	
	char first_name[50];
	char last_name[50];
	char full_name[50];
	
	//first name
	
	printf("Enter your first name: ");
	
	fgets(first_name, 50, stdin);
	
	int len = strlen(first_name);
	
	if (len > 0 && first_name[len-1] == '\n')
		first_name[len-1] = '\0';
	
	if (strcmp(first_name, "Kevin") == 0)
		printf("Hey! Another Kevin!\n\n\n");
	else
		printf("Oh well\n");
	
	
	//last name
	
	printf("Enter your last name: ");
	
	fgets(last_name, 50, stdin);
	
	int length = strlen(last_name);
	
	if (length > 0 && last_name[length-1] == '\n')
		last_name[length-1] = '\0';
	
	//full name
	
	full_name[0] = '\0';
	
	strcat(full_name, first_name);
	strcat(full_name, " ");
	strcat(full_name, last_name);
	
	printf("your name is %s which is %d characters long \n", full_name, strlen(full_name));
	*/
	
	//--------------------------------------------- STARS ---------------------------------------------	
	
	/*
	int flag = 1;
	while(flag)
	{
		char buffer[10];
		printf("How many stars? (0 to quit) ");
		fgets(buffer, 10, stdin);
		//convert string to number
		int number = atoi(buffer);
		
		if(!number)
		{
			flag = 0;
			continue;
		}
		//print stars
		for (int i = 0; i < number; ++i)
		{
			//printf("*");
			for (int j = 0; j < i+1; ++j)
				printf("*");
			printf("\n");
		}
	}
	printf("Bye\n\n");*/
	
	//--------------------------------------------- CASE ---------------------------------------------
	
	/*
	int flag2 = 1; 
	while (flag2) 
	{ 
		// Print menu 
		printf("1 - say hello\n"); 
		printf("2 - say goodbye\n"); 
		printf("0 - exit\n"); 
		printf("Enter choice - "); 
		
		// Read input 
		char buffer[10]; 
		fgets(buffer , 10, stdin); 
		// Convert to number 
		int number = atoi(buffer); 

		// Work on input 
		switch (number) 
		{ 
			case 1: 
				printf("Hello World!\n"); 
				break; 
			case 2: 
				printf("Goodbye World!\n"); 
				break;
			case 0: 
				printf("Exiting...\n"); 
				flag2 = 0; 
				break;
			//if none of the other cases are met
			default:  
				printf("*** INVALID INPUT ***\n"); 
				break; 
		} 
	} 
	*/
	
	//--------------------------------------------- WAGE CALCULATOR ---------------------------------------------
	
	/*
	int flag = 1;
	while (flag !=0)
	{
		char name[50];
		char number[10];
		
		printf("please enter your name: ");
		fgets(name,50,stdin);
		remove_newline(name);
		if (strcmp(name, "0") == 00)
		{
			flag = 0;
			continue;
		}
		
		printf("Enter hourly rate: ");
		fgets(number,10,stdin);
		double rate = atof(number);
		
		printf("Enter hours: ");
		fgets(number,10,stdin);
		double hours = atof(number);
		
		double wage = calculate_wage(rate, hours);
		
		printf ("wage of %s : %.2f GBP\n", name, wage);
					
		//break;
		
	}
	printf("Bye");
		*/
		
	//--------------------------------------------- ARGC ARGV ---------------------------------------------
	
	/*
	for (int i = 0; i < argc; ++i)
	{
		printf("Argument %d: %s\n", i, argv[i]);
	}
	printf("All arguments printed.\n");
	// printf(argv[0]);   argv[0] = name of the file
	*/
	
	//--------------------------------------------- EXERCISE 1 ---------------------------------------------

	
	/*
	char name[50];
	printf("Enter your name: ");	
	fgets(name, 50, stdin);	
	remove_newline(name);
	int len = strlen(name);
	
	for(int i = 0; i<strlen(name)+3; ++i)
	{
		printf("*");
		++j;
	}
	printf("\n");
	printf("* %s*\n", name);
	for(int i = 0; i<strlen(name)+3; ++i)
	{
		printf("*");
	}
	*/
	
	
	//--------------------------------------------- EXERCISE 2 ---------------------------------------------
	/*
	int flag = 1;
	int sum = 0;
	int n = 0;
	
	char name[50];
	printf("Enter your name: ");	
	fgets(name, 50, stdin);	
		
	while (flag) 
	{ 
		// Print menu
		printf("Please enter your grade (1-5): \n"); 
		printf("Press 0 to exit\n"); 		
		char buffer[10]; 
		fgets(buffer , 10, stdin); 		
		remove_newline(name);
		// Convert to number 
		int number = atoi(buffer); 

		// Work on input		
		switch (number) 
		{ 
			case 1: 
				sum += number;
				n++;
				break;
			case 2: 
				sum += number;
				n++;
				break;
			case 3: 
				sum += number;
				n++;
				break;
			case 4: 
				sum += number;
				n++;
				break;
			case 5: 
				sum += number;
				n++;
				break;
			case 0: 
				int avg = sum/n;
				printf("%s  %d",name, avg); 
				flag = 0; 
				break;
			//if none of the other cases are met
			default:  
				printf("*** INVALID INPUT ***\n"); 
				break; 
		} 
	} 
	*/
	
	
	//--------------------------------------------- EXERCISE 3 ---------------------------------------------
	
	int n, spaceN;  //n = number of stars,   spaceN = the space before and after the stars
	char number[10];
	
	printf("Number of rows: \n");	
	fgets(number, 10, stdin);
	int rows = atof(number);
	
	for(int i = 1; i<=rows; i++)
	{
		n = i*2-1;
		spaceN = i+rows-n;
		
		for (int j = 0; j<spaceN; j++)
		{
			printf("%c",' ');
		}
		for (int k = 0; k<n; k++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
	
	for(int l = 0; l<2; l++)
	{
				
		for (int m = 0; m<(rows*2+1)/2; m++)
		{
			printf("%c",' ');
		}
		printf("%c\n",'*');
	}
	
	
	
	//--------------------------------------------- EXERCISE 4 ---------------------------------------------	
	/*
	//n = number of stars,   spaceN = the space before and after the stars
	char number[10];
	
	printf("Triangle or Christmas tree (t / x)?\n");
	char choice = fgetc(stdin);	
	//printf("%c", choice);
	int rows;
	if (choice == 'x')
	{		
		printf("Number of rows: \n");
		scanf("%d", &rows);
		xmas(rows);	
	}
	if (choice == 't')
	{		
		printf("Number of rows: \n");
		scanf("%d", &rows);
		triangle(rows);	
	}
	else 
	{
		printf("INVALID INPUT\n");
	}
	*/
	
	char *str = "2.5";
	float f = atof(str);
	f = f * 2.0f;
	printf("%.2f\n", f);
	
	
	// Return value from program
	return 0;
}
