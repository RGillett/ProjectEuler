/*******************************************************************************
* Node Class
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>

/******************************************************************************
* Class: Node
*	 A node is a class which stores an unsigned int and a pointer to another
*	 node in order to form a list of unsigned ints.
******************************************************************************/
class Node
{
private:
	unsigned int data;                                // Data in each node
	Node* next;                                       // Pointer to next node

public:
	Node();                                           // Creates empty node
	Node(const unsigned int& item);                   // Creates a node with initial data
	Node(const unsigned int& item, Node* const node); // Creates a node with initial data and next
	Node(const Node& nodeToCopy);                     // Copy constructor
	~Node();                                          // Deletes all linked nodes
	Node* getNext() const;                            // Returns next pointer of a node
	int getData() const;                              // Returns data of a node
	void setData(const unsigned int& item);           // Stores item in data member of current node
	void setNext(Node* const node);                   // Sets next to point to node
	void insert(const unsigned int& item);            // Creates a new node and points to it
};

/******************************************************************************
* Node: Default Constructor
*	 Data is uninitialized. Next is null.
******************************************************************************/
Node::Node()
{
   next = NULL;
}

/******************************************************************************
* Node: int Constructor
*	 Takes an int and stores it as the data. Next is null.
******************************************************************************/
Node::Node(const unsigned int& item)
{
   next = NULL;
   data = item;
}

/******************************************************************************
* Node: int, Node* Constructor
*	 Takes an int and stores it as the data. Takes a node pointer and stores
*	 it as next.
******************************************************************************/
Node::Node(const unsigned int& item, Node* const node)
{
   next = node;
   data = item;
}

/******************************************************************************
* Node: Copy Constructor
*	 Behaves as the default copy constructor.
******************************************************************************/
Node::Node(const Node& nodeToCopy)
{
	next = nodeToCopy.next;
	data = nodeToCopy.data;
}

/******************************************************************************
* Node: Destructor
* 	 Deletes the entire chain of Nodes. If you want to save the rest of the
*    data you'll need to unchain it first.
******************************************************************************/
Node::~Node()
{
   delete next;
   next = NULL;
}
 
/******************************************************************************
* Node: getNext
*    Returns a pointer to the next node in the list
******************************************************************************/
Node* Node::getNext() const
{
   return next;
}
 
/******************************************************************************
* Node: getData
*    Returns the data stored in the node
******************************************************************************/
int Node::getData() const
{
   return data;
}
 
/******************************************************************************
* Node: setData
*    Takes an unsigned int and stores it as the node data
******************************************************************************/
void Node::setData(const unsigned int& item)
{
   data = item;
}
 
/******************************************************************************
* Node: setNext
*    Takes a pointer to a Node and assigns it to next
******************************************************************************/
void Node::setNext(Node* const node)
{
   next = node;
}

/******************************************************************************
* Node: insert
*    Takes an unsigned int and creates a new node at the end of the chain
******************************************************************************/
void Node::insert(const unsigned int& item)
{
	//If this is the last node in the list (next is null) add here, else go to the next one.
	if (next == NULL)
	{
		next = new Node(item);
	}
	else
	{
		next->insert(item);
	}
}