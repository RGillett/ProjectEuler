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
long long int prime10001st();
bool isPrime(long long int);

/*******************************************************************************
* Main is the driver. It calls largestPrimeFactor()
* and displays the output.
*******************************************************************************/
int main()
{
	cout << "The 10001st prime is: ";
	cout << prime10001st() << endl;

	return 0;
}

/*******************************************************************************
* largestPrimeFactor()
* Finds the largest prime factor of a given value
*******************************************************************************/
long long int prime10001st()
{
	long long int primeFactor = 0;

	for (int i = 0; i < 10001; i++)
	{
		while (!isPrime(++primeFactor));
	}

	return primeFactor;
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
