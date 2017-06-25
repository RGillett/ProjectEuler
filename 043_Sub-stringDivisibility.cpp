/*******************************************************************************
* Sub-string Divisibility
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>

using namespace std;

//Prototypes
long nextPandigital(long number);
bool isFullPandigital(long value);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	long sumOfDivisibles = 0;
	for (long i = nextPandigital(1000000000); i < 9876543210; i = nextPandigital(i))
	{
		bool divisible = true;
		if (((i % 1000000000) / 1000000) % 2 != 0)
		{
			divisible = false;
		}
		if (((i % 100000000) / 100000) % 3 != 0)
		{
			divisible = false;
		}
		if (((i % 10000000) / 10000) % 5 != 0)
		{
			divisible = false;
		}
		if (((i % 1000000) / 1000) % 7 != 0)
		{
			divisible = false;
		}
		if (((i % 100000) / 100) % 11 != 0)
		{
			divisible = false;
		}
		if (((i % 10000) / 10) % 13 != 0)
		{
			divisible = false;
		}
		if ((i % 1000) % 17 != 0)
		{
			divisible = false;
		}
		if (divisible == true)
		{
			sumOfDivisibles += i;
		}
	}

	cout << sumOfDivisibles << endl;

	return 0;
}

long nextPandigital(long number)
{
	while(!isFullPandigital(++number))
		;

	return number;
}

bool isFullPandigital(long value)
{
	if (value < 1023456789)
	{
		return false;
	}
	bool digitExists[10] = {false};

	while (value > 0)
	{
		if (digitExists[value % 10])
		{
			return false;
		}
		digitExists[value % 10] = true;
		value /= 10;
	}

	for (short i = 0; i < 10; i++)
	{
		if (!digitExists[i])
		{
			return false;
		}
	}
	
	return true;
}