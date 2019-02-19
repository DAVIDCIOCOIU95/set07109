#include <iostream>

void foo(int x)
{
	std::cout << "Start of function, x = " << x << std::endl;
	x = 20;
	std::cout << "End of function, x = " << x << std::endl;
}

int main(int argc, char **argv)
{
	int x = 10;
	std::cout << "Before funciton call, x = " << x << std::endl;
	foo(x);
	std::cout << "After function call, x = " << x << std::endl;

	return  0;
}