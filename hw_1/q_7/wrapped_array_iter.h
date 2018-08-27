#ifndef WRAPPED_ARRAY_ITER_H_
#define WRAPPED_ARRAY_ITER_H_

#include "wrapped_array.h"

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