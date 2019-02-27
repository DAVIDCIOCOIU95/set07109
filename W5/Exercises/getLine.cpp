#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	// Declare string to store name 
	std::string full_name;

	// Prompt for name 
	std::cout << "Please enter your full name: ";
	// Read in full_name using cin and getline
	std::getline(std::cin, full_name);

	// Print name 
	std::cout << "Your full name is " << full_name << " which is ";
	std::cout << full_name.length() << " characters long" << std::endl;;

	return 0;
}