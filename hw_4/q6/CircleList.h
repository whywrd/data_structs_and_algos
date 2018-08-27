/*
A Circular List implementation.
A circular list is a linked list where the tail link points to the head link.
In implementation this means that there is no concrete notion of a head, tail
or absolute position because every node is identical in the sense that it has
a value, and a non empty pointer to next node. In order to fulfill the list
ADT, the head of the list is whichever link you are on and, by extension, the 
tail is the previous node.
*/

#ifndef _CIRCLE_LIST_H_
#define _CIRCLE_LIST_H_

#include "list.h"
#include "link.h"
#include <cassert>

const int defaultSize = 20;

// This is the declaration for CircleList. It is split into two parts
// Circular list implementation
template <typename E> class CircleList: public List<E> {
private:
  Link<E>* curr;       // Access to current element
  int cnt;    	       // Size of list

  void init() {        // Intialization helper method
    cnt=0;
  }

  void firstLink(E it) {  // make a single link pointing to itself
    curr = new Link<E>();
    curr->element = it;
    curr->next = curr;
  }

  void removeall() {   // Return link nodes to free store
    while( cnt-- > 0 ) {
      Link<E>* tmp = curr;
      curr = curr->next;
      delete tmp;
    }
  }

public:
  CircleList(int size=defaultSize) { init(); }    // Constructor
  ~CircleList() { removeall(); }                   // Destructor
  void print() const;                // Print list contents
  void clear() { removeall(); init(); }       // Clear list

  // Insert "it" at current position
  void insert(const E& it) {
    if ( cnt == 0 ) {  // if empty create a single link pointing to itself
      firstLink(it);
    } else {
      curr->next = new Link<E>(it, curr->next);
    }
    cnt++;
  }

  void append(const E& it) { // Append "it" to list
    insert(it);         // this sets it before original curr
    curr = curr->next;  // move back to original position with it at end
    cnt++;
  }

  // Remove and return current element
  E remove() {
    assert(cnt != 0);                // make sure there is a link to remove
    E it = curr->next->element;      // Remember value
    Link<E>* ltemp = curr->next;     // Remember link node
    curr->next = curr->next->next;   // Remove from list
    delete ltemp;                    // Reclaim space
    cnt--;			     // Decrement the count
    return it;
  }

  void moveToStart() {}; // start is curr by definition

  void moveToEnd()   // Place curr at list end ie prev
    { prev(); }

  // Move curr one step left; no change if already at front
  void prev() {
    if (cnt == 0) return;       // No previous element
    Link<E>* temp = curr;
    // March down list until next is curr
    while (temp->next!=curr) temp=temp->next;
    curr = temp;
  }

  // Move curr one step right; no change if already at end
  void next() {
    if ( cnt != 0 ) curr = curr->next;
  }

  int length() const { return cnt; } // Return length

  // Return the position of the current element
  int currPos() const {
    return 0;
  }

  // Move down list to "pos" position
  void moveToPos(int pos) {
    assert ((pos>=0)&&(pos<=cnt));
    for(int i=0; i<pos; i++) curr = curr->next;
  }

  const E& getValue() const { // Return current element
    assert(cnt != 0);
    return curr->next->element;
  }
};


#endif