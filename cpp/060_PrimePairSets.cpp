/*******************************************************************************
* Prime Pair Sets
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;

long long int combine(long long int x, long long int y);
/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	for (long long int p1 = 2; p1 < 10000; nextPrime(p1))
	{
		for (long long int p2 = p1; p2 < 10000; nextPrime(p2))
		{
			if (isPrime(combine(p1,p2)) && isPrime(combine(p2,p1)))
			{
				for (long long int p3 = p2; p3 < 10000; nextPrime(p3))
				{
					if (isPrime(combine(p1,p3)) && isPrime(combine(p3,p1))
						&& isPrime(combine(p2,p3)) && isPrime(combine(p3,p2)))
					{
						for (long long int p4 = p3; p4 < 10000; nextPrime(p4))
						{
							if (isPrime(combine(p1,p4)) && isPrime(combine(p4,p1))
								&& isPrime(combine(p2,p4)) && isPrime(combine(p4,p2))
								&& isPrime(combine(p3,p4)) && isPrime(combine(p4,p3)))
							{
								for (long long int p5 = p4; p5 < 10000; nextPrime(p5))
								{
									if (isPrime(combine(p1,p5)) && isPrime(combine(p5,p1))
										&& isPrime(combine(p2,p5)) && isPrime(combine(p5,p2))
										&& isPrime(combine(p3,p5)) && isPrime(combine(p5,p3))
										&& isPrime(combine(p4,p5)) && isPrime(combine(p5,p4)))
									{
										cout << p1+p2+p3+p4+p5 << endl;
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

long long int combine(long long int x, long long int y)
{
	long long int magnitude = 10;

	while (magnitude <= y)
	{
		magnitude *= 10;
	}

	return x * magnitude + y;
}