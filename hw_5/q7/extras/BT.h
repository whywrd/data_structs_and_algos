/*
A binary tree whose insert algorithm is predicated soley on th e number of elements
in the tree. Therefore, it does not create a binary search tree but rather, prioritizes
completeness.

Do do this consider the cyclic nature of numbers in binary notation.

 0|    0    0    0    0
 1|    0    0    0    1
 2|    0    0    1    0
 3|    0    0    1    1
 4|    0    1    0    0
 5|    0    1    0    1 
 6|    0    1    1    0
 7|    0    1    1    1
 8|    1    0    0    0
 9|    1    0    0    1
10|    1    0    1    0
11|    1    0    1    1
12|    1    1    0    0
13|    1    1    0    1

if you subtract 1 from the number in question, we get the nice property that for each
increasing power the cycle lasts for 2^n numbers.
*/


#ifndef _BT_H_
#define _BT_H_

#include "BSTNode.h"
#include <cmath>
#include <iostream>
using namespace std;

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BT {
private:
    BSTNode<Key,E>* root;     // Root of the BST
    int nodecount;            // Number of nodes in the BST

    void clearhelp(BSTNode<Key, E>*);
    BSTNode<Key,E>* inserthelp(BSTNode<Key, E>*, int row, const Key&, const E&);
    void printhelp(BSTNode<Key, E>*, int) const;
    bool static goLeft(int pos, int row);
    void static toBin(int num, int *bin);

public:
    BT() { root = NULL; nodecount = 0; }    // Constructor
    ~BT() { clearhelp(root); }              // Destructor
    void clear();
    void insert(const Key& k, const E& e);
    int size() const;
    void print() const;
    BSTNode<Key, E>* getRoot() const { return root; }
};






// Reinitialize tree
template <typename Key, typename E>
void BT<Key, E>::clear(){ 
    clearhelp(root); 
    root = NULL; 
    nodecount = 0; 
}






// Insert a record into the tree.
// k Key value of the record.
// e The record to insert.
template <typename Key, typename E>
void BT<Key, E>::insert(const Key& k, const E& e) {
    root = inserthelp(root, 0, k, e);
    nodecount++;
}






// Print the contents of the BST
template <typename Key, typename E>
void BT<Key, E>::print() const {
    if (root == NULL) cout << "The BST is empty.\n";
    else printhelp(root, 0);
}






// return the number of nodes in the tree
template <typename Key, typename E>
int BT<Key, E>::size() const {
    return nodecount;
}






// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BT<Key, E>::clearhelp(BSTNode<Key, E>* root) {
    if (root == NULL) return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}






// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BT<Key, E>::inserthelp(
        BSTNode<Key, E>* root, int row, const Key& k, const E& it) {
    if (root == NULL)  // Empty tree: create node
        return new BSTNode<Key, E>(k, it, NULL, NULL);
    if (goLeft(nodecount, row)) {
        root->setLeft(inserthelp(root->left(), row+1, k, it));
    } else {
        root->setRight(inserthelp(root->right(), row+1, k, it));
    }
    return root;       // Return tree with node inserted
}






// Print out a BST
template <typename Key, typename E>
void BT<Key, E>::printhelp(BSTNode<Key, E>* root, int level) const {
    if (root == NULL) return;           // Empty tree
    printhelp(root->left(), level+1);   // Do left subtree
    for (int i=0; i<level; i++)         // Indent to level
        cout << "     ";
    cout << root->element() << "\n";    // Print node value
    printhelp(root->right(), level+1);  // Do right subtree    
}






// determines whether or not the node in position pos should go left or right
// in at node in row row. This decision is based off of the power of 2 for the
// in position base - row for the number. This creates a tree with complete rows
// because of the cyclic nature of binary representations and how they inherently
// correspond to the number of elements in a row of a binary tree eg there are
// 8 nodes at depth 3 of a binary tree (note 2^3 = 8).
template <typename Key, typename E>
bool BT<Key, E>::goLeft(int pos, int row) {
    int base;       // the power of 2 for the given row
    bool left;      // return val
    
    base = std::log2(pos);         // int will floor it
    int* binrep = new int[base];   // array to hold binary representation of pos
    toBin(pos, binrep);
    
    left = binrep[base - row];
    delete[] binrep;
    return left;
}





// creates an array of 0s and 1s equal to the binary representation of num.
// bin is the array that contains the representation and it is expected to
// of length log2(num). Note that bin[0] is the most significant value.
template <typename Key, typename E>
void BT<Key, E>::toBin(int num, int bin[]) {
    for(int i=std::log2(num); i>=0; i--) {
        bin[i] = (num % 2);
        num /= 2;
    }
}

#endif