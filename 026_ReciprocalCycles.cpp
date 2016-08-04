/*******************************************************************************
* Reciprocal Cycles
* Authors: Ryan Gillett
*
* This program will find the n with the longest string of infinitely repeating
* digits for 1/n where 1 < n < 1000.
*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int countRepeatingDigits(int number);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int n = 0;
	int maxCount = 0;
	for (int i = 1; i < 1000; i++)
	{
		int digitCount = countRepeatingDigits(i);
		if (digitCount > maxCount)
		{
			maxCount = digitCount;
			n = i;
		}
	}
	cout << n << endl;
}

/*******************************************************************************
* countRepeatingDigits()
* Finds the number of digits that repeat when 1 is divided by a given number.
* The approach I took to accomplish this is to not actually calculate the
* division, but to save off the number being divided on each iteration of long
* division into a vector and check if the number has been encountered
* previously. If it has, I know I've found a repetition.
*******************************************************************************/
int countRepeatingDigits(int number)
{
	int numberToDivide = 1; // The number to be divided on each iteration of
							// the long division algorithm
	vector<int> tries; // The array of previous "numberToDivide"s

	while(numberToDivide > 0)
	{
		tries.push_back(numberToDivide);
		// Carry a zero and get the remainder of the division
		numberToDivide *= 10;
		numberToDivide %= number;
		// Check if the current number has been encountered before
		for (int i = 0; i < tries.size(); i++)
		{
			if (numberToDivide == tries[i])
			{
				// Return the length of the repeated string
				return tries.size() - i;
			}
		}
	}

	// If the loop exits, there is no infinite repetition-- return the length
	return tries.size();
}