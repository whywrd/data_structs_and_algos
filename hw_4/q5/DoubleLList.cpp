/*
Implementation of a doubly linked list
In this implementation curr points to the node containing the actual
current element.
*/

#include "DoubleLList.h"
#include "DoubleLNode.h"
#include <cassert>
#include <iostream>


/*
init
Helper method to create an empty list.
*/

template <typename E>
void DoubleLList<E>::init() {
    head = new DoubleLNode<E>();
    tail = new DoubleLNode<E>();
    head->setNext(tail);
    tail->setPrev(head);
    curr = tail;
    cnt = 0;
}






/*
removeAll
Helper to safely delete all nodes in the list
*/

template <typename E>
void DoubleLList<E>::removeAll() {
    while(head != NULL) {
        curr = head;
        head = head->next();
        delete curr;
    }
}






/*
Constructor, just calls init.
*/

template <typename E>
DoubleLList<E>::DoubleLList() {
    init();
}






/*
Destructor, removes all nodes
*/

template <typename E>
DoubleLList<E>::~DoubleLList() {
    removeAll();
}






/*
clear
make the list list empty
*/

template <typename E>
void DoubleLList<E>::clear() {
    removeAll();
    init();
}





/*
insert
Insert val at the current position
*/

template <typename E>
void DoubleLList<E>::insert(const E &val) {
    DoubleLNode<E>* newNode = new DoubleLNode<E>(val, curr->prev(), curr);
    curr->prev()->setNext(newNode);
    curr->setPrev(newNode);
    curr = newNode;
    cnt++;
}






/*
append
insert val at the end of the list. Note that a doubly linked list
has an empty tail node therefore, the node should be placed one
before the tail.
*/

template <typename E>
void DoubleLList<E>::append(const E &val) {
    DoubleLNode<E>* newNode = new DoubleLNode<E>(val, tail->prev(), tail);
    tail->prev()->setNext(newNode);
    tail->setPrev(newNode);
    cnt++;
}






/*
remove
remove and return the current node and return its current value
*/

template <typename E>
E DoubleLList<E>::remove() {
    if( curr == tail || curr == head ) {
        return NULL;
    }
    DoubleLNode<E>* node = curr;
    curr->next()->setPrev(curr->prev());  // previous node goes around curr
    curr->prev()->setNext(curr->next());  // next node goes around curr
    if(curr->next() == tail) {
        curr = curr->prev();
    } else {
        curr = curr->next();
    }
    E val = node->value();
    delete node;
    cnt--;
    return val;
}







/*
moveToStart()
move curr to the start of the list. 
Note that head is a reserved node and its next node is only NULL on init.
*/

template <typename E>
void DoubleLList<E>::moveToStart() {
    if (head->next() != NULL) {
        curr = head->next();
    }
}






/*
moveToEnd
move curr to the end of the list. 
Note that tail is a reserved node and its previous node is only NULL on init.
*/

template <typename E>
void DoubleLList<E>::moveToEnd() {
    if(tail->prev() != NULL) {
        curr = tail->prev();
    }
}







/*
prev
move backwards one in the list. 
Note that head is reserved node. Therefore it is necessary to check 
that that curr is not being moved to head.
*/

template <typename E>
void DoubleLList<E>::prev() {
    if( curr != head && curr->prev() != head) {
        curr = curr->prev();
    }
}







/*
next
move forwards one in the list. 
Note that tail is a reserved node therefore make sure that curr is
not being moved to tail. Additionally, curr is set to tail on init. 
Therefore it is necessary to check that curr is not equal to tail.
*/

template <typename E>
void DoubleLList<E>::next() {
    if( curr != tail && curr->next() != tail) {
        curr = curr->next();
    }
}






/*
length
return the number of nodes (excluding head and tail) in the list
*/

template <typename E>
int DoubleLList<E>::length() const {
    return cnt;
}






/*
currPos
return the position of the element in the list
Start at -1 because head is a reserved node and is technically
outside the pounds of the list.
*/

template <typename E>
int DoubleLList<E>::currPos() const {
    DoubleLNode<E>* temp = head;
    int i;
    for(i=-1; temp != curr; i++) {
        temp = temp->next();
    }
    return i;
}






/*
moveToPos
move down list to pos position
*/

template <typename E>
void DoubleLList<E>::moveToPos(int pos) {
    assert(pos >= 0 && pos < cnt);
    moveToStart();
    for(int i=0; i<pos; i++) {
        curr = curr->next();
    }
}






/*
getValue
return the current value
*/

template <typename E>
E DoubleLList<E>::getValue() const {
    assert(curr != NULL);
    return curr->value();
}






/*
printList
print the contents of the list
*/

template <typename E>
void DoubleLList<E>::printList() const {
    DoubleLNode<E>* node = head->next();
    std::cout << "[";
    
    // When empty, head's next is tail therefore make sure it isn't
    // starting at tail. Stop before the last element so that there
    // isn't an extra comma.
    while( node->next() != tail && node != tail) {
        std::cout << node->value() << ", ";
        node = node->next();
    }
    
    std::cout << node->value() << "]";  
}