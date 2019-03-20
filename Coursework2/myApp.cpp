#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinarySearchTree.h"
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    
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
    string myString;

    // Start getting the file in the vector
    while(getline(fileNewLine, myString))
    {
        myVector.push_back(myString);
    }
    // Close file
    fileNewLine.close();

    // Create BST from vector 
    //BinarySearchTree* myTree1 = new BinarySearchTree(myVector);

    // Output to the console the number of times each word exists
    //cout << myTree1->inorder();
    int myInt = 0;
    for(string myWord : myVector)
    {
        // myInt = myTree1->findWordCounter(myWord);
        // If the word equals to the word in the tree print 
        //cout << myWord << ": " << myTree1->findWordCounter(myWord) << endl;
    }

   // delete myTree1;
    //----------
    BinarySearchTree *testTree = new BinarySearchTree();
    testTree->insert("C");
    //testTree->insert("C");
    //testTree->insert("hello");
    cout << testTree->counter;
    cout << testTree->inorder();

    // Open inline file
    ifstream fileInline;
    fileInline.open ("sentences_test.txt");

    // Initialise a vector
    vector<string> secondVector;
    string word;
    char chars[] = ",.?()-";
    while (fileInline >> word)
    {

        for (unsigned int i = 0; i < strlen(chars); ++i)
        {
            // you need include <algorithm> to use general algorithms like std::remove()
            word.erase (std::remove(word.begin(), word.end(), chars[i]), word.end());
        }

        cout << word << endl;
    }

    
    return 0;
}