/*
Implementation of the MaxHeap class
*/

#include "max_heap.h"

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
        if ((rc < n) && Comp::prior(heap[rc], heap[j])) {
            j = rc; // set j to the greater child's value
        }
        if (Comp::prior(heap[pos], heap[j])) return;
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
    Assert(n < maxsize);
    int curr = n++;
    heap[curr] = it;
    while ((curr != 0) &&
           Comp::prior(heap[curr], heap[parent(curr)])) {
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
    Assert (n > 0);
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
    Assert(pos >= 0 && pos < n);
    if (pos == (n-1)) n--; // no work to do at the last elem
    else {
        swap(heap, pos, --n);
        while ((pos != 0) &&
               Comp::prior(heap[pos], heap[parent(pos)])) {
            swap(heap, pos, parent(pos));
            pos = parent(pos);
        }
        if (n != 0) siftDown(pos);
    }
    return heap[n];
}