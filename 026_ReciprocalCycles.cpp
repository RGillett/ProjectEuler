/*******************************************************************************
* Reciprocal Cycles
* Authors: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int countRepeatingDigits(int number);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int d = 0;
	int maxCount = 0;
	for (int i = 1; i < 1000; i++)
	{
		int digitCount = countRepeatingDigits(i);
		if (digitCount > maxCount)
		{
			maxCount = digitCount;
			d = i;
		}
	}
	cout << d << endl;
}

int countRepeatingDigits(int number)
{
	int numberToDivide = 1;
	vector<int> tries;
	while(numberToDivide > 0)
	{
		tries.push_back(numberToDivide);
		numberToDivide *= 10;
		numberToDivide %= number;
		for (int i = 0; i < tries.size(); i++)
		{
			if (numberToDivide == tries[i])
			{
				return tries.size() - i - 1;
			}
		}
	}

	return tries.size();
}