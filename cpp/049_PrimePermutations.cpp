/*******************************************************************************
* Prime Permutations
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include "primes.h"
#include "combinatorics.h"

using namespace std;

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