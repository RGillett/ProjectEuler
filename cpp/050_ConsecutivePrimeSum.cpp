/*******************************************************************************
* Consecutive Prime Sum
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;
/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	long long int primeSumOfPrimes = 2;
	int highestCount = 1;

	for (long long int prime = 2; prime < 1000000; nextPrime(prime))
	{
		long long int sum = 0;
		int count = 0;
		for (long long int prime2 = prime; sum < 1000000; nextPrime(prime2))
		{
			sum += prime2;
			count++;

			if (isPrime(sum))
			{
				if (count > highestCount)
				{
					highestCount = count;
					primeSumOfPrimes = sum;
				}
			}
		}
	}

	cout << "number: " << highestCount << endl << "prime: " << primeSumOfPrimes << endl;

	return 0;
}