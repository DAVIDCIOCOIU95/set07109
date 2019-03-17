#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class programme
{
    public:
    string code;
    string name;
};

class module
{
    public:
    string code;
    string name;
    unsigned char mark;
};

class student 
{
    private: 
    int bankAccount = 12;

    public:
    unsigned int matric;
    string name;
    string address;
    programme prog;
    module mods;

    void setBankAccount(int value)
    {
        bankAccount = value;
    }

    int getBankAccount()
    {
        return bankAccount;
    }
};



int main(int argc, char **argv)
{
    cout << "Size of programme is: " << sizeof(programme) << " bytes" << endl;
    cout << "Size of module is: " << sizeof(module) << " bytes" << endl;
    cout << "Size of student is: " << sizeof(student) << " bytes" << endl;

    // Create struct
   
    student* myStudent = new student;
    module* myModule = new module;
    programme* myProgramme = new programme;

    // Prompt for details 
    // calculate year avarage
    /*
    cout << "Enter matric: " << endl;
    cin >> myStudent->matric;
    cout << "Enter name: " << endl;
    std::getline (cin, myStudent->name);
    cout << "Enter address" << endl;
    std::getline (cin, (*myStudent).address);
    cout << "Enter programme code " << endl;
    std::getline (cin, (*myStudent).prog.code);
    cout << "Enter programme name" << endl;
    std::getline (cin, myStudent->prog.name);
    cout << "Enter module code" << endl;
    std::getline (cin, myStudent->mods.code);
    cout << "Enter module name" << endl;
    std::getline (cin, myStudent->mods.name);
    cout << "Enter module mark" << endl;
    cin >> myStudent->mods.mark;

    // Print some details
    cout << "Matric is: " << myStudent->matric << endl;
    */

    myStudent->setBankAccount(40);
    cout << "Bank Account: " <<myStudent->getBankAccount() << endl;

    delete myStudent;
    delete myModule;
    delete myProgramme;
    
    return 0;
}