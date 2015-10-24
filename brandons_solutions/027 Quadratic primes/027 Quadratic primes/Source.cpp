#include <iostream>
using namespace std;

bool isPrime(long long int);

void main()
{
	int count = 0;
	int numberOfPrimes = 0;
	int product = 0;

	int a, b, n;
	for (a = -1000; a <= 1000; a++)
	{
		for (b = -1000; b <= 1000; b++)
		{
			count = 0;

			for (n = 0; isPrime(n*n + a*n + b); n++)
			{
				count++;
			}

			if (numberOfPrimes < count)
			{
				numberOfPrimes = count;
				product = a*b;
			}
		}
	}

	cout << product << endl;
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