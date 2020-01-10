/*******************************************************************************
* Number Spiral Diagonals
* Author: Ryan Gillett
*
* This program will find the sums of the diagonals of a 1001x1001 array in
* in which the numbers increment starting from the center in a spiral pattern.
*******************************************************************************/
#include <iostream>

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int spiralSize = 1001;
	int sum = 1;
	int addAmount = 1;

	for (int incramentBy = 2; addAmount < spiralSize*spiralSize; incramentBy += 2)
	{
		for (int i = 0; i < 4; i++)
		{
			addAmount += incramentBy;
			sum += addAmount;
		}
	}

	cout << sum << endl;

	return 0;
}