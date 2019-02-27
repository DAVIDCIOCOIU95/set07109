#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	// Declare an empty string
	std::string command = "";
	// Loop round command lines, appending to the string
	for (int i = 0; i < argc; ++i)
		command += std::string(argv[i]) + std::string(" ");

	// Print the command line
	std::cout << command << std::endl;
	// Print out the length of the string
	std::cout << "Command line is " << command.size() << " characters long" << std::endl;

	return 0;
}