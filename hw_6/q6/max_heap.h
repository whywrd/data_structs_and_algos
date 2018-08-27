/*
MaxHeap
A datastructure that stores elements in a complete binary
tree such that every parent node is greater than it's
child nodes.
*/

#ifndef _MAX_HEAP_H_
#define _MAX_HEAP_H_

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

#endif