#include "DoubleLList.cpp"
#include <iostream>
#include <string>

int main() {
    DoubleLList<std::string> list;
    
    // build list
    std::string temp;
    std::cout << "enter strings (-1 to stop):" << std::endl;
    std::cin >> temp;
    while( temp != "-1" ) {
        list.append(temp);
        std::cin >> temp;
    }

    // print forwards
    list.printList();

    std::cout << std::endl;

    // print backwards
    list.moveToEnd();
    std::cout << "[";
    while( list.currPos() > 0 ) {
        std::cout << list.getValue() << ", ";
        list.prev();
    }
    std::cout << list.getValue();
    std::cout << "]";

    std::cout << std::endl;
}
