/*******************************************************************************
* Quadratic Primes
* Authors: Ryan Gillett
*
* This program will find the product of the values of a and b for n^2+an+b that
* yields the highest number of consecutive prime numbers for n = 0 ... k.
*******************************************************************************/
#include <iostream>
#include <math.h>
#include <time.h>
#include "primes.h"

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int productAB = 0;
	int maxCount = 0;
	for (int a = -999; a < 1000; a++)
	{
		for (int b = -1000; b <= 1000; b++)
		{
			int count = 0;
			for (int n = 0; isPrime(fabs((n*n)+(a*n)+b)) == true; n++)
			{
				count++;
			}

			if (count > maxCount)
			{
				maxCount = count;
				productAB = a * b;
			}
		}
	}

	cout << productAB << endl;

	return 0;
}