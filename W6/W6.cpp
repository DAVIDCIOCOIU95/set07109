/*
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory>

using namespace std;
*/
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
/*

// Note that here we do not create an array but allocate space for one int
int *foo()
{
	// Create memory on the heap
	int *data = new int(5);
	cout << "Address of foo one value: " << data << ",value: " << *data << endl;
	
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
	// data stores the address of *data in foo; therefore *data will be a pointer do data in foo 
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
*/

//-----------------------------------------------------------------------------------

// 6.16 Using shared_ptr
/*
void foo(shared_ptr<int> value)
{
	// Print out number of accessors ot the shared object - should be 2 
	cout << "In foo, count on shared_ptr = " << value.use_count() << endl;
	// shared_ptr behaves like a pointer - we can assign to it by deferencing 
	*value = 5; 
}

int main(int argc, char **argv)
{
	// We can create a shared_ptr by wrapping it around an allocated object
	shared_ptr<int> value = shared_ptr<int>(new int(10));
	cout << "Initial address = " << value << ", value = " << *value << endl;
	// We can also create a shared_ptr by using the make_shared function
	value = make_shared<int>(70);
	cout << "After make shared, address = " << value << ",value = " << *value << endl;
	// Print out number of accessors tot he shared object 
	cout << "Before foo, count on shared_ptr = " <<  value.use_count() << endl;
	// Let's call foo
	foo(value);
	cout << "After foo, address = " << value << ", value = " << *value << endl;
	// Print out number of accessors to the shared object 
	cout << "After foo, count on shared_ptr = " << value.use_count() << endl;
	// Let's set value to nullptr - this will clear the memory 
	value = nullptr;
	// Print out number of accessors to the shared object. Should be 0
	cout << "After nullptr, count on shared_ptr = " << value.use_count() << endl;
	
	return 0;
}
*/

// --------------------------------------------------------------------

// 6. 18 Examining the shared_ptr Value 
/*
void foo(shared_ptr<int> value)
{
	// Output number of accessors to value - 2 
	cout << "In foo, accessors to value = " << value.use_count() << endl;
	// Call make_shared again - we lose this copy
	value = make_shared<int>(25);
	// Output number of accessors to value - should be 1 
	cout << "In foo, after make_shared, accessors to value = " << value.use_count() << endl;
	// No memory leaks! shared_ptr will clean itself up
}

// Note we now have a reference to the shared_ptr
void foo2(shared_ptr<int> &value)
{
	// Output number of accessors to value - should be 1 
	cout << "In foo 2, accessor to value = " << value.use_count() << endl;
	// Call make_shared again - we retain this copy
	value = make_shared<int>(100);
	// Output number of accessors to value - should still be 2 
	cout << "In foo2, after make_shared, accessors to value = " << value.use_count() << endl;
}

int main(int argc, char **argv)
{
	// Create a new shared_ptr
	shared_ptr<int> value = make_shared<int> (5);
	// Print data
	cout << "Address = " << value << ", value = " << *value << ", usage = " << value.use_count() << endl;
	// Call foo
	foo (value);
	// Print data
	cout << "Address = " << value << ", value = " << *value << ", usage = " << value.use_count() << endl;
	// Call foo2
	foo2(value);
	// Print data
	cout << "Address = " << value << ", value = " << *value << ", usage = " << value.use_count() << endl;

	return 0; 
}
*/

// -------------------------------------------------------------------
// 6.12 Using shared_ptr for Arrays 
/*
const int SIZE = 65536;

void build_array(shared_ptr<int> data)
{
	for (int i = 0; i < SIZE; ++i)
		// Have to deference the pointer, then access the values
		data.get()[i] = i;
}

void print_array(shared_ptr<int> data)
{
	for (int i = 0; i < SIZE; ++i)
		// Have to deference the pointer, then access the values
		cout << data.get()[i] << endl;
}

int main(int argc, char **argv)
{
	// We have to tell shared_ptr to delete the data
	// When creating use the default_delete function
	shared_ptr<int> data = shared_ptr<int>(new int[SIZE], default_delete<int[]>());
	// Build the array
	build_array(data);
	// Print the array
	print_array(data);
	// Set data to nullptr - will cause data to be deleted
	data = nullptr; 

	return 0;
}
*/

