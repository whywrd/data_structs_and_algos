#include <iostream>

using namespace std;

int main() {
    // setup the problem
    int x, y, z;
    int * ptrx, * ptry, * ptrz;
    ptrx = &x;
    ptry = &y;
    ptrz = &z;
    
    // test 1
    *ptrx = 10;
    // if this does the same thing as x = 10, the following should return true
    cout << (x == 10) << endl;

    // test 2
    // if the output of *ptrx and x are the same, then *ptrx == x.
    // therefore the following will return true.
    cout << (*ptrx == x) << endl;

    // test3
    // if cin >> *ptrx is equivalent to cin >> x; then cin >> *ptrx
    // should result in *ptrx == x;
    cout << "enter some value: ";
    cin >> *ptrx;
    cout << (*ptrx == x) << endl;

    // test4
    // if *ptrz = *ptrx + *ptry, then before addition, *ptrx == *ptry
    // and after addition *ptrz == z
    x = 1;
    y = 2;
    *ptrz = *ptrx + *ptry;
    cout << (*ptrx == x && *ptry == y && *ptrz == z) << endl;

    // test5
    // if cout << ptrx + 1 is equivalent to cout << x + 1, then
    // ptrx + 1 == x + 1;
    // cout << ((ptrx + 1) == (x + 1)) << endl; // can't compile bc cant compair ptr to int

    int number = 20;
    string phrase = string("test");
    void* test;
    test = &number;
    test = &phrase;
}