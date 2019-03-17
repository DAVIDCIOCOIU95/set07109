#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

// **Constructors **
BinarySearchTree::BinarySearchTree()
{
	Node *tree = nullptr;
}

BinarySearchTree::BinarySearchTree(std::string word)
{
	
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
}

BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
}
//destructor
BinarySearchTree::~BinarySearchTree()
{
}

// **Methods**
void BinarySearchTree::insert(string word)
{
	insertPrivate(word, root);
}

bool BinarySearchTree::exists(std::string word) const
{
	return false; // change this to implement the method, returning true if word exists
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
	// Key equal to node
	// do not add and increment node counter
	else
	{
		cout << "The key" << word << "has already been added" << endl;
		Ptr->counter = Ptr->counter + 1;
	}
}

string static myString; 
string BinarySearchTree::inorder() const
{
	inorderPrivate(root);
	string myNewString = myString;
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
	// Tree empty
	else
	{
		cout << "\nThe tree is empty" << endl;
	}
}

std::string BinarySearchTree::preorder() const
{
	return std::string(""); // change this to return a string representation of the words
							// in the tree preorder.
}

std::string BinarySearchTree::postorder() const
{
	return std::string(""); // change this to return a string representation of the words
							// in the tree postorder.
}

// ----------------------------------------------------------------
// **My methods**
string BinarySearchTree::printRoot()
{
	if (root != nullptr)
	{
		return root->word;
	}
	else
		return "Nothing";
}

BinarySearchTree::Node *BinarySearchTree::CreateLeaf(string word)
{
	Node *n = new Node;
	n->word = word;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}
// -------------------------------------------------------------------------

// **Operator overloads**

BinarySearchTree &BinarySearchTree::operator+(std::string word)
{
	return *this; // returns a reference to the modified tree
}

BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	return *this;
}
