#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define mylength 10

int main(int argc, char **argv)
{
	char buffer[mylength];
	FILE *fp;
	int lineno = 0;
	
	if ((fp = fopen("sorted.txt","r")) == NULL)
	{
		printf("Could not open sorted.txt\n");
		exit(1);
	}

	while ( !feof(fp))
	{
		// read in the line and make sure it was successful
		if (fgets(buffer,mylength,fp) != NULL)
		{
		printf("%d: %s",lineno++,buffer);
		}
	}

	return 0;
}


/*
To read user input or lines from a file, the safest mechanisms is
fgets.  While there are other choices, the methodology presented 
below will work in any language.  

To read from user input or a file, you can read one entire line at 
a time and then parse the line (divide it into parts that you want)
using string functions.

First let's see how to read in from the file:

If you type "man fgets" into a unix terminal, you will see the following
related to fgets:

char *fgets(char *s, int size, FILE *stream);
fgets() reads in at most one less than size characters from stream  and
stores  them  into  the buffer pointed to by s.  Reading stops after an
EOF or a newline.  If a newline is read, it is stored into the  buffer.
A '\0' is stored after the last character in the buffer.

The first line tells us that it returns a char * and expects three
arguments: s, size, and stream.  

s is the destination.  You need to have already declared and allocated
space for that destination.  fgets does not allocate any memory.

size is the size, in bytes, of the space you have allocated (s).  So
if s is 500 characters, put 500 as size.

stream is where it is reading 
FROM.  If you are reading from the keyboard, use stdin for the stream.
If you are reading from a file, you need to have opened that file.

So, if we are reading from the keyboard, we would do the following:

char buffer[500];

// read in the line and make sure it was successful
if (fgets(buffer,500,stdin) != NULL)
{
	// now we process the line
}

If we are reading all the lines in from a file named "myinputfile.txt" 
then we would do the following:

char buffer[500];
FILE *fp;
if ((fp = fopen("myinputfile.txt","r")) == NULL)
{
	printf("Could not open myinputfile.txt\n");
	exit(1);
}

while ( we are not done yet )
{
	// read in the line and make sure it was successful
	if (fgets(buffer,500,fp) != NULL)
	{
		// now we process the line
	}
}

There are two pieces missing - how to check if we are done and how 
to process the line.

To check if we are done, we use feof.

while (!feof(fp))
{

	// read in the line and make sure it was successful
	if (fgets(buffer,500,fp) != NULL)
	{
		// now we process the line
	}

}

Here is code that reads in and prints out all of the lines in a file,
inserting the line number at the beginning of each line.

char buffer[500];
FILE *fp;
int lineno = 0;
if ((fp = fopen("myinputfile.txt","r")) == NULL)
{
	printf("Could not open myinputfile.txt\n");
	exit(1);
}

while ( !feof(fp))
{
	// read in the line and make sure it was successful
	if (fgets(buffer,500,fp) != NULL)
	{
		printf("%d: %s",lineno++,buffer);
	}
}
*/