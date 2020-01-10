/******************************************************************************
* Program:
*    Resilience
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;

// prototypes
double findResilienceOf(long long int denominator);

/******************************************************************************
* Main
******************************************************************************/
int main()
{
	double threshold = 15499.0 / 94744.0;
	long long int product = 1;
	bool pass = true;
	long long int p = 1;

	while (findResilienceOf(product) >= threshold)
	{
		nextPrime(p);
		product *= p;
	}

	product /= p;

	for (int i = 2; i < p; ++i)
	{
		if (findResilienceOf(product*i) < threshold)
		{
			cout << product*i << endl;
			return 0;
		}
	}

	cout << product * p << endl;

	return 0;
}

double findResilienceOf(long long int denominator)
{
	return (double)(totient(denominator))/(double)(denominator-1);
}