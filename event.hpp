//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// event.hpp
//
// This file will describe an event for use in
// the Priority Queue and FIFO Queue
// 
// ----------------------------------------------

#ifndef
#define

#include"customer.hpp"

class event
{
	public:
		event(bool arrival, customer* customer);

		bool IsArrival();
		float GetPriority();
		customer* GetCustomer();
		event* GetNext();
		void SetNext(event* event);

	private:
		bool arrival;
		customer* customer;
		event* next;
};

#endif

