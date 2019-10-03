//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// pqueue.hpp
//
// This file will impliment a priority queue as
// a heap
//
// ----------------------------------------------

#ifndef PQUEUE
#define PQUEUE

#include"node.hpp"

#ifndef VECTOR
#define VECTOR

#include<vector>

#endif

class pqueue
{
	public:
		pqueue();
		~pqueue();
		
		void Push(node* node);
		node* Pull();
		
	private:
		bool Prioritize(node* next);
		node* head;

};

#endif
