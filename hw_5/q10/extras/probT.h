#ifndef _BT_H_
#define _BT_H_

#include "BSTNode.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// Binary tree implemenation of a probability tree
class ProbT {
private:
    BSTNode<string, float>* root;     // Root of the ProbT
    int nodecount;                    // Number of nodes in the ProbT

    void clearhelp(BSTNode<string, float>*);
    void printhelp(BSTNode<string, float>*, int) const;
    static BSTNode<string, float>* createFailureNode(BSTNode<string, float>*);
    void insertHelp(BSTNode<string, float>*, float); // fills a nodes children given prob of success

public:
    ProbT() { root = new BSTNode<string, float>("", 1.0); nodecount = 0; } // Constructor
    ~ProbT() { clearhelp(root); }              // Destructor
    void clear();
    void insert(const float e);
    int size() const;
    void print() const;
    BSTNode<string, float>* getRoot();
};






// get root node
BSTNode<string, float>* ProbT::getRoot() {
    return root;
}






// Reinitialize tree
void ProbT::clear(){ 
    clearhelp(root);
    root = nullptr; 
    nodecount = 0; 
}






// Insert a record into the tree.
// k Key value of the record.
// e The record to insert.
void ProbT::insert(const float p) {
    insertHelp(root, p);
}






// Print the contents of the BST
void ProbT::print() const {
    if (root == NULL) cout << "The BST is empty.\n";
    else printhelp(root, 0);
}






// return the number of nodes in the tree
int ProbT::size() const {
    return nodecount;
}






// Clean up BST by releasing space back free store
void ProbT::clearhelp(BSTNode<string, float>* root) {
    if (root == nullptr) return;
    clearhelp(root->left());
    clearhelp(root->right());
}






// Print out a BST
void ProbT::printhelp(BSTNode<string, float>* root, int level) const {
    if (root == NULL) return;           // Empty tree
    printhelp(root->left(), level+1);   // Do left subtree
    for (int i=0; i<level; i++)         // Indent to level
        cout << "     ";
    cout << root->element() << "\n";    // Print node value
    printhelp(root->right(), level+1);  // Do right subtree    
}






// insertHelp
// given a node that represents the probability of success, fill out the furthest
// row with the relevent children. This is done by giving each leaf node two children
// left is the success child and right is the failure child.
void ProbT::insertHelp(BSTNode<string, float>* rt, float p) {
    if(rt->left() == nullptr) {
        rt->setLeft(new BSTNode<string, float>(rt->key() + "s", 
                                               rt->element() * p));
        nodecount++;
    } else {
        insertHelp(rt->left(), p);
    }
    if(rt->right() == nullptr) {
        rt->setRight(new BSTNode<string, float>(rt->key() + "f", 
                                                rt->element() * (1 - p)));
        nodecount++;
    } else {
        insertHelp(rt->right(), p);
    }
}





#endif