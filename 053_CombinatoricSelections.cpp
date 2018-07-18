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
	int overAMillionCount = 0;
	for (int n = 23; n <= 100; n++)
	{
        int r = 3;
		while (choose(n, ++r) <= 1000000)
            ;
        overAMillionCount += 2 * (n/2 - (r - 1)) - (n%2 == 0);
	}

	cout << overAMillionCount << endl;

    return 0;
}