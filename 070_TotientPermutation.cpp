/******************************************************************************
* Program:
*    Totient Permutation
* Author:
*    Ryan Gillett
* Insights:
*    1) The totient of n must be as large as possible to result in a minimum
*       for n/totient(n)
*    2) The totient formula results in a smaller possible value for each
*       additional distinct prime factor of n
*    3) totient(n) == n-1, for all prime n, therefore totient(n) is never a
*       permutation of n when n is prime
*    4) Because of 2) and 3), we will search only composite numbers having
*       exactly 2 prime factors in order to minimize n/totient(n)
*    5) totient(pq) == (p-1)(q-1). Because the smaller the difference p-q, the
*       larger the product (p-1)(q-1) will be, we will search numbers close to the
*       square root of n. We will do this using the heuristic p <= q <= 2p
******************************************************************************/
#include <iostream>
#include <iomanip>
#include "primes.h"
#include "combinatorics.h"

using namespace std;

// prototypes
long long int totientPQ(long long int p, long long int q);
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int minN = 0;
	long double minVal = 10.0;

	for (long long int p = 3163; p > 2; previousPrime(p))
	{
		for (long long int q = p; q < p * 2 && p * q < 10000000; nextPrime(q))
		{
			long long int n = p * q;
			int totientN = totientPQ(p,q);
			long double value = (long double)n / (long double)totientN;
			if (value < minVal)
			{
				if (isPermutation(n, totientN))
				{
					cout << n << "-" << totientN << ": " << value << endl;
					minN = n;
					minVal = value;
				}
			}
		}
	}

	cout << minN << endl;
	return 0;
}

long long int totientPQ(long long int p, long long int q)
{
    return (p-1)*(q-1);
}