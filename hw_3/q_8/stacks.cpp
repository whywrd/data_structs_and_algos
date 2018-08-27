/*
 * stacks.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: indika
 */
#include <iostream>

using namespace std;

// Singly linked list node
template <typename E> class Link {
	public:
	E element; // Value for this node
	Link *next; // Pointer to next node in list
	// Constructors
	Link(const E& elemval, Link* nextval =NULL)
		{ element = elemval; next = nextval; }
	Link(Link* nextval =NULL) { next = nextval; }
};


// Stack abstarct class
template <typename E> class Stack {
	private:
	void operator =(const Stack&) {} // Protect assignment
	Stack(const Stack&) {} // Protect copy constructor
	public:
	Stack() {} // Default constructor
	virtual ~Stack() {} // Base destructor
	// Reinitialize the stack. The user is responsible for
	// reclaiming the storage used by the stack elements.
	virtual void clear() = 0;
	// Push an element onto the top of the stack.
	// it: The element being pushed onto the stack.
	virtual void push(const E& it) = 0;
	// Remove the element at the top of the stack.
	// Return: The element at the top of the stack.
	virtual E pop() = 0;
	// Return: A copy of the top element.
	virtual const E& topValue() const = 0;
	// Return: The number of elements in the stack.
	virtual int length() const = 0;
};

// Linked stack implementation
template <typename E> class LStack: public Stack<E> {
	private:
	Link<E>* top; // Pointer to first element
	int size; // Number of elements
	public:
	LStack(int sz = 10) // Constructor
	{ top = NULL;
	size = 0;
		}
	~LStack() { clear(); } // Destructor
	void clear() { // Reinitialize
		while (top != NULL) { // Delete link nodes
		Link<E>* temp = top;
		top = top->next;
		delete temp;
	}
	size = 0;
	}
	void push(const E& it) { // Put "it" on stack
		top = new Link<E>(it, top);
		size++;
	}
	E pop() { // Remove "it" from stack
		//Assert(top != NULL, "Stack is empty");
		E it = top->element;
		Link<E>* ltemp = top->next;
		delete top;
		top = ltemp;
		size--;
		return it;
	}
	const E& topValue() const { // Return top value
	//Assert(top != 0, "Stack is empty");
	return top->element;
	}
	int length() const { return size; } // Return length
};


int reverseInt(int);

int main() {

	std::cout << reverseInt(123456) << std::endl;

}




/*
reverseInt
divide by increasing powers of 10 and take the modulus with 10. This will give the
values in incrementing positions. Once the stack has been created with the vals in
the positions, pop them off and sum them while multiplying by 10 to increasing powers.
since stacks are first in first out, the effect is to multiply the higher positions by
lower powers of 10. Thus, reversing the original int.
*/

int reverseInt(int integer) {
	LStack<int> intStack;
	int base, reversed;

	// fill the stack with values from increasing positions of the original int.
	base = 1;
	while((integer / base) > 0) {
		intStack.push((integer / base) % 10);
		base *= 10;
	}

	// pop positions off the stack and multiply them by increasing powers of 10.
	base = 1;
	while(intStack.length() > 0) {
		reversed += intStack.pop() * base;
		base *= 10;
	}

	return reversed;
}


