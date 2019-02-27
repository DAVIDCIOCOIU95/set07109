#include <iostream>
#include <vector>

void sort_copy(std::vector<int> data)
{
	// Iterate through each value
	for (int i = 0; i < data.size(); ++i)
	{
		// Loop through values above index i
		for (int j = 0; j < data.size() - (i + 1); ++j)
		{
			// Test if data[j] > data [j + i]
			if (data[j] > data[j + 1])
			{
				// Swap values
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		if (i % 1000 == 0)
			std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted" << std::endl;
	}
}

void sort_reference(std::vector<int>  &data)
{
	// Iterate through each value
	for (int i = 0; i < data.size(); ++i)
	{
		// Loop through values above index
		for (int j = 0; j < data.size() - (i + 1); ++j)
		{
			// Test if data[j] > data[j + 1}
			if (data[j] > data[j + 1])
			{
				// Swap values
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		if (i % 1000 == 0)
			std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted" << std::endl;
	}
}

int main(int argc, char **argv)
{
	// Create the vector type int named data
	std::vector<int> data;
	// Push in vector from the end subtracting zero each time to obtain the next smaller number until we reach 1
	for (int i = 0; i < 262144; ++i)
		data.push_back(262144 - i);

	std::cout << "Sorting by copy..." << std::endl;
	sort_copy(data);
	std::cout << "Sorting by reference..." << std::endl;
	sort_reference(data);

	return 0;
}
