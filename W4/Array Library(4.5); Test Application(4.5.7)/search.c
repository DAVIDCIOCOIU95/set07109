//the implementation fo the header search  
//double quotes as the search.h is in the same directory
#include "search.h"

int search(int value, int size, int *data)
{
	//Loop through data until found;
	//We start at 0 as the array starts at index 0
	for (int i = 0; i < size; ++i)
	{
		if (data[i] == value)
		{
			//Found value. Return i
			return i;
		}
	}
	
	//Not found. Return -1
	return -1;
}
