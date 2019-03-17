/* This file defines the methods created in the header file
*/
#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

// Root points to NULL
BST::BST()
{
    root = NULL;   
}

BST::node* BST::CreateLeaf(int key)
{
    node* n = new node;
    // The first key is inside our node, the second key referes to the key passed in by the function
    n->key = key;
    // We make our pointer (*n).left and right pointing to null (we create a leaf)
    n->left = NULL;
    n->right = NULL;
    // Return a pointer that is pointing to the newly created node above;
    return n;
}

// Takes in the key from the main and calls AddLeafPrivate from the BST class
void BST::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

// Searches from the right location to add the key from the main into a BST leaf
void BST::AddLeafPrivate(int key, node* Ptr)
{
    // TREE EMPTY
    // Check root is empty
    if(root == NULL)
    {
        // Create a leaf on the root taking in key from main
        // root will retain the pointer returned by CreateLeaf
        root = CreateLeaf(key);
    }

    // **TREE NOT EMPTY**
    // Look left pointer
    else if(key < Ptr->key)
    {
        // **Traverse Left**
        // Pointer Left has a left branch: use recursion on the same function to traverse left;
        if(Ptr->left != NULL)
        {
            // When we call recursion we will check the left and right pointer of the current node
            AddLeafPrivate(key, Ptr->left);
        }

        // **Add Node**
        // If the pointer is not pointing to anything, add a node to the current node left pointer;
        else 
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    // Look right pointer 
    // Same as above but with right pointer
    else if(key > Ptr->key)
    {
        if(Ptr->right != NULL)
        {
            AddLeafPrivate(key, Ptr->right);
        }
        else 
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    // **Key equal to node**
    // If the key is equal to the node we are looking at
    else
    {
        cout << "The key " << key << " has already been added to the tree" << endl;
    }  
}


void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
    // tree not empty
    if(root != NULL)
    {
        if(Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << " ";
        if(Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        } 
    }
    // tree empty
    else
    {
        cout << "The tree is empty" << endl;
    }
}

BST::node* BST::ReturnNode(int key)
{
     return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
    // Check the pointer is pointing to something
    if(Ptr != NULL)
    {
        // Check if the point is our node
        if(Ptr->key == key)
        {
            return Ptr;
        }
        // If pointer not equal to our node do recursion
        else 
        {
            if(key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else 
            {
                return ReturnNodePrivate(key, Ptr->right);
            }   
        }
    }
    // If not pointing to anything
    else
    {
        return NULL;
    }
}

int BST::ReturnRootKey()
{
    if(root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
}

void BST::PrintChildren(int key)
{
    node* Ptr = ReturnNode(key);

    if(Ptr != NULL)
    {
        // Print the parent node (our key)
        cout <<"Parent Node = " << Ptr->key << endl;
        
        // Conditional operator
        // Look left, case 1: NULL; case 2: get left key
        Ptr->left == NULL ? 
        cout << "Left Child = NULL\n" : 
        cout << "Left Child = " << Ptr->left->key << endl;

        // Look right, case 1: NULL; case 2: get right key
        Ptr->right == NULL ? 
        cout << "Right Child = NULL\n" : 
        cout << "Right Child = " << Ptr->right->key << endl;
    }
    // Pointer pointing to NULL
    else 
    {
        cout << "Key " << key << " is not in the tree" << endl;
    }
}

int BST::FindSmallest()
{
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
    if(root == NULL)
    {
        cout << "The tree is empty\n";
        return -1000;
    }
    else
    {
        // Traverse the left pointer until you find NULL
        if(Ptr->left != NULL)
        {
            return FindSmallestPrivate(Ptr->left);
        }
        // When you find NULL return me the key of the pointer we ar lookin at
        else
        {
            return Ptr->key;
        }       
    }
}

void BST::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}


void BST::RemoveNodePrivate(int key, node* parent)
{
    // Tree not empty 
    if(root != NULL)
    {
        // Check if root contains our key 
        if(root->key == key)
        {
            // Delete the root and reconstruct the tree
            RemoveRootMatch();
        }
        // If the root does not contain the match, look at the left child
        else
        {
            // Loof left if key < current key and the left pointer has a value in it(there is a left child)
            if(key < parent->key && parent->left !=NULL)
            {
                // Conditional statemnet:
                // if parent left child contains a key equal to our key: do case 1
                // else do case 2
                parent->left->key == key ?
                RemoveMatch(parent, parent->left, true) :
                RemoveNodePrivate(key, parent->left);
            }
            else if(key > parent->key && parent->right !=NULL)
            {
                parent->right->key == key ?
                RemoveMatch(parent, parent->right, false) :
                RemoveNodePrivate(key, parent->right);
            }
            else 
            {
                cout << " The key" << key << " was not found in the tree\n";
            }
        }  
    }
    else
    {
        cout << "The tree is empty\n";
    }
    
}

void BST::RemoveRootMatch()
{
    if(root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        // Case 0 - 0 children
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }

        // Case 1 - child
        else if(root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "The root node with key " <<rootKey << " was deleted." << 
                    "The new root contains key " << root->key << endl;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout << "The root node with key " <<rootKey << " was deleted." << 
                    "The new root contains key " << root->key << endl;
        }

        // Case 2 - 2 Children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "The root key containing key " << rootKey << 
                    "was overwritten with Key " << root->key << endl;
        }
    }
    else
    {
        cout << "Can not remove root. The tree is empty\n";
    }
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
    if(root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        // Use this one in case the node to delete has 2 children
        int smallestInRightSubTree;

        // Case 0 - 0 Children
        if(match->left == NULL && match->right == NULL)
        {
            // make sure left or right pointer of parent points to null
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }

        // Case 1 - 1 Child
        else if(match->left == NULL && match->right != NULL)
        {
           left == true ? parent->left = match->right : parent->right = match->right;
           match->right = NULL;
           delPtr = match;
           delete delPtr;
           cout << "The node containing key " << matchKey << " was removed\n";
        }
        else if(match->left != NULL && match->right == NULL)
        {
           left == true ? parent->left = match->left : parent->right = match->left;
           match->left = NULL;
           delPtr = match;
           delete delPtr;
           cout << "The node containing key " << matchKey << " was removed\n";
        }

        // Case 2 - 2 Children 
        else
        {
            smallestInRightSubTree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubTree, match);
            match->key = smallestInRightSubTree;
        }
    }
    else
    {
        cout << "Can not remove match. The tree is empty\n";
    }
    
}

BST::~BST()
{
    RemoveSubtree(root);
}

void BST::RemoveSubtree(node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->left != NULL)
        {
            RemoveSubtree(Ptr->left);
        }
        if(Ptr->right != NULL)
        {
            RemoveSubtree(Ptr->right);
        }
        cout << "Deleting node containing key  " << Ptr->key << endl;
        delete Ptr;
    }
    else
    {
        {
            
        }
    }
    
}




// Reference 
// https://www.youtube.com/watch?v=3FPjmO3-6IY&list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q&index=5