/*******************************************************************************
* Driver
*******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	for (long long i = 2; i <= 100; i++)
	{
		vector<int> factors = factorize(i);
		cout << i << ": " << endl;
		for (int j = 0; j < factors.size(); j++)
		{
			cout << factors[j] << endl;
		}
		cout << endl;
	}
	long long prime = 1001;
	previousPrime(prime);
	cout << prime << endl;

	return 0;
}