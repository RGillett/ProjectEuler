#include <iostream>
using namespace std;

bool isPrime(long long int);
int nextPrime(int);
bool satisfiesConjecture(int);

void main()
{
	int i = 2;
	while (satisfiesConjecture(i++));
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

int nextPrime(int prime)
{
	prime++;
	while (!isPrime(prime))
		prime++;
	return prime;
}

bool satisfiesConjecture(int checkValue)
{
	int square;
	int prime = 2;

	if (checkValue % 2 == 0 || isPrime(checkValue))
		return true;

	while (prime < checkValue)
	{
		square = 1;
		while (2*square*square + prime <= checkValue)
		{
			if (2*square*square + prime == checkValue)
				return true;
			square++;
		}
		prime = nextPrime(prime);
	}

	cout << checkValue << endl;
	return false;
}