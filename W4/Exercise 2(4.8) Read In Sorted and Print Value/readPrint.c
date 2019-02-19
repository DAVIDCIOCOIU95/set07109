#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/*An app that:
- reads in a sorted text file 
- prints out the values 
- using fgets to read in lines from text file 
*/

int main(int argc, char **argv)
{
	//open the file
	FILE *file;
	file = fopen("sorted.txt", "r");
	
	if ((file = fopen("sorted.txt","r")) == NULL)
	{
	printf("Could not open myinputfile.txt\n");
	}
	
	char line[10]; 
	for (int i = 0; i < 262144; ++i)
	{
		fgets(line, 10, file);
		printf("%s", line);
	}
		
	fclose(file);
	free(line);
	return 0;
	
	
}