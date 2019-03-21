#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

// **Constructors **
BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::BinarySearchTree(std::string word)
{
	root = new Node;
	this->root->word = word;
	this->root->left = nullptr;
	this->root->right = nullptr;
	this->root->counter = 0;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
	root = copyTreePrivate(rhs.root);
}

Node* BinarySearchTree::copyTreePrivate(const Node* source)
{
	
    if(source == nullptr)
    {
        return nullptr;
    }
	
    Node* result = new Node;
    result->word = source->word;
    result->left = copyTreePrivate(source->left);
    result->right = copyTreePrivate(source->right);
    return result;
}

BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	for(const std::string &words : words)
    {
        insert(words);
    }
}

//destructor
BinarySearchTree::~BinarySearchTree()
{
    DestroyRecursive(root);
}

void BinarySearchTree::DestroyRecursive(Node* Ptr)
{
    if (Ptr)
    {
        DestroyRecursive(Ptr->left);
        DestroyRecursive(Ptr->right);
        delete Ptr;
    }
}

// **Methods**
void BinarySearchTree::insert(string word)
{
	insertPrivate(word, root);
}

void BinarySearchTree::insertPrivate(string word, Node *Ptr)
{
	// TREE EMPTY
	// Check root is empty
	if (root == nullptr)
	{
		// Create a leaf on the root with key from main
		root = CreateLeaf(word);
	}
	// Key equal to node
	// do not add and increment node counter
	else if(word == Ptr->word)
	{
		Ptr->counter++;
	}

	// TREE NOT EMPTY
	// Look left pointer
	else if (word < Ptr->word)
	{
		// Traverse left
		if (Ptr->left != nullptr)
		{
			insertPrivate(word, Ptr->left);
		}
		// Add Node (left pointer is nullptr)
		else
		{
			Ptr->left = CreateLeaf(word);
		}
	}
	// Look right pointer
	else if (word > Ptr->word)
	{
		// Traverse right
		if (Ptr->right != nullptr)
		{
			insertPrivate(word, Ptr->right);
		}
		// Add Node (left pointer is nullptr)
		else
		{
			Ptr->right = CreateLeaf(word);
		}
	}
}

bool BinarySearchTree::exists(std::string word) const
{
	bool myAnswer = existsPrivate(word, root);
	return myAnswer; 
}

bool BinarySearchTree::existsPrivate(string word, Node* ptr) const
{
	if(ptr != nullptr)
	{
		if(word.compare(ptr->word) == 0)
		{
			return true;
		}
		else
		{
			if((word.compare(ptr->word))<0) // Recursion left
			{
					return existsPrivate(word, ptr->left);
			}
			else // Recursion right
			{
					return existsPrivate(word, ptr->right);
			}	
		}	
	}
	return false;
}

// inorderPrivate will output to myString 
string myString;
string BinarySearchTree::inorder() const
{
	inorderPrivate(root);
	string myNewString = myString;
	// Check if not equal to "", if so remove the last " " printed in inorderPrivate
	if(myNewString != "")
		myNewString.pop_back();
	// set myString back to ""
	myString = "";
	return myNewString;
	
}

void BinarySearchTree::inorderPrivate(Node *Ptr) const
{
	// Tree not Empty
	if (root != nullptr)
	{
		if (Ptr->left != nullptr)
		{
			inorderPrivate(Ptr->left);
		}
		myString = myString + Ptr->word + " ";
		//cout << Ptr->word << " ";
		if (Ptr->right != nullptr)
		{
			inorderPrivate(Ptr->right);
		}
	}
	/*
	// Tree empty
	else
	{
		cout << "\nThe tree is empty" << endl;
	}
	*/
}

std::string BinarySearchTree::preorder() const
{
	preorderPrivate(root);
	string myNewString = myString;
	// Check if not equal to "", if so remove the last " " printed in inorderPrivate
	if(myNewString != "")
		myNewString.pop_back();
	// set myString back to ""
	myString = "";
	return myNewString;
}

void BinarySearchTree::preorderPrivate(Node *Ptr) const
{
	// Tree not Empty
	if (root != nullptr)
	{
		myString = myString + Ptr->word + " ";
		if (Ptr->left != nullptr)
		{
			preorderPrivate(Ptr->left);
		}
		if (Ptr->right != nullptr)
		{
			preorderPrivate(Ptr->right);
		}
	}
}

std::string BinarySearchTree::postorder() const
{
	postorderPrivate(root);
	string myNewString = myString;
	// Check if not equal to "", if so remove the last " " printed in inorderPrivate
	if(myNewString != "")
		myNewString.pop_back();
	// set myString back to ""
	myString = "";

	return myNewString;
}

void BinarySearchTree::postorderPrivate(Node *Ptr) const
{
	// Tree not Empty
	if (root != nullptr)
	{
		if (Ptr->left != nullptr)
		{
			postorderPrivate(Ptr->left);
		}
		if (Ptr->right != nullptr)
		{
			postorderPrivate(Ptr->right);
		}
		myString = myString + Ptr->word + " ";
	}
}

// **My methods**

string BinarySearchTree::printRoot()
{
	if (root != nullptr)
	{
		return root->right->word;
	}
	else
		return "Your root is empty";
}

BinarySearchTree::Node *BinarySearchTree::CreateLeaf(string word)
{
	Node *n = new Node;
	n->word = word;
	n->counter = 1;
	n->left = nullptr;
	n->right = nullptr;
	
	return n;
}

int BinarySearchTree::findWordCounter(string word)
{
	return findWordCounterPrivate(word, root);
}

int BinarySearchTree::findWordCounterPrivate(string word, Node* Ptr)
{
	if(Ptr != nullptr)
	{
		if(word.compare(Ptr->word) == 0)
		{
			return Ptr->counter;
		}
		else
		{
			if((word.compare(Ptr->word))<0) // Recursion left
			{
				return existsPrivate(word, Ptr->left);
			}
			else // Recursion right
			{
				return existsPrivate(word, Ptr->right);
			}	
		}	
	}
}

// **Operator overloads**

BinarySearchTree &BinarySearchTree::operator+(std::string word)
{
	insert(word);
	return *this; // returns a reference to the modified tree
}

BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	return *this;
}
