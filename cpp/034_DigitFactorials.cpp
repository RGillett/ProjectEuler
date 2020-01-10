/******************************************************************************
* Program: Digit Factorials
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>

using namespace std;
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int factorials[10] = {1};
	for (int i = 1; i < 10; i++)
	{
		factorials[i] = factorials[i-1] * i;
	}

	int finalSum = 0;
	for (int i = 3; i < 3000000; i++)
	{
		int sum = 0;
		for (int number = i; number > 0; number /= 10)
		{
			sum += factorials[number%10];
		}
		if (sum == i)
		{
			finalSum += sum;
			cout << sum << endl;
		}
	}

	cout << finalSum << endl;

	return 0;
}