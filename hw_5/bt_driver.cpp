#include "BT.h"
#include <iostream>

const int ARRAY_SIZE = 10;

int main() {
    int a[] = {4, 1, 5, 2, 9, 8, 7, 0, 3, 6};
    BT<int, int> bt;

    for(int i=0; i<ARRAY_SIZE; i++) {
        bt.insert(a[i], a[i]);
    }

    bt.print();
}