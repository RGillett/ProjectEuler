/******************************************************************************
* Convergents Of E
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

fraction findFractionalApproximationofE(int,int);
int getConvergentDivisor(int);

/******************************************************************************
* Main
******************************************************************************/
int main()
{
	fraction eApproximation = findFractionalApproximationofE(0,100);
	cout << eApproximation.numerator.digitSum() << endl;

	return 0;
}

fraction findFractionalApproximationofE(int i, int numberOfConvergents)
{
	if (i == numberOfConvergents-1)
	{
		fraction fraction;
		fraction.numerator = getConvergentDivisor(i);
		fraction.denominator = 1;
		return fraction;
	}
	else
	{
		fraction fraction = findFractionalApproximationofE(i+1, numberOfConvergents);
		BigInt temp = fraction.denominator;
		fraction.denominator = fraction.numerator;
		fraction.numerator = temp;
		fraction.numerator += getConvergentDivisor(i) * fraction.denominator;
		return fraction;
	}
}

int getConvergentDivisor(int n)
{
	return (n % 3 != 2 ? (n == 0 ? 2 : 1) : (((n/3)+1)*2));
}