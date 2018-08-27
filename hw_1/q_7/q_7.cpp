/*
CS 110c 
Homework 1
Question 7
FILE: q_7.cpp

The driver program.
*/

#include <iostream>
#include "wrapped_array.h"


int main() {
    
    // test with array of size 24 where it's values are 0,1,2,3,4,5,...,23
    // should print out 0,3,6,...,21
    std::cout << "test1 -- expect 0,3,6,...,21: " << std::endl;
    int size_1 = 24;
    int array_1[size_1];
    
    for(int i = 0; i < size_1; i++) {
        array_1[i] = i;
    }
    
    WrappedArray<int> wArray_1 = WrappedArray<int>(array_1, size_1);
    for(WrappedArray<int>::iterator iter = wArray_1.begin(); 
        iter != wArray_1.end(); iter++ ) {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    // test with array of size 25 where values are 0,1,2,3,4,5,...,24
    // should print out 0,3,6,...,24
    std::cout << "test2 -- expect 0,3,6,...,24: " << std::endl;
    int size_2 = 25;
    int array_2[size_2];

    for(int i = 0; i < size_2; i++) {
        array_2[i] = i;
    }

    WrappedArray<int> wArray_2 = WrappedArray<int>(array_2, size_2);
    for(WrappedArray<int>::iterator iter = wArray_2.begin();
        iter != wArray_2.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    return 0;
}






/*
output:
test1 -- expect 0,3,6,...,21: 
0
3
6
9
12
15
18
21

test2 -- expect 0,3,6,...,24: 
0
3
6
9
12
15
18
21
24
*/