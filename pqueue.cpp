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
node::node()
{
	this->head = nullptr;
	this->tail = nullptr;
}

/*****************************************************
 * pqueue Destructor
*****************************************************/
pqueue::~pqueue()
{
	delete this->head;
	delete this->tail;
}

/*****************************************************
 * Push
 *
 * method to add a node to priority queue
 *
 * Params : node* node
 * Returns : void
*****************************************************/
void pqueue::Push(node* next)
{
	next->SetNext(this->head);
	this->head = next;	
}

/*****************************************************
 * Pull
 *
 * method to remove node with most priority
 *
 * Params : N/A
 * Returns : void
*****************************************************/
node* pqueue::Pull()
{
	node* tempnode = this->head;
	this->head = this->head->GetNext();
	if(!this->head->GetNext())
	{
		this->tail = this->head;
	}
	return tempnode;	
}

/*****************************************************
 * Prioritize
 *
 * recursive helper method to enforce priority
 *
 * Params : void
 * Returns : void
*****************************************************/
bool pqueue::Prioritize(node* next)
{
	if(!next)
	{
		return false
	}

	if(Prioritize(next->GetNext())
	{
		if(next->GetArrival() > this->head->GetArrival())
		{
			this->head->SetNext(next->GetNext());
			next->SetNext(this->head);
			this->head = next;
		}	
	}
	
	return true;
}


