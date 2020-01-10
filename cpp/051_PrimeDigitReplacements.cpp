/*******************************************************************************
* Prime Digit Replacements
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include "primes.h"

using namespace std;

/******************************************************************************
* Main
******************************************************************************/
int main()
{
	// This is an O(n^9) algorithm, but it's still fast because n will never be larger than 11 to solve this problem ;)
	for (int a = -1; a < 10; ++a)
	{
		for (int b = -1; b < 10; ++b)
		{
			for (int c = -1; c < 10; ++c)
			{
				for (int d = -1; d < 10; ++d)
				{
					for (int e = -1; e < 10; ++e)
					{
						for (int f = -1; f < 10; f+=2)
						{
							// Pointers to our digits for DRYer code
							int* digits[6] = {&a,&b,&c,&d,&e,&f};

							// Using -1 as a flag for a wildcard, count how big our wildcard array needs to be
							int wildcardCount = 0;
							for (int n = 0; n < 6; ++n)
							{
								if (*digits[n] == -1)
								{
									wildcardCount++;
								}
							}

							if (wildcardCount > 0)
							{
								// Create an array of pointers to our wildcard digits for mindless replacement of digits
								int* wildcards[wildcardCount];
								for (int i = 0; i < wildcardCount; ++i)
								{
									wildcards[i] = NULL;
								}

								for (int n = 0; n < 6; ++n)
								{
									if (*digits[n] == -1)
									{
										bool found = false;
										for (int k = 0; !found; ++k)
										{
											if (wildcards[k] == NULL)
											{
												wildcards[k] = digits[n];
												found = true;
											}
										}
									}
								}

								// Replace the wildcards with each digit and count the number of resulting primes
								int primeCount = 0;
								int firstPrime = -1;
								for (int digit = 0; digit < 10; ++digit)
								{
									for (int i = 0; i < wildcardCount; ++i)
									{
										*wildcards[i] = digit;
									}

									if (isPrime(a*100000+b*10000+c*1000+d*100+e*10+f))
									{
										if (firstPrime == -1)
										{
											firstPrime = digit;
										}
										++primeCount;
									}
								}

								// Print when we've found a possible answer
								if (primeCount == 8)
								{
									for (int i = 0; i < wildcardCount; ++i)
									{
										*wildcards[i] = firstPrime;
									}
									cout << a << b << c << d << e << f << endl;
								}

								// Reset the wildcard flags as to not interfere with our loops
								for (int i = 0; i < wildcardCount; ++i)
								{
									*wildcards[i] = -1;
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