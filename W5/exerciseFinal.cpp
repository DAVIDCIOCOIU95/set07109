#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <iomanip>
#include <random>
#include <algorithm>

#define PI 3.14159265359

using namespace std;

int main(int argc, char **argv)
{
    double myDouble = PI;
    cout << setprecision(5) << PI << endl;
    // Set precision
   
   // Create a vector
   vector<int> myVector;
   // Push elements into vector
   for (int i = 0; i < 20; ++i)
   {
       myVector.push_back(i);
   }

    for(int i = 0; i < myVector.size(); ++i)
        cout << myVector[i] << endl;

    find(myVector.begin(), myVector.end(), 3);
/*
   // Shuffle vector
   random_device rd;
   uniform_int_distribution<int> dist;
   shuffle(myVector.begin(), myVector.end(), 5);
   */

    return 0;
}

