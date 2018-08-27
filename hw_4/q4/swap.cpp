/*
Will Hayward
CS110C
Homework 4 Question 4

This program defines and tests a function that swaps two arguments without the use of
a temporary address. This is accomplished by the following process:

given a and b
a = a + b
b = a - b     // therefore b = a
a = a - b     // therefore a = b

*/

#include <iostream>

template <typename E> void swap(E&, E&);


int main() {
    // test swap with two integers
    int a = 10, b = 20;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    swap(a, b);
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}






/*
swap
Swaps two variables of the same type in place
For this to work subtraction and addition must be defined as inverse operations for
the type. 
*/

template <typename E> void swap(E &left, E &right) {
    left = left + right;
    right = left - right;
    left = left - right;
}
