/*******************************************************************************
* Permuted Multiples
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<int> buildDigitCountsVector(int number);
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	for (int i = 1; i < 1000000; i++)
	{
		vector<int> digitCounts = buildDigitCountsVector(i);
		if ((digitCounts == buildDigitCountsVector(2*i)) &&
			(digitCounts == buildDigitCountsVector(3*i)) &&
			(digitCounts == buildDigitCountsVector(4*i)) &&
			(digitCounts == buildDigitCountsVector(5*i)) &&
			(digitCounts == buildDigitCountsVector(6*i)))
		{
			cout << i << endl;
		}
	}
	
    return 0;
}

vector<int> buildDigitCountsVector(int number)
{
	vector<int> digitCounts(10);
	while(number > 0)
	{
		digitCounts[number % 10]++;
		number /= 10;
	}

	return digitCounts;
}