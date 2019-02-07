#include <stdio.h>
// the main C standard library header
#include <stdlib.h>
#include <string.h>

//calculate wage
double calculate_wage(double rate, double hours)
{
	return rate * hours;
}

//remove newline. pass in modifiable value
void remove_newline(char *str)
{
	//gets the length of the string
	int len = strlen(str);
	//check if last character is a newline
	if (len > 0 && str[len - 1] == '\n') 
       //if so set newline character to null terminator
	   str[len-1] = '\0';
}

int main(int argc, char **argv) 
{
	//flag to continue
	int flag = 1;
	while (flag != 0)
	{ 
       //buffer for name
	   char name [50];
	   //buffer for number
	   char number [10];
	   //prompt for first name
	   printf("Insert your name here: ");
	   //read name into array
	   fgets(name, 50, stdin);
	   //strop newline
	   remove_newline(name);
	   //if name is 0 then exit
	   if (strcmp(name, "0") == 0 )
	   { 
         flag = 0;
         continue;
	   }
	   //prompt for hourly rate
	   printf("Enter hourl rate: ");
	   //read value into array
	   fgets(number, 10, stdin);
	   //convert to float
	   double rate = atof(number);
	   //prompt for hours
	   printf("Enter hours: ");
	   fgets(number, 10, stdin);
	   //convert to float 
	   double hours = atof(number);
	   //calculate wage
	   double wage = calculate_wage(rate, hours);
	   //output
	   printf("Wage for %s: %.2f\n", name, wage);
	   
	}
	//print goodbye
	printf("Goodbye!");
	return 0;
}