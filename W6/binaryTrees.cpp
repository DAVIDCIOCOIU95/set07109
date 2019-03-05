// Case Study: Binary Trees W6 2019
#include <iostream> 

using namespace std;

// The node of a tree
struct node
{
    // Data stored in this node of the tree
    int data;
    // The left branch of the tree;
    node *left;
    // The right branch of the tree
    node *right; 
};

// Insert a value into the tree - notice ** 
void insert(node **tree, int value)
{
    // Check if nullptr. If so set new node
    if (*tree == nullptr)
    {
        // Create
    }
}

// Delete the tree -freeing memory 
void delete_tree(node *tree)
{

}

// Prints the tree in order
void inorder(node *tree)
{

}

int main(int argc, char **argv)
{
    // Declare the tree - nullptr to a node
    node *tree = nullptr;

    // Loop until -1 entered
    while (true)
    {
        int num;
        cout << "Enter number (-1 to exit): ";
        cin >> num;

        if (num == -1)
            break;
        insert (&tree, num);
    }

    // Print the tree
    inorder(tree);
    cout << endl;

    // Delete the tree
    delete_tree(tree);

    return 0;
}