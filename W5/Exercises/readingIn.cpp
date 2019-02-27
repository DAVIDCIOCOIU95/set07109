#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	// Declare strings to store name
	std::string first_name;
	std::string last_name;
	std::string full_name;

	// Prompt for first name
	std::cout << "Please insert your first name: ";
	// Read in first_name using cin
	std::cin >> first_name;

	// Check if your name is Kevin
	if (first_name == "Kevin")
		std::cout << "Hey! Another Kevin!\n";
	else
		std::cout << "Oh well!\n";

		// Output number of characters entered 
		std::cout << "You entered " << first_name.length()  << " characters" << std::endl;
		// Prompt for last name
	std::cout << "Please insert your last name: ";
	std::cin >> last_name;
	// Output number of characters entered
	std::cout << "You entered" << last_name.length() << "characters" << std::endl;

	// Join the strings 
	full_name = first_name + std::string(" ") + last_name;

	// Print name
	std::cout << "Your full name is " << full_name << " which is ";
	std::cout << full_name.length() << " characters long" << std::endl;;

		return 0;
}