/*
CS 110c 
Homework 1
Question 5

Write a function to perform r left rotations on an integer array.

An example of a single left rotation:
[1,2,3,4,5] -> [2,3,4,5,1];
*/

#include<iostream>

using namespace std;

void leftRotations(int r, int array[], int N); // r rotations
void printArray(int array[], int size); // print the elements of an int array


int main() {
    int array[] = {0, 1, 2, 3, 4, 5};
    cout << "2 rotations: ";
    leftRotations(2, array, 6);
    printArray(array, 6);
    cout << endl;
    
    cout << "4 rotations back to original: ";
    leftRotations(4, array, 6);
    printArray(array, 6);
    cout << endl;
    
    cout << "32 rotations: ";
    leftRotations(32, array, 6);
    printArray(array, 6);
    cout << endl;
}






/*
leftRotations
Perform r left rotations.

Need the array size to be passed as an argument. Could have used a template 
function in order to determine the length of the array being passed in, but
that would have created a different function for every array of a different 
size. 

Note that if r > N, r rotations is equivalent to r % N rotations.
*/

void leftRotations(int r, int array[], int N) {
    r = r % N;
    for(int remaining = r; remaining > 0; remaining--) {
        int temp = array[0];
        for(int i = 0; i < N; i++) {
            array[i] = array[i+1];
        }
        array[N - 1] = temp;
    }
}






/*
printArray
print the int array
*/

void printArray(int array[], int size) {
    int i = 0;
    cout << array[i++];
    while(i < size){
        cout << " " << array[i++];
    }
}






/*
output

2 rotations: 2 3 4 5 0 1
4 rotations back to original: 0 1 2 3 4 5
32 rotations: 2 3 4 5 0 1
*/