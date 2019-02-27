#include <iostream>

void foo(const int *x)
{
	std::cout << "Address of x in function = " << x << std::endl;
	std::cout << "Start of function, x = " << *x << std::endl;
	//Wont compile = value pointed to is const
	*x = 20;
	std::cout << "End of function, x = " << *x << std::endl;
	std::cout << "Address of x at end of function = " << x << std::endl;
}

void foo2(int *const x)
{
	std::cout << "Address of x in function = " << x << std::endl;
	std::cout << "Stard of function, x  = " << *x << std::endl;
	// Will compile - pointer is const, not value pointed to 
	*x = 20; 
	std::cout << "End of function, x = " << *x << std::endl;
	std::cout << "Address of x at end of function = " << x << std::endl;
}

void foo3(int *const x)
{
	std::cout << "Address of x in function = " << x << std::endl;
	std::cout << "Start of function, x = " << *x << std::endl;
	// Won't compile - tryinh yo change address pointed to 
	x = nullptr;
	std::cout << "End of function , x = " << *x << std::endl;
	std::cout << "Address of function x at the end of function = " << x << std::endl;
}

int main(int argc, char **argv)
{
	int x = 10;
	std::cout << "Starting address of x = " << &x << std::endl;
	std::cout << "Before function call, x " << x << std::endl;
	// Have to pass the pointer (or address of) x to the function 
	foo2(&x);
	std::cout << "After function call, x = " << x << std::endl;
	std::cout << "End address of x = " << &x << std::endl;

	return 0;

}