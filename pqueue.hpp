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

#include"event.hpp"

#ifndef VECTOR
#define VECTOR

#include<vector>

#endif

class pqueue
{
	public:
		pqueue();
		~pqueue();
		
		void Add(event* event);
		event* Pull();

		//TEST
		void PrintQueue();
		
	private:
		std::vector<event*> heap;
		int GetParent(int index);
		int GetLeft(int index);
		int GetRight(int index);
		void Swap(int index, int target);
		void PercolateUp(int index);
		void Heapify(int index);

};

#endif
