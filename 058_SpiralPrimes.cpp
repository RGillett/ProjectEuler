/******************************************************************************
* Spiral Primes
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
	int primesCount = 8;
	int totalCount = 13;
	int n = 49;

	for (int increase = 8; (float)primesCount / (float)totalCount >= .1; increase+=2)
	{
		for (int i = 0; i < 4; i++)
		{
			n += increase;
			primesCount += (isPrime(n) ? 1 : 0);
		}
		totalCount += 4;
	}

	cout << (totalCount + 1) / 2 << endl;

	return 0;
}