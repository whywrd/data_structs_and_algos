/*
Will Hayward
CS 110C
HW 6 Q10

Experiment to measure how different implementations of the find
pivot function affects the running time of quicksort on unsorted
and sorted arrays.


The three find pivot implementations being examined are:

firstPivot: takes the first index of the subarray as the pivot.

middlePivot: takes the middle index of the subarray as the pivot.

randomPivot: takes a random index between the beginning and end
of the subarray as the pivot.


results:
cpu time using first element as a pivot: 1605
cpu time using first element as a pivot on a sorted array: 86061

cpu time using middle element as a pivot: 1469
cpu time using middle element as a pivot on a sorted array: 653

cpu time using random element as a pivot: 1548
cpu time using random element as a pivot on a sorted array: 868


explanation:
The effectiveness of a pivot is maximized when the value in the
pivot index partitions the subarray into two halves of equal length.
As a result of the above and the nature of filling the array with
random numbers, all pivot functions are expected to be equivalent on
an unsorted array. Because any index in the subarray is equally likely
to evenly partition the subarray. However, once the array is already
sorted, the some implementations are much worse at evenly partitioning
the subarray. 

firstPivot will always create a pivot that results in 1 element being on 
one side and all the others on the other side when the array is presorted.
This creates a running time of O(n^2).

middlePivot will always evenly partition the subarray when the array is
presorted. This creates a running time of O(nlogn).

randomSort will have a random chance of partitioning the subarray when 
the array is presorted. This creates a running time of O(nlogn).
*/

#include <time.h>    // time
#include <stdlib.h>  // srand, rand
#include <iostream>
#include <ctime>

// prototypes
template <typename E>
void qsort(E[], int, int, int (*findpivot) (E[], int, int));

template <typename E>
int firstPivot (E[], int, int);

template <typename E>
int middlePivot(E[], int, int);

template <typename E>
int randomPivot(E[], int, int);

template <typename E>
int partition(E[], int, int, E&);

template <typename E>
void swap(E[], int, int);


void fillArray(int array[], int size, int min, int max) {
    for(int i = 0; i < size; i++) {
        array[i] = (rand() % max) + min;
    }
}



const int ARRAY_SIZE = 10000;
const int ARRAY_MIN = 1;
const int ARRAY_MAX = 10000;

int main() {
    srand(time(NULL));
    clock_t start;
    
    // fill array with random values and time the how long it takes to sort it
    // twice. Once when the array is not sorted and a second time when it is in
    // order.
    int array[ARRAY_SIZE];
    fillArray(array, ARRAY_SIZE, ARRAY_MIN, ARRAY_MAX);

    start = clock();
    qsort <int> (array, 0, ARRAY_SIZE - 1, firstPivot);
    std::cout << "cpu time using first element as a pivot: "
              << clock() - start
              << std::endl;
    
    start = clock();
    qsort <int> (array, 0, ARRAY_SIZE - 1, firstPivot);
    std::cout << "cpu time using first element as a pivot on a sorted array: "
              << clock() - start
              << std::endl << std::endl;
    
    
    // same expiriment but use the middle element for the pivot
    fillArray(array, ARRAY_SIZE, ARRAY_MIN, ARRAY_MAX);

    start = clock();
    qsort <int> (array, 0, ARRAY_SIZE - 1, middlePivot);
    std::cout << "cpu time using middle element as a pivot: "
              << clock() - start
              << std::endl;

    start = clock();
    qsort <int> (array, 0, ARRAY_SIZE - 1, middlePivot);
    std::cout << "cpu time using middle element as a pivot on a sorted array: "
              << clock() - start
              << std::endl << std::endl;

    
    
    // same expiriment but use a random element for the pivot
    fillArray(array, ARRAY_SIZE, ARRAY_MIN, ARRAY_MAX);

    start = clock();
    qsort <int> (array, 0, ARRAY_SIZE - 1, randomPivot);
    std::cout << "cpu time using random element as a pivot: "
              << clock() - start
              << std::endl;

    start = clock();
    qsort <int> (array, 0, ARRAY_SIZE - 1, randomPivot);
    std::cout << "cpu time using random element as a pivot on a sorted array: "
              << clock() - start
              << std::endl << std::endl;
}






template <typename E>
int partition(E A[], int l, int r, E& pivot) {
    do {
        while (A[++l] < pivot);
        while ((l < r) && (pivot < A[--r]));
        swap(A, l, r);
    } while (l < r);
    return l;
}







template <typename E>
void qsort(E A[], int i, int j, int (*findpivot) (E[], int, int)) {
    if (j <= i) return;
    int pivotindex = findpivot(A, i, j);
    swap(A, pivotindex, j);
    int k = partition<E>(A, i - 1, j, A[j]);
    swap(A, k, j);
    qsort<E>(A, i, k - 1, findpivot);
    qsort<E>(A, k + 1, j, findpivot);
}






template <typename E>
int firstPivot(E A[], int i, int j) {
    return i;
}






template <typename E>
int middlePivot(E A[], int i, int j) {
    return i + ((j - i) / 2);
}






template <typename E>
int randomPivot(E A[], int i, int j) {
    return i + (rand() % (j - i));
}






template <typename E>
void swap(E A[], int i, int j) {
    E temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}