/*******************************************************************************
* Distinct Powers
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <math.h>
#include "primes.h"

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	vector<vector<int> > uniqueValues;
	for (int a = 2; a <= 100; a++)
	{
		vector<int> factors = factorize(a);
		for (int b = 2; b <= 100; b++)
		{
			vector<int> multiples;
			for (int i = 0; i < factors.size(); i++)
			{
				multiples.push_back(factors[i] * b);
			}
			bool unique = true;
			for (int i = 0; i < uniqueValues.size(); i++)
			{
				if (multiples == uniqueValues[i])
				{
					unique = false;
					i = uniqueValues.size();
				}
			}
			if (unique)
			{
				uniqueValues.push_back(multiples);
			}
		}
	}

	cout << uniqueValues.size();

	return 0;
}