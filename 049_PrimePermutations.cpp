/*******************************************************************************
* Prime Permutations
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <set>
#include "primes.h"

using namespace std;

bool isPermutation(long long int firstNumber, long long int secondNumber);
multiset<long long int> digitize(long long int number);
/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	for (long long int i = 1487; i < 10000; nextPrime(i))
	{
		if (isPermutation(i, i+3330) && isPermutation(i, i+6660))
		{
			if (isPrime(i+3330) && isPrime(i+6660))
			{
				cout << i << (i+3330) << (i+6660) << endl;
			}
		}
	}

	return 0;
}

bool isPermutation(long long int firstNumber, long long int secondNumber)
{
	return digitize(firstNumber) == digitize(secondNumber);
}

multiset<long long int> digitize(long long int number)
{
	multiset<long long int> digits;
	while (number > 0)
	{
		digits.insert(number % 10);
		number /= 10;
	}

	return digits;
}