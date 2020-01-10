/*******************************************************************************
* Pentagon Numbers
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//Prototypes
void generateSieve(bool* sieve, const int& size);
bool isPentagonNumber(int number);
int nextPentagonal(int number);
int previousPentagonal(int number);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	try
	{
		for (int i = 1; i < 50000000; i = nextPentagonal(i))
		{
			for (int j = previousPentagonal(i); j > 0; j = previousPentagonal(j))
			{
				if (isPentagonNumber(i - j) && isPentagonNumber(i + j))
				{
					cout << i - j << endl;
					return 0;
				}
			}
		}
	}
	catch (const invalid_argument &e)
	{
		cout << "Error: " << e.what() << endl;
	}
	
	return 0;
}

void generateSieve(bool* sieve, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		sieve[i] = false;
	}

	int n = 0;
	for (int i = 1; n < size; i++)
	{
		sieve[n] = true;
		n = (i * (3 * i - 1)) / 2;
	}
}

bool isPentagonNumber(int number)
{
	static const int SIEVE_MAX = 100000000;
	static bool pentagonNumberSieve[SIEVE_MAX];
	static bool initialized = false;

	if (number >= SIEVE_MAX)
	{
		throw invalid_argument("Number exceeds the SIEVE_MAX limit");
	}

	if (!initialized)
	{
		generateSieve(pentagonNumberSieve, SIEVE_MAX);
		initialized = true;
	}

	return pentagonNumberSieve[number];
}

int nextPentagonal(int number)
{
	while (!isPentagonNumber(++number))
		;

	return number;
}

int previousPentagonal(int number)
{
	while (number > 0 && !isPentagonNumber(--number))
		;

	return number;
}