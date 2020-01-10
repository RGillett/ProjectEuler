/*******************************************************************************
* Digit Fifth Powers
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int finalSum = 0;
	for (int i = 2; i < 1000000; i++)
	{
		int sum = 0;
		int number = i;
		while (number > 0)
		{
			sum += pow(number%10,5);
			number /= 10;
		}
		if (sum == i)
		{
			finalSum += i;
		}
	}

	cout << finalSum << endl;

	return 0;
}