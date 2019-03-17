#include <iostream> 

using namespace std;

class parent
{
private:
    unsigned int x;
protected:
    unsigned int y;
public: 
    unsigned int z;

    void printParent()
    {
        cout<< "parent = {" << x << "," << y << "," << z << "}" << endl;
    }

};

class child : public parent
{
private:
    unsigned int a;
protected:
    unsigned int b;
public: 
    unsigned int c;
   
    void printChild()
   {
       // won't compile as x not accesible 
      // cout << "parent = {" << x << "," << y << "," << "z" << "}" << endl;

      cout << "child = {" << a << "," << b << "," << c << "}" << endl;
   }
};

int main(int argc, char** argv)
{
    cout << "sizeof(parent) = " << sizeof(parent) << " bytes" << endl;
    // Print out size of child
    cout << "sizeof(child) = " << sizeof(child) << " bytes" << endl;

    child ch;
    ch.printChild();
    ch.printParent();

    return 0;
}