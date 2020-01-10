/******************************************************************************
* Program: Champernowne's Constant
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>

using namespace std;
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int digits = 0;
	int digitIndex = 0;
	int product = 1;
	int targetIndexes[7] = {1,10,100,1000,10000,100000,1000000};
	int searchingIndex = 0;
	int nextPowerOfTen = 1;
	for (int i = 1; searchingIndex < 7; i++)
	{
		if (i == nextPowerOfTen)
		{
			digits++;
			nextPowerOfTen *= 10;
		}

		digitIndex += digits;

		if (digitIndex >= targetIndexes[searchingIndex])
		{
			int operand = i;
			for (int j = digitIndex - targetIndexes[searchingIndex]; j > 0; j--)
			{
				operand /= 10;
			}
			searchingIndex++;
			operand %= 10;
			product *= operand;
		}
	}

	cout << product << endl;

	return 0;
}