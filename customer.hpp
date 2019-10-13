//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// customer.hpp
//
// This file impliments a customer object to be
// used as an element in a queue
//
// ----------------------------------------------

#ifndef CUSTOMER
#define CUSTOMER

class customer
{
	public:
		customer(double arrivaltime);

		void SetArrive(double arrivaltime);
		void SetService(double servicetime);
		void SetDeparture(double departuretime);
		double GetArrive();
		double GetService();
		double GetDeparture();
		
	private:
		double arrivaltime;
		double servicetime;
		double departuretime;	
};

#endif




