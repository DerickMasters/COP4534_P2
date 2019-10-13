//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// pqueue.cpp
//
// This file will define the class in pqueue.hpp
//
// ----------------------------------------------

#include"pqueue.hpp"

/*****************************************************
 * pqueue Default Constructor
*****************************************************/
pqueue::pqueue()
{

}

/*****************************************************
 * pqueue Destructor
*****************************************************/
pqueue::~pqueue()
{
	for(int i = 0; i < this->heap.size(); i++)
	{
		event* temp = heap.at(i);
		delete temp;
	}
}

/*****************************************************
 * Add
 *
 * method to add a node to priority queue
 *
 * Params : node* node
 * Returns : void
*****************************************************/
void pqueue::Add(event* event)
{
	this->heap.push_back(event);

	PercolateUp(heap.size());	
}

/*****************************************************
 * Pull
 *
 * method to remove top node from heap and reorder
 * the heap
 *
 * Params : N/A
 * Returns : event*
*****************************************************/
event* pqueue::Pull()
{
	event* temp = this->heap.at(0);
	this->heap.at(0) = this->heap.back();
	this->heap.pop_back();
	Heapify(0);

	return temp;	
}

/*****************************************************
 * PercolateUp
 *
 * recursive helper method to maintain the structure of the heap
 *
 * Params : int index
 * Returns : void
*****************************************************/
void pqueue::PercolateUp(int index)
{
	if(index && (this->heap.at(GetParent(index))->GetPriority() < this->heap.at(index)->GetPriority()))
	{
		Swap(this->heap.at(index),this->heap.at(GetParent(index)));

		PercolateUp(GetParent(index));	
	}	
}

/*****************************************************
 * Heapify
 *
 * recursive helper method to maintain the structure of the heap
 *
 * Params : int index
 * Returns : void
*****************************************************/
void pqueue::Heapify(int index)
{
	int left = GetLeft(index);
	int right = GetRight(index);

	int larger = i;

	int size = this->heap.size();

	if(left < size && this->heap.at(left)->GetArrival() > this->heap.at(index)->GetArrival())
	{
		larger = left;
	}

	if(right < size && this->heap.at(right)->GetArrival() > this->heap.at(index)->GetArrival())
	{
		larger = right;
	}

	if(larger != index)
	{
		Swap(index, larger);
		Heapify(larger);
	}
}


/*****************************************************
 * GetParent
 *
 * helper method to return parent index of entry at 
 * passed index
 *
 * Params : int index
 * Returns : node*
*****************************************************/
int pqueue::GetParent(int index)
{
	return (index-1)/2;
}

/*****************************************************
 * GetLeft
 *
 * helper method to return left index of entry at 
 * passed index
 *
 * Params : int index
 * Returns : node*
*****************************************************/
int pqueue::GetLeft(int index)
{
	return (2 * index) + 1;
}

/*****************************************************
 * GetRight
 *
 * helper method to return parent index of entry at 
 * passed index
 *
 * Params : int index
 * Returns : node*
*****************************************************/
int pqueue::GetRight(int index)
{
	return (2 * index) + 2;
}

/*****************************************************
 * Swap
 *
 * helper method to swap content of vector at the 
 * passed indices.
 *
 * Params : int index, int parent
 * Returns : void
*****************************************************/
void pqueue::Swap(int index, int target)
{
	event* tempptr = this->heap.at(target);
	this->heap.at(target) = this->heap.at(index);
	this->heap.at(index) = tempptr;
}

/*****************************************************
 * IsEmpty
 *
 * method to determine if pqueue is empty
 *
 * Params : N/A
 * Returns : bool
*****************************************************/
bool pqueue::IsEmpty()
{
	if(this->heap.empty())
		return true;
	else
		return false;
}

/*****************************************************
 * size
 *
 * method to determine how many elements in pqueue
 *
 * Params : N/A
 * Returns : int
*****************************************************/
int pqueue::size()
{
	return this->heap.size();
}

//TEST//--------------------------------------------------------------------------------------
void pqueue::PrintQueue()
{
	for(int i = 0; i < this->heap.size(); i++)
	{
		std::cout << i << " " << heap.at(i)->GetPriority() << std::endl;;
	}
}

