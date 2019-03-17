#include <iostream> 

using namespace std;

// Inner class

class inner
{
public: 
    inner()
    {
        cout << "Called Inner Constructor" << endl;
    }
    ~inner()
    {
        cout <<  "Called inner DECONSTRUCTOR" << endl;
    }
};

class parent
{
    // This part is private as default in class
    // Parent contains a pointer to an inner object 
    inner *a;
public: 
    // Parent contains an unsigned int value
    unsigned int x;

    parent()
    {
        cout<< "Called parent constructor" << endl;
        // Calls default constructor 
        a = new inner;
    }
    virtual ~parent() 
    { cout << "Called parent DECONSTRUCTOR" << endl; }
};

class child : public parent
{
public: 
    // Child adds an unsigned int value
    unsigned int y;

    child()
    {
        cout << "Called child constructor" << endl;
    }
    ~child()
    {
        cout << "Called child DECONSTRUCTOR" << endl;
    }
};

int main(int argc, char** argv)
{
    // Print size of inner
    // should be a char (1 byte)
    cout << "sizeof(inner) = " << sizeof(inner) << " bytes" << endl;
    // Print out size of parent
    cout << "sizeof(parent) = " << sizeof(parent) << " bytes" << endl;
    // Print out size of child
    cout << "sizeof(child) = " << sizeof(child) << " bytes" << endl;

    // Create a child object on the heap
    // Calls default constructor
    parent *c = new child;

    //Delete the child object
    delete c;
    return 0;
}