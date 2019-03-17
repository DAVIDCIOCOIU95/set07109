#include <iostream>

using namespace std;

// Creating constructor with struct
struct myStruct
{
    public:
    unsigned int x;
    unsigned int y;

    myStruct(unsigned int a, unsigned int b)
    {
        x = a;
        y = b;
    }
};

// Creating constructor with class
class myClass
{
    public:
    unsigned int x;
    unsigned int y;

    myClass(unsigned int a, unsigned int b)
    {
        x = a;
        y = b;
    }
};

int main(int argc, char** argv)
{
    // Create objects
    myStruct a(10,20);
    myClass b(10, 20);

    // Print details
    cout << "a.x " << a.x << endl;
    cout << "a.y " << a.y << endl;
    cout << "b.a " << b.x << endl;
    cout << "b.y " << b.y << endl;

    // Reallocate a and b
    a = myStruct(20, 40);
    b = myClass(30, 60);

    // Print details 
    cout << "a.x" << a.x << endl;
    cout << "a.y" << a.y << endl;
    cout << "b.a" << b.x << endl;
    cout << "b.y" << b.y << endl;
    
    return 0;
}