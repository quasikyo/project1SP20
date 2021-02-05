#include "UnsortedList.h"

// No argument constructor
// Post: Max_Items initialized to 50 and Length have been initialized.
// The array to hold the list elements has been allocated.
template <class ItemType>
UnsortedList<ItemType>::UnsortedList() : UnsortedList(50) {} // UnsortedList<ItemType>::UnsortedList()

// constructor
// Post: Max_Itemms and Length have been initialized.
// The array to hold the list elements has been allocated.
template <class ItemType>
UnsortedList<ItemType>::UnsortedList(int max) : length{0} : Max_Items{max} {
    info = new ItempType[Max_Items];
} // UnsortedList<ItemType>::UnsortedList(int)

// Class destructor
template <class ItemType>
UnsortedList<ItemType>::~UnsortedList() {
    delete[] info;
} // UnsortedLIst<ItemType>::~UnsortedList()

// Post: Length has been reset to the empty state.
template <class ItemType>
void UnsortedList<ItemType>::makeEmpty() {
    length = 0;
} // UnsortedList<ItemType>::makeEmpty()

// Returns true if the List is empty; false otherwise.
template <class ItemType>
bool UnsortedList<ItemType>::isEmpty() const {
    return length == 0;
} // UnsortedList<ItemType>::isEmpty()

// Returns true if the list is full; false otherwise.
template <class ItemType>
bool UnsortedList<ItemType>::isFull() const {
    return length == Max_Items;
} // UnsortedList<ItemType>::isFull()

// Returns the number of elements in the list.
template <class ItemType>
int UnsortedList<ItemType>::getLength() const {
    return length;
} // UnsortedList<ItemType>::getLength()

