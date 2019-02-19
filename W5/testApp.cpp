#include "generate.h"
#include "sort.h"
#include <iostream>

int main(int arc, char **argv)
{
	std::vector<int> data = generate(65536);
	sort(data);

	// Print the first 100 values
	for (int i = 0; i < 100; ++i)
		std::cout << data[i] << std::endl;

	return 0;
}