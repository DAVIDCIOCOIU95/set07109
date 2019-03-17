#include <iostream> 

using namespace std;

class my_class
{
public: 
    unsigned int x = 10;
    unsigned int y= 20;

    void set_x(unsigned int value)
    {
        x = value;
    }

    void set_y(unsigned int value)
    {
        y = value;
    }
};

int main(int argc, char **argv)
{
    // Allocate an object on the heap
    my_class *a = new my_class();

    // Print values of x and y
    // Need to deference the pointer
    cout << "a.x" << (*a).x << endl;
    cout << "a.y" << (*a).y << endl;

    // Set the values of x and y
    // Need to deference the pointer 
    (*a).set_x(20);
    (*a).set_y(40);

    // Print values of x and y
    // Need to deference the pointer
    cout << "a.x" << (*a).x << endl;
    cout << "a.y" << (*a).y << endl;

    delete a;

    return 0;
 }
