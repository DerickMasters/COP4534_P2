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
event::event(bool arrival, customer* customer)
{
	this->arrival = arrival;
	this->customer = customer;	
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
		return this->customer->GetArrival();
	}
	else
	{
		return this->customer->GetDeparture();
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
	return this->customer;
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
