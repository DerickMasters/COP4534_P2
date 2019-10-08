//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// fifoqueue.hpp
//
// This file will impliment a FIFO queue
//
// ----------------------------------------------

#ifndef FIFOQUEUE
#define FIFOQUEUE

#include "event.hpp"

class fifoqueue
{
	public:
		fifoqueue();

		void Push(event* event);
		event* Pop();

	private:
		event* head;
		event* tail;
};

#endif
