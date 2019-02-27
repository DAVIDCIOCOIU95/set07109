#include <iostream>

// Passing a reference to x (&x)
void foo(int &x)
{
	std::cout << "Start of function, x = " << x << std::endl;
	x = 20;
	std::cout << "End of function, x = " << x << std::endl;
}

int main(int argc, char **argv)
{
	int x = 10;
	std::cout << "Value of x before function call: " << x << std::endl;
	foo(x);
	std::cout << "Value of x after function call: " << x << std::endl;

	return 0;
}