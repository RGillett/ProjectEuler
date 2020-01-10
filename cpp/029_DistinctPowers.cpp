/*******************************************************************************
* Distinct Powers
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <set>
#include "primes.h"

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	set< vector<int> > distinctTerms;
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
			distinctTerms.insert(multiples);
		}
	}

	cout << distinctTerms.size();

	return 0;
}