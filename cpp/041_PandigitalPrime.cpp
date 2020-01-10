/******************************************************************************
* Program:
*    Pandigital Prime
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>
#include <cassert>
#include <math.h>

using namespace std;

//Prototypes
bool isPandigital(unsigned int);
unsigned int* prevPrime(unsigned int&);
bool isPrime(unsigned int);
 
/******************************************************************************
* Driver
******************************************************************************/
int main()
{
	unsigned int pandigitalPrime = 987654322;
	while (!isPandigital(*(prevPrime(pandigitalPrime))))
		cout << pandigitalPrime << "\n";
		
	cout << "Answer: " << pandigitalPrime << endl;
	
	return 0;
}

bool isPandigital(unsigned int value)
{
	bool digitExists[10] = {false};
	
	int numDigits = 0;

	while (value > 0)
	{
		digitExists[value % 10] = true;
		value /= 10;
		numDigits++;
	}

	for (int i = 1; i <= numDigits; i++)
	{
		if (!digitExists[i])
		{
			return false;
		}
	}
	
	return true;
}

unsigned int* prevPrime(unsigned int &value)
{
	while (!isPrime(--value))
			;
			
	return &value;
}

bool isPrime(unsigned int checkValue)
{
	if (checkValue < 2)
		return false;

	if (checkValue % 2 == 0)
	{
		if (checkValue == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
		
	long long int maxValue = sqrt(checkValue);
		
	for (long long int i = 3; i <= maxValue; i += 2)
	{
		if (checkValue % i == 0)
			return false;
	}
	
	return true;
}