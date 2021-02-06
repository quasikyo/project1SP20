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
void UnsortedList<ItemType>::putItem(ItemType newItem){
    for(int i = 0; i < length; i++){
      if(info[i] == newItem){
	throw DuplicateItem(); //duplicate exception
      }
    }
    
  if(length + 1 < Max_Items){
    info[length] = newItem;
    length++;
    
  } else {
    throw FullList(); //Full list exception

  }
  
} // UnsortedList<ItemType>::putItem(ItemType newItem)


// Function: deletes Item from the list.
template <class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType Item){
    bool inList = false;
    if(length == 0){
      throw EmptyList() ; //empty list exception
    }
    //going backward to find the last item/possible duplicate
    //and shifting info by 1 
    for(int i = length; i > 0; i--){
      if(info[i].equals(Item)){
	for(int ii = i; ii < length-1; ii++){
	  info[ii] = info[ii+1];
	}
	//length decrement and bool change
	length--;
	inList = true;
	break;
      }
    }

    if (!inList){
      throw ItemNotFound(); //item not in list
    }
  
} // UnsortedList<ItemType>::deleteItem()


// Returns the number of elements in the list.
template <class ItemType>
int UnsortedList<ItemType>::getLength() const {
  return length;
} // UnsortedList<ItemType>::getLength()


// Function: returns the item stored at index in the list
template <class ItemType>
ItemType UnsortedList<ItemType>::getAt(int index) const{
  if(index >= length || index < 0){
    throw OutofBound();
  } else{
    return info[index];
  }
} // UnsortedList<ItemType>::getAt()

