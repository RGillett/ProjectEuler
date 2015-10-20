/*******************************************************************************
* Prime Generator
* Author: Ryan Gillett
*
* This function will efficiently generate a prime number.
*******************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

//Prototypes
bool isPrime(long long int);
void nextPrime(int& number);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	for (int prime = 1; prime < 1000000; nextPrime(prime))
	{
		cout << prime << "\n";
	}
	
	cout << endl;
	
	return 0;
}

void nextPrime(int& number)
{
	while (!isPrime(++number))
		;
		
	return;
}

/*******************************************************************************
* isPrime()
* Determines whether a number is prime
*******************************************************************************/
bool isPrime(long long int checkValue)
{
	if (checkValue <= 3)
	{
		switch (checkvalue)
		{
			case 2:
				return true;
				break;
			case 3:
				return true;
				break;
			default:
				return false;
				break;
		}
	}
	
	if (checkValue % 6 == 1 || checkValue % 6 == 5)
	{
		long long int maxValue = sqrt(checkValue);
		
		for (long long int i = 3; i <= maxValue; i += 2)
		{
			if (checkValue % i == 0)
				return false;
		}
		
		return true;
	}
	
	return false;
}