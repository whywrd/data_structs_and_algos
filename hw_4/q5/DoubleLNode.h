/*
DoubleLNode 
A node in a doubly linked list. This means it contains pointers
to the previous node in the list and the next node in the list.
*/

#ifndef _DOUBLE_L_NODE_H_
#define _DOUBLE_L_NODE_H_

#include <stddef.h>

template <typename E>
class DoubleLNode {

    private:
        E v;                // the value stored in the node
        DoubleLNode* prv;   // a pointer to the previous element
        DoubleLNode* nxt;   // a pointer to the next element

    public:
        // fully specified constructor
        DoubleLNode(const E& val, DoubleLNode* prevp, DoubleLNode* nextp) {
            v = val;
            prv = prevp;
            nxt = nextp;
        } 
      
        // default constructor
        DoubleLNode(DoubleLNode* prevp=NULL, DoubleLNode* nextp=NULL) {
            prv = prevp;
            nxt = nextp;
        }

        // accessors and mutators for the private members
        E value() { return v; }
        void setValue(E val) { v = val; }
        DoubleLNode* prev() { return prv; }
        void setPrev(DoubleLNode* prev) { prv = prev; }
        DoubleLNode* next() { return nxt; }
        void setNext(DoubleLNode* next) { nxt = next; }

};

#endif