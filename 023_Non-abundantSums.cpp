/*******************************************************************************
* Prime Factors
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <list>
#include <cassert>

using namespace std;

//Prototypes
long long int factorSum(long long int value);
bool isAbundant(int value);
bool isPerfect(int value);

/*******************************************************************************
* Main
*******************************************************************************/
int main(int argc, char** argv)
{
	//the perfect numbers < 28123 are 6, 28, 496, 8128
	//Every multiple of 6 > 12 is abundant
	//All even numbers > 46 can be written as a sum of two abundant numbers
	//No odd numbers < 957 can be written as a sum of two abundant numbers
	//The only even numbers that cannot be written as a sum of two abundant numbers are:
	//2 4 6 8 10 12 14 16 18 20 22 26 28 34 46, their sum being 244
	
	unsigned long long int sum = 2+4+6+8+10+12+14+16+18+20+22+26+28+34+46;
	list<int> oddAbundant;
	list<int> evenAbundant;
	
	for (int i = 1; i < 957; i+=2)
	{
		sum += i;
	}

	for (int i = 945; i <= 28123; i+=10)
	{
		if (isAbundant(i))
		{
			oddAbundant.push_back(i);
		}
	}

	for (int i = 12; i <= 28123; i+=2)
	{
		if (isAbundant(i))
		{
			evenAbundant.push_back(i);
		}
	}
	
	for (int i = 957; i  <= 28123; i+=2)
	{
		bool shouldAdd = true;
		for (list<int>::iterator itE = evenAbundant.begin(); itE != evenAbundant.end(); itE++)
		{
			for (list<int>::iterator itO = oddAbundant.begin(); *itE + *itO <= i && itO != oddAbundant.end(); itO++)
			{
				if (*itE + *itO == i)
				{
					shouldAdd = false;
					itO = --(oddAbundant.end());
					itE = --(evenAbundant.end());
				}
			}
		}
		if (shouldAdd == true)
		{
			sum += i;
		}
	}
	
	cout << "sum: " << sum << endl;
	
		
	return 0;
}

/*******************************************************************************
* Checks whether a number is an abundant number.
*******************************************************************************/
bool isAbundant(int value)
{
	return value < factorSum(value);
}

/*******************************************************************************
* Checks whether a number is an perfect number.
*******************************************************************************/
bool isPerfect(int value)
{
	return value == factorSum(value);
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