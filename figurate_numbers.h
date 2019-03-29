/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#ifndef FIGURATE_NUMBERS
#define FIGURATE_NUMBERS

#define SIEVE_MAX 100000

void populateFigurateSieve(bool* sieve, const int &ADDER_INCREASE)
{
    int number = 0;
    int adder = 1;

	for (int i = 0; i < SIEVE_MAX; i++)
	{
        if (i == number)
        {
		    sieve[i] = true;
            number += adder;
            adder += ADDER_INCREASE;
        }
		else
		{
			sieve[i] = false;
		}
	}

	return;
}

bool isTriangleNumber(long long int n)
{
    static bool triangleNumberSieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		populateFigurateSieve(triangleNumberSieve, 1);
		initialized = true;
	}

	return triangleNumberSieve[n];
}

bool isSquareNumber(long long int n)
{
    static bool squareNumberSieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		populateFigurateSieve(squareNumberSieve, 2);
		initialized = true;
	}

	return squareNumberSieve[n];
}

bool isPentagonalNumber(long long int n)
{
    static bool pentagonalNumberSieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		populateFigurateSieve(pentagonalNumberSieve, 3);
		initialized = true;
	}

	return pentagonalNumberSieve[n];
}

bool isHexagonalNumber(long long int n)
{
    static bool HexagonalNumberSieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		populateFigurateSieve(HexagonalNumberSieve, 4);
		initialized = true;
	}

	return HexagonalNumberSieve[n];
}

bool isHeptagonalNumber(long long int n)
{
    static bool HeptagonalNumberSieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		populateFigurateSieve(HeptagonalNumberSieve, 5);
		initialized = true;
	}

	return HeptagonalNumberSieve[n];
}

bool isOctagonalNumber(long long int n)
{
    static bool octagonalNumberSieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		populateFigurateSieve(octagonalNumberSieve, 6);
		initialized = true;
	}

	return octagonalNumberSieve[n];
}
#endif