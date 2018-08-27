/*
A queue that takes nodes with variable types. This is accomplished via
void pointers and as a result the types to be stored need to be known and
accounted for in order to derreference them. In this implementation the
void pointers and their types are stored in an object called a Variant and
the elements in the list are pointers to Variants.

For the purpose of this assignment the allowed types are int, char and double.
*/

#ifndef _VOID_LQUEUE_H_
#define _VOID_LQUEUE_H_

#include "void_link.h"
#include "queue.h"  
#include <cassert>
#include <typeinfo>

class VoidLQueue: public Queue<Variant*> {
	
	private:
	VoidLink* front; // Pointer to front queue node
	VoidLink* rear; // Pointer to rear queue node
	int size; // Number of elements in queue 
	
	public:
	VoidLQueue(int sz = 20) // Constructor
	{ front = rear = new VoidLink(); size = 0; }
	~VoidLQueue() { clear(); delete front; } // Destructor
	
	void clear() { // Clear queue
		while(front->next != NULL) { // Delete each link node
			rear = front;
			delete rear->element;    // Delete the variant
			delete rear;
		}
		rear = front;
		size = 0;
	}

	template <typename E>
	void enqueue(E &it) {
		Variant* var = new Variant(it);
		enqueue(var);
	}

	void enqueue(Variant* var) { // Put element on rear
		rear->next = new VoidLink(var, NULL);
		rear = rear->next;
		size++;
	}

	Variant* dequeue() { // Remove element from front
		assert(size != 0);
		Variant* var = front->next->element;
		VoidLink* ltemp = front->next; // Hold dequeued link
		front->next = ltemp->next; // Advance front
		if (rear == ltemp) rear = front; // Dequeue last element
		delete ltemp;
		size --;
		return var; // Return link
	}

	Variant *const & frontValue() const { // Get front element
		assert(size != 0);
		return front->next->element;
	}
	
	virtual int length() const { return size; }
};


#endif