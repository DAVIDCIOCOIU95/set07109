#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define arraysize 999999999

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
	
	char line[arraysize]; 
	while(fgets(line,arraysize,file)!= NULL)
	{
		fgets(line,arraysize,file);
		printf("%s", line);
	}
		
	fclose(file);
	return 0;
	
	
}