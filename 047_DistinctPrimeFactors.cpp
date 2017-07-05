/*******************************************************************************
* Distinct Prime Factors
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;

int countDistinctPrimeFactors(long long int number);
/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	for (long long int i = 0; true; i++)
	{
		if (countDistinctPrimeFactors(i) == 4 && countDistinctPrimeFactors(++i) == 4 && countDistinctPrimeFactors(++i) == 4 && countDistinctPrimeFactors(++i) == 4)
		{
			cout << "answer: " << i << endl;
			return 0;
		}
	}

	return 0;
}

int countDistinctPrimeFactors(long long int number)
{
	int distinctFactorCount = 0;

	for (long long int i = 2; number > 1; nextPrime(i))
	{
		if (number % i == 0)
		{
			distinctFactorCount++;
		}

		while (number % i == 0)
		{
			number /= i;
		}
	}

	return distinctFactorCount;
}