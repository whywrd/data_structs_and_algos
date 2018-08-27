/*
CS 110c 
Homework 1
Question 3


Print a multiplication table in the form:
1 | 1 2 3 4 
_________
2 | 2 4 6 8
3 | 3 6 9 12
4 | 4 8 12 16

Where a row is the multiple, a vertical line separator and then the product
of the multiple times each number in the range 1..n where n is the end number
in the table.

Between the header row and the following rows, there is a separator row of 
n*2 + 1 underscores.
*/

#include <iostream>
#include <assert.h>

using namespace std;

// prototypes
void printMultiplicationTable(int max);
void printRow(int multiple, int max);
void printSeparator(int max);
void printRowLabel(int multiple);


int main() {
    printMultiplicationTable(12);
    return 0;
}




 

/*
printMultiplicationTable
Print the entire multiplication table. The precondition is that the max is
greater than 2. A table consists of the header row, the header row separator,
and then rows (with row separators) for multiples in range 2..max
*/

void printMultiplicationTable(int max){
    assert(max > 1);
    printRowLabel(1);
    printRow(1, max);
    printSeparator(max);
    for(int i = 2; i < max + 1; i++) {
        printRowLabel(i);
        printRow(i, max);
    }
}






/*
printRowLabel
Print the label that separates that specifies the multiple that each
value in the row is being multiplied by.
*/

void printRowLabel(int multiple) {
    cout << multiple << " |";
}






/*
printSeparator
Print underscores to separate the header row from the internal rows
*/

void printSeparator(int max) {
    for(int i; i < 2 * (max + 1); i++) {
        cout << "_";
    }
    cout << endl;
}






/*
printRow
Print the values in the row. The entries in the row are the numbers in
range 1..max multiplied by the multiple.
*/

void printRow(int multiple, int max) {
    for(int i = 2; i < max + 1; i++) {
        cout << " " << i * multiple;
    }
    cout << endl;
}






/*
output:

1 | 2 3 4 5 6 7 8 9 10 11 12
__________________________
2 | 4 6 8 10 12 14 16 18 20 22 24
3 | 6 9 12 15 18 21 24 27 30 33 36
4 | 8 12 16 20 24 28 32 36 40 44 48
5 | 10 15 20 25 30 35 40 45 50 55 60
6 | 12 18 24 30 36 42 48 54 60 66 72
7 | 14 21 28 35 42 49 56 63 70 77 84
8 | 16 24 32 40 48 56 64 72 80 88 96
9 | 18 27 36 45 54 63 72 81 90 99 108
10 | 20 30 40 50 60 70 80 90 100 110 120
11 | 22 33 44 55 66 77 88 99 110 121 132
12 | 24 36 48 60 72 84 96 108 120 132 144
*/
