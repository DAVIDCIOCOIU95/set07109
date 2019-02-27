#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	// Print out 
	std::cout << "Hello!< What's your name?" << std::endl;
	// Create a String to read into
	std::string name = "";
	std::cin >> name;
	std::cout << "Your name is: " << name << std::endl;

	return 0;

}