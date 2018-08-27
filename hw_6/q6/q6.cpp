/*
Will Hayward
CS110C HW6 Q6

1) Heap sort is an efficient algorithm for finding the
k elements out of a finite pre specified collection of
n elements.

2) The time complexity to build a heap is O(n) in the worst
case and the time complexity to remove the top element of
the heap (ie the greatest element) is log(n). Therefore,
to get the k largest elements, the time complexity is:
O(n + klog(n)). If n >>> k, then this is much better than
the O(nlogn) complexity required to sort an entire collection.

3) See below
*/
#include <iostream>
#include <stdlib.h> // rand  
#include <time.h>   // time
#include <assert.h>

/*
MaxHeap prototype
*/
template <typename E, typename Comp>
class MaxHeap {
    private:
        E* heap;        // Pointer to the heap array
        int maxsize;    // Maximum number of elments in the heap
        int n;          // Number of elements in the heap
        void siftDown(int pos);
        static void swap(E* array, int idx, int idy) {
            E temp = array[idx];
            array[idx] = array[idy];
            array[idy] = temp;
        }
    public:
        MaxHeap(E* h, int num, int max);
        int size() const { return n; }
        bool isLeaf(int pos) const { 
            return (pos >= n/2) && (pos < n); }
        int leftChild(int pos) const {
            return 2 * pos + 1; }
        int rightChild(int pos) const {
            return 2 * pos + 2; }
        int parent(int pos) const {
            return (pos - 1) / 2; }
        void buildHeap();
        void insert(const E& it);
        E removeFirst();
        E remove(int pos);
};






/*
Comp prototype
Works for integers and floats
*/
template <typename E>
class NumericComp {
    public:
        static bool comp(const E& first, const E& second) {
            return first > second;
        }
};






/*
heapsort prototype
k is the number of elements that you care about and n is the
size of array A;
*/
template <typename E, typename Comp>
void heapsort(E A[], int k, int n);





const int ARRAY_SIZE = 10000000;
const int TOP_RECORDS = 10;

int main() {
    srand(time(NULL));
    int* a = new int[ARRAY_SIZE];
    
    for(int i = 0; i < ARRAY_SIZE; i++) {
        a[i] = rand() % ARRAY_SIZE;
    }

    heapsort<int, NumericComp<int> >(a, TOP_RECORDS, ARRAY_SIZE);

    std::cout << "The top " << TOP_RECORDS << " are: ";
    for(int i = 0; i < TOP_RECORDS; i++) {
        std::cout << a[ARRAY_SIZE - 1 - i] << " ";
    }
    std::cout << std::endl;
    delete[] a;
}






/*
heapsort implementation
Take the top records and put them at the end of the array.
After the process, the last n records will be the n largest
records in the array in ascending order.
*/
template <typename E, typename Comp>
void heapsort(E A[], int k, int n) {
    MaxHeap<E, Comp> H(A, n, n);
    for (int i = 0; i < k; i++) {
        A[n - 1 - i] = H.removeFirst();
    }
}







/*
Implementation of the MaxHeap class
*/

/*
Given an element put it in its correct position. To do
this check that the element in the given position is
greater than its children. If it is not greater than its
children, then swap it and its larger child. Continue
doing this until the original element is in the correct
position. The assumption is that all subtrees are heaps.
*/
template <typename E, typename Comp>
void MaxHeap<E, Comp>::siftDown(int pos) {
    while (!isLeaf(pos)) {
        int j = leftChild(pos);
        int rc = rightChild(pos);
        if ((rc < n) && Comp::comp(heap[rc], heap[j])) {
            j = rc; // set j to the greater child's value
        }
        if (Comp::comp(heap[pos], heap[j])) return;
        swap(heap, pos, j);
        pos = j;  // move down
    }
}





/*
Constructor
Set the heap array, the current size and the max size
*/
template <typename E, typename Comp>
MaxHeap<E, Comp>::MaxHeap(E* h, int num, int max) {
    heap = h; n = num; maxsize = max;
    buildHeap();
}






/*
buildHeap
starting at first interior row, sift down contents
*/
template <typename E, typename Comp>
void MaxHeap<E, Comp>::buildHeap() {
    for (int i=n/2-1; i>=0; i--) {
        siftDown(i);
    }
}






/*
insert
given a new element, put it in the last slot and sift up
*/
template <typename E, typename Comp>
void MaxHeap<E, Comp>::insert(const E& it) {
    assert(n < maxsize);
    int curr = n++;
    heap[curr] = it;
    while ((curr != 0) &&
           Comp::comp(heap[curr], heap[parent(curr)])) {
        swap(heap, curr, parent(curr));
        curr = parent(curr);
    }
}






/*
removeFirst
remove the first element in the heap ie the greatest 
element
*/
template <typename E, typename Comp>
E MaxHeap<E, Comp>::removeFirst() {
    assert (n > 0);
    swap(heap, 0, --n);
    if (n != 0) siftDown(0);
    return heap[n];
}






/*
remove
remove element at position pos
*/
template <typename E, typename Comp>
E MaxHeap<E, Comp>::remove(int pos) {
    assert(pos >= 0 && pos < n);
    if (pos == (n-1)) n--; // no work to do at the last elem
    else {
        swap(heap, pos, --n);
        while ((pos != 0) &&
               Comp::comp(heap[pos], heap[parent(pos)])) {
            swap(heap, pos, parent(pos));
            pos = parent(pos);
        }
        if (n != 0) siftDown(pos);
    }
    return heap[n];
}