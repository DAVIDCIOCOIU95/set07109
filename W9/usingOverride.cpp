#include <iostream>

using namespace std;

class parent
{
public: 
    virtual void my_method()
    {   
        cout << "Called parent.my_method()" << endl;
    }
};

class child : public parent
{
public:
    void my_method() override
    {
        cout << "Called child.my_method()" << endl;
    }
};

int main(int argc, char **argv)
{
    // Create a parent object on the heap
    parent *p = new parent;
    // Call my_method
    p->my_method(); // or (*p).my_method();

    // Create a child object on the heap
    child *c = new child;
    // Call my_method
    c->my_method();

    // Delete parent
    delete p;

    // Set p to c 
    p = (parent*)c;

    // Call my_method
    p->my_method();

    delete c;

    return 0;
}