#include <iostream>

int* create_array()
{
	// This memory is created on the stack
	int data[20];
	for (int i = 0; i < 20; ++i)
		data[i] = i;
	return data;
	// Stack emptied - memory gone
}

int* create_array_new()
{
	// Memory created on the heap
	int *data = new int[20];
	for (int i = 0; i < 20; ++i)
		data[i] = i;
	return data;
	// Memory created on the heap still relevant 
}

void create_array(int *data)
{
	for (int i = 0; i < 20; ++i)
		data[i] = i;
}

int main(int argc, char **argv)
{
	int *data = create_array();
	// Print out all elements 
	for (int i = 0; i < 20; ++i)
		std::cout << data[i] << std::endl;

	data = create_array_new();
	// Print out elements
	for (int i = 0; i < 20; ++i)
		std::cout << data[i] << std::endl;
	// Free the memory
	delete[] data;
	// Set to nullptr
	data = nullptr;

	// Create array from pointer
	// This will cause a memory allocation error
	// nullptr (memory address 0) cannot be allocated to 
	// create_array(data);

	// Allocate memory
	data = new int[20];
	// Create array from pointer
	create_array(data);
	// Print out all elements
	for (int i = 0; i < 20; ++i)
		std::cout << data[i] << std::endl;
	// Free the memory 
	delete[] data;
	// Set to nullptr
	data = nullptr;

	return 0;
}