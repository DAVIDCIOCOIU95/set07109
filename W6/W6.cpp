 #include <iostream>
 #include <cstdlib>
 #include <cstdio>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
// calloc and malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * myCalloc()
{
	int *data = (int*)calloc(20, sizeof(int));

	for (int i = 0; i < 20; ++i)
		data[i] = i;
	return data;
}
// Testing malloc
int main(int argc, char **argv)
{
	// Allocate some memory in the heap
	int *data = (int*)malloc(sizeof(int) * 10);

	// Create an array
	for (int i = 0; i < 10; ++i)
	{
		data[i] = i;
	}

	for (int i = 0; i < 10; ++i)
		printf("%d\n", data[i]);
	// Free the memory in the heap
	free(data);

	// Call myCalloc
	int *myData = myCalloc();

	for(int i = 0; i < 20; ++i)
		printf("%d\n", myData[i]);

	free(myData);

	return 0;
}
*/
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//6.9/6.10
/*
 //Size of data to allocate
const long SIZE = 1048576;

int main(int argc, char **argv)
{
    // Try and create data on the stack
    // This is 1MB - common stack size
    // Other values take us over the stack size
    char data[SIZE];
	for (long i = 0; i < SIZE; ++i)
		data[i] = i;

	for (long i = 0; i < SIZE; ++i)
		printf("%lu\n", data[i]);

    return 0;
} 
*/

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
// 1 megabyte in bytes
const unsigned int MB = 1024 * 1024;
// 1 gigabyte in bytes
const unsigned int GB = 1024 * MB;

int main(int argc, char **argv)
{
    // Allocate 1 GB of data
    char *data = (char*)malloc(GB);
    
    // Need to "use" the data before actual allocation occurs
    for(int i =0; i < 100; ++i)
    {
        data[i] = i; // Optional just to see that the array can actually be filled with values
        printf("%d\n", data[i]);
    }
    
    free(data);

    return 0;
}
*/

//6.12 Pointer to pointer
/*
void foo(int **value)
{
	// Create a pointer to store the memory allocated
	*value = (int*)malloc(sizeof(int) * 1);
	**value = 5;
	printf("Address of value is: %d; and value of value is: %d\n", *value, **value);
}

int main(int argc, char **argv)
{
	int *value = (int*)calloc(1, sizeof(int));
	// point to &value and set its content to 10;
	*value = 10;
	printf("Address of value is: %d; and value of value is: %d\n", value, *value);

	// Call foo; point to 
	foo(&value);

	free(value);

	return 0;
}
*/

//6.14 new and delete
/**/

// Note that here we do not create an array but allocate space for one int
int *foo()
{
	// Create memory on the heap
	int *data = new int(5);
	
	return data;
}
//----------------

// Note that here we create an array: retrieval in main is via &data[i]
// and not *data
int *foo2(unsigned int size)
{
	// Create array on heap
	int *data = new int[size];

	return data;
}

// The output will skip address of 4 as we are using int to allocate memory 
int main(int argc, char **argv)
{
	// Call foo
	int *data = foo();
	// Output address and value
	cout << "Address = " << data << ", value = " << *data << endl;
	// Delete the memory
	delete data;
	//------------------------------
	//Call foo2
	int *data2 = foo2(20);
	// Output addresses and value
	for (int i = 0; i < 20; ++i)
		cout << "Address = " << &data[i] << ", value = " << data[i] << endl;
	// Delete the memory
	delete[] data2;
	return 0; 
}







