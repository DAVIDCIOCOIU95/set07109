#include <iostream>

void foo(int *x)
{
	std::cout << "Address of x in function = " << x << std::endl;
	std::cout << "Start of function, x = " << *x << std::endl;
	// Have to deference pointer to change value
	*x = 20;
	std::cout << "End of function, x = " << *x << std::endl;
}

int main(int argc, char **argv)
{
	int x = 10;
	std::cout << "Starting address of x, = " << &x << std::endl;
	std::cout << "Before function call, x = " << x << std::endl;
	// Have to pass the pointer (or address of) x to the function
	foo(&x);
	std::cout << "After function call, x = " << x << std::endl;
	std::cout << "End address of x = " << &x << std::endl;

	return 0;
}