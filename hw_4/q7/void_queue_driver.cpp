#include "void_lqueue.h"
#include <iostream>

void printVariant(const Variant&);


int main() {
    int intVal1 = 18, intVal2 = 9183;
    double doubleVal1 = 421.31, doubleVal2 = 138941.183;
    char charVal1 = 'a', charVal2 = '!';

    VoidLQueue queue;
    queue.enqueue(intVal1);
    queue.enqueue(doubleVal1);
    queue.enqueue(charVal1);
    queue.enqueue(intVal2);
    queue.enqueue(doubleVal2);
    queue.enqueue(charVal2);

    while(queue.length() > 0) {
        Variant* var = queue.dequeue();
        var->printValue();
        std::cout << " ";
        delete var;   // delete the variant
    }
    std::cout << std::endl;
}
