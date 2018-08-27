/*
DoubleLList 
An implementation of a list or more specifically a linked
list. It consists of DoubleLNodes and as a result can move 
forward and backwards through the list in O(1) time. However,
his time improvement comes at the cost of having two store
an additional pointer (the pointer to the previous node) on 
each node.
*/

#ifndef _DOUBLE_L_LIST_H_
#define _DOUBLE_L_LIST_H_

#include "List.h"
#include "DoubleLNode.h"

template <typename E>
class DoubleLList : public List<E> {

    private:
        DoubleLNode<E>* head;   // pointer to the list's first node
        DoubleLNode<E>* tail;   // pointer to the list's last node
        DoubleLNode<E>* curr;   // pointer to the list's current node
        int cnt;                // the number of nodes in the list

        void init();         // helper to create the list
        void removeAll();    // helper to destroy the list
    
    public:
        DoubleLList();
        ~DoubleLList();
        void clear();
        void insert(const E& item);
        void append(const E& item);
        E remove();
        void moveToStart();
        void moveToEnd();
        void prev();
        void next();
        int length() const;
        int currPos() const;
        void moveToPos(int pos);
        E getValue() const;
        void printList() const;
};

#endif