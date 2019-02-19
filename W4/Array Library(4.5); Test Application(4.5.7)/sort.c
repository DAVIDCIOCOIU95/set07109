#include "sort.h"
#include <stdio.h>

void sort(int size, int *data)
{
	//Iterate thorugh each value
	for (int i = 0; i < size; ++i)
	{
		// Loop through values above index i 
		for (int j = 0; j < size - (i + 1); ++j)
		{
			//Test if data[j] > data[j + 1]
			if (data[j] > data [j + 1])
		    {
				/* Swap values: 
			    if the first data is bigger then the second, 
				then take the second (smaller) and put it first in the array
				*/
			    int temp = data[j + 1];
			    data[j + 1] = data [j];
			    data[j] = temp;
			
		    }
		
			 
			 
		}
	    // Display % of currently sorted data
		if (i % 1000 == 0)
		printf("%2.f%% sorted\n", ((float)i / (float)size) * 100.0f);
		
	}

	
	
	
}
