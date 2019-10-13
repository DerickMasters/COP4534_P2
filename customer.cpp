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
customer::customer(double arrivaltime)
{	
	this->arrivaltime = arrivaltime;
	this->servicetime = 0.0;
	this->departuretime = 0.0;
}

/*****************************************************
 * SetArrive
 *
 * method to set arrival time
 *
 * Params : double arrivaltime
 * Returns : void
*****************************************************/
void customer::SetArrive(double arrivaltime)
{
	this->arrivaltime = arrivaltime;
}

/*****************************************************
 * SetService
 *
 * method to set service times
 *
 * Params : double servicetime
 * Returns : void
*****************************************************/
void customer::SetService(double servicetime)
{
	this->servicetime = servicetime;
}

/*****************************************************
 * SetDeparture
 *
 * method to set departure time
 *
 * Params : double departuretime 
 * Returns : void
*****************************************************/
void customer::SetDeparture(double departuretime)
{
	this->departuretime = departuretime;
}

/*****************************************************
 * GetArrive
 *
 * method to get arrival time
 *
 * Params : N/A
 * Returns : double
*****************************************************/
double customer::GetArrive()
{
	return this->arrivaltime;
}

/*****************************************************
 * GetService
 *
 * method to get service time
 *
 * params : N/A
 * returns : double
*****************************************************/
double customer::GetService()
{
	return this->servicetime;
}

/*****************************************************
 * GetDeparture
 *
 * method to get departure time
 *
 * params : N/A
 * returns : double
*****************************************************/
double customer::GetDeparture()
{
	return this->departuretime;
}


