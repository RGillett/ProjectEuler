/*******************************************************************************
* Combinatoric Selections
* Author: Ryan Gillett
*
* Insights:
*  - The lowest value of n that can produce a number > 1,000,000 is 23
*  - The lowest value of r that can produce a number > 1,000,000 is 4
*  - nCr is symmetrical, so we only have to look at the first half of the r values
*  - If nCr is > 1,000,000, then all further values of r such that r < n/2 will also be > 1,000,000
*******************************************************************************/
#include <iostream>
#include "combinatorics.h"

using namespace std;

/******************************************************************************
* Main
******************************************************************************/
int main()
{
	// cout << partialFactorial(70, 5) << endl;
	int overAMillionCount = 0;
	for (int n = 23; n <= 50; n++)
	{
		for (int r = 4; r <= n/2; r++)
		{
			cout << choose(n, r) << endl;
			// if (choose(n, r) > 1000000)
			// {
			// 	overAMillionCount += 2 * (n - r + 1);
			// }
		}
		cout << endl;
	}

	cout << overAMillionCount << endl;

    return 0;
}