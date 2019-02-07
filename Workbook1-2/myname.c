#include <stdio.h>
#include <string.h>



//remove newline after name
void remove_newline(char *str)
{
	int len = strlen(str);
	if (len > 0 && str[len-1] == '\n')
		str[len-1] = '\0';
}



int main(int argc, char **argv)



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
 
 return 0;
 
}