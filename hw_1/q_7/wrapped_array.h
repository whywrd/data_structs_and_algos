/*
CS 110c 
Homework 1
Question 7
FILE: wrapped_array.h
*/

#ifndef WRAPPED_ARRAY_H_
#define WRAPPED_ARRAY_H_

#include <stddef.h>  // size_t, ptrdiff_t

// forward declare iterator
template <class T> class WrappedArrayIter;


// container class and inline implementation

template <class T>
class WrappedArray {
    private:
        int size;
        T array[100]; // the underlying array
        WrappedArray(); // hide default constructor

    public:

        // typedefs needed for iterator
        typedef WrappedArrayIter<T> iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef T value_type;
        typedef T * pointer;
        typedef T & reference;

        WrappedArray(T _array[], int _size) {
            size = _size;
            for(int i = 0; i < _size; i++) {
                array[i] = _array[i];
            }
        }

        // begin iterator
        iterator begin() { return iterator(*this, 0); };

        // returns iterator pointing one past the end
        iterator end() { 
            return iterator(*this, size % 3 ? size + 3 - (size % 3) : size); 
        };

        // the associated iterator is a friend
        friend class WrappedArrayIter<T>;
};


// iterator class and inline implementation

template <class T>
class WrappedArrayIter {
   
    private:
        WrappedArray<T> & w;
        int position;
    
    public:

        WrappedArrayIter(WrappedArray<T> wa, int pos) :
            w( wa ), position(pos) {};
        
        WrappedArrayIter(const WrappedArrayIter& wit) :
             w(wit.w), position(wit.position) {};
        
        WrappedArrayIter& operator++() { position += 3; };
        
        WrappedArrayIter operator++(int) {
            WrappedArrayIter tmp(*this); 
            operator++(); 
            return tmp;
        };

        bool operator==(const WrappedArrayIter& rhs) const {
            return &w.array[position] == &rhs.w.array[rhs.position];
        }

        bool operator!=(const WrappedArrayIter& rhs) const {
            return &w.array[position] != &rhs.w.array[rhs.position];
        }

        int& operator*() {
            return w.array[position];
        }
};

#endif