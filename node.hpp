//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// node.hpp
//
// This file will impliment a node for use in a
// prioty queue and FIFO queue
//
// ----------------------------------------------

#ifndef NODE
#define NODE

class node
{
	public:
		node();
		node(float arrivaltime, float servicetime, float completiontime);
		~node();

		void SetRight(node* right);
		void SetLeft(node* left);
		void SetParent(node* parent);
		node* GetRight();
		node* GetLeft();
		node* GetParent();

		void SetArrive(float arrivaltime);
	       	void SetService(float servicetime);
		void SetComplete(float completiontime);	
		float GetArrive();
		float GetService();
		float GetComplete();


	private:
		node* right;
		node* left;
		node* parent;
		float arrivaltime;
		float servicetime;
		float completiontime;
};

#endif
