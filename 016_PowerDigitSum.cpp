/*******************************************************************************
* Power Digit Sum
* Authors: Ryan Gillett
*******************************************************************************/
#include "BigInt.h"

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	BigInt x = 2;
	
	for (int i = 1; i < 1000; i++)
	{
		x = x + x;
	}
	
	int digitSum = 0;
	
	for (int i = x.size(); i > 0; i--)
	{
		digitSum += x.digit(i);
	}
	
	cout << digitSum << endl;
	
	return 0;
}