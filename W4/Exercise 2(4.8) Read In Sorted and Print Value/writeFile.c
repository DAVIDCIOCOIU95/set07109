#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// Reads in a block of data as an int array
int readfile(int **data)
{
	// Open file for reading 
	FILE *file;
	file = fopen("numbers.dat", "rb");
	// First value is number of integers
	int size;
	fread(&size, sizeof(int), 1, file);
	// Allocate memmory for that number of values
	*data = (int*)malloc(sizeof(int) *size);
	// Read in rest of data
	fread(*data, sizeof(int), size, file);
	// Close file
	fclose(file);
	// Return size
	return size;
}

// Writes strings to the file
void writefile(int size, int *data)
{
	// Create file
	FILE *file;
	file = fopen("sorted.txt", "w");
	// Loop through each value, writing to the file
	for (int i = 0; i < size; ++i)
		fprintf(file, "%d\n", data[i]);
	// Close the file
	fclose(file);
}

int main(int argc, char **argv)
{
	// Read in data
	int *data;
	int size = readfile(&data);
	// Sort 
	sort(size, data);
	// Write the data
	writefile(size, data);
	// Free the allocated memory - otherwise a memory leak!
	free(data);

	return 0;
}
