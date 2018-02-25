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



#endif // COMBINATORICS