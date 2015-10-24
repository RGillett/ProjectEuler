/*******************************************************************************
* Prime Factors
* Authors: Ryan Gillett, Brandon Gillett
*
* This program will find the largest prime factor of 600,851,475,143. All of
* the tools are in place for it to be modified to calculate
*******************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

//Prototypes
void nextPrime(long long int &);
bool isPrime(long long int);
long long int primeSummation(long long int);

/*******************************************************************************
* Main is the driver. It calls largestPrimeFactor()
* and displays the output.
*******************************************************************************/
int main()
{
	cout << "The sum of all primes less than 2,000,000 is: ";
	cout << primeSummation(2000000) << endl;

	return 0;
}

/*******************************************************************************
* largestPrimeFactor()
* Finds the largest prime factor of a given value
*******************************************************************************/
long long int primeSummation(long long int maxValue)
{
	long long int primeNumber = 0;
	long long int sum = 0;

	while (primeNumber < maxValue)
	{
		sum += primeNumber;

		nextPrime(primeNumber);
	}

	return sum;
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
