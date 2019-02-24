 #include <iostream>
 #include <cstdlib>
 #include <cstdio>

using namespace std;

//6.9/6.10
/* //Size of data to allocate
const unsigned int SIZE = 1048576;

int main(int argc, char **argv)
{
    // Try and create data on the stack
    // This is 1MB - common stack size
    // Other values take us over the stack size
    char data[SIZE];
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", data[i]);

    return 0;
} */

//1 megabyte in bytes
const unsigned int MB = 1024 * 1024;
// 1 gigabyte in bytes
const unsigned int GB = 1024 * MB;

int main(int argc, char **argv)
{
    // Allocate 1 GB of data
    char *data = (char*)malloc(GB);
    
    // Need to "use" the data before actual allocation occurs
    for(int i =0; i < 100; ++i)
    {
        data[i] = i; // Optional just to see that the array can actually be filled with values
        printf("%d\n", data[i]);
    }
    
    free(data);

    return 0;
}




