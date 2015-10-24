#include <iostream>

using namespace std;

double resiliance(int, long long int[]);
bool isPrime(long long int);
void nextPrime(long long int&);
void fillArray(long long int[]);

void main()
{
	int denominator =0;
	long long int arr[100000];
	fillArray(arr);

	for (denominator = 1; resiliance(denominator, arr) >= 15499 / 94744.0; denominator++)
		;
	cout << resiliance(denominator, arr) << ", " << denominator << endl;
}

double resiliance(int denominator, long long int arr[])
{
	static double x = 1;
	long long int coprimeCount = denominator;
	for (int i = 0; arr[i] <= denominator; i++)
	{
		if (denominator%arr[i] == 0)
		{
			if (denominator % (arr[i] * arr[i]) == 0)
				return 1;
			
			coprimeCount *= arr[i] - 1;
			coprimeCount /= arr[i];
		}
	}
	return (double)coprimeCount / (denominator - 1);
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

void nextPrime(long long int& prime)
{
	do
		prime++;
	while (!isPrime(prime));
}

void fillArray(long long int arr[])
{
	long long int prime = 2;
	for (int i = 0; i < 100000; i++, nextPrime(prime))
	{
		arr[i] = prime;
	}
	cout << "filled" << endl;
}

