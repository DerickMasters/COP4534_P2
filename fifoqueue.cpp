//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// fifoqueue.cpp
//
// This file will define the class in pqueue.hpp
//
// ----------------------------------------------

#include"fifoqueue.hpp"

/*****************************************************
 * fifoqueue constructor
*****************************************************/
fifoqueue::fifoqueue()
{
	this->head = nullptr;	
}

/*****************************************************
 * Push
 *
 * method add an event to the queue
 *
 * Params : event* event
 * Returns : void
*****************************************************/
void fifoqueue::Push(event* event)
{
	if(!this->head)
	{
		this->head = event;
		this->tail = event;	
	}
	else
	{
		this->tail->SetNext(event);
		this->tail = event;
	}
}

/*****************************************************
 * Pop
 *
 * method remove an event from the queue
 *
 * Params : N/A
 * Returns : event*
*****************************************************/
event* fifoqueue::Pop()
{
	if(!this->head || !this->tail)
	{
		return nullptr;	
	}
	else
	{
		event* temp = this->head;
		this->head = this->head->GetNext();

		if(!this->head)
		{
			this->tail = nullptr;
		}

		temp->SetNext(nullptr);
		return temp;		
	}
}

