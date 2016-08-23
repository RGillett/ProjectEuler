/******************************************************************************
* Program: Circular Primes
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
	int count = 0;
	for (long long i = 2; i < 1000000; nextPrime(i))
	{
		vector<long long> digits;
		for (long long number = i; number > 0; number /= 10)
		{
			digits.push_back(number%10);
		}
		for (vector<long long>::iterator it = digits.begin(); it != digits.end(); it++)
		{
			it - digits.begin()
		}
	}

	return 0;
}