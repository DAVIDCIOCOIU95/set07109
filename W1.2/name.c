#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
	
  //declare character arrays to store name
  char first_name[50];
  char last_name[50];
  char full_name[50];
  
  //prompt for first name
  printf("Please enter your first name: ");
  fgets(first_name, 50, stdin);
  
  // remove the newline character after the name
  // gets the length of the string; finds the null terminator
  int len = strlen(first_name);
  // check if last character is a new line
  if (len > 0 && first_name [len - 1] == '\n')
	  // if so set newline character to null terminator 
    first_name[len - 1] = '\0';
	
  //check if name is Kevin
  if (strcmp(first_name, "Kevin") == 0)
	  printf("Hey! Another Kevin\n");
  else 
	  printf("Oh well\n!");
  
  
  // *** last name ***
  
  //prompt for last name
  printf("Enter your last name here: ");
  fgets(last_name, 50, stdin);
  
  //remove the new line from last name
  int len1 = strlen(last_name);
  //check for the last char as \n
  //remember last char is \0 automatically set by the double quotes "something here"
  if (len1 > 0 && last_name[len1 - 1] == '\n')
   //if so set the last char as \0 (null terminator) 
   last_name [len1 - 1] = '\0';
   
   //check if last name is Sim
   if (strcmp(last_name, "Sim") == 0)
	   printf("Hey Another Sim!\n");
   else
	   printf("Oh well\n");
   
   // Join the strings
  // strcat looks for null terminator
  // set first character of full name
  full_name[0] = '\0';
  //add first name to full name
  strcat(full_name, first_name);
  //add a space (strcat adds immediately after the first when it encounters \0
  strcat(full_name, " ");
  //add last name
  strcat(full_name, last_name);
  //print name 
  printf("Your name is %s which is %d characters long\n",  full_name, strlen(full_name));
  
  return 0;
 
}
   

