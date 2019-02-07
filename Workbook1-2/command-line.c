#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	//loop for number of arguments
	for (int i = 0; i< argc; ++i)
	{printf("Argument %d: %s\n", i, argv[i]);
	}
	printf("All arguments printed.\n");
	char number [50];
	printf("Insert n: \n");
	fgets(number, 50, stdin);
	
	for (int i = 0; i< argc; ++i)
	{printf("Argument %d: %s\n", i, argv[i]);
	}
	return 0;
	
}