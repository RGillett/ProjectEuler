#include <iostream>
#include <math.h>

using namespace std;

long long int fun(long long int number);
long long int factorCounter(long long int value);
void nextPrime(long long int &value);
bool isPrime(long long int checkValue);

int main()
{
   cout << fun(72) << endl;
}

long long int fun(long long int number)
{
    long long int something;

    something = number * factorCounter(number);
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
