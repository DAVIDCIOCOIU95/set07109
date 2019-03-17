// A Binary Search Tree class for int values
class BST
{

private:
    // Stores a key and two pointers to other two nodes storing addresses;
    struct node
    {
        int key; 
        node* left;
        node* right;
    };
    // Pointer used to reference the very top of the tree(root node)
    node* root;

    // **PRIVATE Methods** 
    // **These functions are not accessed by the main program, only by the class**

    // Creates a leaf
    node* CreateLeaf(int key);
    // Adds a node to the BST
    void AddLeafPrivate(int key, node* Ptr);
    // Prints in order traversal
    void PrintInOrderPrivate(node* Ptr);
    node* ReturnNodePrivate(int key, node* Ptr);
    // Finds the smallest value in the tree
    int FindSmallestPrivate(node* Ptr);
     // Remove a node from the tree
    void RemoveNodePrivate(int key, node* parent);
    // Removes root node
    void RemoveRootMatch();
    // Removes node that is not root
    void RemoveMatch(node* parent, node* match, bool left);
    
    node* ReturnNode(int key);
    void RemoveSubtree(node* Ptr);
    
    // **PUBLIC Methods**
    // **These functions are accessed by the main program
public:
        // Constructor prototypes 
        BST();
        // Destructor
        ~BST();
        // Adds a node to the BST
        void AddLeaf(int key);
        void PrintInOrder();
        int ReturnRootKey();
        // Prints the children of the key
        void PrintChildren(int key);
        // Finds the smallest value in the tree
        int FindSmallest();
        // Remove a node from the tree
        void RemoveNode(int key);
        
};


// Reference 
// https://www.youtube.com/watch?v=3FPjmO3-6IY&list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q&index=5