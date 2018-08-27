/*
Will Hayward
CS 110C
HW 5
Question 8 

The implementation of an isBST method to identify whether or not a binary tree
is a binary search tree. This implementation uses the fact that a binary search
tree must preserve its qualities at any locality or put another way, any subtree
must be a binary search tree. This argument applies bidirectionally in that if
all subtrees are binary search trees than the full tree is a binary search tree.
To see this consider that the binary search tree requirements uniquely constrain
a collection of nodes such that given a collection of nodes than can only be 
constructed into one shape that that satisifies a binary search tree (assuming that
nodes with the same values are equal). Therefore, it is enough to check that each
node and its children satisfy the binary search tree requirements to prove that
the full tree is a binary search tree.

Time complexity discussion:
Since only each node and children group need to be examined, the algorithm can be
implemented recursively and the total number of checks is equal to the number of nodes.
Therefore the time complexity is equal to n*O(node check) where O(node check) = c.
Therefore the time complexity is proporitional to the number of nodes in the worst case
(which is when the tree is a binary search tree because all nodes need to be examined).
And, in the best case (when the first node fails the check), the time complexity is
constant because the recursion terminates and a value of false is returned.

In summary:
BEST CASE: O(n) = c because the first node fails and the recursion terminates.
WORST CASE: O(n) = n because it is a binary search tree and all nodes need to be examined.
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
  const E& element() const { return it; }
  void setElement(const E& e) { it = e; }
  const Key& key() const { return k; }
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
    BSTNode<Key, E>* getRoot();
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






// return the root of the tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::getRoot() {
    return root;
}

#endif







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
    BSTNode<Key, E>* getRoot();
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






// return the root of the tree
template <typename Key, typename E>
BSTNode<Key, E>* BT<Key, E>::getRoot() {
    return root;
}

#endif


#include <iostream>

const int NUM_NODES = 10;

template <typename Key, typename E>
bool isBST(const BSTNode<Key, E>* root);


int main() {
    int nodeArray[] = {4, 1, 5, 2, 9, 8, 7, 0, 3, 6};
    BST<int, int> bst;    // the binary search tree
    BT<int, int> bt;      // the binary tree

    for(int i = 0; i < NUM_NODES; i++) {
        bst.insert(nodeArray[i], nodeArray[i]);
        bt.insert(nodeArray[i], nodeArray[i]);
    }

    // test the binary search tree
    std::cout << "tree 1: " << std::endl;
    bst.print();
    std::cout << std::endl
              << "is binary search tree: "
              << isBST(bst.getRoot())
              << std::endl;

    // test the binary tree
    std::cout << "tree 2: " << std::endl;  
    bt.print();
    std::cout << std::endl
              << "is binary search tree: "
              << isBST(bt.getRoot())
              << std::endl;

}






// isBST
// check that each node's left child's key is less than the root key and that the
// right child's key is greater than or equal to the root key.
template <typename Key, typename E>
bool isBST(const BSTNode<Key, E>* rt) {
    bool leftBST = true,    // whether or not the left and right children are BSTs
         rightBST = true;   // default true bc null node is bst
    if(rt->left() != nullptr) {
        if(rt->key() <= rt->left()->key()) return false;
        leftBST = isBST(rt->left());
    }
    if(rt->right() != nullptr) {
        if(rt->key() > rt->right()->key()) return false;
        rightBST = isBST(rt->right());
    }
    return leftBST & rightBST;
}