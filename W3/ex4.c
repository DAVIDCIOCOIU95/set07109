#include <stdio.h>

void func()
{
	char name[50];
	fgets(name, 50, stdin);
}
int main(int argc, char **argv)
{
	char *message = "Please enter your name here: \n";
	char storedName[50];
	//char *name[50]
	
	__asm
	{
		call printf
		call func
	}//end asm
	
	//printf("Your name is: %s\n", *name);
	
	
	
	
	return 0;
}//end main
