//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// event.cpp
//
// This will impliment things defined in
// event.hpp
// 
// ----------------------------------------------

#include"event.hpp"

/*****************************************************
 * event constructor
*****************************************************/
event::event(bool arrival, customer* someone)
{
	this->arrival = arrival;
	this->someone = someone;	
}

/*****************************************************
 * IsArrival
 *
 * method to determine if Arrival or Departure
 * event
 *
 * Params : N/A
 * Returns : bool
*****************************************************/
bool event::IsArrival()
{
	return this->arrival;
}

/*****************************************************
 * GetPriority
 *
 * method to get priority of customer depending on 
 * event type
 *
 * Params : N/A
 * Returns : float
*****************************************************/
float event::GetPriority()
{
	if(this->arrival)
	{
		return this->someone->GetArrive();
	}
	else
	{
		return this->someone->GetDeparture();
	}
}

/*****************************************************
 * GetCustomer
 *
 * method to get the pointer to a customer associated
 * with event
 *
 * Params : N/A
 * Returns : customer*
*****************************************************/
customer* event::GetCustomer()
{
	return this->someone;
}

/*****************************************************
 * GetNext
 *
 * method to get the pointer to next event for use in
 * FIFO queue
 * 
 * Params : N/A
 * Returns : event*
*****************************************************/
event* event::GetNext()
{
	return this->next;
}

/*****************************************************
 * SetNext
 *
 * method to set the pointer to next event for use in
 * FIFO queue
 * 
 * Params : event* event
 * Returns : void
*****************************************************/
void event::SetNext(event* event)
{
	this->next = event;
}

/*****************************************************
 * SetDeparture
 *
 * method to mark event as departure
 * 
 * Params : N/A
 * Returns : void
*****************************************************/
void event::SetDeparture()
{
	this->arrival = false;
}
