#include "generate.h"
#include <stdlib.h.>
#include <time.h>

void generate(int size, int *data)
{
	//seed the random
	srand(time(NULL));
	//generate random numbers
	for (int i = 0; i < size; ++i)
		data[i] = rand();
}