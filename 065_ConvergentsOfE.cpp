/******************************************************************************
* Program:
*    Convergents Of E
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

//Prototypes
int calculateENumber(const int& n);
void reduceFraction(unsigned long long int& numerator, unsigned long long int& denominator);
void nextPrime(unsigned long long int &value);
bool isPrime(unsigned long long int checkValue);
int addDigits(int value);
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	const int TARGET = 30;
	
	unsigned long long int numerator = 1;
	unsigned long long int denominator = calculateENumber(TARGET);
	
	for (int i = TARGET - 1; i > 1; i--)
	{
		numerator += denominator * calculateENumber(i);
		cerr << "e number: " << calculateENumber(i) << endl;
		int swap = numerator;
		numerator = denominator;
		denominator = swap;
		reduceFraction(numerator, denominator);
		cerr << numerator << "/" << denominator << endl;
	}
	
	numerator += denominator * 2;
	
	cerr << numerator << "/" << denominator << endl;
	
	cout << addDigits(numerator) << endl;
	
	return 0;
}

int calculateENumber(const int& n)
{
	if (n % 3 == 0)
	{
		return (n + 1) * 2 / 3;
	}
	else
	{
		return 1;
	}
}

void reduceFraction(unsigned long long int& numerator, unsigned long long int& denominator)
{cout << "A" << endl;
	unsigned long long int rootNumerator = sqrt(numerator);
	unsigned long long int rootDenominator = sqrt(denominator);
	
	for (unsigned long long int i = 2; i < rootNumerator && i < rootDenominator; i++)
	{cout << "i: " << i << " numerator: " << numerator << " denominator: " << denominator << "\n";
		while (numerator % i == 0 && denominator % i == 0)
		{cout << "C" << endl;
			numerator /= i;
			denominator /= i;
		}
	}
}

void nextPrime(unsigned long long int &value)
{
	while (!isPrime(++value))
			;
}

bool isPrime(unsigned long long int checkValue)
{
	if (checkValue < 2)
		return false;
		
	if (checkValue % 2 == 0)
	{
		if (checkValue == 2)
		{
			return true;
		}
		return false;
	}
		
	long long int maxValue = sqrt(checkValue);
		
	for (long long int i = 3; i <= maxValue; i += 2)
	{
		if (checkValue % i == 0)
			return false;
	}
	
	return true;
}

int addDigits(int value)
{
	int sum = 0;
	
	while (value > 0)
	{
		sum += value % 10;
		value /= 10;
	}
	
	return sum;
}

