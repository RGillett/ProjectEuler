/******************************************************************************
* Program: Truncatable Primes
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	short count = 0;
	long long sum = 0;
	for (long long number = 11; count < 11; nextPrime(number))
	{
		long long digits = 1;
		while (digits <= number)
		{
			digits *= 10;
		}

		bool isTruncatable = true;
		for (long long i = 10; i < digits; i*=10)
		{
			if (!isPrime(number%i) || !isPrime(number/i))
			{
				isTruncatable = false;
			}
		}

		if (isTruncatable)
		{
			sum += number;
			count++;
		}

	}

	cout << sum << endl;

	return 0;
}