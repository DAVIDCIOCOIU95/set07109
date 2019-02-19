#include "generate.h"
#include <random>

std::vector<int> generate(int size)
{
	// Create random generator 
	std::random_device rd;
	// Create distribution 
	std::uniform_int_distribution<int> dist;
	// Generate random numbers
	std::vector<int> data;
	for (int i = 0; i < size; ++i)
		data.push_back(dist(rd));

	return data;
}