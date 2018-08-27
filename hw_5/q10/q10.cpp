/*
Will Hayward
CS 110C 
HW 5 
Question 10

Implementation of a probability tree. Each path along the tree represents a series
of events. At each node the left child represents a success at the next event and the
right child represents a failure. 

The keys of the nodes represents the path in terms of "s" and "f" where "s" is a success 
and "f" is a failure. Therefore, the key of the 3rd left node is "ss" representing 2 
successes. Note the root node's key is "". 

The elements of the nodes represents the probability of reaching that node. Since each
child represents independent outcomes the probability of going left is p and right is
1-p and the element of node at depth h is the product of all the nodes' elements leading
up to it. Note the root node's element is 1 because it always happens.
*/






/*
An implementation of a binary tree node. In this implementation
each node has a key (which is used for comparisons in the tree)
and an element (which is what is being stored).
*/

#ifndef _BST_NODE_H_
#define _BST_NODE_H_

// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode {
private:
  Key k;                  // The node's key
  E it;                   // The node's value
  BSTNode* lc;            // Pointer to left child
  BSTNode* rc;            // Pointer to right child

public:
  // Two constructors -- with and without initial values
  BSTNode() { lc = rc = nullptr; }
  BSTNode(Key K, E e, BSTNode* l =nullptr, BSTNode* r =nullptr)
    { k = K; it = e; lc = l; rc = r; }
  ~BSTNode() {}             // Destructor

  // Functions to set and return the value and key
  E& element() { return it; }
  void setElement(const E& e) { it = e; }
  Key& key() { return k; }
  void setKey(const Key& K) { k = K; }

  // Functions to set and return the children
  inline BSTNode* left() const { return lc; }
  void setLeft(BSTNode<Key, E>* b) { lc = b; }
  inline BSTNode* right() const { return rc; }
  void setRight(BSTNode <Key, E>* b) { rc = b; }

  // Return true if it is a leaf, false otherwise
  bool isLeaf() { return (lc == nullptr) && (rc == nullptr); }
};

#endif


#ifndef _BT_H_
#define _BT_H_

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







#include <iostream>
#include <string>

int const NUM_TRIALS = 4;
float const P_SUCCESS = 0.7;
void leafSum(float&, BSTNode<std::string, float>*);


int main() {
    ProbT probT;
    BSTNode<std::string, float>* currNode;
    float sum = 0.0;

    std::cout << "heads is 's' and tails is 'f'" << std::endl;

    for(int i = 0; i < NUM_TRIALS; i++) {
        probT.insert(P_SUCCESS);
    }
    std::cout << "prob tree: " << std::endl;
    probT.print();
    std::cout << std::endl;
    
    // all heads
    currNode = probT.getRoot();
    for(int i = 0; i < NUM_TRIALS; i++) {
        currNode = currNode->left();
    }
    std::cout << "the prob of getting "
              << currNode->key()
              << " is: "
              << currNode->element()
              << std::endl;

    // all tails
    currNode = probT.getRoot();
    for(int i = 0; i < NUM_TRIALS; i++) {
        currNode = currNode->right();
    }
    std::cout << "the prob of getting "
              << currNode->key()
              << " is: "
              << currNode->element()
              << std::endl;

    // sum of leaf probabilities
    std::cout << "the sum of all the leaf nodes' probabilities is: ";
    leafSum(sum, probT.getRoot());
    std::cout << sum << std::endl;
}






// traverse the prbability tree and sum the probabilities in the leaf nodes
void leafSum(float &sum, BSTNode<std::string, float>* rt) {
    if(rt->left() != nullptr && rt->right() != nullptr) {
        leafSum(sum, rt->left());
        leafSum(sum, rt->right());
    } else {
        sum += rt->element();
    }
}