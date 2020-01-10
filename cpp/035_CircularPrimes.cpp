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
	int circularPrimeCount = 0;
	for (long long i = 2; i < 1000000; nextPrime(i))
	{
		vector<int> digits;
		for (long long number = i; number > 0; number /= 10)
		{
			digits.push_back(number%10);
		}
		bool isCircularPrime = true;
		for (vector<int>::iterator it = digits.begin(); it != digits.end(); it++)
		{
			int power = 1;
			int primeRotation = 0;
			vector<int>::iterator it2 = it;
			do
			{
				primeRotation += *it2 * power;
				power *= 10;
				it2 = (++it2 != digits.end() ? it2 : digits.begin());
			}
			while (it2 != it);

			if (!isPrime(primeRotation))
			{
				isCircularPrime = false;
			}
		}
		if (isCircularPrime)
		{
			circularPrimeCount++;
		}
	}

	cout << circularPrimeCount << endl;

	return 0;
}