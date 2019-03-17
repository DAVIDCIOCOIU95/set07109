#include <iostream>
#include <string>

using namespace std;

// Define a programme of study
struct programme 
{
    string code;
    string name;


    // Default constructor 
    programme()
    {
        cout << "Called programme default constructor" << endl;
    }

    // Constructor with parameters
    programme(const string &code, const string &name)
    {
        cout << "Called programme parameterized constructor" << endl;
        this->code = code;
        this->name = name;
    }

    // Deconstructor for programme
    ~programme()
    {
        cout << "Called programme DESTRUCTOR" << endl;
    }
};

// Defining a module
struct module
{
    string code;
    string name;
    unsigned int mark;

    // Default constructor 
    module()
    {
        cout << "Called module default constructor" << endl;
    }

    // Constructor with parameters 
    module(const string &code, const string &name, unsigned int mark)
    {
        cout << "Called module parameterized constructor" << endl;
        this->code = code;
        this->name = name;
        this->mark = mark;
    }

    // Module destructor 
    ~module()
    {
        cout << "Called module DESTRUCTOR" << endl;
    }
};

// Define a student
struct student
{
    unsigned int matric;
    string name;
    string address;
    programme prog;
    module mods[6];

    // Default constructor 
    student()
    {
        cout << "Called student default construcotr" << endl;
    }

    int avarageMark(module mods[])
    {
        int avarage = 0;
        for(int i = 0; i < sizeof(mods); ++i)
        {
            if(mods[i].mark != NULL)
            avarage = avarage + mods[i].mark;
        }
        return avarage/sizeof(mods);
    }

    // Student destructor
    ~student()
    {
        cout << "Called student DESTRUCTOR" << endl;
    }
};

int main(int argc, char **argv)
{
    cout << "Creating a student object" << endl;
    // we create a pointer for the new object (the pointer helps us retain the hep position)
    student *s = new student();

    // Set some student values
    cout << "Setting student details" << endl;
    // deference (*s).prog  or  s->prog
    s->matric = 42001290;
    s->name = "Kevin Chalmers";
    s->address = "School of Computing";

    // Set the programme 
    cout << "Setting programme" << endl;
    s->prog = programme("56119BH", "BEng (Hons) Sofware Engineering");

    // Set the modules
    cout << "Setting module 0" << endl;
    s->mods[0] = module("SET07109", "Programming Fundamentals", 85);
    cout << "Setting module 1" << endl;
    s->mods[1] = module("SET07109", "Programming Fundamentals", 85);
    cout << "Setting module 2" << endl;
    s->mods[2] = module("SET07109", "Programming Fundamentals", 85);
    cout << "Setting module 3" << endl;
    s->mods[3] = module("SET07109", "Programming Fundamentals", 85);
    cout << "Setting module 4" << endl;
    s->mods[4] = module("SET07109", "Programming Fundamentals", 85);
    cout << "Setting module 5" << endl;
    s->mods[5] = module("SET07109", "Programming Fundamentals", 85);

    // we have to call pointer deferencer even in the method
    cout << "Avarage mark = " << s->avarageMark(s->mods) << endl;

    // Deleting the student object from the heap
    delete s;

    return 0;
}