/*******************************************************************************
* Sum Square Difference
* Authors: Ryan Gillett, Brandon Gillett
*
* This program will find the difference between the square of the sum and the
* sum of the squares of the first 100 natural numbers.
*******************************************************************************/
#include <iostream>

using namespace std;

//Prototypes
int sumSquareDifference(int number);
int squareOfSums(int number);
int sumOfSquares(int number);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	cout << "The sum square difference of the first 100 natural numbers is: "
		 << sumSquareDifference(100) << endl;
}

int sumSquareDifference(int number)
{
	return squareOfSums(number) - sumOfSquares(number);
}

int sumOfSquares(int number)
{
	int sum = 0;

	for (int i = 1; i <= number; i++)
	{
		sum += (i * i);
	}

	return sum;
}

int squareOfSums(int number)
{
	int sum = 0;

	for (int i = 1; i <= number; i++)
	{
		sum += i;
	}

	return sum * sum;
}