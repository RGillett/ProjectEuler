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
int sumSquareDifference();
int squareOfSums();
int sumOfSquares();

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	cout << "The sum square difference of the first 100 natural numbers is: "
		 << sumSquareDifference() << endl;
}

int sumSquareDifference()
{
	return squareOfSums() - sumOfSquares();
}

int sumOfSquares()
{
	int sum = 0;
	
	for (int i = 1; i <= 100; i++)
	{
		sum += (i * i);
	}

	return sum;
}

int squareOfSums()
{
	int sum = 0;
	
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}

	return sum * sum;
}