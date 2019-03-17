#include <iostream>
#include <string>

class Animal
{
private:

    string name;
    string voice;

public:
    void move()
    {

    }
    void speak()
    {

    }

    void eat()
    {

    }
};

class Mammal : public Animal
{

};

class Bird : public Animal
{
    
};

class Horse : public Mammal
{

};

class Pegasus : public Horse
{

};