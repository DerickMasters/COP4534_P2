//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// event.hpp
//
// This file will describe an event for use in
// the Priority Queue and FIFO Queue
// 
// ----------------------------------------------

#ifndef EVENT
#define EVENT

#include"customer.hpp"

class event
{
	public:
		event(bool arrival, customer* someone);

		bool IsArrival();
		float GetPriority();
		customer* GetCustomer();
		event* GetNext();
		void SetNext(event* event);
		void SetDeparture();

	private:
		bool arrival;
		customer* someone;
		event* next;
};

#endif

