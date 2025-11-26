//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <type_traits>

//   SORTING ----------------------------------------------------
template<class ItemType>
void LinkedBag<ItemType>::sort(int method){
	if (itemCount <= 1)
		return;
	
	if (method == 0){
		// update function call if you change the prototype. 
		mergeSort();
	}else{
		// for EXTRA CREDIT, update function call if you change the prototype.
		// If you do NOT implement quickSort, NO action needed here
		quickSort(); 
	}
}

//TO DO: implement merge sort and change its prototype if you need to.
template<class ItemType>
void LinkedBag<ItemType>::mergeSort(){
	headPtr = mergeSortHelper(headPtr);
}

template<class ItemType>
void LinkedBag<ItemType>::splitList(
		Node<ItemType>* start,
		Node<ItemType>*& left,
		Node<ItemType>*& right) {
	if (start == nullptr || start->getNext() == nullptr) {
		left = start;
		right = nullptr;
		return;
	}

	Node<ItemType>* midFinder = start;
	Node<ItemType>* endFinder = start->getNext();

	// endFinder will reach the end first, then midFinder hits midpoint
	while (endFinder != nullptr) {
		endFinder = endFinder->getNext();
		if (endFinder != nullptr) {
			midFinder = midFinder->getNext();
			endFinder = endFinder->getNext();
		}
	}

	left = start;
	right = midFinder->getNext(); // effectively the start of the second half
	midFinder->setNext(nullptr);
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::mergeLists(
	Node<ItemType>* left,
	Node<ItemType>* right) {
	if (left == nullptr)
		return right;
	if (right == nullptr)
		return left;

	Node<ItemType>* result = nullptr;

	// smaller value between left and right will become the next node in sorted list
	if (left->getItem() <= right->getItem()) {
		result = left;

		result->setNext(mergeLists(left->getNext(), right)); // merges the rest of left->getNext() with all of right
	}
	else {
		result = right;

		result->setNext(mergeLists(left, right->getNext())); // merges all of left with the rest of right->getNext()
	}

	// should return smallest node with correct pointer to next value
	return result;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::mergeSortHelper(Node<ItemType>* start) {
	if (start == nullptr || start->getNext() == nullptr) { // already sorted if the list is empty or contains only one node
		return start;
	}

	Node<ItemType>* left = nullptr;
	Node<ItemType>* right = nullptr;

	splitList(start, left, right);

	left = mergeSortHelper(left);
	right = mergeSortHelper(right);

	Node<ItemType>* mergedList = mergeLists(left, right);

	return mergedList;
}

//Extra Credit -- TO DO: implement quick sort and change its prototype 
//                       if you need to.
template<class ItemType>
void LinkedBag<ItemType>::quickSort() {
	if(headPtr == nullptr || headPtr->getNext() == nullptr)
		return;

	Node<ItemType>* tail = getTail(headPtr);
	headPtr = quickSortRec(headPtr, tail);
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getTail(Node<ItemType>* head) {
	while (head != nullptr && head->getNext() != nullptr) {
		head = head->getNext();
	}
	return head;
}

// partitions the LinkedBag around the pivot node
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::partition(
	Node<ItemType>* head,
	Node<ItemType>* end,
	Node<ItemType>*& newHead, 
	Node<ItemType>*& newEnd)
{
	Node<ItemType>* pivot = end; // pivot should always be last node
	Node<ItemType>* prev = nullptr;
	Node<ItemType>* curr = head;
	Node<ItemType>* tail = pivot;

	newHead = nullptr; // becomes the head of left partition

	while (curr != pivot) {
		if (curr->getItem() < pivot->getItem()) { // current node that is (less than pivot) belongs to left partition
			// first left node becomes newHead
			if (newHead == nullptr)
				newHead = curr;

			prev = curr;
			curr = curr->getNext();
		}

		// current node belongs to the right partition (greater or equal to pivot)
		else {
			Node<ItemType>* temp = curr->getNext();

			if (prev == nullptr) {
				head = temp;
			}
			else {
				prev->setNext(temp); // skips curr on the left
			}

			// move curr to the end of right partition
			curr->setNext(nullptr);
			tail->setNext(curr);
			tail = curr;

			curr = temp;
		}
	}

	// pivt becomes the head of partition if newHead is never assigned
	if (newHead == nullptr)
		newHead = pivot;

	newEnd = tail;
	return pivot;
}
	
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::quickSortRec(
	Node<ItemType>* head,
	Node<ItemType>* end) {
	
	if (!head || head == end)
		return head;

	Node<ItemType>* newHead = nullptr;
	Node<ItemType>* newEnd = nullptr;

	Node<ItemType>* pivot = partition(head, end, newHead, newEnd); // get pivot after partitioning list

	if (newHead != pivot) {
		Node<ItemType>* temp = newHead;
		while (temp->getNext() != pivot)
			temp = temp->getNext();
		
		temp->setNext(nullptr);

		// finds node before the pivot and sorts left half
		newHead = quickSortRec(newHead, temp);

		temp = getTail(newHead);
		temp->setNext(pivot);
	}

	// pivot attached after left-side sort, then right side sort
	pivot->setNext(quickSortRec(pivot->getNext(), newEnd));

	return newHead;
}
// --------------------------------------------------------------

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0){
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag){
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
	
	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original bag is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		
		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;		// Points to last node in new chain
		origChainPtr = origChainPtr->getNext();	  // Advance original-chain pointer
		
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
				  
			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			
			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			
			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while
		
		newChainPtr->setNext(nullptr);				  // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag(){
	clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)		  
	Node<ItemType>* nextNodePtr = new Node<ItemType>();

	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr);  // New node points to chain
	headPtr = nextNodePtr;			 // New node is now first node
	itemCount++;
	
	return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const{
	std::vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while
	
	return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry){
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem){
		// Copy data from first node to located node
		entryNodePtr->setItem(headPtr->getItem());
		
		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		
		itemCount--;
	} // end if
	
	return canRemoveItem;
}  // end remove

template<class ItemType>
bool LinkedBag<ItemType>::removeAlt(const ItemType& anEntry){
	Node<ItemType>* prev = headPtr;
	Node<ItemType>* cur = headPtr;
	bool found = false;

	while((cur != nullptr) && !found){
		found = (*(cur->getItem()) == *anEntry);
		if (!found){
			prev = cur;
			cur = cur->getNext();
		}
	}

	if (found){
		prev->setNext(cur->getNext());
		// delete cur->getItem();
		delete cur;
		cur = nullptr;
		itemCount--;
	}

	return found;

}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear(){
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr){
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);

		// delete nodeToDeletePtr->getItem(); 
		delete nodeToDeletePtr;
		
		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr
	
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if
		
		counter++;
		curPtr = curPtr->getNext();
	} // end while
	
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains


// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	
	while (!found && (curPtr != nullptr))
	{
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while
	
	return curPtr;
} // end getPointerTo


