/******************************************************************************
* Program:
*    1000 Digit Fibonacci Number
* Author:
*    Ryan Gillett
******************************************************************************/
#include <cstdlib>
#include "BigInt.h"

using namespace std;
 
/******************************************************************************
* Driver
******************************************************************************/
int main(int argc, char** argv)
{
	int num;
	if (argc < 2)
	{
		cout << "Enter Number: ";
		cin >> num;
	}
	else
		num = atoi(argv[1]);

	BigInt a = 1;
	BigInt b = 0;
	BigInt c = 0;

	for (int i = 0; i < num; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	cout << c << endl;

	return 0;
}