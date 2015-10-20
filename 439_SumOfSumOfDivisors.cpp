/*******************************************************************************
* Sum Of Sum Of Divisors
* Authors: Ryan Gillett, Brandon Gillett
*******************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

//Prototypes
bool isPrime(long long int);
long long int factorSum(long long int value);
long long int factorCounter(long long int value);
void nextPrime(long long int &value);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	for (long long int i = 1; i <= 100; i++)
	{
		cout << i << ": " << factorSum(i) << endl;
	}
	/*long long int sum = 0;
	
	for (long long int i = 1; i <= 10; i++)
	{
		cout << sum << endl;
		for (long long int j = 1; j <= 10; j++)
		{
			sum += factorSum(i*j);
			sum %= 1000000000;
		}
	}
	
	cout << sum << endl;*/

	return 0;
}

long long int factorSum(long long int value)
{
	long long int sum = 0;
	long long int max = sqrt(value);
	
	for (long long int i = 1; i <= max; i++)
	{
		if (value % i == 0)
		{
			sum += i;
			sum += value / i;
		}
	}
	
	if (max * max == value)
		sum -= max;
	
	return sum;
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