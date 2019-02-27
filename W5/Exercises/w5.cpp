/*//5.3

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    // Input to command line as follows:
    // 1) cl name_file.cpp 
    // 2) name_file "random string of things"
    // The commandSize will return:
    // the number of char including spaces (thanks to string (" "))
    // and new line 
    
    // Declare an empty string
    std:: string commandSize = "";
    // Loop around command lines, appending to the string
    for (int i = 0; i < argc; ++i)
    commandSize += std:: string (argv[i]) + std:: string (" ");
    // Notice here the use of parenthesis after string
    // This allows us to use a string without declaring the var for it

    // Print out the command line (prints what we input, therefore what commandSize contains)
    std:: cout << commandSize << std::endl;
    // Print pout the lenth of the string
    std:: cout << "Command line is: " << commandSize.size() << " characters long" << std:: endl;

    return 0;
}
*/

// ---------------------------------------------------------------------------------------------------------------------- 
/*
//5.3.1


#include <iostream>
#include <string> 

// Reads in a name and says hello to the person
// Using: stream input operator, string object and console output


int main(int argc, char **argv)
{
    // String for holding name 
    std:: string myName = "";

    std:: cout << "Hello, what's you name?" << std:: endl;
    std:: cin >> myName;
    std:: cout << "Hello, " << myName << "!" << std:: endl;

    return 0;
}
*/

// -------------------------------------------------------------------------------------------------------------------------

/* 5.4


#include <cstdio>
#include <string>

// A function that will print a C string
void print(const char *str)
{
    printf(str);
}

int main(int argc, char **argv)
{
    // Declare an empty string 
    std:: string command = "";
    // Loop round command lines, appending to the string
    for (int i = 0; i < argc; ++i)
    {
        command += std:: string(argv[i]);
        command += std:: string(" ");
    }

    // Get the C string (raw string) from the C++ string
    const char *str = command.c_str();

    // Call print
    print(str);

    return 0;
}
*/

// -------------------------------------------------------------------------------------------------------------------------
/* 5.6


#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    // Declare strings to store name 
    std::string first_name;
    std::string last_name;
    std::string full_name; 

    // Prompt for first name
    std::cout << "Please eneter your first name: ";
    // Read in first_name using cin
    std::cin >> first_name;

    // Cheack if your name is Kevin
    if (first_name == "Kevin")
        std::cout << "Hey! Another Kevin\n";
    else 
        std::cout << "Oh well\n";
    
    // Output number of characters entered 
    std::cout << "You entered " << first_name.length() << " characters" << std::endl;
    // Prompt for last name
    std::cout << "Please enter your last name: ";
    std::cin >> last_name;
    // Output number of characters entered
    std:: cout << "You entered: " << last_name.length() << " characters" << std::endl;

    // Join the strings
    full_name = first_name + std::string(" ") + last_name;

    // Print name 
    std::cout << "Your full name is: " << full_name << "which is ";
    std:: cout << full_name.length() << " characters long" << std::endl;;
    
    return 0;
}
*/

/* //5.6 getline
 //getline reads in everything until it encounters \n


*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    // Declare string to store name
    std:: string full_name;

    // Prompt for name
    std::cout << "Please enter your full name: ";
    // Read in full_name using cin and getline
    //getline(where to read from, where to red in);

    std::getline(std::cin, full_name);

    // Print name
    std::cout << "Your full name is " << full_name << " which is ";
    std::cout << full_name.length() << " characters long" << std::endl;

    return 0;
}


