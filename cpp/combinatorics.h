/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#ifndef COMBINATORICS
#define COMBINATORICS

/*******************************************************************************
* factorial()
*******************************************************************************/
long long int factorial(int number)
{
	long long int product = 1;
	while (number > 1)
	{
		product *= number--;
	}

	return product;
}

/*******************************************************************************
* partialFactorial()
*******************************************************************************/
long long int partialFactorial(int number, int minimum)
{
	long long int product = 1;
	while (number > minimum)
	{
		product *= number--;
	}

	return product;
}

/*******************************************************************************
* choose()
*******************************************************************************/
long long int choose(int n, int r)
{
	if (r > n-r)
	{
		return partialFactorial(n, r) / factorial(n - r);
	}
	else if (r < n-r)
	{
		return partialFactorial(n, n-r) / factorial(r);
	}
}

/*******************************************************************************
* isPermutation()
*******************************************************************************/
bool isPermutation(long long int firstNumber, long long int secondNumber)
{
	int digitCounts[10] = {0};

	while (firstNumber > 0 && secondNumber > 0)
	{
		digitCounts[firstNumber%10]++;
		digitCounts[secondNumber%10]--;
		firstNumber /= 10;
		secondNumber /= 10;
	}

	if (firstNumber > 0 || secondNumber > 0)
	{
		return false;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (digitCounts[i] != 0)
		{
			return false;
		}
	}

	return true;
}



#endif // COMBINATORICS