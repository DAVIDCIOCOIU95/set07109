#pragma once

#include <string>

using namespace std;

// Node of a tree, stores a word
struct Node
{
    // Word stored in this node of the tree
    std::string word = "";
    int counter = 0;
    
    // The left branch of the tree
    Node *left = nullptr;
    // The right branch of the tree
    Node *right = nullptr;
};
