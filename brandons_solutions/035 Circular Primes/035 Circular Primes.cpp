#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int circularPrimeCounter();
bool checkRotations(int primeNumber);
int findNumberOfDigits(int number);
int integerRotater(int number);
int power(int base, int exponent);
bool isPrime(long long int checkValue);


int main()
{
    cout << circularPrimeCounter() << endl;
}

int circularPrimeCounter()
{
    int counter = 0;
        for(int i = 1; i < 1000000; i++)
        {
            if(isPrime(i) && checkRotations(i))
                counter++;
        }
        return counter;
}

bool checkRotations(int primeNumber)
{
    int rotations = findNumberOfDigits(primeNumber);

    for(int i = 1; i < rotations; i++)
    {
        primeNumber = integerRotater(primeNumber);
        if(!isPrime(primeNumber))
           return false;
    }

    return true;
}

int integerRotater(int number)
{
    int lastDigit;
    lastDigit = number % 10;
    lastDigit *= power(10, findNumberOfDigits(number) - 1);
    number = (number / 10) + lastDigit;
}

int findNumberOfDigits(int number)
{
    int digitCount;

    for(digitCount = 0; number > 0; digitCount++)
    {
        number /= 10;
    }

    return digitCount;
}

bool isPrime(long long int checkValue)
{
	if (checkValue < 2)
		return false;

    if(checkValue % 2 == 0)
    {
        if(checkValue == 2)
            return true;

        else
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

int power(int base, int exponent)
{
    int product = 1;
    while(exponent > 0)
    {
        product *= base;
        exponent--;
    }

    return product;
}
