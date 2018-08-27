/*
Variant class. Objects of this type contain a void pointer to
an object in memory and type field describing the type of the
object being pointed to. This allows us to create void pointers
while retaining knowledge of the type of the object being pointed 
to. Variants are limited to types with corresponding elements
in the Type enumerator.
*/

#ifndef _VARIANT_H_
#define _VARIANT_H_

#include <typeinfo>
#include <iostream>

// enum of types supported by the void link
enum Type {
    t_int,
    t_char,
    t_double
};


// class to store info about the element stored in a link
class Variant {

    private:
        Type type;    // stores the type of the item
        void* item;   // stores a void pointer to the item
        
        //Given an argument of any type return the corresponding Type element.
        template <typename E>
        Type deduceType(E it) {
            Type type;
            if( typeid(E) == typeid(int) ) {
                type = t_int;
            } else if ( typeid(E) == typeid(char) ) {
                type = t_char;
            } else if ( typeid(E) == typeid(double) ) {
                type = t_double;
            } else {
                throw "unsupported type";
            }
            return type;
        }

    public:
        Variant() {};  // defualt constructor

        template <typename E>
        Variant(E &it) {  // constructor given a argument
            type = deduceType(it);
            item = &it;
        }

        Type getType() const { // return the type of the item
            return type;
        }

        const void* getItem() const {  // return a void pointer to the item
            return item;
        }

        void printValue() const {
            switch(type) {
                case t_int:
                    std::cout << *static_cast<const int*>(item);
                    break;
                case t_char:
                    std::cout << *static_cast<const char*>(item);
                    break;
                case t_double:
                    std::cout << *static_cast<const double*>(item);
                    break;
            };
        }
};

#endif