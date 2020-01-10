/*******************************************************************************
* BigInt Class
* Author: Ryan Gillett
*******************************************************************************/
#include <stack>
#include "Node.h"

//#define DEBUG //uncomment to enable debugging code

#ifdef DEBUG
#include <cassert>
#endif

/******************************************************************************
* Class: BigInt
*	Represents an arbitrarily large integer using int nodes.
******************************************************************************/
class BigInt
{
private:
	//The first node in	the chain is the smallest place, followed by the next highest place, etc.
	Node* firstNode;
	
	//The number of digits each node represents.
	const static int DIGITS = 1000000000;    //MUST BE A POWER OF 10 OR YOU'LL BREAK EVERYTHING!
	
	int getDigitsSize() const;

public:
	BigInt();
	BigInt(int value);
	~BigInt();
	BigInt(const BigInt &intToCopy);
	BigInt& operator = (const BigInt &rightSide);
	BigInt operator +(const BigInt &rightSide);
	BigInt& operator = (int rightSide);
	friend std::ostream& operator << (std::ostream& out, const BigInt& displayInt);
	friend bool operator < (const BigInt& leftSide, const BigInt& rightSide);
	int digit(int i) const;
	int size() const;
};
 
/******************************************************************************
* BigInt: Default Constructor
*	Initializes integer to 0
******************************************************************************/
BigInt::BigInt()
{
   firstNode = new Node(0);
}

/******************************************************************************
* BigInt: int Constructor
*	Initializes integer to an int value
******************************************************************************/
BigInt::BigInt(int value)
{
	firstNode = new Node(value % DIGITS);
	while (value >= DIGITS)
	{
		value /= DIGITS;
#ifdef DEBUG
		assert (value != 0);
#endif
		firstNode->insert(value % DIGITS);
	}
}
 
/******************************************************************************
* BigInt: Destructor
******************************************************************************/
BigInt::~BigInt()
{
   delete firstNode;
   firstNode = NULL;
}
 
/******************************************************************************
* BigInt: Copy Constructor
******************************************************************************/
BigInt::BigInt(const BigInt &intToCopy)
{
#ifdef DEBUG
	assert(intToCopy.firstNode != NULL);
#endif
	
	firstNode = new Node(intToCopy.firstNode->getData());
	
	for (Node* it = intToCopy.firstNode->getNext(); it != NULL; it = it->getNext())
	{
		firstNode->insert(it->getData());
	}
}
 
/******************************************************************************
* BigInt: = (BigInts)
*	Overloaded = operator to set *this equal to another BigInt
******************************************************************************/
BigInt& BigInt::operator =(const BigInt &rightSide)
{
	delete firstNode;

#ifdef DEBUG
	assert(rightSide.firstNode != NULL);
#endif
	
	firstNode = new Node(rightSide.firstNode->getData());
	
	for (Node* it = rightSide.firstNode->getNext(); it != NULL; it = it->getNext())
	{
		firstNode->insert(it->getData());
	}
	
	return *this;
}

/******************************************************************************
* BigInt: = (ints)
*	Overloaded = operator to set *this equal to an int
******************************************************************************/
BigInt& BigInt::operator = (int rightSide)
{
	if (firstNode != NULL)
	{
		delete firstNode;
	}

	firstNode = new Node(rightSide % DIGITS);
	while (rightSide >= DIGITS)
	{
		firstNode->insert((rightSide /= DIGITS) % DIGITS);
	}

	return *this;
}

/******************************************************************************
* BigInt: getDigitsSize
*	Private member function - returns the number of digits in DIGITS variable
******************************************************************************/
int BigInt::getDigitsSize() const
{
	int size = 0;
	for (int digits = DIGITS; digits > 1; digits /= 10)
	{
		size++;
	}
	
	return size;
}

