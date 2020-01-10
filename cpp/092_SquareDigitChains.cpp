/******************************************************************************
* Square Digit Chains
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>

using namespace std;

int squareDigitChain(int n);
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int count = 0;
	for (int i = 1; i < 10000000; i++)
	{
		if (squareDigitChain(i) == 89)
		{
			count++;
		}
	}

	cout << count << endl;

	return 0;
}

int squareDigitChain(int n)
{
	while (n != 1 && n != 89)
	{
		int sumOfDigitSquares = 0;
		while (n > 0)
		{
			int digit = n % 10;
			sumOfDigitSquares += digit * digit;
			n /= 10;
		}
		n = sumOfDigitSquares;
	}

	return n;
}