//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// customer.cpp
//
// This file will define the class in node.hpp
//
// ----------------------------------------------

#include"customer.hpp"

/*****************************************************
 * Customer Constructor
*****************************************************/
customer::customer(float arrivaltime)
{	
	this->arrivaltime = arrivaltime;
	this->servicetime = 0.0;
	this->completiontime = 0.0;
	this->next = nullptr
}

/*****************************************************
 * SetArrive
 *
 * method to set arrival time
 *
 * Params : float arrivaltime
 * Returns : void
*****************************************************/
void customer::SetArrive(float arrivaltime)
{
	this->arrivaltime = arrivaltime;
}

/*****************************************************
 * SetService
 *
 * method to set service times
 *
 * Params : float servicetime
 * Returns : void
*****************************************************/
void customer::SetService(float servicetime)
{
	this->servicetime = servicetime;
}

/*****************************************************
 * SetDeparture
 *
 * method to set departure time
 *
 * Params : float departuretime 
 * Returns : void
*****************************************************/
void customer::SetDeparture(float departuretime)
{
	this->departuretime = departuretime;
}

/*****************************************************
 * GetArrive
 *
 * method to get arrival time
 *
 * Params : N/A
 * Returns : float
*****************************************************/
float customer::GetArrive()
{
	return this->arrivaltime;
}

/*****************************************************
 * GetService
 *
 * method to get service time
 *
 * params : N/A
 * returns : float
*****************************************************/
float customer::GetService()
{
	return this->servicetime;
}

/*****************************************************
 * GetDeparture
 *
 * method to get departure time
 *
 * params : N/A
 * returns : float
*****************************************************/
float customer::GetDeparture()
{
	return this->departuretime;
}


