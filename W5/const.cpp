#include <iostream>
#include <string>

std::string join(const std::string &a, const std::string &b)
{
    // Code that gets around const to use append
	std::string str_a = a;
	std::string str_b = b;
	std::string join = str_a.append(str_b);
	// This line won't compile 
	//return a.append(b);
	//Possible to do
	//return a + b;
	return join;
}

int main(int argc, char **argv)
{
	std::string greeting = join(std::string("Hello,"), std::string("World!"));

	std::cout << greeting << std::endl;
}