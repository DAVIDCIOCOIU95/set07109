#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readfile(std::string &filename)
{
	// Open file - default is text
	std::ifstream file(filename);
	// String to read into
	std::string line;
	// Data return 
	std::vector<std::string> data;
	// Read until end of file
	while (std::getline(file, line))
		data.push_back(line);
	// Close file
	file.close();
	// Return data;
	return data;
}

void writefile(std::string &filename, std::vector<std::string> &data)
{
	// Open file - dafault is text
	std::ofstream file(filename);
	// Write each line into file starting at end of vector
	for (int i = data.size() - 1; i >= 0; --i)
		file << data[i] << std::endl; 
	// Close the file 
	file.close();
}

int main(int argc, char **argv)
{
	// Read in file (each line is a string in the vector)
	std::vector<std::string> data = readfile(std::string("sorted.txt"));
	// Print line read
	std::cout << "Lines read = " << data.size() << std::endl;
	writefile(std::string("reversed.txt"), data);

	return 0;
}