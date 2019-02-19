#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

// Read in a block of data as an int array
int readfile (int **data)
{
	// Open file for reading
	FILE *file;
	file = fopen("numbers.dat", "rb");
	// First value is number of integers
	int size;
	fread(&size, sizeof(int), 1, file);
	// Allocate memory for that number of values
	*data = (int*)malloc(sizeof(int) * size); 
	// Read in rest of data
	fread(*data, sizeof(int), size, file);
	// Return size
	return size; 
}

int main (int argc, char **argv)
{
	// Declare data
	int *data;
	// Read in file
	int size = readfile(&data);
	// Sort 
	sort(size, data);
	// Print first 20 results
	for (int i = 0; i < 20; ++i)
		printf("%d\n", data[i]);
	
	// Free the allocated memory - otherwise a memory leak! (very bad)
	free(data);
	
	return 0;
}