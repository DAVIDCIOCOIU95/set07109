#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinarySearchTree.h"
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    // Part 1
    // Open the file 
    ifstream fileNewLine;
    fileNewLine.open("single_words_test.txt");
    if (!fileNewLine) 
    {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    // Create a vector to store the file
    vector<string> myVector;

    // Start getting the file in the vector
    string myString;
    while(getline(fileNewLine, myString))
    {
        myVector.push_back(myString);
    }

    fileNewLine.close();

    // Create BST from vector 
    BinarySearchTree* myTree1 = new BinarySearchTree(myVector);

    // Output to the console the number of times each word exists
    cout << "Printing tree 1 counters" << endl;
    for(string myWord : myVector)
    {
        cout << myWord << ": " << myTree1->findWordCounter(myWord) << endl;
    }

    delete myTree1;


    // Part 2
    // Open inline file
    ifstream fileInLine;
    fileInLine.open ("sentences_test.txt");
    if (!fileInLine) 
    {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    // Initialise a vector
    vector<string> secondVector;
    // Get the words to a string and into a vector
    string word;
    char chars[] = ",.?()-";
    while (fileInLine >> word)
    {
        for (unsigned int i = 0; i < strlen(chars); ++i)
        {
            word.erase (std::remove(word.begin(), word.end(), chars[i]), word.end());
           
        }
        secondVector.push_back(word);
    }
    
    // Create BST from vector 
    BinarySearchTree* secondTree = new BinarySearchTree(secondVector);

    // Output to the console the number of times each word exists
    cout << "Printing tree 2 counters" << endl;
    for(string myWord : secondVector)
    {
        cout << myWord << ": " << myTree1->findWordCounter(myWord) << endl;
    }

    delete secondTree;

    return 0;
}