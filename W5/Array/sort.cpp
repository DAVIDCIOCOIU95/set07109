#include "sort.h"
#include <iostream>

void sort(std::vector<int> &data)
{
	// Iterate through each value
	for (int i = 0; i < data.size(); ++i)
	{
		// Loop through values above index i
		for (int j = 0; j < data.size() - (i + 1); ++j)
		{
			// Test if data at j bigger than next one
			if (data[j] > data[j + 1])
			{
				// Swap values
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		if (i % 1000 == 0)
		{
			std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted" << std::endl;
		}
	}
}