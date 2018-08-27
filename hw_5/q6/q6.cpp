/*
Will Hayward
CS 110C
HW 5
Question 6

Extend the binary search tree to include the following 3 methods.

printLeft: prints the left most nodes of the tree ie the left most edge of the tree
graph. In the best case the tree will have no left edge and O(h) = c becuase there is
nothing to traverse. In the worst case the tree will have a full left edge of height 
equal to the heigh of the tree. In this case O(h) = h because each node is visited 
once and printed.

printRight: prints the right most nodes of the tree ie the right most edge of the
tree graph. The time complexity analysis for this method is the same as the analysis
for printLeft except right is substituted for left. Therefore in the best case
O(h) = c and in the worst case O(h) = h.

printLeaves: prints all nodes in the tree that has 2 empty subtrees. In terms of the
number of nodes in the tree, this method always performs with the same time complexity.
This is due to the fact that is a recursive algorithm that must visit all of the tree's
nodes. Therefore the time complexity in terms of n is n. However, in terms of the tree's
height, if tree has given height h, the time complexity is smaller for trees with fewer
nodes and greater for trees with more nodes. Therefore, if the tree is a single branch,
O(h) = h. Alternatively, if the tree is full, O(h) = 2^h
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






/*
An implementation of a binary search tree where each node has a key
and an element. The key is used in comparisons when constructing
or altering the tree such that the keys for all nodes on the left subtree
are less than or equal to the keys for nodes on the right subtrees.
*/
#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST {
private:
    BSTNode<Key,E>* root;     // Root of the BST
    int nodecount;            // Number of nodes in the BST

    void clearhelp(BSTNode<Key, E>*);
    BSTNode<Key,E>* inserthelp(BSTNode<Key, E>*, const Key&, const E&);
    BSTNode<Key,E>* deletemin(BSTNode<Key, E>*);
    BSTNode<Key,E>* getmin(BSTNode<Key, E>*);
    BSTNode<Key,E>* removehelp(BSTNode<Key, E>*, const Key&);
    E findhelp(BSTNode<Key, E>*, const Key&) const;
    void printhelp(BSTNode<Key, E>*, int) const;
    void printRightHelper(BSTNode<Key, E>*) const;
    void printLeftHelper(BSTNode<Key, E>*) const;
    void printLeavesHelper(BSTNode<Key, E>*) const;


public:
    BST() { root = NULL; nodecount = 0; }    // Constructor
    ~BST() { clearhelp(root); }              // Destructor
    void clear();
    void insert(const Key& k, const E& e);
    E remove(const Key& k);
    E removeAny();
    E find(const Key& k) const;
    int size() const;
    void print() const;
    void printRight() const;
    void printLeft() const;
    void printLeaves() const;
};






// Reinitialize tree
template <typename Key, typename E>
void BST<Key, E>::clear(){ 
    clearhelp(root); 
    root = NULL; 
    nodecount = 0; 
}






// Insert a record into the tree.
// k Key value of the record.
// e The record to insert.
template <typename Key, typename E>
void BST<Key, E>::insert(const Key& k, const E& e) {
    root = inserthelp(root, k, e);
    nodecount++;
}






// Remove a record from the tree.
// k Key value of record to remove.
// Return: The record removed, or NULL if there is none.
template <typename Key, typename E>
E BST<Key, E>::remove(const Key& k) {
    E temp = findhelp(root, k);     // First find it
    if (temp != NULL) {
        root = removehelp(root, k);
        nodecount--;
    }
    return temp;
}






// Remove and return the root node from the dictionary.
// Return: The record removed, null if tree is empty.
template <typename Key, typename E>
E BST<Key, E>::removeAny() {
    if (root != NULL) {
        E temp = root->element();
        root = removehelp(root, root->key());
        nodecount--;
        return temp;
    } 
    else return NULL;
}






// Return Record with key value k, NULL if none exist.
// k: The key value to find. */
// Return some record matching "k".
// Return true if such exists, false otherwise. If
// multiple records match "k", return an arbitrary one.
template <typename Key, typename E>
E BST<Key, E>::find(const Key& k) const { 
    return findhelp(root, k); 
}






// Print the contents of the BST
template <typename Key, typename E>
void BST<Key, E>::print() const {
    if (root == NULL) cout << "The BST is empty.\n";
    else printhelp(root, 0);
}






// return the number of nodes in the tree
template <typename Key, typename E>
int BST<Key, E>::size() const {
    return nodecount;
}






// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::clearhelp(BSTNode<Key, E>* root) {
    if (root == NULL) return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}






// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::inserthelp(
        BSTNode<Key, E>* root, const Key& k, const E& it) {
    if (root == NULL)  // Empty tree: create node
        return new BSTNode<Key, E>(k, it, NULL, NULL);
    if (k < root->key())
        root->setLeft(inserthelp(root->left(), k, it));
    else root->setRight(inserthelp(root->right(), k, it));
    return root;       // Return tree with node inserted
}






// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::getmin(BSTNode<Key, E>* rt) {
    if (rt->left() == NULL)
        return rt;
    else return getmin(rt->left());
}






template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::deletemin(BSTNode<Key, E>* rt) {
    if (rt->left() == NULL) // Found min
        return rt->right();
    else {                  // Continue left
        rt->setLeft(deletemin(rt->left()));
        return rt;
    }
}






// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::removehelp(BSTNode<Key, E>* rt, const Key& k) {
    if (rt == NULL) return NULL;        // k is not in tree
    else if (k < rt->key())
        rt->setLeft(removehelp(rt->left(), k));
    else if (k > rt->key())
        rt->setRight(removehelp(rt->right(), k));
    else {                                // Found: remove it
        BSTNode<Key, E>* temp = rt;
        if (rt->left() == NULL) {         // Only a right child
            rt = rt->right();             // so point to right
            delete temp;
        }
        else if (rt->right() == NULL) { // Only a left child
            rt = rt->left();            // so point to left
            delete temp;
        }
        else {                          // Both children are non-empty
            BSTNode<Key, E>* temp = getmin(rt->right());
            rt->setElement(temp->element());
            rt->setKey(temp->key());
            rt->setRight(deletemin(rt->right()));
            delete temp;
        }
    }
    return rt;
}






// Find a node with the given key value
template <typename Key, typename E>
E BST<Key, E>::findhelp(BSTNode<Key, E>* root, const Key& k) const {
    if (root == NULL) return NULL;          // Empty tree
    if (k < root->key())
        return findhelp(root->left(), k);   // Check left
    else if (k > root->key())
        return findhelp(root->right(), k);  // Check right
    else return root->element();    // Found it
}






// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::printhelp(BSTNode<Key, E>* root, int level) const {
    if (root == NULL) return;           // Empty tree
    printhelp(root->left(), level+1);   // Do left subtree
    for (int i=0; i<level; i++)         // Indent to level
        cout << "     ";
    cout << root->element() << "\n";    // Print node value
    printhelp(root->right(), level+1);  // Do right subtree
    
}





// print nodes along the right edge of the tree
template <typename Key, typename E>
void BST<Key, E>::printRight() const {
    printRightHelper(root);
}





// given a node traverse right nodes printing along the way
template <typename Key, typename E>
void BST<Key, E>::printRightHelper(BSTNode<Key, E>* rt) const {
    if(rt == nullptr) return;
    cout << rt->element() << " ";
    printRightHelper(rt->right());
}






// print nodes along the left edge of the tree
template <typename Key, typename E>
void BST<Key, E>::printLeft() const {
    printLeftHelper(root);
}





// given a node traverse left nodes printing along the way
template <typename Key, typename E>
void BST<Key, E>::printLeftHelper(BSTNode<Key, E>* rt) const {
    if(rt == nullptr) return;
    cout << rt->element() << " ";
    printLeftHelper(rt->left());
}





// print the leaf nodes of a tree
template <typename Key, typename E>
void BST<Key, E>::printLeaves() const {
    printLeavesHelper(root);
}






// traverse until both children are null, then print element
template <typename Key, typename E>
void BST<Key, E>::printLeavesHelper(BSTNode<Key, E>* rt) const {
    if(rt == nullptr) return;
    if(rt->left() == nullptr && rt->right() == nullptr){
        cout << rt->element() << " ";
        return;
    }
    printLeavesHelper(rt->left());
    printLeavesHelper(rt->right());
}

#endif





#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int TREE_SIZE = 12;

void randomBST(BST<int, int> &tree, int len);


int main() {
    // initialize rng
    std::srand ( unsigned ( std::time(0) ) );

    BST<int, int> tree;
    randomBST(tree, TREE_SIZE);
    
    // print the tree and its shape
    cout << "The tree looks like: " << endl;
    tree.print();
    cout << endl;

    cout << "The left nodes are: " << endl;
    tree.printLeft();
    cout << endl;

    cout << "The right nodes are: " << endl;
    tree.printRight();
    cout << endl;

    cout << "The leaves are: " << endl;
    tree.printLeaves();
    cout << endl;
}



void randomBST(BST<int, int> &tree, int len) {
    vector<int> myvector;
    for(int i = 0; i < len; i++) {
        myvector.push_back(i + 1);
    }
    
    std::random_shuffle( myvector.begin(), myvector.end() );
    
    for(std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
            tree.insert(*it, *it);
    }
}