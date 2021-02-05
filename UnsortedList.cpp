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


// Function: Adds newItem to the end of the list.
template <class ItemType>
void putItem(ItemType newItem){
  if(length + 1 < Max_Items;){
    info[length] = newItem;
    length++;
  }
} // UnsortedList<ItemType>::putItem(ItemType newItem)


// Function: deletes Item from the list.
template <class ItemType>
void deleteItem(ItemType Item){

  //going backward to find the last item/possible duplicate
  //and shifting info by 1 
  for(int i = length; i > 0; i--){
    if(info[i].equals(Item)){
      for(int ii = itemNumber; ii < length-1; ii++){
	info[ii]=info[ii+1];
      }
      break;
    }
  }
  //length decrement
  length--;
  
 
} // UnsortedList<ItemType>::deleteItem()


// Returns the number of elements in the list.
template <class ItemType>
int UnsortedList<ItemType>::getLength() const {
    return length;
} // UnsortedList<ItemType>::getLength()


// Function: returns the item stored at index in the list
ItemType getAt(int index) const{
  return info[index];
} // UnsortedList<ItemType>::getAt()

