#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main()
{
    
    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    // Call BST class on myTree
    // The constructor is going to be called automatically when the tree is created (CreateLeaf new tree)
    BST myTree;

    int input = 0;

    // add numbers to the tree
    cout << "Printing the tree in order\nBefore adding numbers" << endl;

    myTree.PrintInOrder();

    for(int i = 0; i < 16; ++i)
    {
        myTree.AddLeaf(TreeKeys[i]);
    }
    cout << "Printing the tree in order\nAfter adding numbers" << endl;
    
    myTree.PrintInOrder();
    cout << endl;

    // Will print the root node and the root nodes children
    //myTree.PrintChildren(myTree.ReturnRootKey());

    /*
     for(int i = 0; i < 16; ++i)
    {
        myTree.PrintChildren(TreeKeys[i]);
        cout << endl;
    }
    */

    cout << "Smallest Value: " << myTree.FindSmallest() << endl;
    
    cout << "Enter a key value to delete or -1 to stop process\n";
    while(input != -1)
    {
        cout << "Delete Node: ";
        cin >> input;
        {
            if(input != -1)
            {
                cout << endl;
                myTree.RemoveNode(input);
                myTree.PrintInOrder();
                cout << endl;
            }
        }
    }
    return 0;
}

// https://www.youtube.com/watch?v=3FPjmO3-6IY&list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q&index=5