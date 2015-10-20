/******************************************************************************
* Program:
*    Amicable Numbers
* Author:
*    Ryan Gillett
*
* This program is designed to sum all of the amicable numbers under 10,000. An
* amicable number pair is a pair of numbers in which SumOfFactors(a) == b and
* SumOfFactors(b) = a.
******************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

//Prototypes
long long int factorSum(long long int);

/******************************************************************************
* Driver to test the class.
******************************************************************************/
int main()
{
	int amicableSum = 0;
	
	for (int i = 1; i < 10000; i++)
	{
		int sum = factorSum(i);
		if (sum > i)
		{
			if (factorSum(sum) == i)
			{
				amicableSum += sum + i;
			}
		}
	}
	
	cout << amicableSum << endl;

	return 0;
}

/*******************************************************************************
* Sums all of the factors of a given number. (Doesn't include the number itself.)
*******************************************************************************/
long long int factorSum(long long int value)
{
	long long int sum = 1;
	long long int max = sqrt(value);
	
	for (long long int i = 2; i <= max; i++)
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