/******************************************************************************
* BigInt: size
*	Returns the number of digits in the integer
******************************************************************************/
int BigInt::size() const
{
	int size = 1; //1 because every number has at least 1 digit
	int digits = getDigitsSize();
	Node* it = firstNode;

	//count digits by number of nodes x node size
	while(it->getNext() != NULL)
	{
#ifdef DEBUG
		assert(it->getNext() != NULL);
#endif
		size += digits;
		it = it->getNext();
	}

#ifdef DEBUG
	assert(it != NULL);
#endif
	
	//count each digit in the last node
	for (int value = it->getData(); value >= 10; value /= 10)
	{
		size++;
	}
	
	return size;
}

/******************************************************************************
* BigInt: digit
*	Returns the digit at 10^(i+1) place. Basically, returns the i-th digit
*	counting from the rightmost digit. If i is out of range, -1 is returned as
*	an error flag.
******************************************************************************/
int BigInt::digit(int i) const
{
	if (i > size() || i < 1)
	{
		return -1;
	}
	
	Node* it = firstNode;
	
	while (i > getDigitsSize())
	{
		i -= getDigitsSize();
		it = it->getNext();
#ifdef DEBUG
		assert (it != NULL);
#endif
	}
	
	int returnInt = it->getData();
	
	for (i; i > 1; i--)
	{
		returnInt /= 10;
	}
	
	return returnInt % 10;
}
 
/******************************************************************************
* BigInt: +
*	Overloaded + operator for adding two BigInts
******************************************************************************/
BigInt BigInt::operator +(const BigInt &rightSide)
{
	//sum: variable for storing the sum of each step of the operation
	int sum = firstNode->getData() + rightSide.firstNode->getData();
	//carry: variable for storing the overflow of each operation
	int carry = sum / DIGITS;
	
	//returnInt: the int containing the total sum to be returned
	BigInt returnInt = sum % DIGITS;
	
	//n1: points to the node of each part of the first operand
	Node* n1 = this->firstNode->getNext();
	//n2: points to the node of each part of the second operand
	Node* n2 = rightSide.firstNode->getNext();
	
	//returnIT: points to the node of each part of the returnInt
	Node* returnIT = returnInt.firstNode;
	
	//loop until n1 and n2 are both null
	while (n1 != NULL || n2 != NULL)
	{
		//reset sum to the overflow from the previous operation
		sum = carry;
		
		//create a new node for returnInt
		if (returnIT->getNext() == NULL)
		{
			returnIT->setNext(new Node(0));
		}
		
		//point to the next returnInt node
		returnIT = returnIT->getNext();
		
		//Add n1's value to sum and point to the next node unless it's null
		if (n1 != NULL)
		{
			sum += n1->getData();
			n1 = n1->getNext();
		}
		
		//Add n2's value to sum and point to the next node unless it's null
		if (n2 != NULL)
		{
			sum += n2->getData();
			n2 = n2->getNext();
		}
		
		//remove the overflow from sum and save it in carry
		carry = sum / DIGITS;
		sum %= DIGITS;
		
		//store the value in returnInt
		returnIT->setData(sum);
	}

#ifdef DEBUG
	assert(carry <= 10);
	assert(n1 == NULL);
	assert(n2 == NULL);
#endif
	
	//save the remaining overflow into another returnInt node
	if (carry > 0)
	{
		returnIT->insert(carry);
	}

	return returnInt;
}

/******************************************************************************
* BigInt: <<
*	Overloaded << operator to display the integer as a whole
******************************************************************************/
std::ostream& operator << (std::ostream& out, const BigInt& displayInt)
{
	//Store the ints from each node in a stack (nodes will be in FILO order)
	std::stack<int> number;

#ifdef DEBUG
	assert(displayInt.firstNode != NULL);
#endif
	
	//Push the ints from each node onto the stack
	for (Node* it = displayInt.firstNode; it != NULL; it = it->getNext())
	{
#ifdef DEBUG
		assert(it != NULL);
#endif
		number.push(it->getData());
	}

	//Output each int without spaces to appear as a complete integer
	while (!number.empty())
	{
		out << number.top();
		number.pop();
		//compensate for 0s
		for (int i = displayInt.DIGITS / 10; i > 1 && !number.empty(); i /= 10)
		{
			if (number.top() / i == 0)
			out << 0;
		}
	}

   return out;
}