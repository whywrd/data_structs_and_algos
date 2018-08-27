/*
Implementation of the void link. 

The void link is designed to hold elements of indetermined types. This is
accomplished through the use of a Variant class which stores information
about the indetermined type. Thus the link actually stores Variants and the
Variants store void pointers and meta info necessary to dereference the void
pointer successfully.
*/

#ifndef _VOID_LINK_H_
#define _VOID_LINK_H_
  
#include <cstdlib>
#include "variant.h"


// Singly linked list node containing Variants
class VoidLink {
	public:
	Variant* element; // Value for this node
	VoidLink* next; // Pointer to next node in list
	// Constructors
	VoidLink(Variant* var, VoidLink* nextval) {
        element = var; next = nextval; 
    }
	VoidLink(VoidLink* nextval =NULL) { next = nextval; }
};

#endif