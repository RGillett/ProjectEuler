/******************************************************************************
* Program:
*    Totient Maximum
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;

// prototypes

/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int maxN = 0;
	float maxVal = 0;
    long long int p = 2;
	for (long long int n = 2; n < 1000000; nextPrime(p), n*=p)
	{
		int totientN = totient(n);
		float value = (float)n / (float)totientN;
		if (maxVal < value)
		{
			maxN = n;
			maxVal = value;
		}
	}

	cout << maxN << endl;
	return 0;
}