/*
A driver to test a our CircleList
*/

#include "CircleList.h"
#include <iostream>
#include <stdio.h>


const int listSize = 10;


template <typename E>
void print(CircleList<E>&);


int main() { 
    CircleList<int> list;
    int cnt = 0, tmp;
    
    std::cout << "input " << listSize << " integers: ";
    while(cnt++ < listSize) {
        std::cin >> tmp; 
        list.append(tmp);
    };
    getchar();

    // print the list
    std::cout << std::endl << "printing list: " << std::endl;
    print(list);
}






/*
print
prints a CircleList. Because a CircleList never ends it
continues until keyboard interupt is signalled
*/

template <typename E>
void print(CircleList<E> &list) {
    int input;
    std::cout << "enter a key to print the next element. esc to exit: ";
    
    input = getchar();
    while (input != 27) {
        std::cout << list.getValue();
        list.next();
        input = getchar();
    }
}