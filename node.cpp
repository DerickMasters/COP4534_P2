//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// node.cpp
//
// This file will define the class in node.hpp
//
// ----------------------------------------------

#include"node.hpp"

/*****************************************************
 * Node Default Constructor
*****************************************************/
node::node()
{
	this->right = nullptr;
	this->left = nullptr;
	this->parent = nullptr;

	this->arrivaltime = 0.0;
	this->servicetime = 0.0;
	this->completiontime = 0.0;
}

/*****************************************************
 * Node Constructor
*****************************************************/
node::node(float arrivaltime, float servicetime, float completiontime)
{	
	this->arrivaltime = arrivaltime;
	this->servicetime = servicetime;
	this->completiontime = completiontime;
}

/*****************************************************
 * Node Destructor
*****************************************************/
node::~node()
{
	delete this->right;
	delete this->left;
}

/*****************************************************
 * SetRight
 *
 * method to set right pointer of node
 *
 * Params : node* right
 * Returns : void
*****************************************************/
void node::SetRight(node* right)
{
	this->right = right;
}

/*****************************************************
 * SetLeft
 *
 * method to set left pointer of node
 *
 * Params : node* left
 * Returns : void
*****************************************************/
void node::SetLeft(node* left)
{
	this->left = left;
}

/*****************************************************
 * SetParent
 *
 * method to set parent pointer of node
 *
 * Params : node* parent
 * Returns : void
*****************************************************/
void node::SetParent(node* parent)
{
	this->parent = parent;
}

/*****************************************************
 * GetRight
 *
 * method to get right pointer of node
 *
 * Params : N/A
 * Returns : node*
*****************************************************/
node* node::GetRight()
{
	return this->right;
}


/*****************************************************
 * GetLeft
 *
 * method to get left pointer of node
 *
 * Params : N/A
 * Returns : node*
*****************************************************/
node* node::GetLeft()
{
	return this->left;
}


/*****************************************************
 * GetParent
 *
 * method to get parent pointer of node
 *
 * Params : N/A
 * Returns : node*
*****************************************************/
node* node::GetParent()
{
	return this->parent;
}

/*****************************************************
 * SetArrive
 *
 * method to set arrival time
 *
 * Params : float arrivaltime
 * Returns : void
*****************************************************/
void node::SetArrive(float arrivaltime)
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
void node::SetService(float servicetime)
{
	this->servicetime = servicetime;
}

/*****************************************************
 * SetComplete
 *
 * method to set completion time
 *
 * Params : float completiontime 
 * Returns : void
*****************************************************/
void node::SetComplete(float completiontime)
{
	this->completiontime = completiontime;
}

/*****************************************************
 * GetArrive
 *
 * method to get arrival time
 *
 * Params : N/A
 * Returns : float
*****************************************************/
float node::GetArrive()
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
float node::GetService()
{
	return this->servicetime;
}

/*****************************************************
 * GetComplete
 *
 * method to get completion time
 *
 * params : N/A
 * returns : float
*****************************************************/
float node::GetComplete()
{
	return this->completiontime;
}


