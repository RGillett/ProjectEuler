/******************************************************************************
* Square Root Convergents
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>
#include "BigInt2.h"

using namespace std;

struct fraction
{
	BigInt numerator;
	BigInt denominator;
};

/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int count = 0;
	fraction approximation = {1, 1};
	for (int i = 1; i <= 1000; i++)
	{
		BigInt placeHolder = approximation.denominator;
		approximation.denominator += approximation.numerator;
		approximation.numerator = approximation.denominator + placeHolder;
		if (approximation.numerator.digitCount() > approximation.denominator.digitCount())
		{
			count++;
		}
	}

	cout << count << endl;

	return 0;
}