//------------------------------------
// 6.21 Using unique_ptr
/*
void foo(unique_ptr<int> value)
{
	// Let's set the value to 500. Can treat just as a pointer
	*value = 500;
	// We don't return unique_ptr. We have lost *ALL* the data
}

unique_ptr<int> foo2(unique_ptr<int> value)
{
	// This time we will move the answer back
	*value = 500;
	return value; 
}

void foo3(unique_ptr<int> &value)
{
	// Using a reference solves the problem 
	*value = 100;
}

int main(int argc, char **argv)
{
	// Create a unique_ptr value
	unique_ptr<int> value (new int(50));
	// Print data
	cout << "Address = " << value.get() << ", value = " << *value << endl;
	// Call foo. We have to "move" the pointer into foo
	foo(move(value));
	// Print data. Cannot print value. No longer valid. 
	cout << "After foo, address = " << value.get() << endl;

	// Recreate the value
	value = unique_ptr<int>(new int(500));
	// Print data
	cout << "Address = " << value.get() << ",value = " << *value << endl;
	// Call foo2. We have to "move" the pointer into foo
	value = foo2(move(value));
	// Print data 
	cout << "After foo2, address = " << value.get() << ", value = " << *value << endl;

	// Call foo3. Use a reference to avoid a move 
	foo3(value);
	cout << "After foo3, address = " << value.get() << ", value = " << *value << endl;

	return 0; 
}
*/

// -----------------------------------------------
// 6.23 Using unique_ptr for Arrays
/*
const int SIZE = 65536;

void build_array(unique_ptr<int[]> &data)
{
	for (int i = 0; i < SIZE; ++i)
		// Have to deference the pointer, the access the values
		data.get()[i] = i;
}

void print_array(unique_ptr<int[]> &data)
{
	for (int i = 0; i < SIZE; ++i)
		// Have to deference the pointer, the access the values
		cout << data.get([i] << endl;
}

int main (int argc, char** argv)
{
	// unique_ptr can have arrays 
	unique_ptr<int[]> data(new int[SIZE]);
	// Build the array - using pass by reference on the unique_ptr
	build_array(data);
	// Print the array
	print_array(data);
	// Set data to nullptr - will delete the array
	data - nullptr;

	return 0; 
}
*/
//-----------------------------------
// The auto Keyword (From now on will copy each bit of code)
// 6.21 Using auto to Simplify Code
/*
#include <iostream> 
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
	// Use the auto keywork - compiler determines the type
	auto data = make_shared<int>(5);
	// ... data is a shared_ptr<int>  Compiler fills in the type
	cout << "My data = " << *data << ", at address = " << data << endl;
	return 0;
}
*/
//-------------------------------
// 6.25 Using static_cast (outputs error)
/*
#include <iostream>
#include <string> 

using namespace std;

int main(int argc, char **argv)
{
	// Declare an int 
	int x = 10; 
	// Cast to a float 
	// Let the compiler work out the type
	auto y = static_cast<float>(x);
	// Declare a string
	string str = "Hello World!";
	// Cast str to a float 
	// Will cause a compiler error
	auto z = static_cast<float>(str);

	return 0;
}

*/
//-----------------------------------------------------------------
// 6.27 Casting with const_cast 
/*
#include <iostream>
#include <string> 

using namespace std;

int main(int argc, char **argv)
{
	// Create a string
	string str = "Hello World!";
	cout << "String = " << str << endl;
	// Get the raw C string
	const char *const_raw = str.c_str();
	// Can't chance any values in raw - const 
	// This won't compile 
	// const_raw[4] = 'p';
	
	// Now let's live dangeriously - use const cast
	char *raw = const_cast<char*>(const_raw);
	// Change the value of raw now
	raw[4] = 'p';
	// Print out the string
	cout << "String = " << str << endl;

	return 0;
}
*/
//---------------------------------------------------------
// 6.29 Using typeid
/*
#include <iostream>
#include <string> 

using namespace std;

int main(int argc, char ** argv)
{
	// Create a string
	string str1 = "Hello";
	string str2 = "World";

	// Check if the types are equal
	if (typeid(str1) == typeid(str2))
		cout << "Types are equal" << endl;
	else
		cout << "Types are not equal" << endl;

	// Create a float
	float x = 52.0f;

	// Print out details
	cout << "x is a " << typeid(x).name() << " with value " << x << endl;

	return 0;
}
*/
//------------------------------------------------------------------------
// Case Study - Building Trees : see other file
