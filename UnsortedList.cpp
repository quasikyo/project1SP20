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
UnsortedList<ItemType>::UnsortedList(int max) : Max_Items{max}, length{0} {
    info = new ItemType[Max_Items];
} // UnsortedList<ItemType>::UnsortedList(int)


// Class destructor
template <class ItemType>
UnsortedList<ItemType>::~UnsortedList() {
    delete[] info;
} // UnsortedLIst<ItemType>::~UnsortedList()


// Post: Length has been reset to the empty state.
template <class ItemType>
void UnsortedList<ItemType>::makeEmpty() {
    // Deallocate memory
    this->~UnsortedList();
    // Reset info and length (NOT Max_Items)
    info = new ItemType[Max_Items];
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


// Function: Adds newItem to the end of the list.
template <class ItemType>
void UnsortedList<ItemType>::putItem(ItemType newItem) {
    // Check if there is still space
    if (this->isFull()) {
        throw FullList();
    } // if

    // Check for a duplicate
    int duplicateItemIndex = findIndex(newItem);
    if (duplicateItemIndex != -1) {
        throw DuplicateItem();
    } // if

    // Add newItem to list
    info[length] = newItem;
    ++length;
} // UnsortedList<ItemType>::putItem(ItemType)


// Function: deletes Item from the list.
template <class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType Item) {
    // No items do delete
    if (this->isEmpty()) {
        throw EmptyList();
    } // if

    // Search for Item; delete and shift if found, exception otherwise
    int itemIndex = findIndex(Item);
    if (itemIndex != -1) {
        for (int i = itemIndex; i < length - 1; ++i) {
            info[i] = info[i + 1];
        } // for
        --length; // also takes care of edge case itemIndex = length - 1
    } else {
        throw ItemNotFound();
    } // if
} // UnsortedList<ItemType>::deleteItem(ItemType)


// Returns the number of elements in the list.
template <class ItemType>
int UnsortedList<ItemType>::getLength() const {
    return length;
} // UnsortedList<ItemType>::getLength()


// Function: returns the item stored at index in the list
template <class ItemType>
ItemType UnsortedList<ItemType>::getAt(int index) const {
    if (index >= length || index < 0) {
        throw OutofBound();
    } // if
    return info[index];
} // UnsortedList<ItemType>::getAt()


template <class ItemType>
int UnsortedList<ItemType>::findIndex(ItemType item) const {
    for (int i = 0; i < length; ++i) {
        if (info[i] == item) {
            return i;
        } // if
    } // for
    return -1;
} // UnsortedList<ItemType>::findIndex(ItemType)

