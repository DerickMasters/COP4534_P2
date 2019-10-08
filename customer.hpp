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
		customer(float arrivaltime);

		void SetArrive(float arrivaltime);
		void SetService(float servicetime);
		void SetDeparture(float departuretime);
		float GetArrive();
		float GetService();
		float GetDeparture();
		
	private:
		float arrivaltime;
		float servicetime;
		float departuretime;	
};

#endif




