/*******************************************************************************
* Highly Divisible Triangular Number
* Authors: Ryan Gillett, Brandon Gillett
*******************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

//Prototypes
long long int findTriangleNumber(long long int n);
bool isPrime(long long int);
long long int factorCounter(long long int value);
void nextPrime(long long int &value);
long long int triangularFactorCounter(long long int targetFactors);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	// The default value for this program is hard coded
	long long int targetFactors = 500;
	
	// Call the calculation function and display the results
	cout << "The smallest triangular number with over " << targetFactors << " is: ";
	cout << triangularFactorCounter(targetFactors) << endl;

	return 0;
}

//Returns a triangle number with the specified number of factors.
long long int triangularFactorCounter(long long int targetFactors)
{
	long long int triangularNumber = 1;
	
	for (long long int n = 1; factorCounter(triangularNumber) <= targetFactors; n++)
	{
		triangularNumber = findTriangleNumber(n);
	}
	
	return triangularNumber;
}

long long int findTriangleNumber(long long int n)
{
	return ((n * (n + 1)) / 2);
}

long long int factorCounter(long long int value)
{
	long long int primeFactor = 0;
	
	int factors = 1;
	
	while (value > 1)
	{
		int factorCounter = 1;
		
		nextPrime(primeFactor);
			
		while (value % primeFactor == 0)
		{
			value /= primeFactor;
			factorCounter++;
		}
		
		factors *= factorCounter;
	}
	
	return factors;
}

void nextPrime(long long int &value)
{
	while (!isPrime(++value))
			;
}

bool isPrime(long long int checkValue)
{
	if (checkValue < 2)
		return false;
		
	if (checkValue == 2)
		return true;
		
	if (checkValue % 2 == 0)
		return false;
		
	long long int maxValue = sqrt(checkValue);
		
	for (long long int i = 3; i <= maxValue; i += 2)
	{
		if (checkValue % i == 0)
			return false;
	}
	
	return true;
}