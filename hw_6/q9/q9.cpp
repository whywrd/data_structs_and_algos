/*
Will Hayward
CS110C HW6 Q9

Given an array of a numeric type find the two elements that have th smallest
absolute difference. For any given number in the array, the minimum difference
will occur when taking the abs difference between it and either the nearest
number greater than it or less than it. Therefore, the first step should be to
sort the arry because it will result in all elements being arranged next to the
numbers nearest to it. Following that the minimum absolute difference can be found
by diffing all neighboring numbers and finding the min.

At the space cost of storing 4 variables of the given numeric type, this calculation
can be done for the same cost as sorting. To see this consider a slightly modified 
heapsort, where after each deheap operation in the sort process, the deheaped number 
is subtracted from the number deheaped in the previous round and the resulting difference
is compared to the previous minimum difference. At the end you will have stored, 
the minimum diff, and the last number involved in creating min diff (the other number
can be recovered by adding to the diff).

Using this process, the pair can be found in O(nlogn).
*/

#include <iostream>
#include <cmath> // abs
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
mindiff
Given an array of size N and numeric type E, return a 2 element array
where the elements are the two elements in the array that are closest
together (ie have the minimum absolute difference).
*/
template <typename E, typename std::size_t N>
void mindiff(E (&A)[N], E pair[2]) {
    E minDiff, diffElement, potentialDiff;
    MaxHeap<E, NumericComp<E> > H(A, N, N);
    
    // calc first diff outside loop
    A[N - 1] = H.removeFirst();
    A[N - 2] = H.removeFirst();
    minDiff = A[N - 1] - A[N - 2];
    diffElement = A[N - 2];

    for (int i = N - 3; i >= 0; i--) {
        A[i] = H.removeFirst();
        potentialDiff = A[i+1] - A[i]; // A[i+1] > A[i] b/c ascending sort
        if(potentialDiff < minDiff) {
            minDiff = potentialDiff;
            diffElement = A[i];
        }
    }

    pair[0] = minDiff + diffElement;
    pair[1] = diffElement;
}






int main() {
    double doubleValues[] = {49.3161, 86.8905, 11.3944, 53.6294, 59.8794, 5.248, 57.382, 
                             25.2015, 86.4258, 48.5549, 94.7989, 57.5996, 85.2883, 27.2116,
                             19.64, 90.5718, 39.8861, 45.408, 98.9921, 28.1435, 84.0393, 
                             50.0511, 92.8203, 88.198, 58.0723, 31.9946, 13.0681, 51.8656, 
                             77.8169, 53.3708, 88.214, 81.7046, 41.7084, 72.053, 96.3368, 
                             26.2633, 66.1523, 33.4011, 18.533, 77.7682, 73.4415, 68.1627, 
                             5.96543, 91.8632, 67.7314, 69.389, 94.7273, 11.733, 32.503, 
                             30.6049, 63.4401, 60.9486, 87.0579, 9.86099, 13.9387, 84.1796, 
                             81.7646, 26.4441, 31.0737, 89.7086, 20.9977, 18.9619, 85.1366, 
                             98.196, 69.5721, 70.8729, 10.2308, 85.6839, 76.1808, 81.6806, 
                             46.8683, 49.4764, 55.5107, 55.575, 63.1231, 93.2853, 27.5485, 
                             48.3143, 64.736, 40.3162, 30.3321, 19.1091, 7.37671, 94.1409, 
                             60.4783, 61.3763, 38.4056, 58.1172, 75.3142, 8.45943, 43.21, 
                             1.14745, 33.0515, 99.656, 11.3098, 16.9994, 11.3334, 77.7073, 
                             86.2351, 35.1895};
    double doublePair[2];
    mindiff(doubleValues, doublePair);
    std::cout << "the double pair with the minimum absolute difference is: ("
              << doublePair[0]
              << ", "
              << doublePair[1]
              << ")"
              << std::endl << std::endl;
    
    int intValues[] = {44, 86, 11, 71, 61, 50, 46, 12, 6, 61, 72, 83, 35, 38, 33, 60, 33, 
                       25, 84, 50, 8, 84, 60, 22, 39, 31, 51, 2, 63, 51, 67, 90, 32, 54, 
                       87, 42, 7, 61, 3, 29, 19, 18, 66, 71, 35, 76, 7, 48, 41, 92, 48, 
                       38, 100, 99, 2, 31, 94, 4, 12, 41, 98, 72, 47, 39, 5, 36, 83, 63, 
                       48, 8, 50, 42, 67, 98, 12, 73, 81, 77, 49, 79, 6, 80, 45, 64, 97, 
                       66, 97, 38, 53, 16, 75, 78, 21, 19, 64, 14, 27, 76, 69, 41};
    int intPair[2];
    mindiff(intValues, intPair);
    std::cout << "the int pair with the minimum absolute difference is: ("
              << intPair[0]
              << ", "
              << intPair[1]
              << ")"
              << std::endl;
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