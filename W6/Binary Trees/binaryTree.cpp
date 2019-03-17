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
        // Create new tree (keep in mind that in main we just declare the tree but we use a nullptr, therefore we don't set it)
        // This stage here is the equivalent to stage one;
        *tree = new node;
        // Set new value
        (*tree)->data = value;
        //Set branches to nullptr;
        (*tree)->left = nullptr;
        // Set branches to nullptr
        (*tree)->right = nullptr;
    }
    // If the value imputted from the command line is minor that current **tree.data (vale), go left and insert the value into the branch (recursion)
    else if (value < ((*tree)->data))
        // here we call the recursion inserting the left branch and the value from command line;
        // Remember we have to use the address when passing into the function;
        insert(&(*tree)->left, value);

    // Else, if the value from cmdl is bigger than value stored into **.tree.data (value) go right and insert it in that node (pointer);
    else if (value > ((*tree)->data))
        insert(&(*tree)->right, value);

    else
        return;
}

// Delete the tree -freeing memory
void delete_tree(node *tree)
{
    if (tree == nullptr)
        return;
    delete_tree(tree->left);
    delete tree->left;
    delete_tree(tree->right);
    delete tree->right;
}

// Prints the tree in order
void inorder(node *tree)
{
    cout << "Printing in order: " << endl;
    if (tree != nullptr)
    {
        inorder((tree)->left);
        cout << tree->data << ", ";
        inorder(tree->right);
    }
}

// Prints current node, left branch, right branch
void pre_order(node *tree)
{
    cout << "Printing in pre order:" << endl;
    if (tree != nullptr)
    {
        cout << tree->data << ", ";
        pre_order((tree)->left);
        pre_order((tree)->right);
    }
}

void post_order(node *tree)
{
    cout << "Printing in post order: " << endl;
    if (tree != nullptr)
    {
        post_order((tree)->left);
        post_order((tree)->right);
        cout << tree->data << ", ";
    }
}

void searchInt(int key, node* tree)
{
    if(tree != nullptr)
    {
        if(key == tree->data)
        {
            cout << "Searching..." << endl;
            cout << "True." << endl;
        }

        else if(key < tree->data)
        {
            searchInt(key, tree->left);
        }
        
        else if(key > tree->data)
        {
            searchInt(key, tree->right);
        }
    }

    else
    {
        cout << "False." << endl;
    }
    
}


node  *Cpy(node *tree) { 

   if (root == NULL ) : return root;

   node *temp = new node();
   temp->data = root-> data;    

   temp->left = Cpy( root -> left);   

   temp->right = Cpy(root -> right);  

   return temp;
}
/*void cloneTree(node **treeClone, node *tree)
{
    //if tree root not null 
    if (*treeClone == nullptr)
    {
        *treeClone = new node;
        (*treeClone)->data = tree->data;
        (*treeClone)->left = nullptr;
        (*treeClone)->right = nullptr;
    }
    
    else if (tree->data < ((*treeClone)->data))
      
        cloneTree(&(*treeClone)->left, node *tree);

    else if (tree->data > ((*treeClone)->data))
        cloneTree(&(*treeClone)->right, node *tree);

    else
        return;
}*/

int main(int argc, char **argv)
{
    // Declare the tree - nullptr to a node
    // This tree will be always set to nullptr in the while loop
    node *tree = nullptr;
    node *treeClone = nullptr;

    // Loop until -1 entered
    while (true)
    {
        int num;
        cout << "Enter number (-1 to exit): ";
        cin >> num;

        if (num == -1)
            break;
        insert(&tree, num);
    }

    // Print the tree
    while (true)
    {
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1) Order Traversal" << endl;
        cout << "2) Pre order" << endl;
        cout << "3) Post order" << endl;
        // Searching 
        cout << "4) Search" << endl;
    
        cout << "-1) Exit" << endl;
        cout << "Enter a number: ";

        int choice;
        cin >> choice;
        if(choice == -1)
            break;

        if (choice == 1)
        {
            inorder(tree);
            cout << endl;
        }

        else if (choice == 2)
        {
            pre_order(tree);
            cout << endl;
        }

        else if (choice == 3)
        {
            post_order(tree);
            cout << endl;
        }

        else if(choice == 4)
        {
            int num;
            cout << "Enter number to be searched: " << endl;
            cin >> num; 
            searchInt(num, tree);
        }
    }

    // Delete the tree
    delete_tree(tree);

    return 0;
}