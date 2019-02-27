#include <cstdio> // This includes functionalities in the stdio.h C header
#include <string>

// A function that will print a C string
void print(const char *str)
{
	printf(str);
}

int main(int argc, char **argv)
{
	// Declare an empty string
	std::string command = "";
	// Loop round command lines, appending to the string
	for (int i = 0; i < argc; ++i)
	{
		command += std::string(argv[i]);
		command += std::string(" ");
	}

	// Get the C string (raw string) from the C++ string
	const char *str = command.c_str();

	// Call print 
	print(str);

	return 0;
}
