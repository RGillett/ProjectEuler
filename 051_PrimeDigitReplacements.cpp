/*******************************************************************************
* Prime Digit Replacements
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <math.h>
#include "primes.h"

using namespace std;

/******************************************************************************
* Main
******************************************************************************/
int main()
{
	// This is an O(n^9) algorithm, but it's still fast because n will never
	// be larger than 11 to solve this problem ;)
	for (int a = 0; a <= 10; ++a)
	{
		for (int b = 0; b <= 10; ++b)
		{
			for (int c = 0; c <= 10; ++c)
			{
				for (int d = 0; d <= 10; ++d)
				{
					for (int e = 0; e <= 10; ++e)
					{
						for (int f = 0; f <= 10; ++f)
						{
							int* digits[6] = {&a,&b,&c,&d,&e,&f};

							int wildcardCount = 0;
							for (int n = 0; n < 6; ++n)
							{
								if (*digits[n] == 10)
								{
									wildcardCount++;
								}
							}

							if (wildcardCount > 0)
							{
								int* wildcards[wildcardCount];
								for (int i = 0; i < wildcardCount; ++i)
								{
									wildcards[i] = NULL;
								}

								for (int n = 0; n < 6; ++n)
								{
									if (*digits[n] == 10)
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

								if (primeCount == 8)
								{
									for (int i = 0; i < wildcardCount; ++i)
									{
										*wildcards[i] = firstPrime;
									}
									cout << a << b << c << d << e << f << endl;
								}

								for (int i = 0; i < wildcardCount; ++i)
								{
									*wildcards[i] = 10;
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