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
long long int largestPrimeFactor(long long int);
bool isPrime(long long int);

/*******************************************************************************
* Main is the driver. It calls largestPrimeFactor()
* and displays the output.
*******************************************************************************/
int main()
{
	// The default value for this program is hard coded
	long long int targetValue = 600851475143;
	
	// Call the calculation function and display the results
	cout << "The largest prime factor of " << targetValue << " is: ";
	cout << largestPrimeFactor(targetValue) << endl;

	return 0;
}

/*******************************************************************************
* largestPrimeFactor()
* Finds the largest prime factor of a given value
*******************************************************************************/
long long int largestPrimeFactor(long long int value)
{
	// The container for testing each prime number. It will contain the
	// largest prime factor of the input value when it is returned.
	long long int primeFactor = 0;
	
	//
	while (value > 1)
	{
		while (!isPrime(++primeFactor))
			;
			
		while (value % primeFactor == 0)
		{
			value /= primeFactor;
		}
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