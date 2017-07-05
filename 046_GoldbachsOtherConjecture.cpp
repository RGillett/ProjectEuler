/*******************************************************************************
* Goldbach's Other Conjecture
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
	for (int i = 9; true; i+=2)
	{
		if (!isPrime(i))
		{
			bool sumMatches = false;
			for (long long int j = 3; j < i && !sumMatches; nextPrime(j))
			{
				for (int k = 1; k < i - j; k++)
				{
					if ((2 * (k*k)) == (i - j))
					{
						sumMatches = true;
					}
				}
			}

			if (!sumMatches)
			{
				cout << "answer: " << i << endl;
				return 0;
			}
		}
	}

	return 0;
}