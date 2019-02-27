#include <iostream>
#include <fstream>
#include <string>
#include "sort.h"

std::vector<int> readfile(std::string &filename)
{
	// Open the file
	std::ifstream file(filename, std::ios::binary);
	// Get the size of the file - seek the end
	file.seekg(0, file.end);
	std::streampos size = file.tellg();
	// Seek back to start 
	file.seekg(0, file.beg);
	// Number of elements is size / sizeof(int)
	int elements = size / sizeof(int);
	// Create an array of data to read into
	int *temp = new int[elements];
	//Read in data
	file.read((char*)temp, size);
	// Close the file
	file.close();
	// Copy data into the vector
	std::vector<int> data(temp, temp + elements);
	// Delete the data
	delete [] temp;
	// Return the vector
	return data;
}

int main(int argc, char **argv)
{
	// Read in a vector
	std::vector<int> data = readfile(std::string("numbers.dat"));
	// Print the vector size
	std::cout << "Numbers read = " << data.size() << std::endl;
	// Sort the vector
	sort(data);
	// Output first 100 numbers
	for (int i = 0; i < 100; ++i)
		std::cout << data[i] << std::endl;

	return 0;
}