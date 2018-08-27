#include <iostream>
#include <assert.h>

template <typename E> class List { // List ADT
	private:
	void operator =(const List&) {} // Protect assignment
	List(const List&) {} // Protect copy constructor
	public:
	List() {} // Default constructor
	virtual ~List() {} // Base destructor
	// Clear contents from the list, to make it empty.
	virtual void clear() = 0;
	// Insert an element at the current location.
	// item: The element to be inserted
	virtual void insert(const E& item) = 0;
	// Append an element at the end of the list.
	// item: The element to be appended.
	virtual void append(const E& item) = 0;
	// Remove and return the current element.
	// Return: the element that was removed.
	virtual E remove() = 0;
	// Set the current position to the start of the list
	virtual void moveToStart() = 0;
	// Set the current position to the end of the list
	virtual void moveToEnd() = 0;
	// Move the current position one step left. No change
	// if already at beginning.
	virtual void prev() = 0;
	// Move the current position one step right. No change
	// if already at end.
	virtual  void next() = 0;
	// Return: The number of elements in the list.
	virtual int length() const = 0;
	// Return: The position of the current element.
	virtual int currPos() const = 0;
	// Set current position.
	// pos: The position to make current.
	virtual void moveToPos(int pos) = 0;
	// Return: The current element.
	virtual const E& getValue() const = 0;
    // Return: the index of the item being searched for
    virtual const int ssearch(const E& item) = 0;
};


template <typename E>
class AList : public List<E> {
    private:
        int maxSize;
        int listSize;
        int curr;
        E* listArray;

    public:
        AList(int size=100) {
            maxSize = size;
            listSize = curr = 0;
            listArray = new E[maxSize];
        }

        ~AList() { delete [] listArray; }

        void clear() {
            delete [] listArray;
            listSize = curr = 0;
            listArray = new E[maxSize];
        }

        void insert(const E& it) {
            assert(listSize < maxSize);
            for(int i=listSize; i>curr; i--) {
                listArray[i] = listArray[i-1];
            }
            listArray[curr] = it;
            listSize++;
        }

        void append(const E& it) {
            assert(listSize < maxSize);
            listArray[listSize++] = it;
        }

        E remove() {
            assert((curr>=0) && (curr < listSize));
            E it = listArray[curr];
            for(int i = curr; i < listSize - 1; i++) {
                listArray[i] = listArray[i+1];
            }
            listSize--;
            return it;
        }

        void moveToStart() {curr = 0;}
        void moveToEnd() { curr=listSize; }
        void prev() { if (curr != 0) curr--; }
        void next() { if (curr < listSize) curr++; }

        int length() const {return listSize; }
        
        int currPos() const { return curr; }

        void moveToPos(int pos) {
            assert((pos >= 0) && (pos <= listSize));
            curr = pos;
        }

        const E& getValue() const {
            assert((curr>=0) && (curr<listSize));
            return listArray[curr];
        }
        
        const int ssearch(const E& item) {
            int origPos = curr, foundPos = -1;
            curr = 0;
            while(foundPos < 0 && curr < listSize) {
                if(getValue() == item) {
                    foundPos = curr;
                }
                curr++;
            }
            curr = origPos;
            return foundPos;
        }
};


int main() {
    AList<int> arrayList;
    arrayList.insert(10);
    arrayList.insert(20);
    arrayList.insert(30);
    std::cout << arrayList.ssearch(10) << std::endl;
    std::cout << arrayList.ssearch(3) << std::endl;
    std::cout << arrayList.currPos() << std::endl;
}